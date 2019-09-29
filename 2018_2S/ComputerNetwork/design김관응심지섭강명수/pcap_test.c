#include <arpa/inet.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <net/ethernet.h>
#include <pcap/pcap.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <netinet/ip_icmp.h>

#define PROMISCUOUS 1
#define NONPROMISCUOUS 0
int port_num = 0;

// DNS header
struct dnshdr {
	uint16_t id;
	uint16_t flags;
	uint16_t qdcount;
	uint16_t ancount;
	uint16_t nscount;
	uint16_t arcount;
};

// IP 헤더 구조체
struct ip *iph;

// TCP 헤더 구조체
struct tcphdr *tcph;
struct udphdr *udph;
struct dnshdr *dnsh;

// 패킷을 받아들일경우 이 함수를 호출한다.  
// packet 가 받아들인 패킷이다.
void callback(u_char *useless, const struct pcap_pkthdr *pkthdr,
	const u_char *packet)
{
	static int count = 1;
	struct ether_header *ep;
	unsigned short ether_type;
	int chcnt = 0;
	int length = pkthdr->len;
	char buf[256];
	int cnt = 0;
	int cntt = 0;
	int i = 0;

	// 이더넷 헤더를 가져온다. 
	ep = (struct ether_header *)packet;

	// IP 헤더를 가져오기 위해서 
	// 이더넷 헤더 크기만큼 offset 한다.   
	packet += sizeof(struct ether_header);

	// 프로토콜 타입을 알아낸다. 
	ether_type = ntohs(ep->ether_type);

	// 만약 IP 패킷이라면 
	if (ether_type == ETHERTYPE_IP)
	{
		// IP 헤더에서 데이타 정보를 출력한다.  
		iph = (struct ip *)packet;
		printf("-----IP header-----\n");
		printf("Version     : %d\n", iph->ip_v);
		printf("Header Len  : %d\n", iph->ip_hl);
		printf("Ident       : %d\n", ntohs(iph->ip_id));
		printf("TTL         : %d\n", iph->ip_ttl);
		printf("Src Address : %s\n", inet_ntoa(iph->ip_src));
		printf("Dst Address : %s\n", inet_ntoa(iph->ip_dst));


		// 만약 TCP 데이타 라면
		   // TCP 정보를 출력한다. 
		if (iph->ip_p == IPPROTO_TCP)
		{
			printf("-----TCP header-----\n");
			tcph = (struct tcp *)(packet + iph->ip_hl * 4);
			printf("Src Port : %d\n", ntohs(tcph->source));
			printf("Dst Port : %d\n", ntohs(tcph->dest));
			printf("Seq # : %x\n", ntohl(tcph->th_seq));
			printf("Ack # : %x\n", ntohl(tcph->th_ack));
			printf("Chksum : %x\n", ntohs(tcph->th_sum));
			printf("SYN bit : %d\n", tcph->syn);
			printf("ACK bit : %d\n", tcph->ack);
			printf("FIN bit : %d\n", tcph->fin);
			packet += iph->ip_hl * 4 + tcph->th_off * 4;
			length -= iph->ip_hl * 4 + tcph->th_off * 4 + sizeof(struct ether_header);
			if (port_num != 5)
			{
				while (length--)
					printf("%c", *(packet++));
			}

		}
		else if (iph->ip_p == IPPROTO_UDP)
		{
			printf("-----UDP header-----\n");
			udph = (struct udp *)(packet + iph->ip_hl * 4);
			printf("Src Port(UDP) : %d\n", ntohs(udph->source));
			printf("Dst Prot(UDP) : %d\n", ntohs(udph->dest));
			printf("Chksum : %x\n", udph->uh_sum);
			packet += iph->ip_hl * 4 + sizeof(struct udphdr);
			length -= iph->ip_hl * 4 + sizeof(struct udphdr) + sizeof(struct ether_header);
		}

		if (port_num == 2)
		{
			dnsh = (struct dnshdr *)packet;
			printf("=========DNS==========\n");
			printf("Transaction ID: 0x%x\n", ntohs(dnsh->id));
			printf("Flags : 0x%x\n", ntohs(dnsh->flags));
			printf("Question count: %u\n", ntohs(dnsh->qdcount));
			printf("Answer count: %u\n", ntohs(dnsh->ancount));
			printf("Nameserver count: %u\n", ntohs(dnsh->nscount));
			printf("AddRecord counter: %u\n", ntohs(dnsh->arcount));
			printf("Query name string:");
			packet += sizeof(struct dnshdr);

			uint8_t count;
			for (;;)
			{
				count = (uint8_t)*packet++;
				if (count == 0)break;
				for (; count > 0;)
				{
					printf("%c", *packet++);
					count--;
				}
				printf(".");
			}
			printf("\n");
		}
		else if (port_num == 5)
		{

			while (length--)
			{
				printf("%2x ", *(packet++));
				cnt++, cntt++;
				if (cntt == 16)
				{
					cntt = 0;
					cnt = 0;
					printf("\n");
				}
				if (cnt == 8)
				{
					cnt = 0;
					printf(" ");
				}

			}
		}
		else if (port_num == 6);
		else while (length--) printf("%c", *(packet++));

	}
	// IP 패킷이 아니라면 
	else
	{
		printf("NONE IP 패킷\n");
	}
	printf("\n\n");
}


