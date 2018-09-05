/*
 * game.cpp
 *
 *  Created on: 2018��9��4��
 *  Author: TIAN FENG
 */

#include "game.h"
#include <stdlib.h>

// ����ӡ�����Ľ������
#define SPACE "            "

// ��
#define ROW 8
// ��
#define COL 8

// ��¼С�˵�λ��
int y = 5;
int x = 4;

//��ͼ �ṹΪ map[y][x]
int map[ROW][COL] = {
		{ 0, 0, 1, 1, 1, 1, 0, 0 }, //0
		{ 0, 0, 1, 0, 0, 1, 1, 1 }, //1
		{ 1, 1, 1, 0, 0, 0, 0, 1 }, //2
		{ 1, 0, 0, 7, 4, 1, 0, 1 }, //3
		{ 1, 0, 0, 3, 7, 0, 0, 1 }, //4
		{ 1, 1, 1, 0, 2, 1, 1, 1 }, //5
		{ 0, 0, 1, 0, 0, 1, 0, 0 }, //6
		{ 0, 0, 1, 1, 1, 1, 0, 0 }, //7

		/*
		 * 0  �յ�
		 * 1  ǽ�� ��
		 * 2  �� ��
		 * 3 ������ ��
		 * 4  Ŀ�ĵ� ��
		 * 6 ���ߵ�Ŀ�ĵ� = 2���ˣ�+4��Ŀ�ĵأ���
		 * 7 �����ӵ�Ŀ�ĵء�
		 */
		};

int isSuccess(){
	return map[3][3]==7&&map[3][4]==7&&map[4][4]==7;
}


void print_map(){

	printf("С��λ�ã�2�� �� x = %d , y = %d",x,y);
	printf("��һλ��ֵ �� value = %d ",map[y - 1][x]);
	for (int i = 0; i < ROW; i++) {
			printf("\n%s%s", SPACE, SPACE);
			for (int j = 0; j < COL; j++) {
				printf("%d  ",map[i][j]);
			}
		}

}

//��ӡ��ͼ
void showMap() {
	system("cls");
//	print_map();
	printf("\n     %s%s������\n\n\n", SPACE, SPACE);
	for (int i = 0; i < ROW; i++) {
		printf("\n%s%s", SPACE, SPACE);
		for (int j = 0; j < COL; j++) {
			switch (map[i][j]) {
			case 0:
				printf("  ");
				break;
			case 1:
				printf("��");
				break;
			case 2:
				printf("��");
				break;
			case 3:
				printf("��");
				break;
			case 4:
				printf("��");
				break;
			case 6:
				printf("��");
				break;
			case 7:
				printf("��");
				break;
			}
		}
	}
	printf("\n\n\n\n\n");
	printf("   %sW:��   S:��   A:��    D:��   Q:�˳�\n", SPACE);

}

//С�������ƶ��ķ���
void moveToUp() {
	// �ж��Ƿ��������
	// ǽ�ڲ�����
	if (map[y - 1][x] == 1 ||
	// ��ʾ�Ա���λ�����������ӻ���ǽ
			((map[y - 1][x] == 3 || map[y - 1][x] == 7)	// �Ա���Ϊ������
			&&
			// �Ա���λ���谭��
					(map[y - 2][x] == 3 || map[y - 2][x] == 7
							|| map[y - 2][x] == 1))) {
		showMap();
		return;

	} else if (map[y - 1][x] == 0 || map[y - 1][x] == 4) {	//�Ա��ǿյػ�����Ŀ�ĵ�
		map[y - 1][x] += 2;
		map[y][x] -= 2;
	} else {	//�Աߴ�������
		map[y - 2][x] += 3;
		/*map[y][x - 1]-=3;
		 map[y][x - 1]+=2;*/
		map[y - 1][x] -= 1;
		map[y][x] -= 2;
		/**
		  0  0  1  1  1  1  0  0
 	 	  0  0  1  0  0  1  1  1
 	 	  1  1  1  0  0  0  0  1
 	 	  1  0  0  7  4  1  0  1
 	 	  1  0  0  3  7  0  0  1
 	 	  1  1  1  0  2  1  1  1
 	 	  0  0  1  0  0  1  0  0
 	 	  0  0  1  1  1  1  0  0
		 */
	}
	y -= 1;
	showMap();

}

//С�������ƶ��ķ���
void moveToDown() {
	// �ж��Ƿ��������
	// ǽ�ڲ�����
	if (map[y + 1][x] == 1 ||
	// ��ʾ�Ա���λ�����������ӻ���ǽ
			((map[y + 1][x] == 3 || map[y + 1][x] == 7)	// �Ա���Ϊ������
			&&
			// �Ա���λ���谭��
					(map[y + 2][x] == 3 || map[y + 2][x] == 7
							|| map[y + 2][x] == 1))) {
		showMap();
		return;

	} else if (map[y + 1][x] == 0 || map[y + 1][x] == 4) {	//�Ա��ǿյػ�����Ŀ�ĵ�
		map[y + 1][x] += 2;
		map[y][x] -= 2;
	} else {	//�Աߴ�������
		map[y + 2][x] += 3;
		/*map[y][x - 1]-=3;
		 map[y][x - 1]+=2;*/
		map[y + 1][x] -= 1;
		map[y][x] -= 2;
	}

	y += 1;
	showMap();

}

//С�������ƶ��ķ���
void moveToRight() {
	// ǽ�ڲ�����
	if (map[y][x + 1] == 1 ||
	// ��ʾ�Ա���λ�����������ӻ���ǽ
			((map[y][x + 1] == 3 || map[y][x + 1] == 7) // �Ա���Ϊ������
			&&
			// �Ա���λ���谭��
					(map[y][x + 2] == 3 || map[y][x + 2] == 7
							|| map[y][x + 2] == 1))) {
		showMap();
		return;

	} else if (map[y][x + 1] == 0 || map[y][x + 1] == 4) { //�Ա��ǿյػ�����Ŀ�ĵ�
		map[y][x + 1] += 2;
		map[y][x] -= 2;
	} else { //�Աߴ�������
		map[y][x + 2] += 3;
		/*map[y][x - 1]-=3;
		 map[y][x - 1]+=2;*/
		map[y][x + 1] -= 1;
		map[y][x] -= 2;
	}

	x += 1;
	showMap();
}

//С�������ƶ��ķ���
void moveToLeft() {
	// �ж��Ƿ��������
	// ǽ�ڲ�����
	if (map[y][x - 1] == 1 ||
	// ��ʾ�Ա���λ�����������ӻ���ǽ
			((map[y][x - 1] == 3 || map[y][x - 1] == 7)	// �Ա���Ϊ������
			&&
			// �Ա���λ���谭��
					(map[y][x - 2] == 3 || map[y][x - 2] == 7
							|| map[y][x - 2] == 1))) {
		showMap();
		return;

	} else if (map[y][x - 1] == 0 || map[y][x - 1] == 4) {	//�Ա��ǿյػ�����Ŀ�ĵ�
		map[y][x - 1] += 2;
		map[y][x] -= 2;
	} else {	//�Աߴ�������
		map[y][x - 2] += 3;
		/*map[y][x - 1]-=3;
		 map[y][x - 1]+=2;*/
		map[y][x - 1] -= 1;
		map[y][x] -= 2;
	}

	x -= 1;
	showMap();
}

