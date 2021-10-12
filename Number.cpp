

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
			value[0] = 1 + '0';
			number = ByLong * (-1);
		}
		else value[0] = 0 + '0';
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
		return value;
	}


	AdditionalCodeValue MakeAdditionalFromStraight(const char* array, struct AdditionalCodeValue Code) {

		if (array[0] == '0') {
			for (int i = 0; i < 21; i++) {
				Code.Additional[i] = array[i];
			}
		}
		if (array[0] == '1') {
			for (int i = 0; i < 21; i++) {
				if (array[i] == '0')
					Code.Additional[i] = '1';
				if (array[i] == '1') {
					Code.Additional[i] = '0';
				}
			}
			for (int i = 21; i > 0; i--) {
				if (Code.Additional[i] == '0') {
					Code.Additional[i] = '1';
					break;
				}
				if (Code.Additional[i] == '1') {
					Code.Additional[i] = '0';
				}
			}
		}
		Code.Additional[21] = '\0';
		int i = 0;
		do {
			std::cout << Code.Additional[i];
			i++;
		} while (i < 21);
		return Code;
	}


	void Number::AdditionalCode() const { // return the focal length
		struct AdditionalCodeValue Code = {};
		MakeAdditionalFromStraight(value, Code);
		int i = 0;
		std::cout << std::endl;
		do {
			std::cout << Code.Additional[i];
			i++;
		} while (i < 21);
		std::cout << std::endl;
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
}

