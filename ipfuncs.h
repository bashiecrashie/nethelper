/*Заголовочный файл с объявлением функций для определения типа ip, получения адреса сети и т.п.*/
void iptype(int octet);//функция для проверки типа IP адреса
int *networkaddress(int BinaryIPFirstOctet[], int BinaryIPSecondOctet[], int BinaryIPThirdOctet[], int BinaryIPFourthOctet[], int BinaryMaskFirstOctet[], int BinaryMaskSecondOctet[], int BinaryMaskThirdOctet[], int BinaryMaskFourthOctet[]);// функция для получения сетевого адреса
void networkbelong(int DecimalNetworkIP[]);//функция для проверки на принадлежность к одной из сетей
void broadcastaddr(int octet);//функция для проверки октеты на содержание определённого значения
