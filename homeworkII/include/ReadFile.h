/**
*
* @author Sude Özkanoğlu - sude.ozkanoglu@ogr.sakarya.edu.tr
* @since 21 Nisan 2024
* <p>
* Doğru bir şekilde dosyadan okuma yapılabilmesi ve program içerisinde gerçekleşecek işlemlerin doğru bir şekilde devam edebilmesi için gerekli metot ve izlerinin oluşturulduğu başlık dosyası.
* </p>
*/

#ifndef READFILE_H
#define READFILE_H

#include "stdlib.h"
#include "stdio.h"
#include "string.h"

struct READFILE
{
    int*(*read_File)(struct READFILE*, int);
    int(*count_Numbers)(struct READFILE*);
    int(*count_Lines)(struct READFILE*);
    void(*yokEdici_RF)(struct READFILE*);
};typedef struct READFILE* ReadFile;


ReadFile ReadFileOlustur(); 
int* read_File(const ReadFile, int); 
int count_Numbers(const ReadFile);
int count_Lines(const ReadFile);
void yokEdici_RF(const ReadFile); 

#endif
