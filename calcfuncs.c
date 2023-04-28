/*Файл с описанием функций для расчётов*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"calcfuncs.h"

int *dectobin(int decimal)
{

    //Счётчик
    int counter = 8;

    //Размер октеты
    const int OctetBinarySize = 8;

    //Массив для двоичного числа
    static int binary[8];

    //Перменные
    int remainder = 0, num = decimal;

    //Инициализируем массив нулями
    for(counter = 0; counter < OctetBinarySize; ++counter)
        binary[counter] = 0;

    if(decimal == 0)
        return binary;

    //Цикл перевода числа в двоичную систему счисления
    while(decimal != 0)
    {

        counter--;
        remainder = num % 2;
        decimal /= 2;
	    num /= 2;
        binary[counter] = remainder;

    }

    return binary;

}

int bintodec(int binary[])
{
    //Перменные-счётчики
    int counter = 0, degree = 7;

    //Результат
    int decimal = 0;

    //Цикл перевода в десятичгую систему счисления
    for(counter = 0; counter < 8; ++counter)
    {
        decimal += (binary[counter] * pow(2, degree));
        --degree;
    }

    return decimal;

}