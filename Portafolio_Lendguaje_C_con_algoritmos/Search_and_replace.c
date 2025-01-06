#include <stdio.h>

#define ARR_LEN 1024
#define TRUE 1
#define FALSE 0

int buscar_palabra(char*,char*,int*);
int longitud(char*);
//int reemplazar(char*,char*);
//int recorrer(char*, int);

int main(void)
{
    char frase[ARR_LEN];
    char *ptr_frase;
    char palabra[ARR_LEN];
    char *ptr_palabra;
    int selector,frase_len,palabra_len, posicion;
    int ptr_posicion;

    ptr_posicion = &posicion;
    ptr_frase = &frase[0];
    ptr_palabra = &palabra[0];

    do
    {
        printf("\n[1] Capturar frase.\n[2] Reemplazar palabra.\n[3] Terminar programa.\nIngrese una opcion valida: ");
        scanf("%d", &selector);

        switch(selector)
        {
            case 1:

            printf("\nCapturar frase: ");
            ffush(stdin);
            fgets(ptr_frase,ARR_LEN,stdin);

            frase_len = longitud(ptr_frase);
            break;
            
            case 2:

            do{
            printf("\nBuscar palabra: ");
            fflush(stdin);
            fgets(ptr_palabra, ARR_LEN, stdin);

            palabra_len = longitud(ptr_palabra);

            if(buscar_palabra(ptr_frase, ptr_palabra) == TRUE)return FALSE;
            else printf("\nPalabra no encontrada.") return TRUE;
            }while(TRUE);

            break;
            case 3:

            ptintf("\nPrograma terminado\n");
            return FALSE;
            break;

            default:

            printf("\nOpcion invalida, intenta nuevamente.\n");
            break;

        }
    }while(TRUE);


    return 0;
}

int longitud(char *string)
{
    int i;

    for(i=0; i<ARR_LEN; i++)
    {
        if(*(string + i) == '\n')*(string + i) = '\0';
        if(*(string + i) == '\0')break;
    }
    return i;
}

int buscar_palabra(char *frase, char *palabra, int *posicion)
{
    int i, j, contador;

    for(i=0; i<ARR_LEN; i++)
    {
        if(*(frase + i) == *palabra)
        {
            *posicion = i;
            contador = 0;
            for(j=0; j<ARR_LEN; j++)
            {
                if(*(frase + i + j) == *(palabra + j))contador++;
                else if(*(frase + i + j) == '\0' && *(palabra + j) == '\0')return TRUE;
                else break;
            }
        }
        else if(*(frase + i) == '\0')return FALSE;
    }
}