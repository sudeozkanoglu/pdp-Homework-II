/**
*
* @author Sude Özkanoğlu - sude.ozkanoglu@ogr.sakarya.edu.tr
* @since 21 Nisan 2024
* <p>
* Yapıcı metot, canlı oluşturma, üstünlük kurallarına göre birbirini yeme, habitat durumunu gösterme ve yıkıcı metotların gövdelerinin oluşturulması.
* </p>
*/

#include "Habitat.h"

//Yapıcı metot
Habitat HabitatOlustur()
{
	Habitat this;
	this = (Habitat)malloc(sizeof(struct HABITAT));
	this->canlilari_Olustur = &canlilari_Olustur;
	this->birbirini_Yeme = &birbirini_Yeme;
	this->habitatDurumu = &habitatDurumu;
	this->yokEdiciAll = &yokEdiciAll;
	this->yokEdici_Habitat = &yokEdici_Habitat;
	return this;
}

//Canlıların doğru bir şekilde oluşturulması için readFile içerisinden gelen dönüş değeri ve oluşturulan elemanların kaybedilmemesi için Canli tipinde diziler ve sayı değerlerine göre oluşturulan for döngüsünün tanımlanması
void canlilari_Olustur(const Habitat this, ReadFile readFile)
{
	int counter = count_Numbers(readFile);
	int lines = count_Lines(readFile);
	int *numbers = read_File(readFile, counter);

	int index_X = 0;
	int index_Y = 0;
	
	Canli *canlilar = (Canli *)malloc(sizeof(Canli) * (counter + 1));
	Bitki *bitkiler = (Bitki *)malloc(sizeof(Bitki) * (counter + 1));
	Bocek *bocekler = (Bocek *)malloc(sizeof(Bocek) * (counter + 1));
	Sinek *sinekler = (Sinek *)malloc(sizeof(Sinek) * (counter + 1));
	Pire *pireler = (Pire *)malloc(sizeof(Pire) * (counter + 1));

	for (int i = 0; i < counter; i++)
	{
		if (numbers[i] >= 1 && numbers[i] <= 9)
		{
			Bitki bitki = BitkiOlustur("B\0", numbers[i], index_X, index_Y);
			bitkiler[i] = bitki;
			canlilar[i] = bitki->super;
			printf("%s ", canlilar[i]->gorunum(bitkiler[i]));
		}
		else if (numbers[i] >= 10 && numbers[i] <= 20)
		{
			Bocek bocek = BocekOlustur("C\0", numbers[i], index_X, index_Y);
			bocekler[i] = bocek;
			canlilar[i] = bocek->super;
			printf("%s ", canlilar[i]->gorunum(bocekler[i]));
		}
		else if (numbers[i] >= 21 && numbers[i] <= 50)
		{
			Sinek sinek = SinekOlustur("S\0", numbers[i], index_X, index_Y);
			sinekler[i] = sinek;
			bocekler[i] = sinek->super;
			canlilar[i] = sinek->super->super;
			printf("%s ", canlilar[i]->gorunum(sinekler[i]));
		}
		else
		{
			Pire pire = PireOlustur("P\0", numbers[i], index_X, index_Y);
			pireler[i] = pire;
			bocekler[i] = pire->super;
			canlilar[i] = pire->super->super;
			printf("%s ", canlilar[i]->gorunum(pireler[i]));
		}

		if (index_Y == lines)
		{
			printf("\n");
			index_X++;
			index_Y = 0;
		}
		else
		{
			index_Y++;
		}
	}
	
	int ch = getchar(); 
	this->birbirini_Yeme(this, canlilar, bitkiler, bocekler, sinekler, pireler, numbers, counter, lines);
}

