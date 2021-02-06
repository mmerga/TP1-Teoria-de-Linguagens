// Alan Francisco da Silva.
// Júlio Hebert Silva.
#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int busca(estado estados[], int tamPalavra, int atualEstado, int atualIndice, char palavraInt[]){ // testar palavras no automato || principal metodo
        if(palavraInt[0] == ' '){
            if ( estados[atualEstado].tipo == 1){   
                return 1;
            }
        }
        if ( atualIndice == tamPalavra){ 
            if ( estados[atualEstado].tipo == 1){   
                return 1;                                                 
            }
        }else if ( estados[atualEstado].hasE == 1){ // possue movimento vazio
            for ( int j = 0; j < estados[atualEstado].qntE; j++){ // controle dos movimentos vazios ativados pelo estado atual 
                 if( busca(estados, tamPalavra, estados[atualEstado].proxE[j], (atualIndice), palavraInt)) {
                     return 1;
                     break;
                 }
            }            
        }
        for ( int i = 0 ; i < estados[atualEstado].qnt; i++){     // i transicoes do estado 
            if (  estados[atualEstado].alfa[i] == palavraInt[atualIndice] ){ 
                if( busca(estados, tamPalavra, estados[atualEstado].prox[i], (atualIndice + 1), palavraInt ) ) {
                    return 1;
                    break;
                }
            }
        }
        return 0;
          
}

int busca_palavra(estado estados[], char palavra[]){ // testar palavras no automato
    int tamPalavra = strlen(palavra);               
    return busca(estados, tamPalavra-1, 0 ,0 , palavra);        // tamPalavra-1 porque esta contando quebra de linha como caractere
}

void testa_palavras(estado estados[], char* palavras){ // testar palavras do .txt || imprime no terminal e em testes.txt
    FILE* arquivo = fopen(palavras, "r");
    if(arquivo){

        FILE* saida = fopen("testes.txt", "w");
        char frase[50];
        while(!feof(arquivo)){
            fgets(frase, 50, arquivo);
            if(busca_palavra(estados, frase)){
                printf("\nPalavra: %s eh aceita pelo automato.\n", frase);
                fprintf(saida, "\nPalavra: %s eh aceita pelo automato.\n", frase);
            }else{
                printf("\nPalavra: %s nao aceita pelo automato.\n", frase);
                fprintf(saida, "\nPalavra: %s nao aceita pelo automato.\n", frase);
            }
            if(feof(arquivo)){
                break;
            }
        }
        fclose(saida);

    }else{
        printf("\n\nERRO:\nNao possivel abrir arquivo com as palavras a serem testadas.\n\n");
    }
    fclose(arquivo);
}
