// Alan Francisco da Silva.
// Júlio Hebert Silva.
#include "func.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main (int argc, char** argv){

    char* automato;
    char* palavras;
    //parametros(automato, palavras);
    //
    char opcao;
    while((opcao = getopt(argc, argv, "a:w:")) != -1){ 
      switch(opcao){
        case 'a':
          automato = optarg;
          break;
        case 'w':
          palavras = optarg;
          break;
        default:
          printf("Parâmetro errados tente novamente.\n");

       }
    }
    printf("%s %s \n", automato, palavras);

    FILE* arquivo = fopen(automato, "r");
    if(arquivo){

        estado estados[100];
        char alfabeto[50];
        int cont = 0;
        while(!feof(arquivo)){
            char frase[50];
            fgets(frase, 50, arquivo);
            ler_alfabeto(frase, alfabeto); 

            while(!feof(arquivo)){
                fgets(frase, 50, arquivo);  
                adicionar_transicao(frase, estados, &cont, alfabeto);  
                if(feof(arquivo)){
                    break;
                }         
            }
            break;
        }

        printf("\n\nAutomato lido com sucesso.\n\n");
        fclose(arquivo);
        int n = -1;
        while(n!=0){
            printf("\n\n1 - Imprimir transicoes do automato.\n2 - Testar palavras.\n0 - Sair.\n");
            scanf("%d", &n);
            while(n<0 || n>2){
                printf("\n\nOpcao invalida, tente novamente.\n");
                printf("1 - Imprimir transicoes do automato.\n2 - Testar palavras.\n0 - Sair.\n");
                scanf("%d", &n);
            }
            if(n==1){
                imprimir_tabela(estados, cont);
            }else if(n==2){
                testa_palavras(estados, palavras);
            }
        }

    }else{
        printf("\n\nERRO:\nNao possivel abrir arquivo com automato.\n\n");
    }

    
    printf("\n");
    return 0;
}