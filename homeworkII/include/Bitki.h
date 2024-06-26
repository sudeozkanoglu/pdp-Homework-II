/**
*
* @author Sude Özkanoğlu - sude.ozkanoglu@ogr.sakarya.edu.tr
* @since 21 Nisan 2024
* <p>
* Bitki sınıfı içerisinde kullanılacak olan metotların ve izlerinin tanımlanmasıyla birlikte Canli sınıfından kalıtım alabilmesi için kalıtım yapısının oluşturulması.
* </p>
*/

#ifndef BITKI_H
#define BITKI_H

#include "Canli.h"

struct BITKI
{
    Canli super;
    void(*yokEdici_Bi)(struct BITKI*);
};
typedef struct BITKI* Bitki;

Bitki BitkiOlustur(char*, int, int, int);
char* gorunumBitkiTur(const Bitki);
void yokEdici_Bi(const Bitki);

#endif