
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//////////////////////// definition structure vecteur ///////////////////////////
typedef struct vecteur vecteur;
struct vecteur {
	int		taille;
	double         *stockage;
	char		type;
};


///////////////////////fonction somme de vecteurs //////////////////////////////
vecteur addition(vecteur v1, vecteur v2)
{
	int		i = 0;
	vecteur		resultat;
	resultat.taille = v1.taille;
	resultat.type = v1.type;
	resultat.stockage = malloc(resultat.taille * sizeof(double));
//le test doit validé si les deux matrice sont de même type et de même taille.
	if (v1.taille == v2.taille && v1.type == v2.type) {
		for (i = 0; i < resultat.taille; i++) {
			resultat.stockage[i] = v1.stockage[i] + v2.stockage[i];
			//printf("%lf ", resultat.stockage[i]);
		}
	} else {
		printf("\n!!!opération impossible!!!\n");

	}
	return resultat;
}

///////////////////////fonction somme de vecteurs //////////////////////////////
vecteur soustraction(vecteur v1, vecteur v2)
{
	int		i = 0;
	vecteur		resultat;
	resultat.taille = v1.taille;
	resultat.type = v1.type;
  resultat.stockage = malloc(resultat.taille * sizeof(double));
//Même test que pour la fonction addition.
	if (v1.taille == v2.taille && v1.type == v2.type) {
		for (i = 0; i < resultat.taille; i++) {
			resultat.stockage[i] = v1.stockage[i] - v2.stockage[i];
		}
	} else {
		printf("\n!!!opération impossible!!!\n");
	}
	return resultat;
}

///////////////////////fonction somme de vecteurs //////////////////////////////
vecteur multiplication(vecteur v1, vecteur v2)
{
	int		i = 0;
	vecteur		resultat;
	resultat.taille = v1.taille;
	resultat.type = v1.type;
  resultat.stockage = malloc(resultat.taille * sizeof(double));
//le test doit validé si les deux matrice ne sont pas de même type, mais les matrices doivent avoir la même taille
	if (v1.taille == v2.taille && v1.type != v2.type) {
		for (i = 0; i < resultat.taille; i++) {
			resultat.stockage[i] = v1.stockage[i] * v2.stockage[i];
		}
	} else {
		printf("\n!!!opération impossible!!!\n");
	}
	return resultat;
}

////////////////////fonction du remplissage ////////////////////////////////////
void
remplissage(vecteur * vect, int dim, char Type, double t[])
{
	vect->type = Type;
	vect->taille = dim;
	vect->stockage = malloc(dim * sizeof(double));

	int		j;

	for (j = 0; j < vect->taille; j++) {
		vect->stockage[j] = t[j];
	}

	//test malloc
		if (vect->stockage == NULL) {
		printf("allocation impossible\n");
	}
}

////////////////////fonction pour afficher ////////////////////////////////////
void
affichage(vecteur * vect)
{
	int		i;

	if (vect->type == 'C') {
		for (i = 0; i < vect->taille; i++) {
			printf("%lf", vect->stockage[i]);
			printf("\n");
		}
	}
	if (vect->type == 'L') {
		for (i = 0; i < vect->taille; i++) {
			printf("%lf ", vect->stockage[i]);
		}
	}
}

/////////////////programme principale //////////////////////////////////////////
int
main()
{
	//definition des trois vecteurs
	double		tab1    [2] = {1, 0};
	double		tab2    [2] = {1, 1};
	double		tab3    [2] = {-1, 0};

	vecteur		V1;
	vecteur		V2;
	vecteur		V3;
	vecteur		Somme;
	vecteur		Difference;
  vecteur   Produit;


	remplissage(&V1, 2, 'L', tab1);
	remplissage(&V2, 2, 'C', tab2);
	remplissage(&V3, 2, 'C', tab3);

	printf("\nV1=\n");
	affichage(&V1);

	printf("\n\nV2=\n");
	affichage(&V2);

	printf("\nV3=\n");
	affichage(&V3);

	Somme = addition(V2, V3);
	Difference = soustraction(V2, V3);
  Produit = multiplication(V1, V2);
  printf("\nsomme=\n");
  affichage(&Somme);
  printf("\ndifference=\n");
	affichage(&Difference);
  printf("\nproduit=\n");
  affichage(&Produit);


return 0;
}
