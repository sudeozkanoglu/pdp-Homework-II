/**
*
* @author Sude Özkanoğlu - sude.ozkanoglu@ogr.sakarya.edu.tr
* @since 21 Nisan 2024
* <p>
* Böcek sınıfından dolayısıyla Canli sınıfından alınan kalıtımla yapıcı, sineğe ait görünüm ve yıkıcı metotların oluşturulması.
* </p>
*/

#include "Sinek.h"

Sinek SinekOlustur(char* tur, int number, int x, int y)
{
    Sinek this;
    this = (Sinek)malloc(sizeof(struct SINEK));
    this->super = BocekOlustur(tur, number, x, y);
    this->super->super->gorunum = &gorunumSinekTur;
    this->yokEdici_S = &yokEdici_S;
    return this;
}

char* gorunumSinekTur(const Sinek this)
{
	char *str = (char*)malloc(sizeof(char)*2);
    sprintf(str, "%s", this->super->super->tur);
    return str;
}

void yokEdici_S(const Sinek this)
{
    if(this == NULL) return;
    if(this->super != NULL) 
        this->super->yokEdici_Bo(this->super);
    free(this);
}