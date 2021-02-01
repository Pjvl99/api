#include <stdio.h>
#include <time.h>
#include <unistd.h>
extern void palabra(float Debit[20], char *name[2][1], int limite, int x, int *contdeb, int *contcred, float *mayordeb, float *mayorcred);
extern void suma(float Deb[20], char *name[2][1], int contador, int contdeb, int contcred, float mayordeb, float *totalcredito, float *totaldebito, int x);
extern void borrar(float cred[20], int *contcred);
int testing(void){
double time_spent = 0.0;
int tests = 0;
int fails = 0;
float totaldeb = 0;
float totalcred = 0;
int contcred = 0;
int contdeb = 0;
float mayordeb = 0;
float mayorcred = 0;
int x = 20;
float Debito[20] = {3.5, 3.2, 3.6, 5.0, 6.7, 4.0, 5.0, 7.43, 10.0, 8.0, 6.0, 5.0, 6.0, 7.0, 11.0, 7.89, 5.6, 4.4, 3.3, 5.4};
float Credito[20] = {3.5, 3.2, 3.6, 4.34, 6.0, 4.0, 4.3, 3.0, 9.0, 8.0, 6.0, 5.0, 6.0, 7.0, 4.0, 7.89, 5.6, 4.4, 3.3, 4.4};
char *nombre[2][1] = {{"Debito"}, {"Credito"}};
clock_t begin = clock();
borrar(Credito, &x);
if((x == 19) && ((int)Credito[4] == 4)){
    // Eliminaremos de la posicion 5 para probar y comprobaremos con x si se elimino 1
    tests++;
}
else{
    printf("Error in function 'borrar'\n\n");
    fails++;
}
suma(Debito, nombre, 20, 20, 0, 11.0, &totalcred, &totaldeb, 0);
suma(Credito, nombre, x, 20, 20, 9.0, &totalcred, &totaldeb, 1);
if(((int)totaldeb == 118) && ((int)totalcred == 96)){
//Probando total de credito y debito
tests++;
}
else{
    printf("Error in function 'suma' \n\n");
    fails++;
}
palabra(Debito, nombre, 10, 0, &contdeb, &contcred, &mayordeb, &mayorcred);
palabra(Credito, nombre, 5, 1, &contdeb, &contcred, &mayordeb, &mayorcred);
// Probaremos si funciona anotando 11 de debito, 6 de credito, poniendo a 8 como mayor de debito y a 9 como mayor de credito
if((contdeb == 11) && (contcred == 6) && ((int)mayordeb == 8) && ((int)mayorcred == 9)){ 
tests++;
}
else{
    printf("Error in function 'palabra' \n\n");
    fails++;
}
sleep(3);
clock_t end = clock();
time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("---------------------------------------------------------------------\n");
    printf("Ran %d tests in %f s\n\n", (tests+fails), time_spent);
    if(tests == 3){
        printf("OK\n\n");
    }
    else{
        printf("FAILED (failures=%d)\n\n", fails);
    }
}