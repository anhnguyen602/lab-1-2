#include<iostream>
#include<string>
using namespace std;
int check(char a) {
	if (a >= 65 && a <= 90)
		return 1;
	else if (a == 32) return 1;
	else if (a >= 97 && a < 122) return 1;
	else return 0;
}
bool CheckString(string a) {
	for (int i = 0; i < a.length(); i++) {
		if (check(a[i]) == 0)
			return false;

	}
	return true;
}
void Xoakitu(string &a, int index) {
	int i;
	for ( i = index; i < a.length() -  1; i++) {
		a[i] = a[i + 1];
	}
	a[i] = '\0';
}
void ChuanHoa(string &a) {
	while (a[0] == 32) {
		Xoakitu(a, 0);
	}
	if (a[0] <= 122 && a[0] >= 97) a[0] -= 32;
	for (int i = 1; i < a.length(); i++) {
		int last = a[i - 1];
		if (last == 32) {
			while (a[i] == 32) {
				Xoakitu(a, i);
			}
			if (a[i] >= 97 && a[i] <= 122) {
				a[i] = a[i] - 32;
			}
		}
		else if (a[i] >= 65 && a[i] <= 90) {
			a[i] += 32;
		}
	}
}
int main() {
	string name;
	do {
		cout << "Nhap vao ten cua ban: ";
		getline(cin, name);
		if (!CheckString(name))
			cout << "Ten ban nhap chua dung yeu cau, vui long nhap lai!" << endl;
	} while (!CheckString (name));
	ChuanHoa(name);
	cout << "hello " << name;
	

	return 0;

}