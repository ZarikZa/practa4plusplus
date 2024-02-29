#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#include <vector>
#include <random>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

int main()
{
    setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "");
	string slovostr = "";
	cin >> slovostr;
	const int dlina = slovostr.length();
	vector<char> slovo(dlina);
    cout << "Выберите действие:\n1. Слово выводится задом наперед.\n2. Вывести слово без гласных.\n3. Вывести слово без согласных.\n4. Рандомно раскидывать буквы заданного слова.\n";
    int vibor;
	cin >> vibor;
	const string glas ("ауоыиэяюёе");
	const string soglas ("бвгджзйклмнпрстфхцчшщ");
	switch (vibor)
	{
	case(1):
		reverse(slovostr.begin(), slovostr.end());
		cout << "\n" << slovostr;
		break;
	case(2):
		slovostr.erase(
			remove_if(slovostr.begin(), slovostr.end(), [&glas](char c) {
				return glas.find(c) != string::npos;
				}),
			slovostr.end()
			);
		cout << slovostr;
		break;
	case(3):
		slovostr.erase(
			remove_if(slovostr.begin(), slovostr.end(), [&soglas](char c) {
				return soglas.find(c) != string::npos;
				}),
			slovostr.end()
		);
		cout << slovostr;
		break;
	case(4):
		random_device rd;
		shuffle(slovostr.begin(), slovostr.end(), rd);
		cout << slovostr;
		break;
	default:
		break;
	}
}