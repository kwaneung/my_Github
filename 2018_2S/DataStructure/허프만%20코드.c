#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 100
typedef struct TreeNode {
	int weight;
	struct TreeNode *left_child;
	struct TreeNode *right_child;
} TreeNode;
typedef struct {
	TreeNode *ptree;
	int key;
} element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

// 초기화 함수
init(HeapType *h)
{
	h->heap_size = 0;
}
// 삽입 함수
void insert_min_heap(HeapType *h, element item)
{
	int i;
	i = ++(h->heap_size);

	//  트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;     // 새로운 노드를 삽입
}
// 삭제 함수
element delete_min_heap(HeapType *h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		// 현재 노드의 자식노드중 더 작은 자식노드를 찾는다.
		if ((child < h->heap_size) &&
			(h->heap[child].key) > h->heap[child + 1].key)
			child++;
		if (temp.key <= h->heap[child].key) break;
		// 한단계 아래로 이동
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

// 이진 트리 생성 함수
TreeNode *make_tree(TreeNode *left, TreeNode *right)
{
	TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
	if (node == NULL) {
		fprintf(stderr, "메모리 에러\n");
		exit(1);
	}
	node->left_child = left;
	node->right_child = right;
	return node;
}
// 이진 트리 제거 함수
void destroy_tree(TreeNode *root)
{
	if (root == NULL) return;
	destroy_tree(root->left_child);
	destroy_tree(root->right_child);
	free(root);
}

void display(TreeNode *Tree)
{
	if (Tree == NULL)
		return;
	display(Tree->left_child);
	printf("%d ", Tree->weight);
	display(Tree->right_child);
}

void display_huff(TreeNode *Tree, int h, char *code)
{
	if (Tree)
	{
		h++;//h는 트리의 깊이를 나타낸다
		code[h] = '1';//왼쪽으로 갈때 1넣는다
		display_huff(Tree->left_child, h, code);
		code[h] = '0';//오른쪽으로 갈때 0넣는다.
		display_huff(Tree->right_child, h, code);
		code[h] = '\0';//문자열의 끝에 널문자를 삽입한다.
		if (Tree->left_child == NULL || Tree->right_child == NULL)
			printf("%d\t | %s\n", Tree->weight, code);
	}
}

// 허프만 코드 생성 함수
void huffman_tree(int freq[], int n)
{
	int i;
	TreeNode *node, *x;
	HeapType heap;
	element e, e1, e2;

	init(&heap);
	for (i = 0; i < n; i++) {
		node = make_tree(NULL, NULL);
		e.key = node->weight = freq[i];
		e.ptree = node;
		insert_min_heap(&heap, e);
	}

	for (i = 1; i < n; i++) {
		e1 = delete_min_heap(&heap);		// 최소값을 가지는 두개의 노드를 삭제
		e2 = delete_min_heap(&heap);
		x = make_tree(e1.ptree, e2.ptree); // 두개의 노드를 합친다.
		e.key = x->weight = e1.key + e2.key;
		e.ptree = x;
		insert_min_heap(&heap, e);
	}
	e = delete_min_heap(&heap); // 최종 트리
	/*
	printf("1 : %d\n", e.key);
	printf("2 : %d %d \n", e.ptree->left_child->weight, e.ptree->right_child->weight);
	printf("3 : %d %d %d %d\n", e.ptree->left_child->left_child->weight, e.ptree->left_child->right_child->weight, e.ptree->right_child->left_child->weight, e.ptree->right_child->right_child->weight);
	printf("4 : %d %d", e.ptree->left_child->right_child->left_child->weight, e.ptree->left_child->right_child->right_child->weight);
	*/
	printf("완성된 허프만코드 트리 중위순회\n");
	display(e.ptree);
	printf("\n\n");

	printf("허프만 코드값 출력\n");
	char buf[100];
	display_huff(e.ptree, -1, buf);

	destroy_tree(e.ptree);
}

// 주함수 
void main()
{
	int freq[] = { 15, 12, 8, 6, 4 };
	huffman_tree(freq, 5);
}
