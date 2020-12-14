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


Status InitBST(BSTree* T);//初始化二叉排序树
Status DestroyBST(BSTNode* T);//销毁二叉排序树
int BSTDepth(BSTree T);//检测二叉排序树深度
void PreOrderTraverse(BSTree T);//先序遍历二叉树
void InOrderTraverse(BSTree T);//中序遍历二叉树
void PostOrderTraverse(BSTree T);//后序遍历二叉树
BSTree SearchBST(BSTree T, ElemType elem);//若二叉树中存在值为elem的结点，则返回该点指针，否则返回NULL
Status InsertBST(BSTNode* T, ElemType elem);//若二叉树中不存在值为elem的结点，则插入至T
Status DeleteBST(BSTNode* T, ElemType elem);//若二叉树中存在值为elem的结点，则将其删除


//限定输入数据时只能输入带符号数字
int is_unlimitted_digit();

//限定输入数据时只能输入不带符号正整数
int is_limitted_digit();
int is_limitted_digit(int max_num);