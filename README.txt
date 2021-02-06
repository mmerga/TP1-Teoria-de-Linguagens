----------====----------====----------====----------====----------====----------====

COMPILADO E TESTADO NO WINDOWS 10

----------====----------====----------====----------====----------====----------====

Para compilar o programa deve digitar:

gcc main.c palavras.c automato.c func.h -g -o tp

tp -a automato.txt -w palavra.txt

----------====----------====----------====----------====----------====----------====

** Auto.txt é o arquivo onde deve estar o automato a ser testado, 
porem deve ser escrito desta maneira:
AFN que tenha essa tabela:

&	0 		1
q0	{q0,q1}		{q0}
*q1	-		-

Deve ser escrito desta forma:

0 1
0 - 0 1 - 0
*1

----------====----------====----------====----------====----------====----------====

Para transicoes com movimento vazio, devese colocar a letra ' E ' 
para representar. Exemplo:
Estado q0 ativa q1 com movimento vazio, deve-se escrever no .txt:

0 - E1

----------====----------====----------====----------====----------====----------====

Palavra.txt deve conter as palavras a serem testadas pelo automato,
exemplo de escrita:

0
1
0000
 
001111
111111

----------====----------====----------====----------====----------====----------====

**  Caso queira testar palavra vazia, deve dar apenas um "espaço".

----------====----------====----------====----------====----------====----------====
