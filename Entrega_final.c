#include <stdio.h> //libreria para entrada y salida de datos
#include <string.h> //libreria para manejo de cadenas de caracteres

//Funcion menu: muestra el menu y solicita al usuario que ingrese una opcion, luego devuelve la opcion elegida
int mostrar_menu(int *opcion_elegida){
    printf("\nENCRIPTACION\n");
    printf("0. Cargar palabra\n");
    printf("1. Encriptar por el metodo de Abecedario Desordenado\n");
    printf("2. Desencriptar por el metodo de Abecedario Desordenado\n");
    printf("3. Encriptar por el metodo de Vocales Invertidas\n");
    printf("4. Desencriptar por el metodo de Vocales Invertidas\n");
    printf("5. Salir\n");
    printf("Ingrese una opcion: ");
    scanf("%d", opcion_elegida);
    return *opcion_elegida;
}

//Funcion para cargar la palabra: no devuelve ningun valor
void cargar_palabra(char palabras[4][50]){ //[4] es por lo que pidieron 4 palabras para probar el sistema, solo se deberia modificar el for
    for(int i=0; i<1; i++){ //se puede modificar el numero 1 por otro numero para cargar mas palabras, pero se debe modificar el menu y las funciones de encriptacion y desencriptacion para que trabajen con todas las palabras cargadas
        printf("Ingrese la palabra %d (solo minusculas, sin espacios): ", i+1);
        scanf("%s", palabras[i]);
    }
    printf("Palabra cargada exitosamente.\n");
}

//Funcion metodo del abecedarios desordenado
void abecedario_desordenado(char palabras[4][50], int modo){ 
    char normal[]=     "abcdefghijklmnopqrstuvwxyz"; //abecedario normal
    char desordenado[]="qwertyuiopasdfghjklzxcvbnm"; //abecedario desordenado 
    for(int p=0; p<1; p++){  
        printf("Palabra original: %s\n", palabras[p]); //muestra la palabra original antes de encriptar o desencriptar
        for(int i=0; palabras[p][i]!='\0'; i++){ 
            char letra=palabras[p][i];
            if(letra>='a' && letra<='z'){ //recorre la palabra letra por letra
                if(modo==1){ //encritar
                    int posicion=letra-'a'; //calcula la posicion de la letra en el abecedario normal
                    palabras[p][i]=desordenado[posicion]; //reemplaza la letra por la letra correspondiente en el abecedario desordenado'
                }
                else{  //desencriptar
                    for(int j=0; j<26; j++){
                        if(desordenado[j]==letra){  //busca la letra en el abecedario desordenado para encontrar su posicion
                            palabras[p][i]=normal[j]; //reemplaza la letra por la letra correspondiente en el abecedario normal
                            break;
                        }
                    }
                }
            }
        }
        printf("Resultado: %s\n", palabras[p]);
    }
}
//Funcion metodo de vocales invertidas
void vocales_invertidas(char palabras[4][50]){
    char normal[]="aeiou"; //vocales normales
    char invertidas[]="uoiea"; //vocales invertidas
    for(int p=0; p<1; p++){
        printf("Palabra original: %s\n", palabras[p]); //muestra la palabra original antes de encriptar o desencriptar
        for(int i=0; palabras[p][i]!='\0'; i++){ //recorre la palabra letra por letra
            char letra=palabras[p][i];
            if(letra=='a' || letra=='e' || letra=='i' || letra=='o' || letra=='u'){ //si es vocal busca la posicion y la reemplaza
                for(int j=0; j<5; j++){
                    if(normal[j]==letra){
                        palabras[p][i]=invertidas[j];
                        break; //al ser espejo, la misma funcion sirve para encriptar y desencriptar, por lo que no es necesario verificar el modo
                    }
                }
            }
        }
        printf("Resultado: %s\n", palabras[p]); //muestra el resultado despues de encriptar o desencriptar
    }
}
//Funcion principal
int main(){
    char palabras[4][50];
    int opcion;
    int cargado=0, encriptado_metodo1=0, encriptado_metodo2=0; //variables de control para verificar si se han cargado palabras y si se han encriptado con cada metodo, para evitar errores al intentar encriptar o desencriptar sin haber cargado palabras o sin haber encriptado previamente
    do{
        mostrar_menu(&opcion); //muestra el menu y obtiene la opcion seleccionada por el usuario
        switch(opcion){
            case 0: //carga las palabras
                cargar_palabra(palabras);
                cargado=1;
                encriptado_metodo1=0;
                encriptado_metodo2=0;
            break;
            case 1: //palabra cargada y encriptada por el metodo 1
                if(cargado == 0){ //caso de no estar cargada la palabra
                printf("\nNo se han cargado palabras. Por favor, cargue las palabras primero.\n");
                }
                else if(encriptado_metodo1 == 1 || encriptado_metodo2 == 1){ //para evitar que encripte una palabra ya encriptada con cualquiera de los metodos
                printf("\nError: La palabra ya se encuentra encriptada. Desencriptela primero.\n");
                }
                else{ //resultado
                printf("\nAbecedario Desordenado - Encriptar\n");
                abecedario_desordenado(palabras, 1);
                encriptado_metodo1 = 1;
                }
            break;
            case 2: //desencriptar por el metodo 1 
                if(encriptado_metodo1){ 
                    printf("\nAbecedaario Desordenado - Desencriptar\n");
                    abecedario_desordenado(palabras, 2);
                    encriptado_metodo1=0;
                }
                else{
                    printf("\nNo se han encriptado las palabras con el metodo de Abecedario Desordenado. Por favor, encripte primero.\n");
                }
            break;
            case 3: //palabraencriptada por el segundo metodo
                if(cargado == 0){ //caso de no estar cargada la palabra
                    printf("\nNo se han cargado palabras. Por favor, cargue las palabras primero.\n");
                }
                else if(encriptado_metodo1 == 1 || encriptado_metodo2 == 1){ //para evitar que encripte una palabra ya encriptada con cualquiera de los metodos
                    printf("\nError: La palabra ya se encuentra encriptada. Desencriptela primero.\n");
                }
                else{ //resultados
                    printf("\nVocales Invertidas - Encriptar\n");
                    vocales_invertidas(palabras);
                    encriptado_metodo2 = 1;
                }
            break;
            case 4: //desencriptar por el metodo 2
                if(encriptado_metodo2){
                    printf("\nVocales Invertidas - Desencriptar\n");
                    vocales_invertidas(palabras);
                    encriptado_metodo2=0;
                }
                else{
                    printf("\nNo se han encriptado las palabras con el metodo de Vocales Invertidas. Por favor, encripte primero.\n");
                }
                break;
            case 5: //salir del programa
                printf("\nSaliendo del programa. ¡Hasta luego!\n");
            break;
        }
    } while(opcion!=5); //el programa se ejecuta hasta que el usuario elige la opcion de salir
    return 0;
}