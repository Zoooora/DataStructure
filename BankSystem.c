#include <stdio.h>
#include <stdlib.h>
#include "InputController.h"
#include "service.h"
#include "head.h"

int main() {
	printf("请输入银行服务时间（0 ~ 1440 min）：");
	BankServiceTime = max_limitted_digit(1440);
	if (BankServiceTime == 0) {
		printf("营业时间已结束\n");
		system("pause");
		return 0;
	}
	printf("请输入最大到达时间间隔：");
	MaxInterval = max_limitted_digit(BankServiceTime);
	printf("请输入最小到达时间间隔：");
	MinInterval = max_limitted_digit(MaxInterval);
	A:printf("请输入客户最大交易时间：");
	MaxTradingTime = max_limitted_digit(BankServiceTime);
	if (MaxTradingTime == 0) {
		printf("最大交易时间不允许为0\n");
		goto A;
	}
	printf("请输入客户最小交易时间：");
	MinTradingTime = max_limitted_digit(MaxTradingTime);
	printf("请输入银行开始拥有金额（>0）：");
	BankAccount = is_limitted_digit();
	B:printf("请输入最大交易限额：");
	MaxTradingLimits = max_limitted_digit(BankAccount);
	if (MaxTradingLimits == 0) {
		printf("最大交易限额不允许为0\n");
		goto B;
	}
	printf("请输入最小交易限额：");
	MinTradingLimits = max_limitted_digit(MaxTradingLimits);
	InitQueue();
	int num = 0;
	int status;
	printf("\n客户序列       类型       任务       时间       处理金额       银行余额\n\n");
	while (NowTime <= BankServiceTime) {
		num++;
		status = ClientBehavior_Line_1(num);
		C:switch (status) {
		case(-1):
			printf("营业时间已结束\n");

			shutdown();

			printf("\n请求取款业务总人数：%d\n", Task_1_num);
			printf("请求借款业务总人数：%d\n", Task_2_num);
			printf("请求存款业务总人数：%d\n", Task_3_num);
			printf("请求还款业务总人数：%d\n\n", Task_4_num);

			printf("取款成功总人数：%d\n", Task_1_success_num);
			printf("借款成功总人数：%d\n", Task_2_success_num);
			printf("存款成功总人数：%d\n", Task_3_success_num);
			printf("还款成功总人数：%d\n\n", Task_4_success_num);

			printf("取款成功比例：%f\n", Task_1_success_num * 1.0 / Task_1_num);
			printf("借款成功比例：%f\n", Task_2_success_num * 1.0 / Task_2_num);
			printf("存款成功比例：%f\n", Task_3_success_num * 1.0 / Task_3_num);
			printf("还款成功比例：%f\n\n", Task_4_success_num * 1.0 / Task_4_num);

			printf("客户平均逗留时间：%f\n", AverClientStayTime / num);

			printf("\ncopyright@区肇洲 19软一   学号3119005025\n");
			system("pause");
			return 0;
		case(1):
			if (line2->front) {
				status = ClientBehavior_Line_2();
				goto C;
			}
			break;
		}
	}
}
