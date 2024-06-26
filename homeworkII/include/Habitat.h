/**
*
* @author Sude Özkanoğlu - sude.ozkanoglu@ogr.sakarya.edu.tr
* @since 21 Nisan 2024
* <p>
* Canlıların oluşturulması, birbirini yeme, habitat durumu ve yok edici metotların ve izlerinin oluşturulduğu başlık dosyası.
* </p>
*/

#ifndef HABITAT_H
#define HABITAT_H

#include "ReadFile.h"
#include "Bitki.h"
#include "Bocek.h"
#include "Pire.h"
#include "Sinek.h"

struct HABITAT{
	void(*canlilari_Olustur)(struct HABITAT*, ReadFile);
	void(*birbirini_Yeme)(struct HABITAT*, Canli*, Bitki*, Bocek*, Sinek*, Pire*, int*, int, int);
	void(*habitatDurumu)(struct HABITAT*, Canli*, Bitki*, Bocek*, Sinek*, Pire*, int*, int, int);
	void(*yokEdiciAll)(struct HABITAT*, Canli*, Bitki*, Bocek*, Sinek*, Pire*, int*, int, int);
	void(*yokEdici_Habitat)(struct HABITAT*);
};
typedef struct HABITAT* Habitat;

Habitat HabitatOlustur();
void canlilari_Olustur(const Habitat, ReadFile);
void birbirini_Yeme(const Habitat, Canli*, Bitki*, Bocek*, Sinek*, Pire*, int*, int, int);
void habitatDurumu(const Habitat, Canli*, Bitki*, Bocek*, Sinek*, Pire*, int*, int, int);
void yokEdiciAll(const Habitat, Canli*, Bitki*, Bocek*, Sinek*, Pire*, int*, int, int);
void yokEdici_Habitat(const Habitat);

#endif