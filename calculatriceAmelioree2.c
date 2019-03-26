#include <stdio.h>
#include <stdlib.h>
#include <math.h>
///////////////////////////////////////////////////////////////////////////////
//Liste de fonction appel √ ©dans le programme ////////////////////
double 
saisi()
{
        //fonction saisi des nombres √ †traiter.
        double          x = 0;
        printf("saisi nombre √† traiter\n>> ");
        scanf("%lf", &x);
        return x;
}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/////liste des op √ ©rations appel √ ©s dans le programme ////////////////////
double 
addition(double x, double y)
{
        return x + y;
}
double 
soustraction(double x, double y)
{
        return x - y;
}
double 
multiplication(double x, double y)
{
        return x * y;
}
double 
division(double x, double y)
{
        return x / y;
}
double 
x(double x)
{
        return x;
}
double 
x2(double x)
{
        return pow(x, 2);
}
double 
x3(double x)
{
        return pow(x, 3);
}
double 
Cos(double x)
{
        return cos(x);
}
double 
Sin(double x)
{
        return sin(x);
}
double 
Tan(double x)
{
        return tan(x);
}
double 
inverse(double x)
{
        return 1 / x;
}
double 
ln(double x)
{
        return log(x);
}
double 
expo(double x)
{
        return exp(x);
}
///////////////////////////////////////////////////////////////////////////////
/////Fonction permettant de choisir une fonction √ †integrer ///////////////:
double 
fonction()
{

        int             f = 0;
        //variable permettant de choisir une fonction a calculer
                double          r;

        printf(" f(x)= \n1. x        2. x¬≤       3. x¬≥ ");
        printf("\n4. cos(x)   5. sin(x)   6. tan(x)");
        printf("\n7. 1/x      8. ln(x)     9. exp(x)\n>>");

        scanf("%d", &f);
        //saisi de l 'op√©ration √† effectuer

                switch (f) {
        case 1:
                ptr_fonction = &x;
                break;
        case 2:
                ptr_fonction = &x2;
                break;
        case 3:
                ptr_fonction = &x3;
                break;
        case 4:
                ptr_fonction = &Cos;
                break;
        case 5:
                ptr_fonction = &Sin;
                break;
        case 6:
                ptr_fonction = &Tan;
                break;
        case 7:
                ptr_fonction = &inverse;
                break;
        case 8:
                ptr_fonction = &ln;
                break;
        case 9:
                ptr_fonction = &expo;
                break;
        }
        return ptr_fonction;
}
////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
/////////Fonction pour l 'int√©gration de Simpson////////////////
double 
integral(double a, double b, int n, double *fonction())
{
        int             i;
        double          s = 0, s1 = 0, s2 = 0, dx = 0, d2 = 0;
        double          x = 0, f = 0;

        f = &fonction;
        x = a - dx;
        dx = (b - a) / n;
        s = f(a) + f(b);
        d2 = 2 * dx;
        s1 = 0;

        for (i = 1; i <= n - 1; i = i + 2) {
                x = x + d2;
                s1 = s1 + f(x);
        }

        x = a;
        s2 = 0;

        for (i = 2; i <= n - 2; i = i + 2) {
                x = x + d2;
                s2 = s2 + f(x);
        }

        s = dx * (s + 4 * s1 + 2 * s2) / 3;
        return s;
}
////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//Programme principal ///////////////////////////////
///////////////////////////////////
int 
main()
{
        int             op = 0, validation = 1, test = 0, n = 0;
        //op est la variable pour le choix de l 'op√©ration, validation sert de condition pour refaire un calcul ou non.
                double          nb1 = 0, nb2 = 0, result = 0, a = 0, b = 0;

        double          (*ptr_fonction) (double);
        ptr_fonction = fonction;

        while (validation == 1) {

                printf(" op√©ration √† effecuter\n1. + \n2. - \n3. x \n4. / \n5.Calcul d'une fonction \n6.Calcul integral \n>> ");
                scanf("%d", &op);
                //saisi de l 'op√©ration √† effectuer

                        if (0 < op && op < 7) {
                        //il faut que la valeur de op soit comprise entre 1 et 6 pour effectuer une op √ ©ration.

                                validation = 0;

                        switch (op) {
                        case 1:
                                result = addition(nb1 = saisi(), nb2 = saisi());
                                break;
                        case 2:
                                result = soustraction(nb1 = saisi(), nb2 = saisi());
                                break;
                        case 3:
                                result = multiplication(nb1 = saisi(), nb2 = saisi());
                                break;
                        case 4:
                                result = division(nb1 = saisi(), nb2 = saisi());
                                break;
                        case 5:
                                result = fonction(nb1 = saisi());
                                break;
                        case 6:
                                while (test == 0) {
                                        printf("saisir la borne inferieure -a-\n>> ");
                                        scanf("%lf", &a);
                                        printf("saisir la borne superieure -b-\n>> ");
                                        scanf("%lf", &b);
                                        printf("saisir le pas\n>> ");
                                        scanf("%d", &n);
                                        if (a > b) {
                                                printf("veuillez saisir -a- plus petit que -b-\n\n");
                                        } else {
                                                test = 1;
                                        }
                                }
                                test = 0;
                                result = integral(a, b, n, *fonction);
                                break;

                        }
                        printf("=%lf\n\n", result);
                        //affichage du r √ ©sultat
                } else {
                        printf("entrez une valeur valide\n");
                } //message d 'erreur

                        printf("tapez 1 pour effectuer un calcul\ntapez 0 pour quitter\n");
                scanf("%d", &validation);
        }

        return 0;
}
