/*Файл с описанием функций*/
#include<stdio.h>
#include<stdlib.h>
#include"calcfuncs.h"

void iptype(int octet)
{
    //Проверка содержимого числа
	if (octet == 10 || octet == 127 || octet == 169 || octet == 172 || octet == 192)
		printf("IP является частным.\n");
	else
		printf("IP является публиным.\n");

}


int *networkaddress(int BinaryIPFirstOctet[], int BinaryIPSecondOctet[], int BinaryIPThirdOctet[], int BinaryIPFourthOctet[], int BinaryMaskFirstOctet[], int BinaryMaskSecondOctet[], int BinaryMaskThirdOctet[], int BinaryMaskFourthOctet[])
{
    //Переменные для обозначения размеров двоичной октеты и числа октет
    const int BinaryOctetSize = 8, OctetNumber = 4;

    //Переменныые-счётчики
    int counter = 0, SecondCounter = 0;

    //Массивы для хранения содержимого октет сетевого адреса в двоичном виде
    int BinaryNetworkAddressFirstOctet[BinaryOctetSize], BinaryNetworkAddressSecondOctet[BinaryOctetSize], BinaryNetworkAddressThirdOctet[BinaryOctetSize], BinaryNetworkAddressFourthOctet[BinaryOctetSize];

    //Массив для хранения сетевого адреса в десятичном виде
    static int NetworkDecimalIP[4];

    //Циклы для заполнения октет сетевого адреса результатами операции-конъюнкции между IP и маской сети
    for(counter = 0; counter < BinaryOctetSize; ++counter)
        BinaryNetworkAddressFirstOctet[counter] = BinaryIPFirstOctet[counter] && BinaryMaskFirstOctet[counter];
    for(counter = 0; counter < BinaryOctetSize; ++counter)
        BinaryNetworkAddressSecondOctet[counter] = BinaryIPSecondOctet[counter] && BinaryMaskSecondOctet[counter];
    for(counter = 0; counter < BinaryOctetSize; ++counter)
        BinaryNetworkAddressThirdOctet[counter] = BinaryIPThirdOctet[counter] && BinaryMaskThirdOctet[counter];
    for(counter = 0; counter < BinaryOctetSize; ++counter)
        BinaryNetworkAddressFourthOctet[counter] = BinaryIPFourthOctet[counter] && BinaryMaskFourthOctet[counter];

    //Заполнение массива адреса сети результатами преобразования вида двоичного сетевого адреса в десятичный вид
    NetworkDecimalIP[0] = bintodec(BinaryNetworkAddressFirstOctet);
    NetworkDecimalIP[1] = bintodec(BinaryNetworkAddressSecondOctet);
    NetworkDecimalIP[2] = bintodec(BinaryNetworkAddressThirdOctet);
    NetworkDecimalIP[3] = bintodec(BinaryNetworkAddressFourthOctet);

    return NetworkDecimalIP;

}

void networkbelong(int DecimalNetworkIP[])
{

    //Переменные для обозначения числа октет
    const int OctetNumber = 4;

    //Переменные-счётчики
    int counter = 0, checks = 0;

    //Массивы с сетевыми адресами 
    int Network_1[4] = {192, 168, 10, 0}, Network_2[4] = {192, 168, 160, 0}, Network_3[4] = {141, 127, 0, 0}, Network_4[4] = {192, 0, 172, 0};

    //Циклы для проверки на принадлежность к одной из сети
    for(counter = 0; counter < OctetNumber; ++counter)
    {
        if(DecimalNetworkIP[counter] != Network_1[counter])
        {
            printf("%d.%d.%d.%d не относится к сети %d.%d.%d.%d\n", DecimalNetworkIP[0], DecimalNetworkIP[1], DecimalNetworkIP[2], DecimalNetworkIP[3], Network_1[0], Network_1[1], Network_1[2], Network_1[3]);
            break;
        }else
            ++checks;
    }
    if(checks == 4)
        printf("%d.%d.%d.%d относится к сети %d.%d.%d.%d\n", DecimalNetworkIP[0], DecimalNetworkIP[1], DecimalNetworkIP[2], DecimalNetworkIP[3], Network_1[0], Network_1[1], Network_1[2], Network_1[3]);

    checks = 0;
    for(counter = 0; counter < OctetNumber; ++counter)
    {
        if(DecimalNetworkIP[counter] != Network_2[counter])
        {
            printf("%d.%d.%d.%d не относится к сети %d.%d.%d.%d\n", DecimalNetworkIP[0], DecimalNetworkIP[1], DecimalNetworkIP[2], DecimalNetworkIP[3], Network_2[0], Network_2[1], Network_2[2], Network_2[3]);
            break;
        }else
            ++checks;
    }
    if(checks == 4)
        printf("%d.%d.%d.%d относится к сети %d.%d.%d.%d\n", DecimalNetworkIP[0], DecimalNetworkIP[1], DecimalNetworkIP[2], DecimalNetworkIP[3], Network_2[0], Network_2[1], Network_2[2], Network_2[3]);

    checks = 0;
    for(counter = 0; counter < OctetNumber; ++counter)
    {
        if(DecimalNetworkIP[counter] != Network_3[counter])
        {
            printf("%d.%d.%d.%d не относится к сети %d.%d.%d.%d\n", DecimalNetworkIP[0], DecimalNetworkIP[1], DecimalNetworkIP[2], DecimalNetworkIP[3], Network_3[0], Network_3[1], Network_3[2], Network_3[3]);
            break;
        }else
            ++checks;
    }
    if(checks == 4)
        printf("%d.%d.%d.%d относится к сети %d.%d.%d.%d\n", DecimalNetworkIP[0], DecimalNetworkIP[1], DecimalNetworkIP[2], DecimalNetworkIP[3], Network_3[0], Network_3[1], Network_3[2], Network_3[3]);

    checks = 0;
    for(counter = 0; counter < OctetNumber; ++counter)
    {
        if(DecimalNetworkIP[counter] != Network_4[counter])
        {
            printf("%d.%d.%d.%d не относится к сети %d.%d.%d.%d\n", DecimalNetworkIP[0], DecimalNetworkIP[1], DecimalNetworkIP[2], DecimalNetworkIP[3], Network_4[0], Network_4[1], Network_4[2], Network_4[3]);
            break;
        }else
            ++checks;
    }
    if(checks == 4)
        printf("%d.%d.%d.%d относится к сети %d.%d.%d.%d\n", DecimalNetworkIP[0], DecimalNetworkIP[1], DecimalNetworkIP[2], DecimalNetworkIP[3], Network_4[0], Network_4[1], Network_4[2], Network_4[3]);

}

void broadcastaddr(int octet)
{
    //Проверка на широковещательный адрес
    if(octet == 255)
        printf("Адрес является широковещательным.\n");

}