#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void palabra(float Debit[20], char *name[2][1], int limite, int x, int *contdeb, int *contcred, float *mayordeb, float *mayorcred);
void suma(float Deb[20], char *name[2][1], int contador, int contdeb, int contcred, float mayordeb, float *totalcredito, float *totaldebito, int x);
void borrar(float cred[20], int *contcred);
void clearscreen(void);
int testing(void);
int main(void){
float Debito[20];
char *nombre[2][1] = {{"Debito"}, {"Credito"}};
float Credito[20];
int x = 0;
float mayordeb = 0;
float mayorcred = 0;
int contdeb = 0;
int contcred = 0;
float totaldebito = 0;
float totalcredito = 0;
char numero[5];
testing();
printf("Bienvenido al sistema bancario, recuerde: debe anotar al menos 10 operaciones de debito y 5 de credito para poder salir (limite: 20)\n");
palabra(Debito, nombre, 10, x, &contdeb, &contcred, &mayordeb, &mayorcred);
x++;
palabra(Credito, nombre, 5, x, &contdeb, &contcred, &mayordeb, &mayorcred);
volver:
x = 0;
suma(Debito, nombre, contdeb, contdeb, contcred, mayordeb, &totaldebito, &totalcredito, x);
x++;
suma(Credito, nombre, contcred, contdeb, contcred, mayordeb, &totaldebito, &totalcredito, x);
printf("Desea eliminar algun monto? (s/n): ");
scanf("%s", &numero);
clearscreen();
if(strcmp(numero, "s") == 0){
    borrar(Credito, &contcred);
}
else{
    return 0;
}
goto volver;
}
void palabra(float Debit[20], char *name[2][1], int limite, int x, int *contdeb, int *contcred, float *mayordeb, float *mayorcred){
    char numero[5];
    float mayor = 0;
    int a;
for(a=0;a<20;a++){
    inicio:
printf("Inserte el %s #%d(si ya lleva %d puede escribir 'out' para salir): \n",name[x][0], (a+1), limite);
scanf("%s", &numero);
clearscreen();
if(strcmp(numero, "out") == 0){
    if(a >= limite){    
    break;
    }
    else{
        printf("Aun no hay 10\n");
        goto inicio;
    }
}
Debit[a] = atof(numero);
    if(mayor >= Debit[a]){}
    else{
       mayor = Debit[a];   }
}
if(x == 0){
    *contdeb = a;
    *mayordeb = mayor;
}
else{
    *contcred = a;
    *mayorcred = mayor;
}
a = 0;
return;
}
void suma(float Deb[20], char *name[2][1], int contador, int contdeb, int contcred, float mayordeb, float *totalcredito, float *totaldebito, int x){
float total = 0;
float saldo = 0;
printf("Elementos del arreglo '%s':", name[x][0]);
for(int f=0;f<contador;f++){
    total = total + Deb[f];
    printf(" %.2f,", Deb[f]);
}
if(x == 0){
*totaldebito = total;
printf("\n");
printf("Total de debito: Q%.2f\n", *totaldebito);
x++;
return;
}
else{
*totalcredito = total;
printf("\n");
printf("Total de credito: Q%.2f\n", *totalcredito);
saldo = *totaldebito - *totalcredito;
printf("Total de saldo: Q%.2f\n", saldo);
printf("El promedio de debitos es: Q%.2f\n", (*totaldebito/(float)contdeb));
printf("Se tiene %d operaciones de debito contra %d de credito\n", contdeb, contcred);
printf("El monto mas grande de Debitos es: Q%.2f\n", mayordeb);
return;
}
}
void borrar(float cred[20], int *contcred){
    char numero[5];
    int q;
    int m;
    monto:
    printf("Introduzca la posicion del monto a eliminar (De la posicion 1 en adelante...): \n");
    scanf("%s", &numero);
    clearscreen();
    if(atoi(numero)>*contcred || atoi(numero)<0){
            printf("Posicion invalida!");
            goto monto;
        }
    for(q=atoi(numero)-1; q<*contcred-1;q++){
                cred[q] = cred[q+1];
        }
        printf("Monto eliminado exitosamente!\n");
    *contcred = *contcred-1;
    return;
}
void clearscreen(void)
{
    system("@cls||clear");
}