#include <stdio.h>
#define MAX_SIZE 7

typedef struct TreeNode {
	char key[512];
	struct TreeNode *left, *right;
} TreeNode;


void insert_node(TreeNode **root, char key);
void delete_node(TreeNode **root, char key);
void init_node(TreeNode **root);
void display(TreeNode *p);

int main()
{
	char *buf[MAX_SIZE];

	for (int a = 0; a < MAX_SIZE; a++)
		buf[a] = malloc(512);

	strcpy(buf[0], "hello");
	strcpy(buf[1], "wow");
	strcpy(buf[2], "kim");
	strcpy(buf[3], "hello");
	strcpy(buf[4], "lee");
	strcpy(buf[5], "apple");
	strcpy(buf[6], "chicken");

	int i = 0;
	TreeNode t, *tree = NULL;

	tree = malloc(sizeof(TreeNode));
	tree = &t;

	init_node(&tree);//�ʱ�ȭ

	tree->left = NULL;
	tree->right = NULL;
	strcpy(tree->key, buf[0]);

	for (i = 0; i < MAX_SIZE; i++)
		insert_node(&tree, &buf[i]);

	printf("�����մϴ�\n");
	display(tree);

	return 0;
}

// ���� Ž�� Ʈ�� ��� �Լ�
void display(TreeNode *p)
{

	if (p == NULL)
		return;

	display(p->left);
	printf("%s ", p->key);
	display(p->right);
}

void insert_node(TreeNode **root, char **key)
{
	TreeNode *p, *t; // p�� �θ���, t�� ������ 
	TreeNode *n;	    // n�� ���ο� ���

	t = *root;
	p = NULL;
	
	// Ž���� ���� ���� 
	while (t != NULL) {
		if (strcmp(*key, t->key) == 0) return;
		p = t;
		if (strcmp(*key, t->key) < 0) t = t->left;
		else t = t->right;
	}
	// key�� Ʈ�� �ȿ� �����Ƿ� ���� ����
	n = (TreeNode *)malloc(sizeof(TreeNode));
	if (n == NULL) return;
	// ������ ����
	//printf("%s\n", *key);
	//printf("%s\n", t->key);
	strcpy(n->key, *key);

	n->left = n->right = NULL;
	// �θ� ���� ��ũ ����
	if (p != NULL)
		if (strcmp(*key, p->key) < 0)
			p->left = n;
		else p->right = n;
	else *root = n;
}

void init_node(TreeNode **root)
{
	TreeNode *t;

	t = *root;

	t->left = NULL;
	t->right = NULL;
	*(t->key) = NULL;
}

/*
// ���� �Լ�
void delete_node(TreeNode **root, char key)
{
	TreeNode *p, *child, *succ, *succ_p, *t;

	// key�� ���� ��� t�� Ž��, p�� t�� �θ���
	p = NULL;
	t = *root;
	// key�� ���� ��� t�� Ž���Ѵ�.
	while (t != NULL && t->key != key) {
		p = t;
		t = (key < t->key) ? t->left : t->right;
	}
	// Ž���� ����� ������ t�� NULL�̸� Ʈ���ȿ� key�� ����
	if (t == NULL) { 	// Ž��Ʈ���� ���� Ű
		printf("key is not in the tree");
		return;
	}
	// ù��° ���: �ܸ������ ���
	if ((t->left == NULL) && (t->right == NULL)) {
		if (p != NULL) {
			// �θ����� �ڽ��ʵ带 NULL�� �����.
			if (p->left == t)
				p->left = NULL;
			else   p->right = NULL;
		}
		else	// ���� �θ��尡 NULL�̸� �����Ǵ� ��尡 ��Ʈ
			*root = NULL;
	}
	// �ι�° ���: �ϳ��� �ڽĸ� ������ ���
	else if ((t->left == NULL) || (t->right == NULL)) {
		child = (t->left != NULL) ? t->left : t->right;
		if (p != NULL) {
			if (p->left == t)	// �θ� �ڽİ� ���� 
				p->left = child;
			else p->right = child;
		}
		else   // ���� �θ��尡 NULL�̸� �����Ǵ� ��尡 ��Ʈ
			*root = child;
	}
	// ����° ���: �ΰ��� �ڽ��� ������ ���
	else {
		// ������ ����Ʈ������ �İ��ڸ� ã�´�.
		succ_p = t;
		succ = t->left;
		// �İ��ڸ� ã�Ƽ� ��� �������� �̵��Ѵ�.
		while (succ->right != NULL) {
			succ_p = succ;
			succ = succ->right;
		}
		// �ļ����� �θ�� �ڽ��� ���� 
		if (succ_p->right == succ)
			succ_p->right = succ->left;
		else
			succ_p->left = succ->left;
		// �ļ��ڰ� ���� Ű���� ���� ��忡 ����
		t->key = succ->key;
		// ������ �ļ��� ����
		t = succ;
	}
	free(t);
}
*/