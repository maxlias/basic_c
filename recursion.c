#include <stdio.h>
#include <stdlib.h>

void restasSucesivas();
int division(int, int);
void invertirNum();
void invetir(int);
void sumarNum();
int sumar();
void multiplicarVector();
int multiplicar(int [], int);
void sumarMatriz();
int sumarM(int [][2], int, int);

int main()
{
    //restasSucesivas();
    //invertirNum();
    //sumarNum();
    //multiplicarVector();
    sumarMatriz();
    return 0;
}

void restasSucesivas()
{
    int div, divisor;
    printf("Inserte dividendo:\n");
    scanf("%d", &div);
    printf("Inserte divisor:\n");
    scanf("%d", &divisor);
    printf("La division es: %d\n", division(div, divisor));
}

int division(int dividendo, int divisor)
{
    if(dividendo - divisor < 0)
    {
        return 0;
    }
    else
    {
        return division(dividendo - divisor, divisor) + 1;
    }
}

void invertirNum()
{
    int num;

    printf("Escriba un numero:\n");
    scanf("%d", &num);

    invertir(num);
}

void invertir(int n){
    if(n>0) {
        printf("%d", n%10);
        invertir(n/10);
    }
}

void sumarNum(){

    int num, suma = 0;

    printf("Escriba un numero:\n");
    scanf("%d", &num);

    suma = sumar(num);
    printf("\nLa suma de los numeros es: %d", suma);
}

int sumar(int num){

    if(num%10 == 0)
    {
        return num;
    }

    return sumar(num/10) + num%10;
}

void multiplicarVector(){

    int vector[4], resultado = 0, i;

    for (i = 0; i < 4; i++)
    {
        printf("Escriba un numero:\n");
        scanf("%d",  &vector[i]);

    }

    resultado = multiplicar(vector, 3);
    printf("\nLa multiplicacion de los numeros del vector es: %d", resultado);
}

int multiplicar(int vec [], int pos){

    if(pos == 0)
    {
        return vec[pos];
    }

    return multiplicar(vec, pos-1) * vec[pos];
}

void sumarMatriz(){

    int matriz[2][2];
    int i, j, suma = 0;

    for (i=0; i < 2; i++)
    {
        for (j=0; j < 2; j++)
        {
            printf("Escribir el valor para la posc[%d][%d]:", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    suma = sumarM(matriz, 1, 1);
    printf("\nLa suma de los numeros de la matriz es: %d", suma);
}

int sumarM(int matriz [][2], int fila, int col){

     if (fila == 0 && col == 0)
     {
         return matriz[0][0];
     }
     else
     {
          if (col == 0)
          {
            return matriz[fila][col] + sumarM (matriz, fila - 1, fila);
          }
          else
          {
            return matriz[fila][col] + sumarM (matriz, fila, col-1);
          }
     }
}

