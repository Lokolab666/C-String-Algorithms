#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSTRING 1000

char cadenaStr[MAXSTRING] = {0};

int contadorRepeticion(char *str, char *buscar);
void removerPalabra(char *, const char);


void proper(){

    int i;

    printf("Ingrese la cadena:\n");
    scanf("%[^\n]s", cadenaStr);

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

void mainMenu(){

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
            case 1: proper();
                break;

            case 2: mostrarRepetir();
                break;

            case 6: mostrarEliminar();
                break;

            case 10: printf("Saliendo\n");
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
