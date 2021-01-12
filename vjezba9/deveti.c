#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

typedef struct cvor_ *Pozicija;
typedef struct cvor_ {
	int element;
	Pozicija l_child;
	Pozicija d_child;
}Cvor;


Pozicija UnosenjeNovogElementa(Pozicija root, Pozicija novi);
int InicijalizacijaRoota(Pozicija root);
int odabir(Pozicija root);
Pozicija IspisStabla( Pozicija root);
Pozicija BrisanjeElementa(Pozicija root, int broj);
Pozicija PronalazenjeElementa(Pozicija root, int broj);
Pozicija findmin(Pozicija root);
Pozicija findmax(Pozicija root);
Pozicija alokacija();
int main() {
	Pozicija root=(Pozicija)malloc(sizeof(Cvor));
	
	InicijalizacijaRoota(root);
	odabir(root);

	return 0;
}
int InicijalizacijaRoota(Pozicija root) {
	int broj;
	
	printf("Unesite element za root:\n");
	scanf("%d", &broj);
	root->element = broj;
	root->d_child = NULL;
	root->l_child = NULL;
	return 0;

}
int odabir(Pozicija root) {
	int izbor;
	int broj;
	Pozicija q;
	printf("Unesite broj:\n0.Izlaz\n1.Unosenje novog elementa u stablo\n");
	printf("2.Ispis stabla\n3.Brisanje nekog elementa\n4.Pronalazenje nekog elementa\n");
	
	do {
		printf("Vas ponovni odabir:\n");
		scanf("%d", &izbor);
		switch (izbor) {
		case 1:
			printf("Koji element zelite unijeti?\n");
			scanf("%d", &broj);
			q = alokacija();
			q->element = broj;
			UnosenjeNovogElementa(root, q);
			break;
		case 2:
			IspisStabla(root);
			break;
		case 3:
			printf("Koji element zelite izbrisati?\n");
			scanf("%d", &broj);
			BrisanjeElementa(root ,broj);
			break;
		case 4:
			printf("Koji element zelite pretraziti?\n");
			scanf("%d", &broj);
			PronalazenjeElementa(root, broj);
			break;
		default:
			printf("Pogresan unos!\n");
		}
	} while (izbor != 0);

	return 0;
}



Pozicija BrisanjeElementa(Pozicija root , int broj) {
	
	if (root == NULL) {
		return NULL;
	}
	if (root->element == broj) {
		if (root->l_child != NULL) {
			Pozicija pom = findmax(root->l_child);
			root->element = pom->element;
			root->l_child = BrisanjeElementa(root->l_child, pom->element);
		}
	

	else if (root->d_child != NULL) {
			Pozicija pom = findmin(root->l_child);
			root->element = pom->element;
			root->d_child = BrisanjeElementa(root->d_child, pom->element);

		}
		else {
			free(root);
			return NULL;
		}

	}
	else if (root->element > broj) {
		root->l_child = BrisanjeElementa(root->l_child, broj);
	}
	else {
		root->d_child = BrisanjeElementa(root->d_child, broj);
	}

	return root;

	
}

Pozicija PronalazenjeElementa( Pozicija root ,int broj) {
	if (root == NULL)
		return NULL;
	if (root->element == broj) {
		return root;
	}
	else if (broj < root->element)
		root->l_child = PronalazenjeElementa(root->l_child, broj);
	else
		root->d_child = PronalazenjeElementa(root->d_child, broj);


	return root;
}

Pozicija findmin(Pozicija root) {

	if (root == NULL) return NULL;

	while (root->l_child != NULL) {
		root = root->l_child;
	}
	return root;
}


Pozicija findmax(Pozicija root) {
	if (root == NULL) return NULL;

	while (root->d_child != NULL) {
		root = root->d_child;
	}
	return root;

}
Pozicija alokacija() {
	Pozicija q;
	q = (Pozicija)malloc(sizeof(Cvor));
	if (q == NULL) {
		printf("Greska u alokaciji!\n");
		
	}
	return q;
}
Pozicija UnosenjeNovogElementa(Pozicija root, Pozicija novi) {

	if (root == NULL) {
		root = novi;
		return novi;
	}

	if (novi->element > root->element)
		root->d_child = UnosenjeNovogElementa(root->d_child, novi);
	else if (novi->element < root->element)
		root->l_child = UnosenjeNovogElementa(root->l_child, novi);
	else
		free(root);

	return root;
}

Pozicija IspisStabla(Pozicija root) {
	if (root == NULL) {
		return ;
	}
	printf("%d\n", root->element);
	IspisStabla(root->l_child);
	IspisStabla(root->d_child);
	return root;
}
