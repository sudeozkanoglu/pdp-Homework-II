/**
*
* @author Sude Özkanoğlu - sude.ozkanoglu@ogr.sakarya.edu.tr
* @since 21 Nisan 2024
* <p>
* Böcek sınıfından dolayısıyla Canli sınıfından alınan kalıtımla yapıcı, pireye ait görünüm ve yıkıcı metotların oluşturulması.
* </p>
*/

#include "Pire.h"

Pire PireOlustur(char* tur, int number, int x, int y)
{
    Pire this;
    this = (Pire)malloc(sizeof(struct PIRE));
    this->super = BocekOlustur(tur, number, x, y);
    this->super->super->gorunum = &gorunumPireTur;
    this->yokEdici_P = &yokEdici_P;
    return this;
}

char* gorunumPireTur(const Pire this)
{
	char *str = (char*)malloc(sizeof(char)*2);
    sprintf(str, "%s", this->super->super->tur);
    return str;
}

void yokEdici_P(const Pire this)
{
    if(this == NULL) return;
    if(this->super != NULL) 
        this->super->yokEdici_Bo(this->super);
    free(this);
}