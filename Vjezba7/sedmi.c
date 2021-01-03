#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct cvor* Pozicija;
typedef struct cvor {
	float br;
	Pozicija next;
}Cvor;

int ispis(Pozicija P);
int pushStack(Pozicija, int);
int popStack(Pozicija);
int citanje(Pozicija, char*);
int racunanje(Pozicija, int, int, char);
int main() {
	char ime[20];
	
	Pozicija head;
	head = (Pozicija)malloc(sizeof(Cvor));
	head->next = NULL;
	printf("Unesite ime datoteke\n");
	scanf("%s", &ime);
	citanje(head, ime);
	ispis(head->next);
	return 0;
}
int pushStack(Pozicija P, int broj) {
	Pozicija q;
	q = (Pozicija)malloc(sizeof(Cvor));
	if (q == NULL) {
		printf("Greska!\n");
		return -1;
	}
	q->br = broj;
	q->next = P->next;
	P->next = q;
	return 0;
}
int popStack(Pozicija P) {
	int element;
	Pozicija pom = P->next;
	element = pom->br;
	P->next = pom->next;
	free(pom);
	return element;
}
int citanje(Pozicija P, char* dat) {
	FILE* fp;
	char ime[100];
	char operator;
	float br;
	int brznakova;
	float operand1;
	float operand2;
	int i;
	int rez;

	fp = fopen(dat, "r");


	if (!fp) {
		printf("Greska u otvaranju datoteke!\n");
		return -1;
	}
	fgets(ime, 100, fp);
	rewind(fp);
	printf("Izraz u datoteci je: ");
	for (i = 0; i < 3; i++) {
		printf("%c", ime[i]);
	}
	
	while(fgetc(fp)!=EOF) {
		
		if (sscanf(ime, " %d%n", &br, &brznakova) == 1) {
			pushStack(P, br);
			*ime += brznakova;
			
		}
		else {
			operand2 = popStack(P);
			operand1 = popStack(P);
			sscanf(ime, "%c%n",&operator, &brznakova);
			rez=racunanje(P, operand1, operand2, operator);
			
			pushStack(P, rez);
			*ime += brznakova;
			
		}
	} 
	fclose(fp);
	return 0;
}
int racunanje(Pozicija P, int a, int b, char op) {
	int rezultat;
	switch (op)
	{
	case '+':
	{
		rezultat = a + b;
		break;
	}
	case '-':
	{
		rezultat = a - b;
		break;
	}
	case '*':
	{
		rezultat = a * b;
		break;
	}
	case '/':
	{
		if (b == 0)
		{
			printf("Dijeljenje s nulom.\n");
			return -1;
		}
		rezultat = a / b;
		break;
	}
	default:
	{
		break;
	}

	return rezultat;
	}
}
int ispis(Pozicija P)
{
	printf("\nIzraz je:");
	while (P != NULL)
	{
		printf("%d", P->br);
		P = P->next;
	}
	return 0;
}
