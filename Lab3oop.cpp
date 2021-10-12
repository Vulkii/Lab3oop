// Sukhikh Matvei B20-523

#include <iostream>
#include "C:\Users\Vulki\Desktop\Lab3oop\Libfor3lab\Number.h"

using namespace Prog3;

int main(){
    int choice = -1;
	int size_of_number; // Количество цифр в вводимом числе. до 14.
	char number[10]; // Сами цифры в числе.
	long initnumber; // Число не чаром
	char AdditionalCode[31];
	Number num1;
	do{
		if (get(choice, -1, "\n0.Exit\n1.Enter by long number\n2.Enter by char\n3.Get value in Additional Code\n") < 0){
		}
		switch (choice){
		case 1:
			std::cout << "Enter long number" << std::endl; 
			if (!getNum(initnumber)) // Добавить подсчёт отдельной функцией - цифр в числе должно быть не больше 9.
				return -1;
			num1.SetByLong(initnumber);
			num1.GetChar();
			break;
		case 2:
			std::cout << "Enter char number" << std::endl; // 
			std::cin >> number; // Добавить проверку, что до 10 символов. (Включая знак).
			num1.SetByChar(number);
			num1.GetChar();
			break;
		case 3:
			num1.GetChar();
			break;
		case 4:
			num1.AdditionalCode();
		}
	} while (choice != 0);
}
