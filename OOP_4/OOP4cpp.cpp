#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
#include<algorithm> 

using namespace std;

class String {
protected:
	char* array;
	int size;
public:
	String() {
		size = 1;
		array = new char[size + 1];
		array[0] = '0';
		array[1] = '\n';
	}
	String(char* arr1) {
		int size1 = 0;
		while (arr1[size1] != '\n') {
			size1++;
		}
		size = size1;
		this->array = new char[size+1];
		for (int i = 0; i < size; i++) {
			this->array[i] = arr1[i];
		}
		arr1[size] = '\n';
	}
	String(const String& str) {
		size = str.size;
		array = new char[str.size + 1];
		for (int i = 0; i < str.size; i++) {
			array[i] = str.array[i];
		}
		array[size] = '\n';
	}
	int GetSize() const{
		return (size);
	}
	char* GetPointerOnString() const {
		return (array);
	}
	void Print_string() {
		for (int i = 0; i < size; i++) {
			cout << array[i];
		}
		cout << " ";
	}
	~String() {
		delete[]array;
		size = 0;
	}
};

class NumericString : public String 
{
public:
	NumericString(char* s) :String(s) {
		for (int i = 0; i < size; i++) {
			if (s[i] < 48 || s[i] > 57)s[i] = '0';
			array[i] = s[i];
		}
		array[size] = '\n';
	}    
    NumericString operator=(const NumericString& str) {
        delete[] array;
        size = str.size;
        array = new char[size + 1];
        for (int i = 0; i < size; i++) {
            array[i] = str.array[i];
        }
        array[size] = '\n';
        return(array);
    }
    bool operator ==(const NumericString& str) {
        if (size != str.size)return(false);
        else {
            for (int i = 0; i < str.size; i++)
            {
                if (str.array[i] != array[i])return(false);
            }
            return(true);
        }
    }
    bool operator >(const NumericString& str) {
        if (size > str.size) return true;
        else if (str.size > size) return false;
        else for (int i = 0; i < size; i++) {
            if (array[i] > str.array[i]) return true;
            else if (array[i] < str.array[i])return false;
        }
        return false;
    }
};

int main()
{
    setlocale(LC_ALL, "Rus");
    //ввод строк
    char* ck = new char[100];
    int y = 0;
    char m;
    cout << "Введите строку типа Numeric String" << endl;
    while (scanf("%c", &m)) {
        ck[y] = m;
        y++;
    }
    char* str1 = new char[y + 1];
    for (int i = 0; i < y; i++) {
        str1[i] = ck[i];
    }
    str1[y] = '\n';
    delete[]ck;
    NumericString a(str1);
    
    cout << "Введите строку типа Numeric String" << endl;
    char* ch = new char[100];
    int x = 0;
    char b;
    while (scanf("%c", &b)) {
        ch[x] = b;
        x++;
    }
    char* str = new char[x];
    for (int i = 1; i < x; i++) {
        str[i - 1] = ch[i];
    }
    delete[]ch;
    NumericString d(str);

    cout << "Введите строку типа Numeric String" << endl;
    char* cm = new char[100];
    int y1 = 0;
    char m1;
    while (scanf("%c", &m1)) {
        cm[y1] = m1;
        y1++;
    }
    char* str2 = new char[y1 + 1];
    for (int i = 1; i < y1; i++) {
        str2[i - 1] = cm[i];
    }
    delete[]cm;
    NumericString c(str2);
    // для понятной сортировки
    NumericString l = d;

    //оператор =
    cout << "Строку ";
    a.Print_string();
    cout << "Присвоили строке ";
    d.Print_string();
    d = a;

    //оператор ==
    cout << "Если строка ";
    a.Print_string();
    cout << "равна строке ";
    d.Print_string();
    cout << "На экране появится Yes" << endl;
    if (d == a)cout << "Yes" << endl;
    else cout << "No" << endl;

    //оператор>
    cout << "Если строка ";
    c.Print_string();
    cout << "больше строки ";
    d.Print_string();
    cout << "На экране появится Yes" << endl;
    if (c > d)cout << "Yes" << endl;
    else cout << "No" << endl;

    //сортировка
    NumericString arr[3] = { c, l, a };
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (arr[i] > arr[j]) {
                NumericString tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    cout << "Отсортированный массив" << endl;
    for (int i = 0; i < 3; i++) {
        arr[i].Print_string();
        cout << endl;
    }
}




