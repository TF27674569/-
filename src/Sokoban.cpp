//============================================================================
// Name        : Sokoban.cpp
// Author      : TIAN FENG
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
 #include<conio.h>
#include "resouce/game.h"

void purit_success(char * end){
	system("cls");
	printf("\n\n\n");
	printf("            ********************************************\n");
	printf("            **************               ***************\n");
	printf("            **************     %s    ***************\n",end);
	printf("            **************               ***************\n");
	printf("            ********************************************\n");
	printf("\n\n\n");
}

int main() {
	showMap();
	while (!isSuccess()) {
		char action = getch();
		switch (action) {
		case 'w':
		case 'W':
		case 72:
			moveToUp();
			break;
		case 's':
		case 'S':
		case 80:
			 moveToDown();
			break;
		case 'A':
		case 'a':
		case 75:
			moveToLeft();
			break;
		case 'D':
		case 'd':
		case 77:
			moveToRight();
			break;
		case 'Q':
		case 'q':
		case 0x1b:
			purit_success("À¿≤Àπ∑");
			goto end;
			break;
		}
	}

	purit_success("≈£±∆∞°");

	end:
	system("pause");
	return 0;
}

