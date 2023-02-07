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
	//1���� �迭�� ��� ���˵� ������ ���
	if (num == 5)
	{
		//Promising �ϴٸ� ���� 1 ���� => �迭 1�� ������ ���� �ٲ㰡�� Ž��
		if (Promising(a, depth))
			Einstein_Riddle(a, 0, depth + 1);//�Ʒ� ������ �� �� �� �պ��� swap�ذ����� num�� 0����, ���̴� 1 ����
		COUNT++;
		return;
	}
	for (int i = num; i < 5; i++) {
		Swap(a[depth], i, num);//���� ���� ã�� ���� swap�ذ��� ã�´�
		Einstein_Riddle(a, num + 1, depth);  //1���� �迭 �ȿ��� depth 1 ������Ű�� ���� �����
		Swap(a[depth], i, num); // �ٽ� ���ڸ���
	}
}

int Promising(int a[][5], int depth) {
	//depth 0 : ���� ���� row
	if (depth == 0) {
		if (a[NATIONALITY][Norwegian] != 0) return 0;
	}
	//depth 1 : ���� ���� row
	else if (depth == 1) {
		if (a[NATIONALITY][Brit] != a[COLOR][Red]) return 0;
		if (a[COLOR][Green] - a[COLOR][White] != -1) return 0;
		if (a[COLOR][Blue] - a[NATIONALITY][Norwegian] != 1) return 0;
	}
	//depth2 : ���� ���� row
	else if (depth == 2) {
		if (a[NATIONALITY][Dane] != a[BEVERAGE][Tea]) return 0;
		if (a[COLOR][Green] != a[BEVERAGE][Coffee]) return 0;
		if (a[BEVERAGE][Milk] != 2) return 0;
	}
	//depth3 : ��� ���� row
	else if (depth == 3)
	{
		if (a[COLOR][Yellow] != a[CIGAR][Dunhill]) return 0;
		if (a[CIGAR][Blue_master] != a[BEVERAGE][Beer]) return 0;
		if (a[NATIONALITY][German] != a[CIGAR][Prince]) return 0;
		if (abs(a[CIGAR][Blend] - a[BEVERAGE][Water]) != 1) return 0;
	}
	//depth4 : ���� ���� row
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
	cout << setw(20) << "0����" << setw(20) << "1����" << setw(20) << "2����" << setw(20) << "3����" << setw(20) << "4����" << endl;
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
	cout << endl << "���ν�Ÿ���� �������� ������� count�� Ƚ���� " << COUNT << "�Դϴ�" << endl;
	cout << "�������� ������ ����⸦ �⸣�»���� �������̴�." << endl;

}

