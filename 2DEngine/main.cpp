#include "main.h"
#include <SDL.h>
#define LOG(format, ...) LogPrint(__FILE__, __LINE__, format, __VA_ARGS__);
#define MIN(a,b) {a < b ? a : b}
#define MAX(a,b) {a > b ? a : b}

int main() {

	DynamicArray fulles;

	fulles.Reallocate(7);

	fulles.data[0] = 1;
	fulles.data[1] = 2;
	fulles.data[2] = 3;
	fulles.data[3] = 4;
	fulles.data[4] = 5;
	fulles.data[5] = 6;
	fulles.data[6] = 7;
	fulles.PushBack(8);


	/*printf("%d", fulles.data[0]);
	printf("%d", fulles.data[1]);
	printf("%d", fulles.data[2]);
	printf("%d", fulles.data[3]);
	printf("%d", fulles.data[4]);
	printf("%d", fulles.data[5]);
	printf("%d", fulles.data[6]);*/
	printf("%d", fulles.data[8]);


	






	/*
	lList <float> l;
	l.add(1.0f);
	l.add(2.0f);
	l.add(3.0f);

	l.delList();


	int i = MIN(3,5);
	//printf("%d",i);

	*/
	getchar();
	return 0;
}

