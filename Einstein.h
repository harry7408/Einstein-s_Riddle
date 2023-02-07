#pragma once
enum ATTRIBUTES { NATIONALITY, COLOR, BEVERAGE, CIGAR, PET }; //행렬의 행으로 각 요소 깊이 표현용
enum ZERO { Brit, Dane, German, Norwegian, Swede };
enum FIRST { Blue, Green, Red, White, Yellow };
enum SECOND { Beer, Coffee, Milk, Tea, Water };
enum THIRD { Blue_master, Dunhill, Pall_mall, Prince, Blend };
enum FOURTH { Cat, Bird, Dog, Fish, Horse };

void Einstein_Riddle(int a[][5], int depth, int num);
int Promising(int a[][5], int depth);
void print_solution(int a[][5]);
void Swap(int a[], int x, int y) {
	int temp = a[x];
	a[x] = a[y];
	a[y] = temp;
}
