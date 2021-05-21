#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "head.h"
#include "queue.h"

void come(int num, int task, int arrtime, int amount) {//������
	switch (task) {
	case(1):
		printf("   %-12d����       ȡ��       %-12d%-16d%d\n", num, arrtime, amount, BankAccount);
		break;
	case(2):
		printf("   %-12d����       ���       %-12d%-16d%d\n", num, arrtime, amount, BankAccount);
		break;
	case(3):
		printf("   %-12d����       ���       %-12d%-16d%d\n", num, arrtime, amount, BankAccount);
		break;
	case(4):
		printf("   %-12d����       ����       %-12d%-16d%d\n", num, arrtime, amount, BankAccount);
		break;
	case(10):
		printf("   %-12d����       ȡ��       %-12d%-16d%-7d�������2\n", num, arrtime, amount, BankAccount);
		break;
	case(20):
		printf("   %-12d����       ���       %-12d%-16d%-7d�������2\n", num, arrtime, amount, BankAccount);
		break;
	}
}

void leave(int num, int task, int arrtime, int durtime, int amount) {//������
	switch (task) {
	case(1):
		printf("   %-12d�뿪       ȡ��       %-12d%-16d%d\n", num, arrtime + durtime, amount, BankAccount);
		break;
	case(2):
		printf("   %-12d�뿪       ���       %-12d%-16d%d\n", num, arrtime + durtime, amount, BankAccount);
		break;
	case(3):
		printf("   %-12d�뿪       ���       %-12d%-16d%d\n", num, arrtime + durtime, amount, BankAccount);
		break;
	case(4):
		printf("   %-12d�뿪       ����       %-12d%-16d%d\n", num, arrtime + durtime, amount, BankAccount);
		break;
	case(10):
		printf("   %-12d�뿪       ȡ��       %-12d%-16d%-7d�뿪����2\n", num, arrtime + durtime, amount, BankAccount);
		break;
	case(20):
		printf("   %-12d�뿪       ���       %-12d%-16d%-7d�뿪����2\n", num, arrtime + durtime, amount, BankAccount);
		break;
	}
}

int ClientBehavior_Line_1(int num) {
	int status;
	CustNode* cus = (CustNode*)malloc(sizeof(CustNode));
	status = SetRandom(&cus->task, &cus->arrtime, &cus->durtime, &cus->amount);
	if (status == -1) return -1;//����-1ָ��ʱ-------->����ʱ�� + ����ʱ�� > ��Ӫҵʱ��
	if (cus->task == 1 || cus->task == 2) cus->amount *= -1;
	if (cus->task == 1) Task_1_num++;
	else if (cus->task == 2) Task_2_num++;
	else if (cus->task == 3) Task_3_num++;
	else if (cus->task == 4) Task_4_num++;
	if (cus->amount < 0 && -1 * cus->amount > BankAccount) {
		Push(num, cus->task, cus->arrtime, cus->durtime, cus->amount);
		come(num, 10 * cus->task, cus->arrtime, cus->amount);
		return 0;//����0��ʾ�ÿͻ��������2
	}
	else if(cus->amount > 0 || (cus->amount < 0 && -1 * cus->amount < BankAccount)){
		come(num, cus->task, cus->arrtime, cus->amount);
		NowTime = cus->arrtime + cus->durtime;
		BankAccount += cus->amount;
		leave(num, cus->task, cus->arrtime, cus->durtime, cus->amount);
		AverClientStayTime += cus->durtime;
		if (cus->task == 1) Task_1_success_num++;
		else if (cus->task == 2) Task_2_success_num++;
		else if (cus->task == 3) Task_3_success_num++;
		else if (cus->task == 4) Task_4_success_num++;
		if (cus->amount > 0) return 1;//�����������
		else return 2;//����������
	}
	free(cus);
	cus = NULL;
}

int ClientBehavior_Line_2() {
	if (CompareFront()) {
		CustNode* p = (CustNode*)malloc(sizeof(CustNode));
		Pop(p);
		BankAccount += p->amount;
		leave(p->num, 10 * p->task, NowTime, p->durtime, p->amount);
		if (p->task == 1) Task_1_success_num++;
		else if (p->task == 2) Task_2_success_num++;
		else if (p->task == 3) Task_3_success_num++;
		else if (p->task == 4) Task_4_success_num++;
		NowTime += p->durtime;
		AverClientStayTime += (NowTime - p->arrtime);
		free(p);
		p = NULL;
	}
	if (line2->front && CompareFront()) return 1;
	else return 0;
}

int SetRandom(int* task, int* arrtime, int* durtime, int* amount) {//����-1ָ��ʱ
	*task = rand() % 4 + 1;
	*arrtime = rand() % (MaxInterval - MinInterval + 1) + MinInterval + NowTime;
	if (*arrtime > BankServiceTime) return -1;
	*durtime = rand() % (MaxTradingTime - MinTradingTime + 1) + MinTradingTime;
	if (*arrtime + *durtime > BankServiceTime) return -1;
	*amount = rand() % (MaxTradingLimits - MinTradingLimits + 1) + MinTradingLimits;
}

void shutdown() {
	CustNode* still_in_line2 = (CustNode*)malloc(sizeof(CustNode));
	while (line2->len) {
		Pop(still_in_line2);
		leave(still_in_line2->num, still_in_line2->task, still_in_line2->arrtime, still_in_line2->durtime, still_in_line2->amount);
	}
}
