/**
*
* @author Sude Özkanoğlu - sude.ozkanoglu@ogr.sakarya.edu.tr
* @since 21 Nisan 2024
* <p>
* Dosya okuma ve gerekli işlemlerin yapılmasıyla ilgili nesnenin oluşturulmasıyla birlikte 
  habitat ve habitat içerisinde gerçekleşecek işlemler için de habitat nesnesinin oluşturulmasını içerir. Son olarak heap'ten alınan alanı geri teslim etmek için
  yıkıcı metotlar çağırılır.
* </p>
*/

#include "ReadFile.h"
#include "Habitat.h"

int main()
{
    ReadFile readFile = ReadFileOlustur();
	
	Habitat habitat = HabitatOlustur(); 
	habitat->canlilari_Olustur(habitat, readFile);

	yokEdici_RF(readFile);
	yokEdici_Habitat(habitat);
	
    return 0;
}
