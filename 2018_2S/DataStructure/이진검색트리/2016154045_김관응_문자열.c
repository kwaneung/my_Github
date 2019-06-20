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

	init_node(&tree);//초기화

	tree->left = NULL;
	tree->right = NULL;
	strcpy(tree->key, buf[0]);

	for (i = 0; i < MAX_SIZE; i++)
		insert_node(&tree, &buf[i]);

	printf("정렬합니다\n");
	display(tree);

	return 0;
}

// 이진 탐색 트리 출력 함수
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
	TreeNode *p, *t; // p는 부모노드, t는 현재노드 
	TreeNode *n;	    // n은 새로운 노드

	t = *root;
	p = NULL;
	
	// 탐색을 먼저 수행 
	while (t != NULL) {
		if (strcmp(*key, t->key) == 0) return;
		p = t;
		if (strcmp(*key, t->key) < 0) t = t->left;
		else t = t->right;
	}
	// key가 트리 안에 없으므로 삽입 가능
	n = (TreeNode *)malloc(sizeof(TreeNode));
	if (n == NULL) return;
	// 데이터 복사
	//printf("%s\n", *key);
	//printf("%s\n", t->key);
	strcpy(n->key, *key);

	n->left = n->right = NULL;
	// 부모 노드와 링크 연결
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
// 삭제 함수
void delete_node(TreeNode **root, char key)
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
*/