#pragma once

#ifndef number_h
#define number_h


#endif


namespace Prog3 {

    struct AdditionalCodeValue {
        char Additional[21];
    };


    template <typename Type>
    int get(Type& x, int min, const char* message)
    {
        while (true)
        {
            std::cout << message << std::endl;
            std::cin >> x;
            if (std::cin.eof() || std::cin.bad())
                return -1;
            else if (std::cin.fail() || x <= min)
            {
                std::cin.clear();
                std::cin.ignore(32767, '\n');
                std::cout << "Input error. Try again\n";
            }
            else
                return 0;
        }
    }

    template <class T>
    bool getNum(T& a)
    {
        while (!(std::cin >> a))
        {
            if (std::cin.eof())
                return false;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        return true;

    }

    int CountDigits(long i);

    class Number {
    private:
        char value[22];


    public:
        // Constructors
        Number() {
            for (int i = 0; i < 21; i++) {
                value[i] = 0+'0';
        }
            value[21] = '\0';
        }; // empty constructor

        // Setters
        Number& SetByLong(long ByLong);
        Number& SetByChar(char* ByChar);

        // Getters
        const char *GetChar();
        // Methods

        void AdditionalCode() const;


        // Destructor
        ~Number() {
            std::cout << "Destructor called for Number" << std::endl;
        }

    };

}


#include "Number.cpp"