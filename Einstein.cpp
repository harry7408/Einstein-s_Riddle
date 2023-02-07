#include "Einstein.h"
#include <iostream>
#include <iomanip>
using namespace std;
int COUNT = 0;
void Einstein_Riddle(int a[][5], int num, int depth) {
	if (depth == 5)
	{
		print_solution(a);
		return;
	}
	//1차원 배열이 모두 점검된 상태인 경우
	if (num == 5)
	{
		//Promising 하다면 깊이 1 증가 => 배열 1줄 끝까지 원소 바꿔가며 탐색
		if (Promising(a, depth))
			Einstein_Riddle(a, 0, depth + 1);//아래 행으로 갈 때 맨 앞부터 swap해가도록 num을 0으로, 깊이는 1 증가
		COUNT++;
		return;
	}
	for (int i = num; i < 5; i++) {
		Swap(a[depth], i, num);//시작 값을 찾기 위해 swap해가며 찾는다
		Einstein_Riddle(a, num + 1, depth);  //1차원 배열 안에서 depth 1 증가시키며 순열 만들기
		Swap(a[depth], i, num); // 다시 제자리로
	}
}

int Promising(int a[][5], int depth) {
	//depth 0 : 나라 정보 row
	if (depth == 0) {
		if (a[NATIONALITY][Norwegian] != 0) return 0;
	}
	//depth 1 : 색상 정보 row
	else if (depth == 1) {
		if (a[NATIONALITY][Brit] != a[COLOR][Red]) return 0;
		if (a[COLOR][Green] - a[COLOR][White] != -1) return 0;
		if (a[COLOR][Blue] - a[NATIONALITY][Norwegian] != 1) return 0;
	}
	//depth2 : 음료 정보 row
	else if (depth == 2) {
		if (a[NATIONALITY][Dane] != a[BEVERAGE][Tea]) return 0;
		if (a[COLOR][Green] != a[BEVERAGE][Coffee]) return 0;
		if (a[BEVERAGE][Milk] != 2) return 0;
	}
	//depth3 : 담배 정보 row
	else if (depth == 3)
	{
		if (a[COLOR][Yellow] != a[CIGAR][Dunhill]) return 0;
		if (a[CIGAR][Blue_master] != a[BEVERAGE][Beer]) return 0;
		if (a[NATIONALITY][German] != a[CIGAR][Prince]) return 0;
		if (abs(a[CIGAR][Blend] - a[BEVERAGE][Water]) != 1) return 0;
	}
	//depth4 : 동물 정보 row
	else
	{
		if (a[NATIONALITY][Swede] != a[PET][Dog]) return 0;
		if (a[CIGAR][Pall_mall] != a[PET][Bird]) return 0;
		if (abs(a[CIGAR][Blend] - a[PET][Cat]) != 1) return 0;
		if (abs(a[CIGAR][Dunhill] - a[PET][Horse]) != 1) return 0;
	}
	return 1;
}

void print_solution(int a[][5]) {
	cout.setf(ios::right);
	cout << setw(20) << "0번집" << setw(20) << "1번집" << setw(20) << "2번집" << setw(20) << "3번집" << setw(20) << "4번집" << endl;
	for (int depth = 0; depth < 5; depth++)
	{
		for (int column = 0; column < 5; column++)
		{
			for (int row = 0; row < 5; row++)
			{
				if (a[depth][row] == column)
				{
					switch (depth)
					{
					case NATIONALITY:
						switch (row)
						{
						case 0: cout << setw(20) << "Brit"; break;
						case 1: cout << setw(20) << "Dane"; break;
						case 2: cout << setw(20) << "German"; break;
						case 3: cout << setw(20) << "Norwegian"; break;
						case 4: cout << setw(20) << "Swede"; break;
						default:
							break;
						} break;
					case COLOR:
						switch (row)
						{
						case 0: cout << setw(20) << "Blue"; break;
						case 1: cout << setw(20) << "Green"; break;
						case 2: cout << setw(20) << "Red"; break;
						case 3: cout << setw(20) << "White"; break;
						case 4: cout << setw(20) << "Yellow"; break;
						default:
							break;
						} break;
					case BEVERAGE:
						switch (row)
						{
						case 0: cout << setw(20) << "Beer"; break;
						case 1: cout << setw(20) << "Coffee"; break;
						case 2: cout << setw(20) << "Milk"; break;
						case 3: cout << setw(20) << "Tea"; break;
						case 4: cout << setw(20) << "Water"; break;
						default:
							break;
						} break;
					case CIGAR:
						switch (row)
						{
						case 0: cout << setw(20) << "Blue Master"; break;
						case 1: cout << setw(20) << "Dunhill"; break;
						case 2: cout << setw(20) << "Pall Mall"; break;
						case 3: cout << setw(20) << "Prince"; break;
						case 4: cout << setw(20) << "Blend"; break;
						default:
							break;
						} break;
					case PET:
						switch (row)
						{
						case 0: cout << setw(20) << "Cat"; break;
						case 1: cout << setw(20) << "Bird"; break;
						case 2: cout << setw(20) << "Dog"; break;
						case 3: cout << setw(20) << "Fish"; break;
						case 4: cout << setw(20) << "Horse"; break;
						default:
							break;
						} break;
					default:
						break;
					}
				}
			}
		}
		cout << endl;
	}
}
int main() {
	int arr[5][5] = {
		{0,1,2,3,4},
		{1,2,3,4,0},
		{2,3,4,0,1},
		{3,4,0,1,2},
		{4,0,1,2,3}
	};

	Einstein_Riddle(arr, 0, 0);
	cout << endl << "아인슈타인의 수수께끼 정답까지 count된 횟수는 " << COUNT << "입니다" << endl;
	cout << "수수께끼 정답은 물고기를 기르는사람은 독일인이다." << endl;

}

