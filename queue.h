#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int InitQueue() {
	line2 = (queue*)malloc(sizeof(queue));
	line2->front = line2->rear = NULL;
	line2->len = 0;
	return 0;
}

int Push(int num, int task, int arrtime, int durtime, int amount) {
	CustNode* p = (CustNode*)malloc(sizeof(CustNode));
	p->num = num;
	p->task = task;
	p->arrtime = arrtime;
	p->durtime = durtime;
	p->amount = amount;
	p->next = NULL;
	if (line2->len == 0) line2->front = line2->rear = p;
	else {
		line2->rear->next = p;
		line2->rear = line2->rear->next;
	}
	line2->len++;
	return 0;
}

int Pop(CustNode* p) {
	p->num = line2->front->num;
	p->task = line2->front->task;
	p->arrtime = line2->front->arrtime;
	p->durtime = line2->front->durtime;
	p->amount = line2->front->amount;
	p->next = NULL;
	line2->front = line2->front->next;
	line2->len--;
	return 0;
}

int CompareFront() {
	if (BankAccount >= -1 * line2->front->amount && NowTime + line2->front->durtime < BankServiceTime)
		return 1;
	return 0;
}

