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
int Dodavanjeiza(Pozicija);
int Dodavanjeispred(Pozicija);
int sortiranjePrez(Pozicija);
int UpisUDat(Pozicija);
int CitajIzDat(Pozicija);
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
		printf("\n6.Dodavanje elementa iza nekog elementa");
		printf("\n7.Dodavanje elemnta ispred nekog elementa");
		printf("\n8. Sortiranje liste po prezimenu");
		printf("\n9.Upisivanje liste u datoteku");
		printf("\n10. Citanje liste iz datoteke");
		printf("\n0 za izlaz");
		printf("\n");
		scanf(" %d", &odabir);

		switch (odabir)
		{
		case 0:
			return 1;
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
		case 6:
			Dodavanjeiza(&head);
			break;
		case 7:
			Dodavanjeispred(&head);
			break;
		case 8:
			sortiranjePrez(&head);
			break;
		case 9:
			UpisUDat(head.next);
			break;
		case 10:
			CitajIzDat(head.next);
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

	printf("\nUnesite ime: ");
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

int Dodavanjeiza(Pozicija P) {
	Pozicija preth, novi;
	
	preth = traziP(P);
	printf("Unos osobe:");
	novi = dodajO();
	novi->next = preth->next;
	preth->next = novi;
	
	
	return 0;
}

int Dodavanjeispred(Pozicija P) {
	Pozicija pom,preth,novi;
	printf("Ispred kojeg elementa zelite unijeti novi element: ");
	pom = traziP(P);
	preth = traziPrethodni(P,pom);
	printf("\nUnos novog elementa:");
	novi = dodajO();
	novi->next = preth->next;
	preth->next = novi;

	return 0;
}

int sortiranjePrez(Pozicija P) {
	Pozicija pom, glavna, preth,end;
	end = NULL;
	while (P->next != end) {
		preth = P;
		glavna = P->next;
		while (glavna->next != end) {
			if (strcmp(glavna->prezime, glavna->next->prezime) > 0) {
				pom = glavna->next;
				preth->next = pom;
				glavna->next = pom->next;
				pom->next = glavna;

				glavna = pom;
			}
			preth = glavna;
			glavna = glavna->next;
		}
		end = glavna;
	}

		return 0;

}

int UpisUDat(Pozicija P) {
	
	FILE* fp;
	char ime[20];
	printf("Ime datoteke? \n");
	scanf("%s", ime);

	fp = fopen("A.txt", "w+");
	if (fp == NULL) {
		printf("Greska pri otvaranju datoteke");
	}

	
	while (P != NULL) {
		fprintf(fp, "%s %s %d", P->ime, P->prezime, P->godina);
		P = P->next;
	}

	fclose(fp);

	return 0;
}

int CitajIzDat(Pozicija P) {
	FILE* fp;
	char ime[20];
	P =(Pozicija) malloc(sizeof(Osoba));
	int i, br = 0;
	
	printf("Ime datoteke? \n");
	scanf("%s", ime);

	fp = fopen(ime, "r");
	if (fp == NULL) {
		printf("Greska pri otvaranju datoteke");
	}

	while (!feof(fp)) {
		if (fgetc(fp) == '\n') {
			br++;
		}
	}
	printf("\nCitanje iz datoteke:\n");
	for (i = 0; i < br; i++) {
		fscanf(fp, "%s %s %d\n", P->ime, P->prezime, &P->godina);
		printf("%s %s %d\n", P->ime, P->prezime, P->godina);
	}
	fclose(fp);

	return 0;
}
