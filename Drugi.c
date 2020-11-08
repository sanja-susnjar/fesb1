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

int dodajP(Pozicija);//dodavanje na pocetak
Pozicija dodajO(void);//dodavanje novog elementa
int dodajK(Pozicija); //dodavanje elementa na kraj
int ispis(Pozicija);
Pozicija traziP(Pozicija);//trazenje po prezimenu
int brisanjeIzListe(Pozicija);
Pozicija traziPrethodni(Pozicija,Pozicija);
int main() {
	Osoba head;
	head.next = NULL;

	int odabir;
	do {
		printf("\n\nOdaberite opciju: ");
		printf("\n1. Unos elementa na pocetak liste");
		printf("\n2.Ispis liste ");
		printf("\n3.Unos elementa na kraj liste");
		printf("\n4.Pronadi element(po prezimenu)");
		printf("\n5.Brisanje elementa iz liste");
		printf("\n0 za izlaz");
		printf("\n");
		scanf(" %d", &odabir);

		switch (odabir)
		{
		case 1:
			dodajP(&head);
			break;
		case 2:
			ispis(head.next);
			break;
		case 3:
			dodajK(&head);
			break;
		case 4:
			traziP(head.next);
			break;
		case 5:
			brisanjeIzListe(&head);
			break;

		}
	} while (odabir != 0);
	return 0;
}
int dodajP(Pozicija P) {
	Pozicija q;
	q = (Pozicija)malloc(sizeof(Osoba));
	q=dodajO();
	q->next = P->next;
	P->next = q;

	return 0;
}

Pozicija dodajO(void) {
	Pozicija P;
	P = (Pozicija)malloc(sizeof(Osoba));

	printf("Unesite ime: ");
	scanf("%s", P->ime);
	printf("Unesite prezime: ");
	scanf("%s", P->prezime);
	printf("Unesite godinu rodenja: ");
	scanf("%d", &P->godina);
	return P;
}

int ispis(Pozicija P) {

	if (P == NULL) {
		printf("Lista je prazna");
	}

	
	while (P != NULL) {
		printf("\n %s %s %d", P->ime, P->prezime, P->godina);
		P =  P->next;
	}

	return 0;
}
int dodajK(Pozicija P) {
	Pozicija a;
	a = (Pozicija)malloc(sizeof(Osoba));
	a = dodajO();
	if (P == NULL) {
		printf("Lista je prazna");
	}

	while (P->next != NULL) {
		P = P->next;
	}
	a->next = P->next;
	P->next = a;
	return 0;
}

Pozicija traziP(Pozicija P) {
	
	char prezime[20];

	printf("Koje prezime zelite pretraziti?\n");
	scanf("%s", prezime);

	while (P != NULL && strcmp(P->prezime, prezime)) {
		P = P->next;
	}
	printf("Osoba s trazenim prezimenom je %s %s %d",P->ime, P->prezime, P->godina);

	return P;

}
int brisanjeIzListe(Pozicija P) {
	char prezime[20];
	Pozicija pom,prev;
	
	pom = traziP(P);
	prev = traziPrethodni(P, pom);
	prev->next = pom->next;
	free(pom);
	return 0;
}

Pozicija traziPrethodni(Pozicija P, Pozicija pom) {
	while (P->next != pom) {
		P = P->next;
	}
	return P;
}
