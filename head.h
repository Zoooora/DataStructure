#pragma once

typedef enum Status {
	ERROR = 0,
	SUCCESS = 1,
	Already_exists = 2
} Status;

typedef int ElemType;

typedef struct BSTNode {
	ElemType data;
	struct BSTNode* lchild, * rchild;
}BSTNode, * BSTree;


Status InitBST(BSTree* T);//��ʼ������������
Status DestroyBST(BSTNode* T);//���ٶ���������
int BSTDepth(BSTree T);//���������������
void PreOrderTraverse(BSTree T);//�������������
void InOrderTraverse(BSTree T);//�������������
void PostOrderTraverse(BSTree T);//�������������
BSTree SearchBST(BSTree T, ElemType elem);//���������д���ֵΪelem�Ľ�㣬�򷵻ظõ�ָ�룬���򷵻�NULL
Status InsertBST(BSTNode* T, ElemType elem);//���������в�����ֵΪelem�Ľ�㣬�������T
Status DeleteBST(BSTNode* T, ElemType elem);//���������д���ֵΪelem�Ľ�㣬����ɾ��


//�޶���������ʱֻ���������������
int is_unlimitted_digit();

//�޶���������ʱֻ�����벻������������
int is_limitted_digit();
int is_limitted_digit(int max_num);