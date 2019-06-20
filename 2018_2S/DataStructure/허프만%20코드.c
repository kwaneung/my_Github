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

// �ʱ�ȭ �Լ�
init(HeapType *h)
{
	h->heap_size = 0;
}
// ���� �Լ�
void insert_min_heap(HeapType *h, element item)
{
	int i;
	i = ++(h->heap_size);

	//  Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;     // ���ο� ��带 ����
}
// ���� �Լ�
element delete_min_heap(HeapType *h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		// ���� ����� �ڽĳ���� �� ���� �ڽĳ�带 ã�´�.
		if ((child < h->heap_size) &&
			(h->heap[child].key) > h->heap[child + 1].key)
			child++;
		if (temp.key <= h->heap[child].key) break;
		// �Ѵܰ� �Ʒ��� �̵�
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

// ���� Ʈ�� ���� �Լ�
TreeNode *make_tree(TreeNode *left, TreeNode *right)
{
	TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
	if (node == NULL) {
		fprintf(stderr, "�޸� ����\n");
		exit(1);
	}
	node->left_child = left;
	node->right_child = right;
	return node;
}
// ���� Ʈ�� ���� �Լ�
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
		h++;//h�� Ʈ���� ���̸� ��Ÿ����
		code[h] = '1';//�������� ���� 1�ִ´�
		display_huff(Tree->left_child, h, code);
		code[h] = '0';//���������� ���� 0�ִ´�.
		display_huff(Tree->right_child, h, code);
		code[h] = '\0';//���ڿ��� ���� �ι��ڸ� �����Ѵ�.
		if (Tree->left_child == NULL || Tree->right_child == NULL)
			printf("%d\t | %s\n", Tree->weight, code);
	}
}

// ������ �ڵ� ���� �Լ�
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
		e1 = delete_min_heap(&heap);		// �ּҰ��� ������ �ΰ��� ��带 ����
		e2 = delete_min_heap(&heap);
		x = make_tree(e1.ptree, e2.ptree); // �ΰ��� ��带 ��ģ��.
		e.key = x->weight = e1.key + e2.key;
		e.ptree = x;
		insert_min_heap(&heap, e);
	}
	e = delete_min_heap(&heap); // ���� Ʈ��
	/*
	printf("1 : %d\n", e.key);
	printf("2 : %d %d \n", e.ptree->left_child->weight, e.ptree->right_child->weight);
	printf("3 : %d %d %d %d\n", e.ptree->left_child->left_child->weight, e.ptree->left_child->right_child->weight, e.ptree->right_child->left_child->weight, e.ptree->right_child->right_child->weight);
	printf("4 : %d %d", e.ptree->left_child->right_child->left_child->weight, e.ptree->left_child->right_child->right_child->weight);
	*/
	printf("�ϼ��� �������ڵ� Ʈ�� ������ȸ\n");
	display(e.ptree);
	printf("\n\n");

	printf("������ �ڵ尪 ���\n");
	char buf[100];
	display_huff(e.ptree, -1, buf);

	destroy_tree(e.ptree);
}

// ���Լ� 
void main()
{
	int freq[] = { 15, 12, 8, 6, 4 };
	huffman_tree(freq, 5);
}
