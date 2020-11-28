#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NO_OF_CHARS 256
#define MAXSTRING 1000

char cadenaStr[MAXSTRING] = {0};

int contadorRepeticion(char *str, char *buscar);
void removerPalabra(char *, const char);


void proper(){
    int i;

    printf("Ingrese la cadena:\n");
    scanf("%[^\n]s", &cadenaStr);

    for (i = 0; cadenaStr[i] != '\0'; i++) {
        if (i==0) {
            if (cadenaStr[i] >= 'a' && cadenaStr[i] <= 'z')
                cadenaStr[i] = cadenaStr[i] - 32;
            continue;
        }
        if (cadenaStr[i] == ' '){
            ++i;
            if (cadenaStr[i]>='a' && cadenaStr[i]<='z'){
                cadenaStr[i] = cadenaStr[i]-32;
                continue;
            }
        } else{
            if (cadenaStr[i]>='A' && cadenaStr[i]<='Z')
                cadenaStr[i] = cadenaStr[i]+32;
        }
    }
    printf("Cadena convertido a nombre propio es: %s\n ", cadenaStr);
}

void mostrarRepetir(){
    char buscar[MAXSTRING];
    int contador;

    printf("Ingrese la cadena:\n");
    gets(cadenaStr);
    printf("Ingrese la palabra que desee saber la repeticion:\n");
    gets(buscar);

    contador = contadorRepeticion(cadenaStr, buscar);

    printf("Numero total de repeticiones de %s es %d\n", buscar, contador);
}

int contadorRepeticion(char *str,  char *buscar){
    int encontrar, contadorAux;
    int longitudString, longitudPalabra;

    longitudString = strlen(str);
    longitudPalabra = strlen(buscar);

    contadorAux = 0;

    for (int i = 0; i < longitudString-longitudPalabra; ++i) {
        encontrar = 1;
        for (int j = 0; j < longitudPalabra; ++j) {
            if (str[i+j] != buscar[j]){
                encontrar = 0;
                break;
            }
        }
        if (encontrar == 1){
            contadorAux++;
        }
    }
    return contadorAux;
}

void mostrarEliminar(){
    char eliminar;

    printf("Ingrese la cadena:\n");
    gets(cadenaStr);

    printf("Ingrese la palabra a eliminar:\n");
    eliminar = getchar();

    removerPalabra(cadenaStr, eliminar);

    printf("La cadena con la palabra eliminada es %s\n", cadenaStr);

}

void removerPalabra(char *str, const char remover){
    int longitud = strlen(str);

    for (int i = 0; i < longitud; ++i) {
        if (str[i] == remover){
            for (int j = i; j < longitud; ++j) {
                str[j] = str[j+1];
            }
            longitud--;
            i--;
        }
    }

}

char* remove_repeatation(char *str)
{
    char flag[256] = {0};
    int  i            = 0;
    int  j            = 0;

    for(i=0; str[i] != '\0'; i++)
    {
        if(0 == flag[str[i]])
        {
            flag[str[i]] = 1;
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';
    return *str;
}

void interseccion() {

    int i, j, k = 0;

    char str1[NO_OF_CHARS];
    char str2[NO_OF_CHARS];
    char str3[NO_OF_CHARS];

    printf("ingrese la cadena 1: ");
    scanf("%s", &str1);


    printf("Ingrese la cadena 2: ");
    scanf("%s", &str2);

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    for (i = 0; i < len1; i++) {
        for (j = 0; j < len2; j++) {
            if (str1[i] == str2[j]) {
                str3[k] = str1[i];
                k++;
            }
        }
    }

    str3[k] = '\0';
    remove_repeatation(str3);
    printf("\nLa interseccion de las dos cadenas es:%s", str3);
    printf("\n");
}

int diferenciarStrings(){

    char str1[NO_OF_CHARS];
    char str2[NO_OF_CHARS];
    char str_rem[NO_OF_CHARS];
    int i = 0, j = 0, k = 0;

    printf("ingrese la cadena 1: ");
    scanf("%s", &str1);


    printf("Ingrese la cadena 2: ");
    scanf("%s", &str2);

    for (i = 0; str1[i] != '\0'; i++)    {
        for (j = 0; str2[j] != '\0'; j++){
            if (str1[i] == str2[j]){
                continue;
            }
            else{
                str_rem[k] = str2[j];
                k ++;
            }
        }
        str_rem[k] = '\0';
        strcpy (str2, str_rem);
        k = 0;
    }

    printf ("Los caracteres distintos de la cadena 2 a la 1 son: %s\n", str_rem);
    printf("\n");

    return 0;
}

int *getCharCountArray(char *str){
    int *count = (int *)calloc(sizeof(int), NO_OF_CHARS);
    int i;
    for (i = 0; *(str+i);  i++)
        count[*(str+i)]++;
    return count;
}

void *removeDirtyChars(char *str,char *mask_str) {
    int *count  = getCharCountArray(mask_str);
    int ip_ind  = 0, res_ind = 0;
    while (*(str + ip_ind))
    {
        char temp = *(str + ip_ind);
        if (count[temp] == 0)
        {
            *(str + res_ind) = *(str + ip_ind);
            res_ind++;
        }
        ip_ind++;
    }

    *(str+res_ind) = '\0';

    printf("El resultado es: %s",str);
    printf("\n");
}

void mainMenu(){

    char str[NO_OF_CHARS];
    char mask_str[NO_OF_CHARS];

    char *menu = ">>>MENU PRINCIPAL<<<\n\n1. Option 1 Convertir en nombre Propio el contenido de una cadena\n"
                 "2. Option 2 Numero de veces que existe una palabra en una cadena\n"
                 "3. Option 3 Encriptar cadena\n4. Option 4 Desencriptar cadena\n5. Option 5 Llenar caracteres por izquierda o derecha\n"
                 "6. Option 6 Borrar caracteres de una cadena\n7. Option 7 Interseccion entre dos cadenas\n"
                 "8. Option 8 Diferencia entre dos cadenas\n9. Option 9 Borrar caracteres izquierda o derecha\n"
                 "10. Salir\nDigite Opcion...\n";
    int option;

    do {
        system("cls");
        printf("%s", menu);
        scanf("%d", &option);
        fflush(stdin);

        switch (option) {
            case 1:
                proper();
                break;
            case 2:
                mostrarRepetir();
                break;
            case 6:
                mostrarEliminar();
                break;
            case 7:
                interseccion();
                break;
            case 8:
                diferenciarStrings();
                break;
            case 9:
                printf("cadena 1:");
                scanf("%s", &str);

                printf("Cadena 2:");
                scanf("%s", &mask_str);
                removeDirtyChars(str,mask_str);
                break;
            case 10: printf("Saliendo...\n");
                exit(0);

            default: printf("Opcion invalida");
                break;
        }

    }while (option != 10);
}

int main() {
    mainMenu();
    return 0;
}