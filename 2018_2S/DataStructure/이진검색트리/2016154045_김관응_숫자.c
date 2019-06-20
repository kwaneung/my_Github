#include <stdio.h>
#define MAX_SIZE 11

typedef struct TreeNode {
	int key;
	struct TreeNode *left, *right;
} TreeNode;


void insert_node(TreeNode **root, int key);
void delete_node(TreeNode **root, int key);
void init_node(TreeNode **root);
void display(TreeNode **root);

int main()
{
	TreeNode t, *tree = NULL;
	int buf[MAX_SIZE] = { 35, 68, 18, 7, 26, 99, 3, 12, 22, 25, 30 };

	tree = malloc(sizeof(TreeNode));
	tree = &t;

	init_node(&tree);//�ʱ�ȭ

	for(int i=0; i<MAX_SIZE;i++)
		insert_node(&tree, buf[i]);

	printf("�����մϴ�\n");
	display(tree);

	return 0;
}

void init_node(TreeNode **root)
{
	TreeNode *t;

	t = *root;

	t->left = NULL;
	t->right = NULL;
	t->key = NULL;
}


// ���� Ž�� Ʈ�� ��� �Լ�
void display(TreeNode *p)
{
	
	if (p == NULL)
		return;

	display(p->left);
	printf("%d ", p->key);
	display(p->right);
}


void insert_node(TreeNode **root, int key)
{
	TreeNode *p, *t; // p�� �θ���, t�� ������ 
	TreeNode *n;	    // n�� ���ο� ���

	t = *root;
	p = NULL;

	if (t->key == NULL)
	{
		t->left = NULL;
		t->right = NULL;
		t->key = key;
	}
	// Ž���� ���� ���� 
	while (t != NULL) {
		if (key == t->key) return;
		p = t;
		if (key < t->key) t = t->left;
		else t = t->right;
	}
	// key�� Ʈ�� �ȿ� �����Ƿ� ���� ����
	n = (TreeNode *)malloc(sizeof(TreeNode));
	if (n == NULL) return;
	// ������ ����
	n->key = key;
	n->left = n->right = NULL;
	// �θ� ���� ��ũ ����
	if (p != NULL)
		if (key < p->key)
			p->left = n;
		else p->right = n;
	else *root = n;
}




// ���� �Լ�
void delete_node(TreeNode **root, int key)
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
