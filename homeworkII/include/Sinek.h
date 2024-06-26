/**
*
* @author Sude Özkanoğlu - sude.ozkanoglu@ogr.sakarya.edu.tr
* @since 21 Nisan 2024
* <p>
* Sinek sınıfı içerisinde kullanılacak olan metotların ve izlerinin tanımlanmasıyla birlikte Böcek sınıfından dolayısıyla da Canli sınıfından kalıtım alabilmesi için kalıtım yapısının oluşturulması.
* </p>
*/

#ifndef SINEK_H
#define SINEK_H

#include "Bocek.h"

struct SINEK
{
    Bocek super;
    void(*yokEdici_S)(struct SINEK*);
};
typedef struct SINEK* Sinek;

Sinek SinekOlustur(char*, int, int, int);
char* gorunumSinekTur(const Sinek);
void yokEdici_S(const Sinek);

#endif