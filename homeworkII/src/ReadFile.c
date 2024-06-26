/**
*
* @author Sude Özkanoğlu - sude.ozkanoglu@ogr.sakarya.edu.tr
* @since 21 Nisan 2024
* <p>
* Doğru bir şekilde dosyadan okuma yapılabilmesi ve program içerisinde gerçekleşecek işlemlerin doğru bir şekilde devam edebilmesi için gerekli metotların ve yapıcının gövdelerinin oluşturulması.
* </p>
*/

#include "ReadFile.h"

ReadFile ReadFileOlustur()
{
    ReadFile this;
    this = (ReadFile)malloc(sizeof(struct READFILE));
    this->read_File = &read_File;
    this->count_Numbers = &count_Numbers;
    this->count_Lines = &count_Lines;
	this->yokEdici_RF = &yokEdici_RF;
    return this;
}

//Dosya okuma ve array oluşturulma işleminin 1-99 dahil arasındaki sayıları alabilecek şekilde gerçekleştirilmesi.
int* read_File(const ReadFile this,int counter) {

    int c;
    char str[300];
    int i = 0;
    int index = 0;
    int num = 0;
    int* numbers = (int*) malloc(sizeof(int) * counter+1);

    FILE *file = fopen("Veri.txt", "r");
    if (file == NULL)
    {  
        printf("Dosya açılamadı\n");
		free(numbers);
        return 0; 
    }
    
    while ((c = fgetc(file)) != EOF)
    {  
        str[i++] = c;
        if(c == ' ' || c == '\n')
        {
            str[i] = '\0';
            num = atoi(str);
            if(num >= 1 && num <= 99)
            {
                numbers[index] = num;
                index++;
            }
            i = 0;
        }
    }
    num = atoi(str);
    if(num >= 1 && num <= 99)
        numbers[index] = num;
    fclose(file);
    return numbers;
}

//Veri.txt dosyasının kaç satırdan oluştuğunun bulunmasını sağlayan metot
int count_Lines(const ReadFile this)
{
    int c;
    int line = 0;

    FILE *file = fopen("Veri.txt", "r");
    if (file == NULL)
    {  
        printf("Dosya açılamadı\n");
        return 0;
    }

    while((c = fgetc(file)) != '\n')
    {
        if(c == ' ')
        {
            line++;
        }
    }
    fclose(file);
    return line;
}

//Veri.txt içerisinde kaç adet sayı olduğunu hesaplayan metot
int count_Numbers(const ReadFile this)
{
    int c;
    int counter = 0;
    char str[300];
    int i = 0;
    FILE *file = fopen("Veri.txt", "r");
    if (file == NULL) 
	{
        printf("Dosya açılamadı\n");
        return 0;
    }

    while(!feof(file))
    {
        c = fgetc(file);
        str[i++] = c;
        if(c == ' ' || c == '\n')
        {
            int num = atoi(str);
            if(num >= 1 && num <= 99)
            {
                counter++;
            }
            i = 0;
        }
    }
    counter++;
    fclose(file);
    return counter;
}

//Yok edici metot
void yokEdici_RF(const ReadFile this)
{
	if(this == NULL) 
		return;
	free(this);
} 