int main(int argc, char **argv)
{
	char *dev;
	char *net;
	char *mask;

	bpf_u_int32 netp;
	bpf_u_int32 maskp;
	char errbuf[PCAP_ERRBUF_SIZE];
	int ret;
	struct pcap_pkthdr hdr;
	struct in_addr net_addr, mask_addr;
	struct ether_header *eptr;
	const u_char *packet;

	struct bpf_program fp;
	char *port_name;


	pcap_t *pcd;  // packet capture descriptor
	printf("1.HTTP\n2.DNS\n3.SMTP\n4.POP\n5.BITCOIN\n6.SSH\nINPUT PORT NUMBER : ");
	scanf("%d", &port_num);
	if (port_num == 1)
		port_name = "port 80";
	else if (port_num == 2)
		port_name = "port 53";
	else if (port_num == 3)
		port_name = "port 25";
	else if (port_num == 4)
		port_name = "port 110";
	else if (port_num == 5)
		port_name = "port 8333";
	else if (port_num == 6)
		port_name = "port 22";
	else
		printf("Wrong Number!");

	// 사용중인 디바이스 이름을 얻어온다. 
	dev = pcap_lookupdev(errbuf);
	if (dev == NULL)
	{
		printf("%s\n", errbuf);
		exit(1);
	}
	printf("DEV : %s\n", dev);

	// 디바이스 이름에 대한 네트웍/마스크 정보를 얻어온다. 
	ret = pcap_lookupnet(dev, &netp, &maskp, errbuf);
	if (ret == -1)
	{
		printf("%s\n", errbuf);
		exit(1);
	}

	// 네트웍/마스트 정보를 점박이 3형제 스타일로 변경한다. 
	net_addr.s_addr = netp;
	net = inet_ntoa(net_addr);
	printf("NET : %s\n", net);

	mask_addr.s_addr = maskp;
	mask = inet_ntoa(mask_addr);
	printf("MSK : %s\n", mask);
	printf("=======================\n");

	// 디바이스 dev 에 대한 packet capture 
	// descriptor 를얻어온다.   
	pcd = pcap_open_live(dev, BUFSIZ, NONPROMISCUOUS, -1, errbuf);
	if (pcd == NULL)
	{
		printf("%s\n", errbuf);
		exit(1);
	}

	// 컴파일 옵션을 준다.
	if (pcap_compile(pcd, &fp, port_name, 0, netp) == -1)
	{
		printf("compile error\n");
		exit(1);
	}
	// 컴파일 옵션대로 패킷필터 룰을 세팅한다. 
	if (pcap_setfilter(pcd, &fp) == -1)
	{
		printf("setfilter error\n");
		exit(0);
	}

	// 지정된 횟수만큼 패킷캡쳐를 한다. 
	// pcap_setfilter 을 통과한 패킷이 들어올경우 
	// callback 함수를 호출하도록 한다. 
	pcap_loop(pcd, -1, callback, NULL);
}