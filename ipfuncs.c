/*Файл с описанием функций*/
#include<stdio.h>
#include<stdlib.h>
#include"calcfuncs.h"
#include"ipdata.h"

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
    //Переменная структуры с двоиным представлением адресов и масок
    BinData bin;
    //Переменная структуры с десятичным представлением адресов и масок
    DecData dec;
    //Присваиваем полю структуры значение
    bin.BinaryOctetSize = 8;
    //Переменныые-счётчики
    int counter = 0, SecondCounter = 0;
    //Циклы для заполнения октет сетевого адреса результатами операции-конъюнкции между IP и маской сети
    for(counter = 0; counter < bin.BinaryOctetSize; ++counter)
        bin.BinaryNetworkAddressFirstOctet[counter] = BinaryIPFirstOctet[counter] && BinaryMaskFirstOctet[counter];
    for(counter = 0; counter < bin.BinaryOctetSize; ++counter)
        bin.BinaryNetworkAddressSecondOctet[counter] = BinaryIPSecondOctet[counter] && BinaryMaskSecondOctet[counter];
    for(counter = 0; counter < bin.BinaryOctetSize; ++counter)
        bin.BinaryNetworkAddressThirdOctet[counter] = BinaryIPThirdOctet[counter] && BinaryMaskThirdOctet[counter];
    for(counter = 0; counter < bin.BinaryOctetSize; ++counter)
        bin.BinaryNetworkAddressFourthOctet[counter] = BinaryIPFourthOctet[counter] && BinaryMaskFourthOctet[counter];
    //Заполнение массива адреса сети результатами преобразования вида двоичного сетевого адреса в десятичный вид
    NetworkDecimalIP[0] = bintodec(bin.BinaryNetworkAddressFirstOctet);
    NetworkDecimalIP[1] = bintodec(bin.BinaryNetworkAddressSecondOctet);
    NetworkDecimalIP[2] = bintodec(bin.BinaryNetworkAddressThirdOctet);
    NetworkDecimalIP[3] = bintodec(bin.BinaryNetworkAddressFourthOctet);
    //Возвращаем значение
    return NetworkDecimalIP;
}

void networkbelong(int DecimalNetworkIP[])
{
    //Переменная структуры
    DecData dec;
    //Присваиваем полю структуры значение
    dec.OctetNumber = 4;
    //Переменные-счётчики
    int counter = 0, checks = 0;
    //Массивы с сетевыми адресами 
    dec.Network_1[0] = 192;
    dec.Network_1[1] =  168;
    dec.Network_1[2] = 10;
    dec.Network_1[3] =  0;

    dec.Network_2[0] = 192;
    dec.Network_2[1] = 168;
    dec.Network_2[2] =  160;
    dec.Network_2[3] = 0;

    dec.Network_3[0] = 141;
    dec.Network_3[1] = 127;
    dec.Network_3[2] = 0;
    dec.Network_3[3] = 0;

    dec.Network_4[0] = 192;
    dec.Network_4[1] = 0;
    dec.Network_4[2] = 172;
    dec.Network_4[3] = 0;

    //Циклы для проверки на принадлежность к одной из сети
    for(counter = 0; counter < dec.OctetNumber; ++counter)
    {
        if(DecimalNetworkIP[counter] != dec.Network_1[counter])
        {
            printf("%d.%d.%d.%d не относится к сети %d.%d.%d.%d\n", DecimalNetworkIP[0], DecimalNetworkIP[1], DecimalNetworkIP[2], DecimalNetworkIP[3], dec.Network_1[0], dec.Network_1[1], dec.Network_1[2], dec.Network_1[3]);
            break;
        }else
            ++checks;
    }
    if(checks == 4)
        printf("%d.%d.%d.%d относится к сети %d.%d.%d.%d\n", DecimalNetworkIP[0], DecimalNetworkIP[1], DecimalNetworkIP[2], DecimalNetworkIP[3], dec.Network_1[0], dec.Network_1[1], dec.Network_1[2], dec.Network_1[3]);

    checks = 0;
    for(counter = 0; counter < dec.OctetNumber; ++counter)
    {
        if(DecimalNetworkIP[counter] != dec.Network_2[counter])
        {
            printf("%d.%d.%d.%d не относится к сети %d.%d.%d.%d\n", DecimalNetworkIP[0], DecimalNetworkIP[1], DecimalNetworkIP[2], DecimalNetworkIP[3], dec.Network_2[0], dec.Network_2[1], dec.Network_2[2], dec.Network_2[3]);
            break;
        }else
            ++checks;
    }
    if(checks == 4)
        printf("%d.%d.%d.%d относится к сети %d.%d.%d.%d\n", DecimalNetworkIP[0], DecimalNetworkIP[1], DecimalNetworkIP[2], DecimalNetworkIP[3], dec.Network_2[0], dec.Network_2[1], dec.Network_2[2], dec.Network_2[3]);

    checks = 0;
    for(counter = 0; counter < dec.OctetNumber; ++counter)
    {
        if(DecimalNetworkIP[counter] != dec.Network_3[counter])
        {
            printf("%d.%d.%d.%d не относится к сети %d.%d.%d.%d\n", DecimalNetworkIP[0], DecimalNetworkIP[1], DecimalNetworkIP[2], DecimalNetworkIP[3], dec.Network_3[0], dec.Network_3[1], dec.Network_3[2], dec.Network_3[3]);
            break;
        }else
            ++checks;
    }
    if(checks == 4)
        printf("%d.%d.%d.%d относится к сети %d.%d.%d.%d\n", DecimalNetworkIP[0], DecimalNetworkIP[1], DecimalNetworkIP[2], DecimalNetworkIP[3], dec.Network_3[0], dec.Network_3[1], dec.Network_3[2], dec.Network_3[3]);

    checks = 0;
    for(counter = 0; counter < dec.OctetNumber; ++counter)
    {
        if(DecimalNetworkIP[counter] != dec.Network_4[counter])
        {
            printf("%d.%d.%d.%d не относится к сети %d.%d.%d.%d\n", DecimalNetworkIP[0], DecimalNetworkIP[1], DecimalNetworkIP[2], DecimalNetworkIP[3], dec.Network_4[0], dec.Network_4[1], dec.Network_4[2], dec.Network_4[3]);
            break;
        }else
            ++checks;
    }
    if(checks == 4)
        printf("%d.%d.%d.%d относится к сети %d.%d.%d.%d\n", DecimalNetworkIP[0], DecimalNetworkIP[1], DecimalNetworkIP[2], DecimalNetworkIP[3], dec.Network_4[0], dec.Network_4[1], dec.Network_4[2], dec.Network_4[3]);

}

void broadcastaddr(int octet)
{
    //Проверка на широковещательный адрес
    if(octet == 255)
        printf("Адрес является широковещательным.\n");
}