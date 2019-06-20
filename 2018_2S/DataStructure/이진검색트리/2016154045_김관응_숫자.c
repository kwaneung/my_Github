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

	init_node(&tree);//초기화

	for(int i=0; i<MAX_SIZE;i++)
		insert_node(&tree, buf[i]);

	printf("정렬합니다\n");
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


// 이진 탐색 트리 출력 함수
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
	TreeNode *p, *t; // p는 부모노드, t는 현재노드 
	TreeNode *n;	    // n은 새로운 노드

	t = *root;
	p = NULL;

	if (t->key == NULL)
	{
		t->left = NULL;
		t->right = NULL;
		t->key = key;
	}
	// 탐색을 먼저 수행 
	while (t != NULL) {
		if (key == t->key) return;
		p = t;
		if (key < t->key) t = t->left;
		else t = t->right;
	}
	// key가 트리 안에 없으므로 삽입 가능
	n = (TreeNode *)malloc(sizeof(TreeNode));
	if (n == NULL) return;
	// 데이터 복사
	n->key = key;
	n->left = n->right = NULL;
	// 부모 노드와 링크 연결
	if (p != NULL)
		if (key < p->key)
			p->left = n;
		else p->right = n;
	else *root = n;
}




// 삭제 함수
void delete_node(TreeNode **root, int key)
{
	TreeNode *p, *child, *succ, *succ_p, *t;

	// key를 갖는 노드 t를 탐색, p는 t의 부모노드
	p = NULL;
	t = *root;
	// key를 갖는 노드 t를 탐색한다.
	while (t != NULL && t->key != key) {
		p = t;
		t = (key < t->key) ? t->left : t->right;
	}
	// 탐색이 종료된 시점에 t가 NULL이면 트리안에 key가 없음
	if (t == NULL) { 	// 탐색트리에 없는 키
		printf("key is not in the tree");
		return;
	}
	// 첫번째 경우: 단말노드인 경우
	if ((t->left == NULL) && (t->right == NULL)) {
		if (p != NULL) {
			// 부모노드의 자식필드를 NULL로 만든다.
			if (p->left == t)
				p->left = NULL;
			else   p->right = NULL;
		}
		else	// 만약 부모노드가 NULL이면 삭제되는 노드가 루트
			*root = NULL;
	}
	// 두번째 경우: 하나의 자식만 가지는 경우
	else if ((t->left == NULL) || (t->right == NULL)) {
		child = (t->left != NULL) ? t->left : t->right;
		if (p != NULL) {
			if (p->left == t)	// 부모를 자식과 연결 
				p->left = child;
			else p->right = child;
		}
		else   // 만약 부모노드가 NULL이면 삭제되는 노드가 루트
			*root = child;
	}
	// 세번째 경우: 두개의 자식을 가지는 경우
	else {
		// 오른쪽 서브트리에서 후계자를 찾는다.
		succ_p = t;
		succ = t->left;
		// 후계자를 찾아서 계속 왼쪽으로 이동한다.
		while (succ->right != NULL) {
			succ_p = succ;
			succ = succ->right;
		}
		// 후속자의 부모와 자식을 연결 
		if (succ_p->right == succ)
			succ_p->right = succ->left;
		else
			succ_p->left = succ->left;
		// 후속자가 가진 키값을 현재 노드에 복사
		t->key = succ->key;
		// 원래의 후속자 삭제
		t = succ;
	}
	free(t);
}
