/*Основной файл*/
#include<stdio.h>
#include<stdlib.h>
#include"calcfuncs.h"//файл с объявлением функций для расчётов
#include"ipfuncs.h"//файл с объявлением функций для определения типа ip, получения адреса сети и т.п.
#include"ipdata.h"

int main(int argc, char *argv[])
{
    //Для красоты :-)
    char *logo = "\n"                                                      
" _____ _____ _____ _____ _____ __    _____ _____ _____ \n"
"|   | |   __|_   _|  |  |   __|  |  |  _  |   __| __  |\n"
"| | | |   __| | | |     |   __|  |__|   __|   __|    -|\n"
"|_|___|_____| |_| |__|__|_____|_____|__|  |_____|__|__|\n"
"                                            Version 0.3\n";

    printf("%s", logo);                                                   
    //Переменная структуры с двоиным представлением адресов и масок
    BinData bin;
    //Переменная структуры с десятичным представлением адресов и масок
    DecData dec;
    //Присваиваем полям структуры значения
    bin.BinaryOctetSize = 8;
    dec.OctetNumber = 4;
    //Переменная для сетевого префикса
    int prefix = 0;
    //Переменные-счётчики
    int counter = 0, PrefixCheck = 0;
    //Переменные-указатели
    int *OutPointer;
    //Проверка количества аргументов
    if(argc != 2){ printf("Неверный формат. Пример: 123.123.123.123/12\n"); return 1; }
    //Занесение данных в массив и переменную
    sscanf(argv[1], "%d.%d.%d.%d/%d", &dec.DecimalIP[0], &dec.DecimalIP[1], &dec.DecimalIP[2], &dec.DecimalIP[3], &prefix);
    //Проверка правильности адреса
    for(counter = 0; counter < 3; ++counter)
        if(dec.DecimalIP[counter] > 254){ printf("Октета в адресе не может быть больше, чем 254.\n"); break; return 1; }
    //Проверка правильности префикса сети
    if(prefix > 32){ printf("Префикс сети не может быть больше, чем 32\n"); return 1; }
    //Вывод данных
    printf("IP адрес в десятичном виде: %d.%d.%d.%d\n", dec.DecimalIP[0], dec.DecimalIP[1], dec.DecimalIP[2], dec.DecimalIP[3]);
    printf("Префикс сети в десятичном виде: %d\n", prefix);
    //Заполняем первую октету IP
    OutPointer = dectobin(dec.DecimalIP[0]);
    for(counter = 0; counter < bin.BinaryOctetSize; ++counter)
        bin.BinaryIPFirstOctet[counter] = OutPointer[counter];
    //Заполняем вторую октету IP
    OutPointer = dectobin(dec.DecimalIP[1]);
    for(counter = 0; counter < bin.BinaryOctetSize; ++counter)
        bin.BinaryIPSecondOctet[counter] = OutPointer[counter];
    //Заполняем третью IP
    OutPointer = dectobin(dec.DecimalIP[2]);
    for(counter = 0; counter < bin.BinaryOctetSize; ++counter)
        bin.BinaryIPThirdOctet[counter] = OutPointer[counter];
    //Заполняем четвёртую октету IP
    OutPointer = dectobin(dec.DecimalIP[3]);
    for(counter = 0; counter < bin.BinaryOctetSize; ++counter)
        bin.BinaryIPFourthOctet[counter] = OutPointer[counter];
    //Выводим содержание октет
    printf("IP в двоичном представлении: ");
    for(counter = 0; counter < bin.BinaryOctetSize; ++counter)
        printf("%d", bin.BinaryIPFirstOctet[counter]);
    printf(".");
    for(counter = 0; counter < bin.BinaryOctetSize; ++counter)
        printf("%d", bin.BinaryIPSecondOctet[counter]);
    printf(".");
    for(counter = 0; counter < bin.BinaryOctetSize; ++counter)
        printf("%d", bin.BinaryIPThirdOctet[counter]);
    printf(".");
    for(counter = 0; counter < bin.BinaryOctetSize; ++counter)
        printf("%d", bin.BinaryIPFourthOctet[counter]);
    printf("\n");
    //Инициализируем нулями массивы для маски
    for(counter = 0; counter < bin.BinaryOctetSize; ++counter)
        bin.BinaryMaskFirstOctet[counter] = 0; bin.BinaryMaskSecondOctet[counter] = 0; bin.BinaryMaskThirdOctet[counter] = 0; bin.BinaryMaskFourthOctet[counter] = 0;
    //Заполняем первую октету для маски в двоичном виде
    for(counter = 0; counter < bin.BinaryOctetSize; ++counter)
    {
        if(PrefixCheck < prefix)
        {
            bin.BinaryMaskFirstOctet[counter] = 1;
            ++PrefixCheck;
        }else if(PrefixCheck == prefix)
            bin.BinaryMaskFirstOctet[counter] = 0;
    }
    //Заполняем вторую октету для маски в двоичном виде
    for(counter = 0; counter < bin.BinaryOctetSize; ++counter)
    {
        if(PrefixCheck < prefix)
        {
            bin.BinaryMaskSecondOctet[counter] = 1;
            ++PrefixCheck;
        }else if(PrefixCheck == prefix)
            bin.BinaryMaskSecondOctet[counter] = 0;
    }
    //Заполняем третью октету для маски в двоичном виде
    for(counter = 0; counter < bin.BinaryOctetSize; ++counter)
    {
        if(PrefixCheck < prefix)
        {
            bin.BinaryMaskThirdOctet[counter] = 1;
            ++PrefixCheck;
        }else if(PrefixCheck == prefix)
            bin.BinaryMaskThirdOctet[counter] = 0;
    }
    //Заполняем четвёртую октету для маски в двоичном виде
    for(counter = 0; counter < bin.BinaryOctetSize; ++counter)
    {
        if(PrefixCheck < prefix)
        {
            bin.BinaryMaskFourthOctet[counter] = 1;
            ++PrefixCheck;
        }else if(PrefixCheck == prefix)
            bin.BinaryMaskFourthOctet[counter] = 0;
    }
    //Выводим маску в двоичном виде
    printf("Префикс сети в двоичном представлении:");
    for(counter = 0; counter < bin.BinaryOctetSize; ++counter)
        printf("%d", bin.BinaryMaskFirstOctet[counter]);
    printf(".");
    for(counter = 0; counter < bin.BinaryOctetSize; ++counter)
        printf("%d", bin.BinaryMaskSecondOctet[counter]);
    printf(".");
    for(counter = 0; counter < bin.BinaryOctetSize; ++counter)
        printf("%d", bin.BinaryMaskThirdOctet[counter]);
    printf(".");
    for(counter = 0; counter < bin.BinaryOctetSize; ++counter)
        printf("%d", bin.BinaryMaskFourthOctet[counter]);
    printf("\n");
    //Заполняем массив преобразованной в десятичный вид маски
    dec.DecimalMask[0] = bintodec(bin.BinaryMaskFirstOctet);
    dec.DecimalMask[1] = bintodec(bin.BinaryMaskSecondOctet);
    dec.DecimalMask[2] = bintodec(bin.BinaryMaskThirdOctet);
    dec.DecimalMask[3] = bintodec(bin.BinaryMaskFourthOctet);
    //Выводим маску в десятичном виде
    printf("Маска сети: %d.%d.%d.%d\n", dec.DecimalMask[0], dec.DecimalMask[1], dec.DecimalMask[2], dec.DecimalMask[3]);
    //Определяем тип IP
    iptype(dec.DecimalIP[0]);
    //Формируем адрес сети
    OutPointer = networkaddress(bin.BinaryIPFirstOctet, bin.BinaryIPSecondOctet, bin.BinaryIPThirdOctet, bin.BinaryIPFourthOctet, bin.BinaryMaskFirstOctet, bin.BinaryMaskSecondOctet, bin.BinaryMaskThirdOctet, bin.BinaryMaskFourthOctet);
    //Заполняем массив адресом сети
    for(counter = 0; counter < dec.OctetNumber; ++counter)
        NetworkDecimalIP[counter] = OutPointer[counter];
    //Выводим адрес сети
    printf("Адрес сети в десятичном представлении: %d.%d.%d.%d\n", NetworkDecimalIP[0], NetworkDecimalIP[1], NetworkDecimalIP[2], NetworkDecimalIP[3]);
    //Проверка на предмет широковещательного адреса
    broadcastaddr(dec.DecimalIP[3]);
    //Проверка на принадлежность к одной из сетей
    networkbelong(NetworkDecimalIP);
}