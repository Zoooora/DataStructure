#pragma once

#include <stdio.h>
#include <string.h>
#include <math.h>


//�޶���������ʱֻ���������������
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
					printf("���������֣�");
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
					printf("���������֣�");
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

//�޶���������ʱֻ�����벻������������
int is_limitted_digit() {
	char input[100];
	int len, n, output = 0;
	while (1) {
	C:n = 0;
		scanf("%s", input);
		len = strlen(input);
		for (; n < len; n++) {
			if (input[n] == '-') {
				printf("��������������");
				goto C;
			}
			if (input[n] < 48 || input[n] > 57) {
				printf("��������������");
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
				printf("��������������");
				goto C;
			}
			if (input[n] < 48 || input[n] > 57) {
				printf("��������������");
				goto C;
			}
		}
		for (n = 0, len -= 1; n <= len; n++) {
			output += ((input[n] - 48) * pow(10, len - n));
		}
		if (output > max_num) {
			printf("������1~%d��������:", max_num);
			goto C;
		}
		return output;
	}
}
