#pragma once

typedef struct CustNode {
	int num;//�ڼ�λ�������е�
	int task;//��ִ������ȡ��/���/���/����---------1/2/3/4��
	int arrtime;//����ʱ��
	int durtime;//������ʱ��
	int amount;//��������
	struct CustNode* next;
}CustNode;

typedef struct queue {
	CustNode* front;
	CustNode* rear;
	int len;
}queue;

queue* line2 = NULL;

int BankServiceTime;//-------���з�����ʱ��
int NowTime = 0;//---------------��ǰʱ��
int MaxInterval;//-----------����׼��ʱ��
int MinInterval;//-----------��С���׼��ʱ��
int MaxTradingTime;//--------����״���ʱ��
int MinTradingTime;//--------��С���״���ʱ��
int BankAccount;//-----------��ǰ���д����
int MaxTradingLimits;//------������޶�
int MinTradingLimits;//------��С�����޶�

int Task_1_num = 0;
int Task_2_num = 0;
int Task_3_num = 0;
int Task_4_num = 0;
int Task_1_success_num = 0;
int Task_2_success_num = 0;
int Task_3_success_num = 0;
int Task_4_success_num = 0;
float AverClientStayTime = 0.0;

int InitQueue();//-----------��ʼ������
int Push(int num, int task, int arrtime, int durtime, int amount);//----------------���
int Pop(CustNode* p);//-----------------����
int CompareFront();//--------�Ͷ�ͷԪ�رȽ�
