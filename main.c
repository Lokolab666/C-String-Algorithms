#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define NO_OF_CHARS 256
#define MAXSTRING 1000
#define TAM_ALFABETO 26
#define COD_ALFABETO_MAY 65
#define COD_ALFABETO_MIN 97
#define MOD(i, n) (i % n + n) % n

const char *alfabetoMinusculas = "abcdefghijklmnopqrstuvwxyz";
const char *alfabetoMayusculas = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char cadenaStr[MAXSTRING] = {0};

int contadorRepeticion(char *str, char *buscar);

void proper(){
    int i;

    printf("Ingrese la cadena:\n");
    fflush(stdin);
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
    char buscar[MAXSTRING] = "";
    int contador = 0;

    printf("Ingrese la cadena:\n");
    fflush(stdin);
    gets(cadenaStr);
    printf("Ingrese la palabra que desee saber la repeticion:\n");
    fflush(stdin);
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

    for (int i = 0; i < longitudString; ++i) {
        encontrar = 1;
        for (int j = 0; j < longitudPalabra; ++j) {
            if (str[i+j] != buscar[j] && str[i+j] != buscar[j]-32 && str[i+j]-32 != buscar[j]){
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

int valorCaracter(char c) {
    return (int)c;
}

void encriptar(char *mensaje, char *mensajeEncriptado){
    int i = 0;
    while (mensaje[i]) {
        char caracterActual = mensaje[i];
        int posicionOriginal = valorCaracter(caracterActual);
        //Comprueba si el carácter es alfabético o no
        if (!isalpha(caracterActual)) {
            mensajeEncriptado[i] = caracterActual;
            i++;
            continue;
        }
        //Verifica cuantos caracteres en mayuscula y minuscula existen
        if (isupper(caracterActual)) {
            mensajeEncriptado[i] = alfabetoMayusculas[(posicionOriginal - COD_ALFABETO_MAY + 2) % (TAM_ALFABETO-2)];
        } else {
            mensajeEncriptado[i] = alfabetoMinusculas[(posicionOriginal - COD_ALFABETO_MIN + 2) % (TAM_ALFABETO-2)];
        }
        i++;
    }
}

void desencriptar(char *mensajeEncriptado, char *mensaje){
    int i = 0;
    while (mensajeEncriptado[i]) {
        char caracterActual = mensajeEncriptado[i];
        int posicionOriginal = valorCaracter(caracterActual);
        if (!isalpha(caracterActual)) {
            mensaje[i] = caracterActual;
            i++;
            continue; // Ir a la siguiente iteración; por eso arriba aumentamos a i
        }
        if (isupper(caracterActual)) {
            mensaje[i] = alfabetoMayusculas[MOD(posicionOriginal - COD_ALFABETO_MAY - 2,(TAM_ALFABETO-2))];
        } else {
            mensaje[i] = alfabetoMinusculas[MOD(posicionOriginal - COD_ALFABETO_MIN - 2,(TAM_ALFABETO-2))];
        }
        i++;
    }
}

void funcionEncriptar(){
    char cadena[300] = "";
    char cadenaEncriptada[300] = "";
    printf("Ingrese la cadena que desea encriptar : ");
    fflush(stdin);
    fgets(cadena, 300, stdin);
    cadena[strcspn(cadena,"\r\n")] = 0;
    printf("La cadena ingresada es: %s\n", cadena);
    encriptar(cadena,cadenaEncriptada);
    printf("La cadena encriptada es: %s\n", cadenaEncriptada);
}

void funcionDesencriptar() {
    char cadenaEncriptada[300] = "";
    char cadenaDesencriptada[300] = "";
    printf("Ingrese la cadena que se desea desencriptar : ");
    fflush(stdin);
    fgets(cadenaEncriptada, 300, stdin);
    cadenaEncriptada[strcspn(cadenaEncriptada, "\r\n")] = 0;
    printf("La cadena encriptada ingresada es: %s\n", cadenaEncriptada);
    desencriptar(cadenaEncriptada, cadenaDesencriptada);
    printf("La cadena desencriptada es: %s\n", cadenaDesencriptada);
}

void showRepetition(){
    int optionIzDer, numVeces;
    char agregar;

    printf("Ingrese la cadena:\n");
    fflush(stdin);
    gets(cadenaStr);
    printf("Ingrese el caracter a repetir:\n");
    fflush(stdin);
    agregar = getchar();

    printf("Ingrese el numero de veces que desea que se repita el caracter:\n");
    fflush(stdin);
    scanf("%i", &numVeces);
    printf("Digite 1 si es por izquierda o 2 si es por derecha:\n");
    fflush(stdin);
    scanf("%d", &optionIzDer);
    while(optionIzDer != 1 && optionIzDer != 2){
        printf("El numero ingresado no es correcto\n");
        printf("Digite 1 si es por izquierda o 2 si es por derecha:\n");
        fflush(stdin);
        scanf("%d", &optionIzDer);
    }

    if (optionIzDer == 1){
        for (int i = 0; i < numVeces; ++i) {
            printf("%c", agregar);
        }
        printf("%s\n", cadenaStr);
    }if (optionIzDer == 2){
        printf("%s", cadenaStr);
        for (int i = 0; i < numVeces; ++i) {
            printf("%c", agregar);
        }
    }
    printf("\n");
}

void removerCaracter(char *cadena, int caracter) {
    int indiceCadena = 0, indiceCadenaLimpia = 0;
    int contador = 1;
    while (cadena[indiceCadena]) {
        contador = 1;
        if (cadena[indiceCadena] == caracter || cadena[indiceCadena]-32 == caracter || cadena[indiceCadena] == caracter-32) {
            contador = 0;
        }

        if (contador == 1) {
            cadena[indiceCadenaLimpia] = cadena[indiceCadena];
            indiceCadenaLimpia++;
        }
        indiceCadena++;
    }
    cadena[indiceCadenaLimpia] = 0;
}

void funcionBorrarCaracteres(){
    char cadena[300] = "";
    char caracter[1];
    int tamCaracter;
    int codigo;

    printf("Ingresar una cadena : ");
    fflush(stdin);
    gets(cadena);
    printf("Ingresar el caracter que desea eliminar : ");
    fflush(stdin);
    scanf("%c", &caracter);
    codigo = caracter[0];
    tamCaracter = strlen(caracter);
    printf("La cadena ingresada es : %s\n",cadena);
    printf("El caracter ingresado para eliminar es : %c\n",caracter[0]);
    removerCaracter(cadena,codigo);
    printf("La cadena final es : %s\n",cadena);
}

char* remove_repeatation(char *str)
{
    char flag[256] = {0};
    int  i            = 0;
    int  j            = 0;

    for(i=0; str[i] != '\0'; i++){
        if(0 == flag[str[i]] || 0 == flag[str[i]]-32){
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

    printf("Ingrese la cadena 1: ");
    fflush(stdin);
    scanf("%s", &str1);


    printf("Ingrese la cadena 2: ");
    fflush(stdin);
    scanf("%s", &str2);

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    for (i = 0; i < len1; i++) {
        for (j = 0; j < len2; j++) {
            if (str1[i] == str2[j] || str1[i]-32 == str2[j] || str1[i] == str2[j]-32) {
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

    printf("Ingrese la cadena 1: ");
    fflush(stdin);
    scanf("%[^\n]s", &str1);

    printf("Ingrese la cadena 2: ");
    fflush(stdin);
    scanf("%[^\n]s", &str2);

    for (i = 0; str1[i] != '\0'; i++)    {
        for (j = 0; str2[j] != '\0'; j++){
            if (str1[i] == str2[j] || str1[i]-32 == str2[j] || str1[i] == str2[j]-32){
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
        printf("%s", menu);
        fflush(stdin);
        scanf("%d", &option);

        switch (option) {
            case 1:
                proper();
                break;
            case 2:
                mostrarRepetir();
                break;
            case 3:
                funcionEncriptar();
                break;
            case 4:
                funcionDesencriptar();
                break;
            case 5:
                showRepetition();
                break;
            case 6:
                funcionBorrarCaracteres();
                break;
            case 7:
                interseccion();
                break;
            case 8:
                diferenciarStrings();
                break;
            case 9:
                printf("cadena 1:");
                fflush(stdin);
                scanf("%s", &str);

                printf("Cadena 2:");
                fflush(stdin);
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
