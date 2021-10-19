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
        Number() {
            for (int i = 0; i < MAXSIZE-1; i++) {
                value[i] = '0';
        }
            value[MAXSIZE-1] = '\0';
        }; // empty constructor

        // Setters
        Number& SetByLong(long ByLong);
        Number& SetByChar(char* ByChar);

        // Getters
        const char *GetChar();

        // Methods
        AdditionalCodeValue AdditionalCode();
        int Addition(long operatnum);
        int Multiplication();

        int & operator +(const Number &r);

        // Destructor
        ~Number() {
            std::cout << "Destructor called for Number" << std::endl;
        }

    };

}


#include "Number.cpp"