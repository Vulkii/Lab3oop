

/*
*/

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <math.h>
#include <string>
#include <stdio.h>
#include <strstream>
#include <cstdlib>
#include "Number.h"

namespace Prog3 {

	// Setters
	Number& Number::SetByLong(long ByLong) { 
		if (CountDigits(ByLong)>7)
			throw std::logic_error("Too much digits");
		long number = ByLong;
		if (ByLong < 0) {
			value[0] = '1';
			number = ByLong * (-1);
		}
		else value[0] = '0';
		for (int i = 20; i > 0; i--) {
			value[i] = (number % 2)+'0';
			number = number / 2;
		}
		value[21] = '\0';
		return *this;
	}
	Number& Number::SetByChar(char *ByChar) { // сеттим пр€мой код из чара, перегон€€ его сначала в int, а потом действу€ как в SetByLong
		int len=strlen(ByChar);
		int number=0, k = 0;
		int i = 0;
		if (ByChar[0] == '-') {
			i = 1;
		}
		for (i; i < len; i++) {
			if (isdigit(ByChar[i]-'0')) {
				throw std::logic_error("Incorrect string!");
			}
		}
		if (ByChar[0] == '-') {
			value[0] = 1 + '0';
			k = 1;
		}
		else {
			value[0] = 0 + '0';
		}
		i = 1;
		for (int j = len; j > 0+k; j--) {
			number = number + (i * (ByChar[j-1] - '0'));
			i = i * 10;
		}
		for (int i = 20; i > 0; i--) {
			value[i] = (number % 2) + '0';
			number = number / 2;
		}
		value[21] = '\0';
		return *this;
	}

	const char *Number::GetChar() {
		int result = 0;
		int j = 0;
			for (int i = 20; i > 0; i--) {
				result = result + ((value[i] - '0') * pow(2, j));
				j++;
			}
			if (value[0] == '1')
				result = result * (-1);
		std::cout << "Straight code for " << result << " is" << std::endl;
		return value;
	}


	AdditionalCodeValue MakeAdditionalFromStraight(const char* array, struct AdditionalCodeValue Code) {

		if (array[0] == '0') {
			for (int i = 0; i < 21; i++) {
				Code.Additional[i] = array[i];
			}
		}
		if (array[0] == '1') {
			Code.Additional[0] = '1';
			for (int i = 1; i < 21; i++) { // мен€ем цифры кроме знака
				if (array[i] == '0')
					Code.Additional[i] = '1';
				if (array[i] == '1') {
					Code.Additional[i] = '0';
				}
			}
			for (int i = 21; i > 0; i--) {
				if (Code.Additional[i] == '0') { // до первого нул€
					Code.Additional[i] = '1';
					break;
				}
				if (Code.Additional[i] == '1') {
					Code.Additional[i] = '0';
				}
			}
		}
		Code.Additional[21] = '\0';
		return Code;
	}


	 AdditionalCodeValue Number::AdditionalCode() {
		struct AdditionalCodeValue Code = {};
		int result = 0;
		int j = 0;
		Code = MakeAdditionalFromStraight(value, Code);
		if (Code.Additional[0] != '1') {
			for (int i = 20; i > 0; i--) {
				result = result + ((Code.Additional[i] - '0') * pow(2, j));
				j++;
			}
		}
		else if (Code.Additional[0] == '1') {
			result = -1;
			for (int i = 20; i > 0; i--) {
				if (Code.Additional[i] == '0') {
					result = result - (1 * pow(2, j));
				}
				j++;
			}
		}
		std::cout <<"Additional code for "<< result << " is "<<std::endl;
		return Code;
	}

	int CountDigits(long i) {
		int k = 0;
		if (i < 0)
			i = i * -1;
		while (i>0){
			i = i / 10;
			k = k++;
		}
		return k;
	}

