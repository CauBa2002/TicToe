#include <iostream>
#include <string>
#include <cstdlib>
#define Max 25
using namespace std;

void CreateMaTran(int& n, string a[Max][Max]) {
	do {
		cout << "Nhap n :";
		cin >> n;
		if (n <= 5 || n > 25) {
			cout << "Vui long nhap lai!!\n";
		}
	} while (n <= 5 || n > 25);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = "!";
		}
	}
}

void OutputMaTran(int& n, string a[Max][Max]) {
	system("cls");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << "\t";
		}
		cout << endl << endl;
	}
}

void RoundPlayerA(int n, string a[Max][Max]) {
	int x, y;
	do {
		cout << "Luoi Player A : \n";
		do {
			cout << "Nhap toa do x va y : ";
			cin >> x >> y;
			if (x < 0 || x > n || y < 0 || y > n)
				cout << "Toa do khong hop le!! Vui long nhap lai!!\n";
		} while (x < 0 || x > n || y < 0 || y > n);
		if (a[x][y] != "!")
			cout << "Toa do da duoc danh!! Vui long nhap lai!!\n";
	} while (a[x][y] != "!");
	a[x][y] = "X";
}

void RoundPlayerB(int n, string a[Max][Max]) {
	int x, y;
	do {
		cout << "Luoi Player B : \n";
		do {
			cout << "Nhap toa do x va y : ";
			cin >> x >> y;
			if (x < 0 || x > n || y < 0 || y > n)
				cout << "Toa do khong hop le!! Vui long nhap lai!!\n";
		} while (x < 0 || x > n || y < 0 || y > n);
		if (a[x][y] != "!")
			cout << "Toa do da duoc danh!! Vui long nhap lai!!\n";
	} while (a[x][y] != "!");
	a[x][y] = "O";
}

bool CheckWin(int n, string a[Max][Max]) {
	int count = 0;
	//Check hàng ngang j++ nếu 5 ký tự liên tiếp thì thắng
	for (int i = 0; i < n; i++) {
		count = 1;
		for (int j = 0; j < n; j++) {
			if (a[i][j] == "X") {
				if (a[i][j + 1] == "O")
					count = 1;
				if (a[i][j] == a[i][j + 1] && a[i][j] != "!") {
					count++;
					if (count == 5 && a[i][j - 4] != "O" && a[i][j + 2] != "O") {
						return true;
					}
				}
			}
		}
		count = 1;
		for (int j = 0; j < n; j++) {
			if (a[i][j] == "O") {
				if (a[i][j + 1] == "X")
					count = 1;
				if (a[i][j] == a[i][j + 1] && a[i][j] != "!") {
					count++;
					if (count == 5 && a[i][j - 4] != "X" && a[i][j + 2] != "X") {
						return true;
					}
				}
			}
		}
	}

	//Check hàng dọc nếu 5 ký tự liên tiếp thì thắng
	for (int j = 0; j < n; j++) {
		count == 1;
		for (int i = 0; i < n; i++) {
			if (a[i][j] == "X") {
				if (a[i + 1][j] == "O")
					count = 1;
				if (a[i][j] == a[i + 1][j] && a[i][j] != "!") {
					count++;
					if (count == 5 && a[i - 4][j] != "O" && a[i + 2][j] != "O") {
						return true;
					}
				}
			}

		}
		count = 1;
		for (int i = 0; i < n; i++) {
			if (a[i][j] == "O") {
				if (a[i + 1][j] == "X")
					count = 1;
				if (a[i][j] == a[i + 1][j] && a[i][j] != "!") {
					count++;
					if (count == 5 && a[i - 4][j] != "X" && a[i + 2][j] != "X") {
						return true;
					}
				}
			}
		}
	}
	//Kiểm tra đường chéo dấu huyền nếu 5 ký tự liên tiếp thì thắng
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			count = 1;
			while(a[i][j] == a[i + 1][j + 1] && a[i][j] != "!" && a[i][j] == "X" && i < n && j < n){
				if (a[i + 1][j + 1] == "O")
					count = 1;
				count++;
				if (count == 5 && a[i - 4][j - 4] != "O" && a[i + 2][j + 2] != "O") {
					return true;
				}
				i++;
				j++;
			}
			count = 1;
			while (a[i][j] == a[i + 1][j + 1] && a[i][j] != "!" && a[i][j] == "O" && i < n && j < n) {
				if (a[i + 1][j + 1] == "X")
					count = 1;
				count++;
				if (count == 5 && a[i - 4][j - 4] != "X" && a[i + 2][j + 2] != "X") {
					return true;
				}
				i++;
				j++;
			}
		}
	}
	//Kiểm tra đường chéo dấu sắc nếu 5 ký tự liên tiếp thì thắng
	for (int i = n - 1; i > 0; i--) {
		for (int j = n - 1; j > 0; j--) {
			count = 1;
			//if (j + count >= 5) {
				while (a[i][j] == a[i - 1][j + 1] && a[i][j] != "!" && a[i][j] == "X" && i < n && j >= 0) {
					if (a[i - 1][j + 1] == "O")
						count = 1;
					count++;
					if (count == 5 && a[i + 4][j - 4] == "O" && a[i - 2][j + 2] == "O") {
						return true;
					}
					i++;
					j--;
				}
			//}
			count = 1;
			//if (j + count >= 5) {
				while (a[i][j] == a[i - 1][j + 1] && a[i][j] != "!" && a[i][j] == "O" && i < n && j >= 0) {
					if (a[i - 1][j + 1] == "X")
						count = 1;
					count++;
					if (count == 5 && a[i + 4][j - 4] == "X" && a[i - 2][j + 2] == "X") {
						return true;
					}
					i++;
					j--;
				}
			//}
		}
	}
}

int main() {
	int n = 0, choose;
	string a[Max][Max];
	do {
		cout << "\n======================= - TicToe - ======================";
		cout << "\n| 0. Thoat.                                             |";
		cout << "\n| 1. Choi tiep.                                         |";
		cout << "\n=========================================================";
		cout << "\nNhap lua chon : ";
		cin >> choose;
		switch (choose)
		{
			case 0: {
				cout << "Say beiii...";
				break;
			}
			case 1: {
				CreateMaTran(n, a);
				OutputMaTran(n, a);
				while (true) {
					RoundPlayerA(n, a);
					OutputMaTran(n, a);
					if (CheckWin(n, a) == true) {
						cout << "Player A win!!";
						break;
					}
					RoundPlayerB(n, a);
					OutputMaTran(n, a);
					if (CheckWin(n, a) == true) {
						cout << "Player B win!!";
						break;
					}
				}
			}
		}
	} while (choose != 0);
	return 0;
}
