#pragma once
#include "head.h"
#include "InputController.h"
#include <stdio.h>
#include <stdlib.h>

//1.初始化二叉排序树
Status InitBST(BSTree* T) {
	if (!*T) {
		printf("请输入elem：");
		ElemType elem = is_unlimitted_digit();
		//scanf("%d", &elem);
		BSTNode* p;
		p = (BSTree)malloc(sizeof(BSTNode));
		p->data = elem;
		p->lchild = p->rchild = NULL;
		*T = p;
		return SUCCESS;
	}
	return Already_exists;
}

//2.插入结点
Status InsertBST(BSTNode* T, ElemType elem) {
	if (elem == T->data) return Already_exists;
	if (elem < T->data) {
		if (T->lchild) InsertBST(T->lchild, elem);
		else {
			T->lchild = (BSTree)malloc(sizeof(BSTNode));
			T->lchild->data = elem;
			T->lchild->lchild = NULL;
			T->lchild->rchild = NULL;
			return SUCCESS;
		}
	}
	else if (elem > T->data) {
		if (T->rchild) InsertBST(T->rchild, elem);
		else {
			T->rchild = (BSTree)malloc(sizeof(BSTNode));
			T->rchild->data = elem;
			T->rchild->lchild = NULL;
			T->rchild->rchild = NULL;
			return SUCCESS;
		}
	}
}

//3.三种顺序遍历输出二叉树
void PreOrderTraverse(BSTree T) {
	if (!T) {
		printf("# ");
		return;
	}
	//if (T->data == '#') printf("# ");
	printf("%d ", T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

void InOrderTraverse(BSTree T) {
	if (!T) {
		printf("# ");
		return;
	}
	InOrderTraverse(T->lchild);
	//if (T->data == '#') printf("# ");
	printf("%d ", T->data);
	InOrderTraverse(T->rchild);
}

void PostOrderTraverse(BSTree T) {
	if (!T) {
		printf("# ");
		return;
	}
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	//if (T->data == '#') printf("# ");
	printf("%d ", T->data);
}

//4.寻找结点
BSTree SearchBST(BSTree T, ElemType elem) {
	if (!T) return NULL;
	if (elem == T->data) return T;
	else if (elem < T->data) return SearchBST(T->lchild, elem);
	else return SearchBST(T->rchild, elem);
}

//5.检测二叉排序树深度
int BSTDepth(BSTree T) {
	int left, right;
	if (!T) return -1;
	else {
		left = BSTDepth(T->lchild);
		right = BSTDepth(T->rchild);
		return 1 + (left > right ? left : right);
	}
}

void DeleNode(BSTNode* p) {
	BSTNode* q, * s;
	q = p;
	if (!(p->rchild)) {
		p = p->lchild; free(p);
	}
	else if (!(p->lchild)) {
		p = p->lchild; free(p);
	}
	else {
		s = p->lchild;
		while (s->rchild) {
			q = s; s = s->rchild;
		}
		p->data = s->data;
		if (q == p) q->lchild = s->lchild;
		else q->rchild = s->rchild;
		free(s);	
	}
}

//6.删除结点
Status DeleteBST(BSTNode* T, ElemType elem) {
	if (!T) return ERROR;
	if (elem == T->data) {
		DeleNode(T);
		return SUCCESS;
	}
	else if (elem < T->data) return DeleteBST(T->lchild, elem);
	return DeleteBST(T->rchild, elem);
}

//7.销毁二叉排序树并退出
Status DestroyBST(BSTNode* T) {
	if (T->lchild) DestroyBST(T->lchild);
	if (T->rchild) DestroyBST(T->rchild);
	free(T);
	T = NULL;
	return SUCCESS;
}

void map() {
	printf("*******************************************\n");
	printf("*          二叉查找树操作菜单             *\n");
	printf("*******************************************\n");
	printf("*  1.以elem为头结点构建二叉查找树         *\n");
	printf("*  2.插入结点                             *\n");
	printf("*  3.三种顺序遍历输出二叉树               *\n");
	printf("*  4.寻找结点                             *\n");
	printf("*  5.检测二叉排序树深度                   *\n");
	printf("*  6.删除结点                             *\n");
	printf("*  7.销毁二叉排序树                       *\n");
	printf("*  8.退出                                 *\n");
	printf("*******************************************\n");
	printf("请输入选项：");
}