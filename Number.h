#pragma once

#ifndef number_h
#define number_h


#endif


namespace Prog3 {

    struct AdditionalCodeValue {
        char Additional[22];
    };
    int CountDigits(long i);

    class Number {
    private:
        char value[22];
        


    public:
        // Constructors
        Number() {
            for (int i = 0; i < 21; i++) {
                value[i] = '0';
        }
            value[21] = '\0';
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