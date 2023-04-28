/*Основной файл*/
#include<stdio.h>
#include<stdlib.h>
#include"calcfuncs.h"//файл с объявлением функций для расчётов
#include"ipfuncs.h"//файл с объявлением функций для определения типа ip, получения адреса сети и т.п.

int main(int argc, char *argv[])
{

    //Для красоты :-)
    char *logo = "\n"                                                      
" _____ _____ _____ _____ _____ __    _____ _____ _____ \n"
"|   | |   __|_   _|  |  |   __|  |  |  _  |   __| __  |\n"
"| | | |   __| | | |     |   __|  |__|   __|   __|    -|\n"
"|_|___|_____| |_| |__|__|_____|_____|__|  |_____|__|__|\n"
"                                            Version 0.2\n";

    printf("%s", logo);                                                   

    //Размеры для массивов с данными
    const int BinaryOctetSize = 8, DecimalOctetSize = 3, OctetNumber = 4, MaxPrefixSize = 32;

    //Числовые массивы для IP в двоичном представлении
    int BinaryIPFirstOctet[BinaryOctetSize], BinaryIPSecondOctet[BinaryOctetSize], BinaryIPThirdOctet[BinaryOctetSize], BinaryIPFourthOctet[BinaryOctetSize];

    //Числовые массивы для маски в двоичном представлении
    int BinaryMaskFirstOctet[BinaryOctetSize], BinaryMaskSecondOctet[BinaryOctetSize], BinaryMaskThirdOctet[BinaryOctetSize], BinaryMaskFourthOctet[BinaryOctetSize], BinaryPrefix[MaxPrefixSize];

    //Числовык массивы для IP и маски в десятичном представлении
    int NetworkDecimalIP[OctetNumber], DecimalIP[OctetNumber], DecimalMask[OctetNumber];

    //Переменная для сетевого префикса
    int prefix = 0;

    //Переменные-счётчики
    int counter = 0, PrefixCheck = 0;

    //Переменные-указатели
    int *OutPointer;

    //Проверка количества аргументов
    if(argc != 2){ printf("Неверный формат. Пример: 123.123.123.123/12\n"); return 1; }

    //Занесение данных в массив и переменную
    sscanf(argv[1], "%d.%d.%d.%d/%d", &DecimalIP[0], &DecimalIP[1], &DecimalIP[2], &DecimalIP[3], &prefix);

    //Проверка правильности адреса
    for(counter = 0; counter < 3; ++counter)

        if(DecimalIP[counter] > 254){ printf("Октета в адресе не может быть больше, чем 254.\n"); break; return 1; }

    //Проверка правильности префикса сети
    if(prefix > 32){ printf("Префикс сети не может быть больше, чем 32\n"); return 1; }

    //Вывод данных
    printf("IP адрес в десятичном виде: %d.%d.%d.%d\n", DecimalIP[0], DecimalIP[1], DecimalIP[2], DecimalIP[3]);
    printf("Префикс сети в десятичном виде: %d\n", prefix);

    //Заполняем первую октету IP
    OutPointer = dectobin(DecimalIP[0]);
    for(counter = 0; counter < BinaryOctetSize; ++counter)
        BinaryIPFirstOctet[counter] = OutPointer[counter];

    //Заполняем вторую октету IP
    OutPointer = dectobin(DecimalIP[1]);
    for(counter = 0; counter < BinaryOctetSize; ++counter)
        BinaryIPSecondOctet[counter] = OutPointer[counter];

    //Заполняем третью IP
    OutPointer = dectobin(DecimalIP[2]);
    for(counter = 0; counter < BinaryOctetSize; ++counter)
        BinaryIPThirdOctet[counter] = OutPointer[counter];

    //Заполняем четвёртую октету IP
    OutPointer = dectobin(DecimalIP[3]);
    for(counter = 0; counter < BinaryOctetSize; ++counter)
        BinaryIPFourthOctet[counter] = OutPointer[counter];

    //Выводим содержание октет
    printf("IP в двоичном представлении: ");
    for(counter = 0; counter < BinaryOctetSize; ++counter)
        printf("%d", BinaryIPFirstOctet[counter]);
    printf(".");
    for(counter = 0; counter < BinaryOctetSize; ++counter)
        printf("%d", BinaryIPSecondOctet[counter]);
    printf(".");
    for(counter = 0; counter < BinaryOctetSize; ++counter)
        printf("%d", BinaryIPThirdOctet[counter]);
    printf(".");
    for(counter = 0; counter < BinaryOctetSize; ++counter)
        printf("%d", BinaryIPFourthOctet[counter]);
    printf("\n");

    //Инициализируем нулями массивы для маски
    for(counter = 0; counter < BinaryOctetSize; ++counter)
        BinaryMaskFirstOctet[counter] = 0; BinaryMaskSecondOctet[counter] = 0; BinaryMaskThirdOctet[counter] = 0; BinaryMaskFourthOctet[counter] = 0;

    //Заполняем первую октету для маски в двоичном виде
    for(counter = 0; counter < BinaryOctetSize; ++counter)
    {
        if(PrefixCheck < prefix)
        {
            BinaryMaskFirstOctet[counter] = 1;
            ++PrefixCheck;
        }else if(PrefixCheck == prefix)
            BinaryMaskFirstOctet[counter] = 0;
    }
    //Заполняем вторую октету для маски в двоичном виде
    for(counter = 0; counter < BinaryOctetSize; ++counter)
    {
        if(PrefixCheck < prefix)
        {
            BinaryMaskSecondOctet[counter] = 1;
            ++PrefixCheck;
        }else if(PrefixCheck == prefix)
            BinaryMaskSecondOctet[counter] = 0;
    }
    //Заполняем третью октету для маски в двоичном виде
    for(counter = 0; counter < BinaryOctetSize; ++counter)
    {
        if(PrefixCheck < prefix)
        {
            BinaryMaskThirdOctet[counter] = 1;
            ++PrefixCheck;
        }else if(PrefixCheck == prefix)
            BinaryMaskThirdOctet[counter] = 0;
    }
    //Заполняем четвёртую октету для маски в двоичном виде
    for(counter = 0; counter < BinaryOctetSize; ++counter)
    {
        if(PrefixCheck < prefix)
        {
            BinaryMaskFourthOctet[counter] = 1;
            ++PrefixCheck;
        }else if(PrefixCheck == prefix)
            BinaryMaskFourthOctet[counter] = 0;
    }

    //Выводим маску в двоичном виде
    printf("Префикс сети в двоичном представлении:");
    for(counter = 0; counter < BinaryOctetSize; ++counter)
        printf("%d", BinaryMaskFirstOctet[counter]);
    printf(".");
    for(counter = 0; counter < BinaryOctetSize; ++counter)
        printf("%d", BinaryMaskSecondOctet[counter]);
    printf(".");
    for(counter = 0; counter < BinaryOctetSize; ++counter)
        printf("%d", BinaryMaskThirdOctet[counter]);
    printf(".");
    for(counter = 0; counter < BinaryOctetSize; ++counter)
        printf("%d", BinaryMaskFourthOctet[counter]);
    printf("\n");

    //Заполняем массив преобразованной в десятичный вид маски
    DecimalMask[0] = bintodec(BinaryMaskFirstOctet);
    DecimalMask[1] = bintodec(BinaryMaskSecondOctet);
    DecimalMask[2] = bintodec(BinaryMaskThirdOctet);
    DecimalMask[3] = bintodec(BinaryMaskFourthOctet);

    //Выводим маску в десятичном виде
    printf("Маска сети: %d.%d.%d.%d\n", DecimalMask[0], DecimalMask[1], DecimalMask[2], DecimalMask[3]);

    //Определяем тип IP
    iptype(DecimalIP[0]);

    //Формируем адрес сети
    OutPointer = networkaddress(BinaryIPFirstOctet, BinaryIPSecondOctet, BinaryIPThirdOctet, BinaryIPFourthOctet, BinaryMaskFirstOctet, BinaryMaskSecondOctet, BinaryMaskThirdOctet, BinaryMaskFourthOctet);

    //Заполняем массив адресом сети
    for(counter = 0; counter < OctetNumber; ++counter)
        NetworkDecimalIP[counter] = OutPointer[counter];

    //Выводим адрес сети
    printf("Адрес сети в десятичном представлении: %d.%d.%d.%d\n", NetworkDecimalIP[0], NetworkDecimalIP[1], NetworkDecimalIP[2], NetworkDecimalIP[3]);

    //Проверка на предмет широковещательного адреса
    broadcastaddr(DecimalIP[3]);

    //Проверка на принадлежность к одной из сетей
    networkbelong(NetworkDecimalIP);


}