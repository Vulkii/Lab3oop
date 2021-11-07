#pragma once

#ifndef number_h
#define number_h


#endif

#define MAXSIZE 22

namespace Prog3 {

    struct AdditionalCodeValue {
        char Additional[MAXSIZE];
    };
    int CountDigits(long i);

    class Number {
    private:
        char value[MAXSIZE];
        


    public:
        // Constructors
        Number() { // empty const
            for (int i = 0; i < MAXSIZE-1; i++) {
                value[i] = '0';
        }
            value[MAXSIZE-1] = '\0';
        }; // empty constructor
        Number(long number) { // const by long
            if (CountDigits(number) > 7)
                throw std::logic_error("Too much digits");
            if (number < 0) {
                value[0] = '1';
                number = number * (-1);
            }
            else value[0] = '0';
            for (int i = MAXSIZE - 2; i > 0; i--) {
                value[i] = (number % 2) + '0';
                number = number / 2;
            }
            value[MAXSIZE - 1] = '\0';
        }
        Number(char* ByChar) { // const by Char
            int len = strlen(ByChar);
            if (len > 7) {
                throw std::logic_error("Incorrect string!");
            }
            for (int i = 0; i < MAXSIZE - 1; i++) {
                value[i] = '0';
            }
            int number = 0, k = 0;
            int i = 0;
            if (ByChar[0] == '-') {
                i = 1;
            }
            if (ByChar[0] == '-') {
                value[0] = '1';
                k = 1;
            }
            else {
                value[0] = '0';
            }
            i = 1;
            for (int j = len; j > 0 + k; j--) {
                number = number + (i * (ByChar[j - 1] - '0'));
                i = i * 10;
            }
            for (int i = MAXSIZE - 2; i > 0; i--) {
                value[i] = (number % 2) + '0';
                number = number / 2;
            }
            value[MAXSIZE - 1] = '\0';
        }

        // Setters
        Number& SetByLong(long ByLong);
        Number& SetByChar(char* ByChar);

        // Getters
        const char *GetChar(); 

        // Methods
        AdditionalCodeValue AdditionalCode();
        int Addition(long operatnum); 
        int Multiplication();

        friend Number operator +(const Number &r,const Number &l);
        AdditionalCodeValue & operator ~();

        // Destructor
        ~Number() {
            std::cout << "Destructor called for Number" << std::endl;
        }

    };

}


#include "Number.cpp"