	int Number::Addition(long operatnum) { // сумма и разность.
		struct AdditionalCodeValue MyCode = {};
		struct AdditionalCodeValue OperationCode = {};
		struct AdditionalCodeValue SumCode = {};
		char helper[22];
		int result = 0;
		int j = 0;
		int k = 0;
		if (CountDigits(operatnum) > 7)
			throw std::logic_error("Too much digits");

		long number = operatnum;
		if (operatnum < 0) {
			helper[0] = '1';
			number = operatnum * (-1);
		}
		else helper[0] = '0';
		for (int i = 20; i > 0; i--) {
			helper[i] = (number % 2) + '0';
			number = number / 2;
		}
		helper[21] = '\0';
		MyCode = MakeAdditionalFromStraight(value, MyCode);
		OperationCode = MakeAdditionalFromStraight(helper, OperationCode);
		SumCode = MakeAdditionalFromStraight(value, SumCode);


		for (int i = 21; i > -1; i--) {
			if (MyCode.Additional[i] == '0' && OperationCode.Additional[i] == '0' && k == 0) {
				SumCode.Additional[i] = '0';
			}
			else if (MyCode.Additional[i] =='0' && OperationCode.Additional[i] == '0' && k != 0) {
				SumCode.Additional[i] = '1';
				k--;
			}
			else if (MyCode.Additional[i] =='1' && OperationCode.Additional[i] == '1' && k == 0) {
				SumCode.Additional[i] = '0';
				k++;
			}
			else if (MyCode.Additional[i] == '1' && OperationCode.Additional[i] == '1' && k != 0) {
				SumCode.Additional[i] = '1';
			}
			else if (MyCode.Additional[i] == '1' && OperationCode.Additional[i] == '0' && k == 0) {
				SumCode.Additional[i] = '1';
			}
			else if (MyCode.Additional[i] == '1' && OperationCode.Additional[i] == '0' && k != 0) {
				SumCode.Additional[i] = '0';
			}
			else if (MyCode.Additional[i] == '0' && OperationCode.Additional[i] == '1' && k == 0) {
				SumCode.Additional[i] = '1';
			}
			else if (MyCode.Additional[i] == '1' && OperationCode.Additional[i] == '0' && k != 0) {
				SumCode.Additional[i] = '0';	
			}
		}
		if (SumCode.Additional[0] != '1') {
			for (int i = 20; i > 0; i--) {
				result = result + ((SumCode.Additional[i] - '0') * pow(2, j));
				j++;
			}
		}
		else if (SumCode.Additional[0] == '1') {
			result = -1;
			for (int i = 20; i > 0; i--) {
				if (SumCode.Additional[i] == '0') {
					result = result - (1 * pow(2, j));
				}
				j++;
			}
		}
		return result;
	}


	int Number::Multiplication() {
		char helper[22];
		char superhelper[22];
		char res[22];
		int k = 0;
		for (int i = 0; i < 21; i++) {
			res[i] = '0';
			helper[i] = '0';
			superhelper[i] = '0';
		}
		res[21] = '\0';
		helper[21] = '\0';
		superhelper[21] = '\0';


		for (int i = 20; i > 3; i--) {
			helper[i - 1] = value[i];
			superhelper[i - 3] = value[i];
		}
		for (int i = 0; i < 21; i++) {
			res[i] = '0';
		}
		for (int i = 21; i > -1; i--) {
			if (helper[i] == '0' && superhelper[i] == '0' && k == 0) {
				res[i] = '0';
			}
			else if (helper[i] == '0' && superhelper[i] == '0' && k != 0) {
				res[i] = '1';
				k--;
			}
			else if (helper[i] == '1' && superhelper[i] == '1' && k == 0) {
				res[i] = '0';
				k++;
			}
			else if (helper[i] == '1' && superhelper[i] == '1' && k != 0) {
				res[i] = '1';
			}
			else if (helper[i] == '1' && superhelper[i] == '0' && k == 0) {
				res[i] = '1';
			}
			else if (helper[i] == '1' && superhelper[i] == '0' && k != 0) {
				res[i] = '0';
			}
			else if (helper[i] == '0' && superhelper[i] == '1' && k == 0) {
				res[i] = '1';
			}
			else if (helper[i] == '1' && superhelper[i] == '0' && k != 0) {
				res[i] = '0';
			}
		}
		int result = 0;
		int j = 0;
		for (int i = 20; i > 0; i--) {
			result = result + ((res[i] - '0') * pow(2, j));
			j++;
		}
		if (value[0] == '1')
			result = result * (-1);
		return result;
	}
}

