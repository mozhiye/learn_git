/*================================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：temp.cpp
*   创 建 者：MoZhiYe
*   创建日期：2019年03月31日 10:31:49
*   描    述：
*
================================================================*/
#include <iostream>

#define RATIO           (9.0 / 5.0)
#define ADD_SUBTRACT    (32)

void converTemperature(double tempin, char typein)
{
    double tempout;
    char typeout;

    std::cout << "DOUBLE";
    switch (typein)
    {
        case 'C':
        case 'c':
            tempout = tempin * RATIO + ADD_SUBTRACT;
            typeout = 'F';
            typein = 'C';
            break;
        case 'F':
        case 'f':
            tempout = (tempin - ADD_SUBTRACT) / RATIO;
            typeout = 'C';
            typein = 'F';
        default:
            typeout = 'E';
            break;
    }

    if (typeout != 'E') {
        std::cout << tempin << typein << " = " << tempout << typeout << "\n\n";
    } else {
        std::cout << "input Err!\n";
    }
}

void converTemperature(int tempin, char typein)
{
    int tempout;
    char typeout;

    std::cout << "INT";

    switch (typein)
    {
        case 'C':
        case 'c':
            tempout = tempin * RATIO + ADD_SUBTRACT;
            typeout = 'F';
            typein = 'C';
            break;
        case 'F':
        case 'f':
            tempout = (tempin - ADD_SUBTRACT) / RATIO;
            typeout = 'C';
            typein = 'F';
        default:
            typeout = 'E';
            break;
    }

    if (typeout != 'E') {
        std::cout << tempin << typein << " = " << tempout << typeout << "\n\n";
    } else {
        std::cout << "input Err!\n";
    }
}


int main(int argc, char argv[])
{
    std::cout << "Hellow, c++\n";
    double tempin;
    int tempin_int;
    char typein;
    std::cout << "input [xxx.x C] or [xxx.x F] temp:";
    std::cin >> tempin >> typein;
    std::cin.ignore(100, '\n');
    std::cout << "\n";
    converTemperature(tempin, typein);

    std::cout << "input [xx C] or [xx F] temp:";
    std::cin >> tempin_int >> typein;
    std::cin.ignore(100, '\n');
    std::cout << "\n" << std::endl;
    converTemperature(tempin_int, typein);

    std::cout << tempin << typein;

    return 0;
}
