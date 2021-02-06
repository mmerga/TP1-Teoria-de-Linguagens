// Alan Francisco da Silva.
// Júlio Hebert Silva.
#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimir_tabela(estado estados[], int cont){ // imprimir as transicoes do automato
    for( int i = 0 ; i<cont; i++){
        if (estados[i].tipo==1){
            printf("*");
        }
        if(estados[i].qnt==0){
            printf("q%d", estados[i].nome);
        }
        for( int j = 0 ; j<estados[i].qnt; j++){
            printf("q%d", estados[i].nome);
            printf("---> %c ---> q%d\n", estados[i].alfa[j], estados[i].prox[j] );
        }
        if(estados[i].hasE == 1){
            for ( int j = 0 ; j<estados[i].qntE; j++){
                printf("q%d", estados[i].nome);
                printf("---> E q%d\n", estados[i].proxE[j]);
            }
        }
        printf("\n");     
    }
    printf("\n");
} 

void adicionar_transicao(char frase[], estado estados[50], int* cont, char alfabeto[]){ // ler demais linhas do .txt do automato
    int tam = strlen(frase);      
    tam--;
    int i = 0;
    if(frase[0] == '*'){    // é final
            estados[*cont].tipo = 1;
            i++;
    }else{
        estados[*cont].tipo = 0;
    }
    
    char* aux = &frase[i]; 
    i++;
    estados[*cont].nome = atoi(aux); // cast char para int
    estados[*cont].qnt = 0 ;
    estados[*cont].qntE = 0 ;
    estados[*cont].hasE = 0 ;

    int alfa = 0;
    for( i=i+3; i < tam; i++){
        if(frase[i] == ' '){
            //faça nada
        }else if(frase[i] == '-'){     
            alfa++;    
        }else if(frase[i] == 'E'){
            estados[*cont].hasE = 1 ;
            aux = &frase[i+1];
            estados[*cont].proxE[estados[*cont].qntE] = atoi(aux);
            estados[*cont].qntE++;
            i++;
        }else{
            estados[*cont].alfa[estados[*cont].qnt] = alfabeto[alfa];
            aux = &frase[i];
            estados[*cont].prox[estados[*cont].qnt] = atoi(aux); // cast char para int
            estados[*cont].qnt++;
        }
    }

    *cont = *cont +1;
}

void ler_alfabeto(char frase[], char* alfabeto ){ // ler primeira linha do .txt do automato
    int contador = 0;
    int tam = strlen(frase);   
    tam--;
    
    for( int i = 0 ; i < tam; i++){ // pegar o alfabeto na primeira linha do arquivo    
        if(frase[i] != ' '){      
            alfabeto[contador++] = frase[i];   
        }
    }   
}