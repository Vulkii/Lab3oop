#pragma once


namespace Prog3 {


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
}