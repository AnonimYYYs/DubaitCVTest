#include<iostream>
#include<map>
#include<string>

using namespace std;

/*
Для задачи с небольшой системой исчисления можно сделать словарь вручную
Если система счисления будет больше, то можно сделать через `return C < 'A' ? (int(C) - 48) : (int(C) - 55)`
Однако словарь лучше так как экономит время вычисления
*/
map<char, int> NumbersMap = map<char, int>{
	{'0', 0},
	{'1', 1},
	{'2', 2},
	{'3', 3},
	{'4', 4},
	{'5', 5},
	{'6', 6},
	{'7', 7},
	{'8', 8},
	{'9', 9},
	{'A', 10},
	{'B', 11},
	{'C', 12},
};

/*
Считаем, что мы гарантированно знаем длину строки
*/
bool isEqual(string left, string right) {
	int lSum = 0, rSum = 0;
	for (int i = 0; i < 6; i++) {
		lSum += NumbersMap[left[i]];
		rSum += NumbersMap[right[i]];
	}
	return lSum == rSum;
}

/*
Так как в условии не указано, каким образом получаем числа - пусть будет список
Кроме этого, в условии сказано "напишите в ответе число красивых чисел", но не 
	указано, какой именно список проверять. Поэтому проверим список из трех 
	чисел из списка "например".
Здесь и дальше сразу считаем, что все числа корректные, без проверок
*/

string InitialNumbers[] = {
	"ABA98859978C0",
	"6789110551234",
	"0000007000000",
};

int main() {
	int total = 0, correct = 0;
	string toCheck;

	/*
	Если делать ввод через консоль с условием, что конец ввода - символ `-`

	while (true) {
		cin >> toCheck;
		if (toCheck == "-") break;
		total++;
		correct += isEqual(toCheck.substr(0, 6), toCheck.substr(7, 6));
	}
	*/

	for (int i = 0; i < sizeof(InitialNumbers) / sizeof(InitialNumbers[0]); i++) {
		toCheck = InitialNumbers[i];
		if (toCheck == "-") break;
		total++;
		correct += isEqual(toCheck.substr(0, 6), toCheck.substr(7, 6));
	}


	cout << "Total numbers: " << total << endl;
	cout << "\"Good\" numbers: " << correct << endl;
	return 0;
}