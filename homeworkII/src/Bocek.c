/**
*
* @author Sude Özkanoğlu - sude.ozkanoglu@ogr.sakarya.edu.tr
* @since 21 Nisan 2024
* <p>
* Canli sınıfından alınan kalıtımla yapıcı, böceğe ait görünüm ve yıkıcı metotların oluşturulması.
* </p>
*/

#include "Bocek.h"

Bocek BocekOlustur(char* tur, int number, int x, int y)
{
    Bocek this;
    this = (Bocek)malloc(sizeof(struct BOCEK));
    this->super = CanliOlustur(tur, number, x, y);
    this->super->gorunum = &gorunumBocekTur;
    this->yokEdici_Bo = &yokEdici_Bo;
    return this;
}

char* gorunumBocekTur(const Bocek this)
{
    char *str = (char*)malloc(sizeof(char)*2);	
    sprintf(str, "%s", this->super->tur);
    return str;
}

void yokEdici_Bo(const Bocek this)
{
    if(this == NULL) return;
    if(this->super != NULL) 
        this->super->yokEdici_C(this->super);
    free(this);
}