//Birbirini yeme işlemi sonrası o an ki durumun doğru bir şekilde tespit edilmesi ve bitiş durumuna göre gorunum metodu sayesinde ekrana yazdırma işlemlerinin yapılması
void habitatDurumu(const Habitat this, Canli* canlilar, Bitki* bitkiler, Bocek* bocekler, Sinek* sinekler, Pire* pireler, int* numbers, int counter, int lines )
{
	printf("\n");
	int a = 0;
	int x = 0;
	int y = 0;
	int counter_x = 0;
	char sonuc = 'X';
	for (int i = 0; i < counter; i++)
	{
		if (numbers[i] >= 1 && numbers[i] <= 9)
		{
			printf("%s ", canlilar[i]->gorunum(bitkiler[i]));
			if(strcmp(canlilar[i]->tur, "B") == 0)
			{
				x = canlilar[i]->index_X;
				y = canlilar[i]->index_Y;
				sonuc = 'B';
			}
			else
				counter_x++;
		}
		else if (numbers[i] >= 10 && numbers[i] <= 20)
		{
			printf("%s ", canlilar[i]->gorunum(bocekler[i]));
			if(strcmp(canlilar[i]->tur, "C") == 0)
			{
				x = canlilar[i]->index_X;
				y = canlilar[i]->index_Y;
				sonuc = 'C';
			}
			else
				counter_x++;
		}
		else if (numbers[i] >= 21 && numbers[i] <= 50)
		{
			printf("%s ", canlilar[i]->gorunum(sinekler[i]));
			if(strcmp(canlilar[i]->tur, "S") == 0)
			{
				x = canlilar[i]->index_X;
				y = canlilar[i]->index_Y;
				sonuc = 'S';
			}
			else
				counter_x++;
		}
		else
		{
			printf("%s ", canlilar[i]->gorunum(pireler[i]));
			if(strcmp(canlilar[i]->tur, "P") == 0)
			{
				x = canlilar[i]->index_X;
				y = canlilar[i]->index_Y;
				sonuc = 'P';
			}
			else
				counter_x++;
		}
		if (a == lines)
		{
			printf("\n");
			a = 0;
		}
		else
		{
			a++;
		}
	}
	system("cls");
	if(counter_x == counter-1)
	{
		printf("Kazanan: %c : (%d,%d) \n", sonuc,x, y);
	}
}

