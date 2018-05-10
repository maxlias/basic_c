#include <stdio.h>
#include <stdlib.h>

void cargar_matriz(int[5][5], int, int);
void mostrar_matriz(int matriz[5][5], int, int);
void sumatoria_fila(int matriz[5][5], int, int);
void min_fila(int matriz[5][5], int, int);
void mayor_columna(int matriz[5][5], int, int);
void promedio_multiplos_5(int matriz[5][5], int, int);
void sumatoria_diagonal_princ(int matriz[5][5], int, int);
void mostrar_diagonal_sec(int matriz[5][5], int, int);
void matriz_simetrica(int matriz[5][5], int, int);
void elementos_debajo_princ_diag(int matriz[5][5], int);
void matriz_transpuesta(int matriz[5][5]);
void promedio_diagonales(int matriz[5][5], int);
void multi_transpuesta(int matriz [][5], int, int);
void cant_primo_matriz(int matriz[][5], int, int);
int esPrimo(int);

int main()
{
    int matriz[5][5], filas = 0, columnas = 0;

    //Parte 1
    printf("Ingrese la cantidad de filas: \n");
    scanf("%d", &filas);
    printf("Ingrese la cantidad de columnas: \n");
    scanf("%d", &columnas);
    cargar_matriz(matriz, filas, columnas);
    mostrar_matriz(matriz, filas, columnas);

    //Parte 2

    return 0;
}

void cargar_matriz(int matriz[][5], int filas, int columnas)
{
    int i, j;

    for (i=0; i < filas; i++)
    {
        for (j=0; j < columnas; j++)
        {
            printf("Escribir el valor para la posc[%d][%d]:", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void mostrar_matriz(int matriz[][5], int filas, int columnas)
{
    int i, j;

    for (i=0; i < filas; i++)
    {
        printf("\n");

        for (j=0; j < columnas; j++)
        {
            printf("%d \t", matriz[i][j]);
        }
    }
}

void sumatoria_fila(int matriz[][5], int columnas, int num_fila)
{
    int i, sumatoria = 0;

    for (i=0; i < columnas; i++)
    {
        sumatoria += matriz[num_fila][i];
    }

    printf("La sumatoria de la fila: %d es %d", num_fila, sumatoria);
}

void min_fila(int matriz[][5], int filas, int cols)
{
    int i, j, min = 0;

    for (i=0; i < cols; i++)
    {
        for (j=0; j < filas; j++)
        {
          if(i == 0)
          {
            min = matriz[j][i];
          }

          if(matriz[j][i] < min)
          {
            min = matriz[j][i];
          }
        }
     }

    printf("El min de la fila: es %d", min);
}

void mayor_columna(int matriz[][5], int filas, int num_col)
{
    int i, mayor = 0;

    for (i=0; i < filas; i++)
    {
        if(matriz[i][num_col] > mayor)
        {
            mayor = matriz[i][num_col];
        }
    }

    printf("Mayor de la columna: %d es %d", num_col, mayor);
}

void promedio_multiplos_5(int matriz[][5], int filas, int cols)
{
    int i, j, suma = 0, cant = 0, promedio = 0;

    for (i=0; i < filas; i++)
    {
        for (j=0; j < cols; j++)
        {
            if(matriz[i][j] % 5 == 0)
            {
                suma += matriz[i][j];
                cant++;
            }
        }
    }

    promedio = suma / cant;
    printf("El promedio de los multiplos de 5 es %d", promedio);
}

void sumatoria_diagonal_princ(int matriz[][5], int filas, int cols)
{
    int i, suma = 0;

    for (i=0; i < filas; i++)
    {
      suma += matriz[i][i];
    }

    printf("La sumatoria de la diagonal es %d", suma);
}

void mostrar_diagonal_sec(int matriz[][5], int filas, int cols)
{
    int i;

    for (i=filas-1; i >= 0; i--)
    {
      printf("Los elementos de la dia sec es %d", matriz[i][i]);
    }
}

void matriz_simetrica(int matriz[][5], int filas, int cols)
{
    int i, j, simetrica = 0;

    for (i=0; i < filas; i++)
    {
        for (j=0; j < cols; j++)
        {
            if (matriz[i][j] != matriz[j][i])
            {
              simetrica = 1;
            }
        }
    }

    if(simetrica == 0)
    {
        printf("La matriz es simetrica");
    }
    else
    {
       printf("La matriz es no es simetrica");
    }
}

void elementos_debajo_princ_diag(int matriz[][5], int n)
{
    int i, j;

    for(i=1; i < n; i++){

      for(j=0; j < i ;j++){

        printf("Elemento debajo de la diagonal: \n %d ",matriz[i][j]);

      }
    }
}

void matriz_traspuesta(int matriz [][5], int filas, int columnas)
{

    int i, j;

    for (i=0; i < filas; i++)
    {
        printf("\n");

        for (j=0; j < columnas; j++)
        {
            printf("%d \t", matriz[j][i]);
        }
    }
}


void promedio_diagonales(int matriz [][5], int filas)
{

    int i, j, promedio = 0, suma = 0;

    for (i=0; i < filas; i++)
    {
      suma += matriz[i][i];
    }

    for (j=filas-1; j > -1; j--)
    {
      suma += matriz[j][j];
    }

    promedio = suma/filas;
    printf("El promedio de la diagonal es %d", promedio);
}


void multi_transpuesta(int matriz [][5], int filas, int cols)
{

    int i, j, k, suma = 0;

    int resultado[filas][cols];

    for (i=0; i < filas; i++)
    {
        printf("\n");

        for (j=0; j < cols; j++)
        {
            resultado[i][j] = matriz[i][j] * matriz[j][i];
        }

        for(k=0; k < filas; i++)
        {
            suma += resultado[i][k];
        }

        printf("%d \t", suma);
    }
}


void cant_primo_matriz(int matriz[][5], int filas, int columnas)
{
    int i, j, cantidad = 0, nroPrimo = 0;

    for (i=0; i < filas; i++)
    {
        for (j=0; j < columnas; j++)
        {
            nroPrimo = esPrimo(matriz[i][j]);

            if(nroPrimo == 0)
            {
                cantidad ++;
            }
        }
    }

    printf("La cantidad de nros primos en la matriz es es %d", cantidad);
}


int esPrimo(int numero)
{
    int x = 0;

    if (numero == 0 || numero == 1 || numero == 4)
    {
      return 1;
    }

    for (x = 2; x < numero / 2; x++)
    {
        if (numero % x == 0)
        {
            return 1;
        }
    }

    return 0;
}
