#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void transmitir_bit(int bit){
        if(bit == 1){
                printf("[+5]");
        }else{
                printf("[-5]");
        } 
}

int ruido(int bit){
        int probabilidad = 10;
        int random = rand() % 100;
        if(random < probabilidad){
                return !bit;
        }else{
                return bit;
        }
}

void imprimir_binario(char letra){
    printf("Letra: %c ", letra);
    char repAscii[8];
        for(int i = 7; i >= 0; i--){
                int bit = (letra >> i) & 1;
                repAscii[7-i] = bit + '0';
                transmitir_bit(bit);
        }
        printf(" \n");
        repAscii[8] = '\0';
        printf("Representacion en binario: %s \n", repAscii);
        printf(" \n");
}

void imprimir_binario_con_ruido(char letra){
    printf("Letra: %c ", letra);
    char repAscii[8];
        for(int i = 7; i >= 0; i--){
                int bit = (letra >> i) & 1;
                bit = ruido(bit);
                repAscii[7-i] = bit + '0';
                transmitir_bit(bit);
        }
        printf(" \n");
        repAscii[8] = '\0';
        printf("Representacion en binario con ruido: %s \n", repAscii);
        printf(" \n");
}

int main(){
        srand(time(NULL));

        char palabra[20];
        printf("Ingresa la palabra: \n");
        scanf("%19s", palabra);
        printf("\n");

                for (int i = 0; i < strlen(palabra); i++){
                        imprimir_binario(palabra[i]);
                }
        printf("-------------------------------\n");
                for (int i = 0; i < strlen(palabra); i++){
                        imprimir_binario_con_ruido(palabra[i]);
                }

        return 0;
}
