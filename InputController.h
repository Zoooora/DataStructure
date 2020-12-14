#pragma once

#include <stdio.h>
#include <string.h>
#include <math.h>


//限定输入数据时只能输入带符号数字
int is_unlimitted_digit() {
	char input[10000];
	int len, n, output = 0;
	while (1) {
	C:n = 0;
		scanf("%s", input);
		len = strlen(input);
		if (input[0] != '-') {
			for (; n < len; n++) {
				if (input[n] < 48 || input[n] > 57) {
					printf("请输入数字：");
					goto C;
				}
			}
			for (n = 0, len -= 1; n <= len; n++) {
				output += ((input[n] - 48) * pow(10, len - n));
			}
			return output;
		}
		else if (input[0] == '-') {
			n = 1;
			for (; n < len; n++) {
				if (input[n] < 48 || input[n] > 57) {
					printf("请输入数字：");
					goto C;
				}
			}
			for (n = 1, len -= 1; n <= len; n++) {
				output += (input[n] - 48) * pow(10, len - n);
			}
			return -1 * output;
		}
	}
}

//限定输入数据时只能输入不带符号正整数
int is_limitted_digit() {
	char input[100];
	int len, n, output = 0;
	while (1) {
	C:n = 0;
		scanf("%s", input);
		len = strlen(input);
		for (; n < len; n++) {
			if (input[n] == '-') {
				printf("请输入正整数：");
				goto C;
			}
			if (input[n] < 48 || input[n] > 57) {
				printf("请输入正整数：");
				goto C;
			}
		}
		for (n = 0, len -= 1; n <= len; n++) {
			output += ((input[n] - 48) * pow(10, len - n));
		}
		return output;
	}
}

int max_limitted_digit(int max_num) {
	char input[100];
	int len, n, output;
	while (1) {
	C:n = 0;
		for (int i = 0; i < 100; i++) input[i] = '\0';
		output = 0;
		scanf("%s", input);
		len = strlen(input);
		for (; n < len; n++) {
			if (input[n] == '-') {
				printf("请输入正整数：");
				goto C;
			}
			if (input[n] < 48 || input[n] > 57) {
				printf("请输入正整数：");
				goto C;
			}
		}
		for (n = 0, len -= 1; n <= len; n++) {
			output += ((input[n] - 48) * pow(10, len - n));
		}
		if (output > max_num) {
			printf("请输入1~%d的正整数:", max_num);
			goto C;
		}
		return output;
	}
}
