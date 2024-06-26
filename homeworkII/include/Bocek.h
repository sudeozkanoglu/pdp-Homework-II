/**
*
* @author Sude Özkanoğlu - sude.ozkanoglu@ogr.sakarya.edu.tr
* @since 21 Nisan 2024
* <p>
* Böcek sınıfı içerisinde kullanılacak olan metotların ve izlerinin tanımlanmasıyla birlikte Canli sınıfından kalıtım alabilmesi için kalıtım yapısının oluşturulması.
* </p>
*/

#ifndef BOCEK_H
#define BOCEK_H

#include "Canli.h"

struct BOCEK
{
    Canli super;
    void(*yokEdici_Bo)(struct BOCEK*);
    
};
typedef struct BOCEK* Bocek;

Bocek BocekOlustur(char*, int, int, int);
char* gorunumBocekTur(const Bocek);
void yokEdici_Bo(const Bocek);


#endif