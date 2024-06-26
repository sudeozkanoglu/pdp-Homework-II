/**
*
* @author Sude Özkanoğlu - sude.ozkanoglu@ogr.sakarya.edu.tr
* @since 21 Nisan 2024
* <p>
* Canli sınıfından alınan kalıtımla yapıcı, bitkiye ait görünüm ve yıkıcı metotların oluşturulması.
* </p>
*/
#include "Bitki.h"

Bitki BitkiOlustur(char* tur, int number, int x, int y)
{
    Bitki this;
    this = (Bitki)malloc(sizeof(struct BITKI));
    this->super = CanliOlustur(tur, number, x, y);
    this->super->gorunum = &gorunumBitkiTur;
    this->yokEdici_Bi = &yokEdici_Bi;
    return this;
}

char* gorunumBitkiTur(const Bitki this)
{
    char *str = (char*)malloc(sizeof(char)*2);
    sprintf(str, "%s", this->super->tur);
    return str;
}

void yokEdici_Bi(const Bitki this)
{
    if(this == NULL) return;
    if(this->super != NULL) 
        this->super->yokEdici_C(this->super);
    free(this);
}
