#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
#define MIN 10
typedef struct cvor* Pozicija;
typedef struct cvor {
	int element;
	Pozicija next;
} Cvor;

int Random(int, int);
int pushStog(Pozicija, int);
int pushRed(Pozicija, int);
int pop(Pozicija);
int ispis(Pozicija);
int main() {
	int odabir,broj;
	Cvor stog, red;
	stog.next = NULL;
	red.next = NULL;

	srand((unsigned)time(NULL));
	do {
		printf("Odaberite operaciju:\n ");
		printf("1 Dodaj broj u stog\n");
		printf("2 DOdaj broj u red\n");
		printf("3 Izbaci broj iz stoga\n");
		printf("4 Izbaci broj iz reda\n");
		printf("0 za izlaz\n");
		scanf("%d", &odabir);
		switch (odabir) {
		case 1:
		{
			broj = Random(MIN, MAX);
			pushStog(&stog, broj);
			ispis(stog.next);
			break;
		}
		case 2:
		{
			broj = Random(MIN, MAX);
			pushRed(&red, broj);
			ispis(red.next);
			break;
		}
		case 3:
		{
			pop(&stog);
			ispis(stog.next);
			break;
		}
		case 4:
		{
			pop(&red);
			ispis(red.next);
			break;
		}
		default: {
			printf("Nepostojeci broj\n");
			break;
		}
		}
	} while (odabir != 0);



	return 0;
}
int Random(int a, int b) {
	return rand() % (b - a + 1) + a;
}
int pushStog(Pozicija P, int br) {
	Pozicija q;
	q = (Pozicija)malloc(sizeof(Cvor));
	if (q == NULL) {
		printf("Greska!");
		return -1;
	}
	q->element = br;
	q->next = P->next;
	P->next = q;
	return 0;

}
int pushRed(Pozicija P, int br) {
	Pozicija q;
	q = (Pozicija)malloc(sizeof(Cvor));
	q->element = br;
	if (q == NULL) {
		printf("Greska\n");
	}
	while (P->next != NULL) {
		P= P->next;
	}

	P->next = q->next;
	P ->next = q;

	return 0;
}
int pop(Pozicija P) {
	Pozicija prev;
	prev = P;
	P = P->next;
	prev->next = P->next;
	free(P);
	return 0;

}
int ispis(Pozicija P) {
	if (P == NULL) {
		printf("Lista je prazna\n");
		return -1;
	}
	while (P != NULL) {
		printf("%d ", P->element);
		P = P->next;
	}
	return 0;
}
