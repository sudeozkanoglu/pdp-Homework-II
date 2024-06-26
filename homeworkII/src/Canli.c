/**
*
* @author Sude Özkanoğlu - sude.ozkanoglu@ogr.sakarya.edu.tr
* @since 21 Nisan 2024
* <p>
* Kalıtımın doğru bir şekilde sağlanabilmesi ve Canli sınıfının doğru bir şekilde çalışması için gerekli yapıcı, tür değiştirme ve yıkıcı metodun içeriğinin tanımlanması.
* </p>
*/

#include "Canli.h"

Canli CanliOlustur(char* tur, int number, int index_X, int index_Y)
{
    Canli this;
    this = (Canli)malloc(sizeof(struct CANLI));
	this->tur = tur;
    this->index_X = index_X;
    this->index_Y = index_Y;
    this->number = number;
	this->setCanliTur = &setCanliTur;
    this->yokEdici_C = &yokEdici_Canli;
    return this;
}

void setCanliTur(const Canli this, char* tur)
{
	this->tur = tur;
}

void yokEdici_Canli(const Canli this)
{
    if(this == NULL) return;
    free(this);
}
