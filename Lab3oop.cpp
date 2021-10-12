// Sukhikh Matvei B20-523

#include <iostream>
#include "C:\Users\Vulki\Desktop\Lab3oop\Libfor3lab\Number.h"

using namespace Prog3;

int main(){

    int choice = -1;
	char number[10]; // Сами цифры в числе.
	long initnumber; // Число не чаром
	Number num1;
	do{
		if (get(choice, -1, "\n0.Exit\n1.Enter by long number\n2.Enter by char\n3.Get value in Additional Code\n") < 0){
		}
		switch (choice){
		case 1:
			std::cout << "Enter long number" << std::endl; 
			if (!getNum(initnumber))
				return -1;
			num1.SetByLong(initnumber);
			break;
		case 2:
			std::cout << "Enter char number" << std::endl; // 
			std::cin >> number; // Добавить проверку, что до 7 символов. (Включая знак).
			num1.SetByChar(number);
			break;
		case 3:
			std::cout << num1.GetChar()<<std::endl;
			break;
		case 4:
			num1.AdditionalCode();
		}
	} while (choice != 0);
}
