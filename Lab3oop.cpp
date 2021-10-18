// Sukhikh Matvei B20-523

#include <iostream>
#include "C:\Users\Vulki\Desktop\Lab3oop\Libfor3lab\Number.h"

using namespace Prog3;

int main(){

    int choice = -1;
	char number[10]; // Сами цифры в числе.
	long initnumber; // Число не чаром
	long operationnumber;
	Number num1;
	int result;
	struct AdditionalCodeValue Code = {};
	do{
		if (get(choice, -1, "\n0.Exit\n1.Enter by long number\n2.Enter by char\n3.Get value in straight Code\n4.Get value in additional code\n"
			"5.Get sum of two numbers\n6.Get multiplication of your number and 10.\n") < 0){
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
			Code = num1.AdditionalCode();
			for (int i = 0; i < 22; i++) {
				std::cout << Code.Additional[i];
			}
			break;
		case 5:
			std::cout << "Enter long number which you want to sum" << std::endl;
			if (!getNum(operationnumber))
				return -1;
			result = num1.Addition(operationnumber);
			std::cout << "Result of sum equals " << result << std::endl;
			break;
		case 6:
			std::cout << num1.Multiplication() << std::endl;
			break;
		}
	} while (choice != 0);
}
