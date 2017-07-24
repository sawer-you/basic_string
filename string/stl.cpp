#include<iostream>
#include"MySTLString.h"

using namespace std;

int main() {
	MySTLString str("Hello");
	cout << str.back() << endl;
	MySTLString str1(5, ' ');
	cout << str1.front() << endl;
	str1 = str;
	cout << str1.front() << endl;
}