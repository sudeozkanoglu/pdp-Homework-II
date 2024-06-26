/**
*
* @author Sude Özkanoğlu - sude.ozkanoglu@ogr.sakarya.edu.tr
* @since 21 Nisan 2024
* <p>
* Pire sınıfı içerisinde kullanılacak olan metotların ve izlerinin tanımlanmasıyla birlikte Böcek sınıfından dolayısıyla da Canli sınıfından kalıtım alabilmesi için kalıtım yapısının oluşturulması.
* </p>
*/

#ifndef PIRE_H
#define PIRE_H

#include "Bocek.h"

struct PIRE
{
    Bocek super;
    void(*yokEdici_P)(struct PIRE*);
};
typedef struct PIRE* Pire;

Pire PireOlustur(char*, int, int, int);
char* gorunumPireTur(const Pire);
void yokEdici_P(const Pire);

#endif