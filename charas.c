#include <stdio.h>
#include <stdlib.h>

void elim_palabras_1_letra();
void grupo_bl_vl();
void intercambiarLetras();
void contarPenultima();

int main()
{
   // elim_palabras_1_letra();
   // grupo_bl_vl();
   // intercambiarLetras();
   contarPenultima();
    return 0;
}

void elim_palabras_1_letra()
{
    int c, aux, prim, cont=0;
    printf("Ingrese la frase\n");
    c=getchar();

    while(c!='.')
    {
        while(c==' ' && c!='.')
        {
            c=getchar();
        }

        prim = c;
        c=getchar();

        if (c!=' ')
        {
            putchar(prim);
            putchar(c);
        }

        while(c!=' ' && c!='.')
        {
            c=getchar();
            putchar(c);
        }
    }
}

void grupo_bl_vl()
{
    char c, prox;

    printf("Ingrese la frase\n");
    c = getchar();

    while( c == ' ')
    {
        c = getchar();
    }

    while ( c != '.')
    {
        while ( c != ' ' && c != '.')
        {
            if ( c == 'v')
            {
                prox = getchar();

                if ( prox == 'l')
                {
                    c = 'b';
                    putchar(c);
                    putchar(prox);

                }
            }
            else
            {
                putchar(c);
            }

            c = getchar();

            while ( c == ' ' )
            {

            putchar(c);

            c = getchar();

            }
        }
    }
}

void intercambiarLetras()
{
    int c, aux, anterior, ultimo, cont = 1;
    printf("Ingrese la frase\n");
    c=getchar();

    while(c!='.')
    {
        while(c==' ' && c!='.')
        {
            c=getchar();
        }

        putchar(c);
        cont ++;

        while(c!=' ' && c!='.')
        {
            if (cont > 2)
            {
                aux = getchar();
                if (aux != ' ' && aux != '.')
                {
                    c = getchar();

                    if (c != ' ' && c != '.')
                    {
                        putchar(anterior);
                        anterior = aux;
                        ultimo = c;
                    }
                    else
                    {
                        putchar(anterior);
                        putchar(aux);
                        putchar(ultimo);
                        putchar(c);
                    }
                }
                else
                {
                    putchar(ultimo);
                    putchar(anterior);
                    putchar(aux);
                    c = aux;

                }

            }
            else
            {
              c = getchar();
              anterior = c;

            }

            cont ++;
        }

        cont = 1;
    }

}

void contarPenultima()
{
    int c, aux, penultima = 0,ultimo, cont = 0;
    printf("Ingrese la frase\n");
    c=getchar();

    while(c!='.')
    {
        while(c==' ' && c!='.')
        {
            c=getchar();
        }

        if (penultima == c)
        {
            cont++;
        }

        penultima = c;

        while(c!=' ' && c!='.')
        {
            aux=getchar();

            if (aux != ' ' && aux != '.')
            {
                c=getchar();

                if(c != ' ' && c != '.')
                {
                    penultima = aux;
                    ultimo = c;
                }
                else
                {
                    penultima = ultimo;
                }

            }
            else
            {
                c = aux;
            }
        }
    }

    printf("cantidad de palabras que empiezan con la penultima: %d", cont);
}