//İç içe 2 adet for döngüsüyle birlikte her bir eleman için kendisinden sonraki elemanlar arasında kıyas işlemlerinin yapılması. Yapılan kıyas sonucunda (i) indexine sahip canli yeme işlemini gerçekleştirirse for döngüsü normal akışında devam eder.
//(j) indexine sahip canli yeme işlemini gerçekleştirirse yeni pivot eleman (j) indexindeki eleman olur ve for döngüsü güncellenerek işlemler devam eder.
void birbirini_Yeme(const Habitat this, Canli* canlilar, Bitki* bitkiler, Bocek* bocekler, Sinek* sinekler, Pire* pireler, int* numbers, int counter, int lines)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < counter; i++)
	{
		for (j = i; j < counter; j++)
		{
			if (strcmp(canlilar[i]->tur, "C") == 0)
			{
				if (strcmp(canlilar[j]->tur, "B") == 0)
				{
					canlilar[j]->setCanliTur(canlilar[j], "X");
					habitatDurumu(this, canlilar, bitkiler, bocekler, sinekler, pireler, numbers, counter, lines);
				}
				else if (strcmp(canlilar[j]->tur, "P") == 0)
				{
					canlilar[j]->setCanliTur(canlilar[j], "X");
					habitatDurumu(this, canlilar, bitkiler, bocekler, sinekler, pireler, numbers, counter, lines);
				}
				else if (strcmp(canlilar[j]->tur, "S") == 0)
				{
					canlilar[i]->setCanliTur(canlilar[i], "X");
					habitatDurumu(this, canlilar, bitkiler, bocekler, sinekler, pireler, numbers, counter, lines);
					i = j;
				}
				else
				{
					if (canlilar[i]->number >= canlilar[j]->number)
					{
						canlilar[j]->setCanliTur(canlilar[j], "X");
						habitatDurumu(this, canlilar, bitkiler, bocekler, sinekler, pireler, numbers, counter, lines);
					}
					else
					{
						canlilar[i]->setCanliTur(canlilar[i], "X");
						habitatDurumu(this, canlilar, bitkiler, bocekler, sinekler, pireler, numbers, counter, lines);
						i = j;
					}
				}
			}
			else if (strcmp(canlilar[i]->tur, "S") == 0)
			{
				if (strcmp(canlilar[j]->tur, "P") == 0)
				{
					canlilar[j]->setCanliTur(canlilar[j], "X");
					habitatDurumu(this, canlilar, bitkiler, bocekler, sinekler, pireler, numbers, counter, lines);
				}
				else if (strcmp(canlilar[j]->tur, "C") == 0)
				{
					canlilar[j]->setCanliTur(canlilar[j], "X");
					habitatDurumu(this, canlilar, bitkiler, bocekler, sinekler, pireler, numbers, counter, lines);
				}
				else if (strcmp(canlilar[j]->tur, "B") == 0)
				{
					canlilar[i]->setCanliTur(canlilar[i], "X");
					habitatDurumu(this, canlilar, bitkiler, bocekler, sinekler, pireler, numbers, counter, lines);
					i = j;
				}
				else
				{
					if (canlilar[i]->number >= canlilar[j]->number)
					{
						canlilar[j]->setCanliTur(canlilar[j], "X");
						habitatDurumu(this, canlilar, bitkiler, bocekler, sinekler, pireler, numbers, counter, lines);
					}
					else
					{
						canlilar[i]->setCanliTur(canlilar[i], "X");
						habitatDurumu(this, canlilar, bitkiler, bocekler, sinekler, pireler, numbers, counter, lines);
						i = j;
					}
				}
			}
			else if (strcmp(canlilar[i]->tur, "B") == 0)
			{
				if (strcmp(canlilar[j]->tur, "S") == 0)
				{
					canlilar[j]->setCanliTur(canlilar[j], "X");
					habitatDurumu(this, canlilar, bitkiler, bocekler, sinekler, pireler, numbers, counter, lines);
				}
				else if (strcmp(canlilar[j]->tur, "P") == 0)
				{
					canlilar[j]->setCanliTur(canlilar[j], "X");
					habitatDurumu(this, canlilar, bitkiler, bocekler, sinekler, pireler, numbers, counter, lines);
				}
				else if (strcmp(canlilar[j]->tur, "C") == 0)
				{
					canlilar[i]->setCanliTur(canlilar[i], "X");
					habitatDurumu(this, canlilar, bitkiler, bocekler, sinekler, pireler, numbers, counter, lines);
					i = j;
				}
				else
				{
					if (canlilar[i]->number >= canlilar[j]->number)
					{
						canlilar[j]->setCanliTur(canlilar[j], "X");
						habitatDurumu(this, canlilar, bitkiler, bocekler, sinekler, pireler, numbers, counter, lines);
					}
					else
					{
						canlilar[i]->setCanliTur(canlilar[i], "X");
						habitatDurumu(this, canlilar, bitkiler, bocekler, sinekler, pireler, numbers, counter, lines);
						i = j;
					}
				}
			}
			else 
			{
				if( (canlilar[i]->number >= canlilar[j]->number) &&(canlilar[i]->tur == canlilar[j]->tur) )
                {
                    canlilar[j]->setCanliTur(canlilar[j], "X");
                }
                else 
                {
                    canlilar[i]->setCanliTur(canlilar[i], "X");
                    i = j;
                }
			}
		}
	}
	
	this->yokEdiciAll(this, canlilar, bitkiler, bocekler, sinekler, pireler, numbers, counter, lines);
}

//Heap içerisinden alınan alanların doğru bir şekilde geri tahsis edilebilmesi için for döngüsünün oluşturulması ve dizilerin serbest bırakılması
void yokEdiciAll(const Habitat this, Canli* canlilar, Bitki* bitkiler, Bocek* bocekler, Sinek* sinekler, Pire* pireler, int* numbers, int counter, int lines)
{
	if (this == NULL)
        return;
    for (int i = 0; i < counter; i++)
    {
        if (numbers[i] >= 1 && numbers[i] <= 9)
        {
            bitkiler[i]->yokEdici_Bi(bitkiler[i]);
        }
        else if (numbers[i] >= 10 && numbers[i] <= 20)
        {
            bocekler[i]->yokEdici_Bo(bocekler[i]);
        }
        else if (numbers[i] >= 21 && numbers[i] <= 50)
        {
            sinekler[i]->yokEdici_S(sinekler[i]);
        }
        else
        {
            pireler[i]->yokEdici_P(pireler[i]);
        }
    }
	
	free(canlilar);
	free(bitkiler);
	free(bocekler);
	free(sinekler);
	free(pireler);
	free(numbers);
}

//Habitat nesnesi için yıkıcının oluşturulması
void yokEdici_Habitat(const Habitat this)
{
	if(this == NULL) 
		return;
	free(this);
}