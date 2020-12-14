#include <stdio.h>
#include <stdlib.h>
#include "Linked.h"


int main() {
	int num, dep;
	ElemType elem;
	Status status;
	BSTree T = NULL;
	BSTree p = NULL;
	C:map();
	//scanf("%d", &num);
	num = max_limitted_digit(8);
	switch (num) {
	case(1):
		status = InitBST(&T);
		if (status == SUCCESS) printf("成功创建排序二叉树\n");
		else if (status == Already_exists) printf("二叉树已存在\n");
		system("pause");
		system("cls");
		goto C;
	case(2):
		if (!T) {
			printf("树为空\n");
			system("pause");
			system("cls");
			goto C;
		}
		printf("请输入插入结点数据：");
		//scanf("%d", &elem);
		elem = is_unlimitted_digit();
		status = InsertBST(T, elem);
		if (status == SUCCESS) printf("成功插入数据\n");
		else if (status == Already_exists) printf("数据已经存在\n");
		system("pause");
		system("cls");
		goto C;
	case(3):
		printf("先序遍历：");    PreOrderTraverse(T);	printf("\n");
		printf("中序遍历：");    InOrderTraverse(T);    printf("\n");
		printf("后序遍历：");	PostOrderTraverse(T);	printf("\n");
		printf("(以 ‘#’ 表示空)\n");
		system("pause");
		system("cls");
		goto C;
	case(4):
		if (!T) {
			printf("树为空\n");
			system("pause");
			system("cls");
			goto C;
		}
		printf("请输入查找结点数据：");
		//scanf("%d", &elem);
		elem = is_unlimitted_digit();
		p = SearchBST(T, elem);
		if (p) printf("数据 %d 所在内存为 %d\n",elem, p);
		else if (!p) printf("数据 %d 不存在\n",elem);
		system("pause");
		system("cls");
		goto C;
	case(5):
		if (!T) {
			printf("树为空\n");
			system("pause");
			system("cls");
			goto C;
		}
		dep = BSTDepth(T);
		printf("该树的深度为 %d\n", dep);
		system("pause");
		system("cls");
		goto C;
	case(6):
		if (!T) {
			printf("树为空\n");
			system("pause");
			system("cls");
			goto C;
		}
		printf("请输入删除结点数据：");
		//scanf("%d", &elem);
		elem = is_unlimitted_digit();
		status = DeleteBST(T, elem);
		if (status == SUCCESS) printf("成功删除数据\n");
		else if (status == ERROR) printf("数据不存在\n");
		system("pause");
		system("cls");
		goto C;
	case(7):
		if (!T) {
			printf("树为空\n");
			system("pause");
			system("cls");
			goto C;
		}
		DestroyBST(T);
		T = NULL;
		printf("成功摧毁该树\n");
		system("pause");
		system("cls");
		goto C;
	case(8):
		if (!T) goto G;
		DestroyBST(T);
		G:T = NULL;
		printf("成功摧毁该树,即将退出......\n");
		return 0;
	}
}
