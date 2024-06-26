/**
*
* @author Sude Özkanoğlu - sude.ozkanoglu@ogr.sakarya.edu.tr
* @since 21 Nisan 2024
* <p>
* Alt sınıflarda kalıtımın doğru bir şekilde sağlanabilmesi için gerekli değişkenlerin, metotların ve metot izleriyle birlikte Canli sınıfına ait yıkıcının oluşturulması.
* </p>
*/

#ifndef CANLI_H
#define CANLI_H

#include "stdio.h"
#include "stdlib.h"

struct CANLI
{
	char* tur;
    int number;
    int index_X;
    int index_Y;
	
    char*(*gorunum)(); //Soyut method
	void(*setCanliTur)(struct CANLI*, char*);
    void(*yokEdici_C)(struct CANLI*);
};
typedef struct CANLI* Canli;

Canli CanliOlustur(char*, int, int, int);
void setCanliTur(const Canli, char*);
void yokEdici_Canli(const Canli);

#endif