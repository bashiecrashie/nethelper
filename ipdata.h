typedef struct BinData {
    //Переменная для хранения размера двоичной октеты
    int BinaryOctetSize;
    //Массивы для хранения IP в двоичной системе счисления
    int BinaryIPFirstOctet[8], BinaryIPSecondOctet[8], BinaryIPThirdOctet[8], BinaryIPFourthOctet[8];    
    //Массивы для хранения маски в двоичной системе счисления
    int BinaryMaskFirstOctet[8], BinaryMaskSecondOctet[8], BinaryMaskThirdOctet[8], BinaryMaskFourthOctet[8];
    //Массивы для хранения содержимого октет сетевого адреса в двоичном виде
    int BinaryNetworkAddressFirstOctet[8], BinaryNetworkAddressSecondOctet[8], BinaryNetworkAddressThirdOctet[8], BinaryNetworkAddressFourthOctet[8];
} BinData;

//Массив для хранения сетевого адреса в десятичном виде
static int NetworkDecimalIP[4];
typedef struct DecData {
    int DecimalOctetSize;
    int OctetNumber;
    int DecimalIP[4];
    int DecimalMask[4];
    //Массивы с сетевыми адресами 
    int Network_1[4];
    int Network_2[4]; 
    int Network_3[4];
    int Network_4[4];
} DecData;
