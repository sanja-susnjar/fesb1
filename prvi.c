
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
	char ime[20];
	char prezime[20];
	int apsolutni;
	float relativni;
}studenti;


int broj_redaka();
int relativni(studenti*, int,int);
int main() {
	
	int broj,i, max=100;
	studenti* lista;
	FILE* fp = fopen("student.txt", "r");
	if (fp == NULL) {
		printf("Datoteka se ne moze otvoriti.\n ");
	}

	broj = broj_redaka();
	printf("Broj_redaka je: %d\n", broj);

	lista = (studenti*)malloc(broj * sizeof(studenti));
	
	while (!feof(fp)) {
		for (i = 0; i < broj; i++) {
			fscanf(fp, "%s %s %d", lista[i].ime, lista[i].prezime, &lista[i].apsolutni);
			
		}
	}

	relativni(lista, broj, max);
	
	for (i = 0; i < broj; i++) {
		printf("%s %s %d %f\n", lista[i].ime, lista[i].prezime, lista[i].apsolutni, lista[i].relativni);
	}
	return 0;
}

int broj_redaka() {
	char c;
	int br = 0; //brojac
	

	FILE* fp = fopen("student.txt", "r");

	if (fp == NULL) {
		printf("Datoteka se ne moze otvoriti");
		return 0;
	}

	while ((c = getc(fp))!=EOF) {
		if (c == '\n') {
			br++;
		}
	}


	fclose(fp);
	return br+1;
}
int relativni(studenti* lista, int n, int max) {
	int i;
	for (i = 0; i < n; i++) {
		lista[i].relativni = lista[i].apsolutni / (float)max * 100;
	}
	return 0;
}