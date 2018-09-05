/*
 * game.cpp
 *
 *  Created on: 2018年9月4日
 *  Author: TIAN FENG
 */

#include "game.h"
#include <stdlib.h>

// 将打印出来的界面居中
#define SPACE "            "

// 行
#define ROW 8
// 列
#define COL 8

// 记录小人的位置
int y = 5;
int x = 4;

//地图 结构为 map[y][x]
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
		 * 0  空地
		 * 1  墙壁 ■
		 * 2  人 ♀
		 * 3 空箱子 ☆
		 * 4  目的地 ⊙
		 * 6 人走到目的地 = 2（人）+4（目的地）※
		 * 7 空箱子到目的地★
		 */
		};

int isSuccess(){
	return map[3][3]==7&&map[3][4]==7&&map[4][4]==7;
}


void print_map(){

	printf("小人位置（2） ： x = %d , y = %d",x,y);
	printf("上一位的值 ： value = %d ",map[y - 1][x]);
	for (int i = 0; i < ROW; i++) {
			printf("\n%s%s", SPACE, SPACE);
			for (int j = 0; j < COL; j++) {
				printf("%d  ",map[i][j]);
			}
		}

}

//打印地图
void showMap() {
	system("cls");
//	print_map();
	printf("\n     %s%s推箱子\n\n\n", SPACE, SPACE);
	for (int i = 0; i < ROW; i++) {
		printf("\n%s%s", SPACE, SPACE);
		for (int j = 0; j < COL; j++) {
			switch (map[i][j]) {
			case 0:
				printf("  ");
				break;
			case 1:
				printf("■");
				break;
			case 2:
				printf("♀");
				break;
			case 3:
				printf("☆");
				break;
			case 4:
				printf("⊙");
				break;
			case 6:
				printf("※");
				break;
			case 7:
				printf("★");
				break;
			}
		}
	}
	printf("\n\n\n\n\n");
	printf("   %sW:上   S:下   A:左    D:右   Q:退出\n", SPACE);

}

//小人向上移动的方法
void moveToUp() {
	// 判断是否可以行走
	// 墙壁不可走
	if (map[y - 1][x] == 1 ||
	// 表示旁边两位有箱子有箱子或是墙
			((map[y - 1][x] == 3 || map[y - 1][x] == 7)	// 旁边以为有箱子
			&&
			// 旁边两位有阻碍物
					(map[y - 2][x] == 3 || map[y - 2][x] == 7
							|| map[y - 2][x] == 1))) {
		showMap();
		return;

	} else if (map[y - 1][x] == 0 || map[y - 1][x] == 4) {	//旁边是空地或者是目的地
		map[y - 1][x] += 2;
		map[y][x] -= 2;
	} else {	//旁边带有箱子
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

//小人向下移动的方法
void moveToDown() {
	// 判断是否可以行走
	// 墙壁不可走
	if (map[y + 1][x] == 1 ||
	// 表示旁边两位有箱子有箱子或是墙
			((map[y + 1][x] == 3 || map[y + 1][x] == 7)	// 旁边以为有箱子
			&&
			// 旁边两位有阻碍物
					(map[y + 2][x] == 3 || map[y + 2][x] == 7
							|| map[y + 2][x] == 1))) {
		showMap();
		return;

	} else if (map[y + 1][x] == 0 || map[y + 1][x] == 4) {	//旁边是空地或者是目的地
		map[y + 1][x] += 2;
		map[y][x] -= 2;
	} else {	//旁边带有箱子
		map[y + 2][x] += 3;
		/*map[y][x - 1]-=3;
		 map[y][x - 1]+=2;*/
		map[y + 1][x] -= 1;
		map[y][x] -= 2;
	}

	y += 1;
	showMap();

}

//小人向右移动的方法
void moveToRight() {
	// 墙壁不可走
	if (map[y][x + 1] == 1 ||
	// 表示旁边两位有箱子有箱子或是墙
			((map[y][x + 1] == 3 || map[y][x + 1] == 7) // 旁边以为有箱子
			&&
			// 旁边两位有阻碍物
					(map[y][x + 2] == 3 || map[y][x + 2] == 7
							|| map[y][x + 2] == 1))) {
		showMap();
		return;

	} else if (map[y][x + 1] == 0 || map[y][x + 1] == 4) { //旁边是空地或者是目的地
		map[y][x + 1] += 2;
		map[y][x] -= 2;
	} else { //旁边带有箱子
		map[y][x + 2] += 3;
		/*map[y][x - 1]-=3;
		 map[y][x - 1]+=2;*/
		map[y][x + 1] -= 1;
		map[y][x] -= 2;
	}

	x += 1;
	showMap();
}

//小人向左移动的方法
void moveToLeft() {
	// 判断是否可以行走
	// 墙壁不可走
	if (map[y][x - 1] == 1 ||
	// 表示旁边两位有箱子有箱子或是墙
			((map[y][x - 1] == 3 || map[y][x - 1] == 7)	// 旁边以为有箱子
			&&
			// 旁边两位有阻碍物
					(map[y][x - 2] == 3 || map[y][x - 2] == 7
							|| map[y][x - 2] == 1))) {
		showMap();
		return;

	} else if (map[y][x - 1] == 0 || map[y][x - 1] == 4) {	//旁边是空地或者是目的地
		map[y][x - 1] += 2;
		map[y][x] -= 2;
	} else {	//旁边带有箱子
		map[y][x - 2] += 3;
		/*map[y][x - 1]-=3;
		 map[y][x - 1]+=2;*/
		map[y][x - 1] -= 1;
		map[y][x] -= 2;
	}

	x -= 1;
	showMap();
}

