#pragma once

typedef struct CustNode {
	int num;//第几位来到银行的
	int task;//所执行任务（取款/借款/存款/还款---------1/2/3/4）
	int arrtime;//到达时间
	int durtime;//任务处理时间
	int amount;//任务处理金额
	struct CustNode* next;
}CustNode;

typedef struct queue {
	CustNode* front;
	CustNode* rear;
	int len;
}queue;

queue* line2 = NULL;

int BankServiceTime;//-------银行服务总时间
int NowTime = 0;//---------------当前时间
int MaxInterval;//-----------最大交易间隔时间
int MinInterval;//-----------最小交易间隔时间
int MaxTradingTime;//--------最大交易处理时间
int MinTradingTime;//--------最小交易处理时间
int BankAccount;//-----------当前银行存款金额
int MaxTradingLimits;//------最大交易限额
int MinTradingLimits;//------最小交易限额

int Task_1_num = 0;
int Task_2_num = 0;
int Task_3_num = 0;
int Task_4_num = 0;
int Task_1_success_num = 0;
int Task_2_success_num = 0;
int Task_3_success_num = 0;
int Task_4_success_num = 0;
float AverClientStayTime = 0.0;

int InitQueue();//-----------初始化队列
int Push(int num, int task, int arrtime, int durtime, int amount);//----------------入队
int Pop(CustNode* p);//-----------------出队
int CompareFront();//--------和队头元素比较
