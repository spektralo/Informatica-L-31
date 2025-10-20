#include<stdio.h>
#include<string.h>
#define DIM 30
int main(){

    char nome[DIM], cognome[DIM], comuni[DIM];
    int comuniIndex=0;
    printf("Inserisci il tuo nome:");
    scanf("%s", nome);

    printf("Inserisci il tuo cognome:");
    scanf("%s", cognome);
    
    printf("\nPrima e terza lettera nome:%c %c",nome[0],nome[2]);
    printf("\nSeconda e quarta lettera cognome:%c %c",cognome[1],cognome[3]);

    for (int i = 0; i < strlen(nome); i++) {
        for (int j = 0; j < strlen(cognome); j++) {
            if (nome[i] == cognome[j]) {
                // Verifica se il carattere è già presente nella stringa comuni
                int alreadyPresent = 0;
                for (int k = 0; k < comuniIndex; k++) {
                    if (comuni[k] == nome[i]) {
                        alreadyPresent = 1;
                        break;
                    }
                }
                // Se il carattere non è già presente, lo aggiunge
                if (!alreadyPresent) {
                    comuni[comuniIndex++] = nome[i];
                }
            }
        }
    }

    // Aggiunge il terminatore di stringa
    comuni[comuniIndex] = '\0';

    // Stampa i caratteri comuni
    printf("\nCaratteri comuni tra nome e cognome: %s\n", comuni);
      
      
    }
