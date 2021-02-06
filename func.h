// Alan Francisco da Silva.
// Júlio Hebert Silva.
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct estado{
    int nome;
    int tipo;   // 0 inicial  1 final
    char alfa[15];
    int prox[15];
    int qnt;
    int hasE;
    int qntE;
    int proxE[15];
}estado;

// PALAVRAS

int busca(estado estados[], int tamPalavra, int atualEstado, int atualIndice, char palavraInt[]);   // testar palavras no automato || principal metodo

int busca_palavra(estado estados[], char palavra[]);    // testar palavras no automato

void testa_palavras(estado estados[], char* palavras);  // testar palavras do .txt || imprime no terminal e em testes.txt

// AUTOMATO

void imprimir_tabela(estado estados[], int cont);     // imprimir as transicoes do automato

void adicionar_transicao(char frase[], estado estados[50], int* cont, char alfabeto[]);     // ler demais linhas do .txt do automato

void ler_alfabeto(char frase[], char* alfabeto );   // ler primeira linha do .txt do automato
