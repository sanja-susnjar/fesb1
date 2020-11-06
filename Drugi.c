#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct osoba* Pozicija;
typedef struct osoba {
	char ime[20];
	char prezime[20];
	int godina;
	Pozicija next;
}Osoba;

int unosP(Pozicija);
int Ispis(Pozicija);
int unosK(Pozicija);
Pozicija Trazi(Pozicija);
Pozicija TraziPreth(char* , Pozicija );
int Brisanje(char*, Pozicija);
int Unos(Pozicija);

int main() {
	Osoba head;
	head.next = NULL;
	char prezime[20];

	unosP(&head);
	Ispis(head.next);
	unosK(&head);
	Trazi(head.next);
	printf("\nPrezime za brisanje? ");
	scanf("%s", prezime);
	Brisanje(prezime, &head);

	return 0;
}

int unosP(Pozicija P) {
	Pozicija a;
	a = (Pozicija)malloc(sizeof(Osoba));
	Unos(a);
	a->next = P->next;
	P->next = a;

}

int Ispis(Pozicija P) {
	while (P != NULL) {
		printf("\nIme: %s\n", P->ime);
		printf("\nPrezime: %s", P->prezime);
		printf("\nGodina: %d", P->godina);
		P = P->next;
	}

}

int unosK(Pozicija P) {
	Pozicija a;
	a = (Pozicija)malloc(sizeof(Osoba));
	Unos(a);
	while (P->next != NULL) {
		P = P->next;
	}
	a->next = P->next;
	P->next = a;
}



int Unos(Pozicija P) {
	printf("\nIme? ");
	scanf("%s", P->ime);
	printf("\nPrezime? ");
	scanf("%s", P->prezime);
	printf("\nGodina rodenja? ");
	scanf("%d", &P->godina);

	return 0;
}

Pozicija Trazi(Pozicija P)
{
	char prezime[20];
	printf("Unesite prezime koje zelite pretraziti: ");
	scanf("%s", prezime);
	Pozicija x = NULL;
	while (P != NULL)
	{
		if (strcmp(P->prezime, prezime) == 0)
		{
			printf("Pronadena osoba s prezimenom %s\n", prezime);
			printf("ime osobe: %s\n", P->ime);
			printf("prezime osobe: %s\n", P->prezime);
			printf("godina rodenja osobe: %d\n", P->godina);
			x = P;
		}
		P = P->next;
	}
	if (x == NULL)
	{
		printf("osoba s %s prezimenom ne postoji u listi.\n", prezime);
	}
}
Pozicija TraziPreth(char* prezime, Pozicija P)
{
	Pozicija prev = P;
	P = P->next;
	while (P != NULL && strcmp(P->prezime, prezime))
	{
		prev = P;
		P = P->next;
	}
	if (P == NULL)
	{
		printf("Element ne postoji u listi. ");
		return NULL;
	}
	return prev;
}
int Brisanje(char* prezime, Pozicija P)
{
	Pozicija prev;
	prev = TraziPreth(prezime, P);
	if (prev != NULL)
	{
		P = prev->next;
		prev->next = P->next;
		free(P);
	}

	return 0;
}

