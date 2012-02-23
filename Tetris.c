/*
UNIVERSIDADE ESTADUAL DE MONTES CLAROS - UNIMONTES
GRUPO DE ESTUDOS EM JOGOS
Programa: Tetris
Linguagem: C
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>


//== Declaração de estruturas ==

// Uma peça do tetris possui seu tipo, que define sua estrutura
// possui sua rota, que indica as coordenadas 'x' e 'y'
// forma que define sua matriz
typedef struct Peca{
    int tipo;
    int rota;
    int forma[4][4];
}peca;

//== Protótipos de funções ==
peca Gerar(int tipo);
peca Sobelinha(peca ps);
peca VerificaLinha(peca ps);
peca Girar(peca ps);

//== Corpo das funções ==

// Função que gera uma peça de acordo com o tipo fornecido pela
// 'main()' e retorna a matriz da peça
peca Gerar(int tipo){
    peca nova_peca;
    int i,j;

    // Criar o 'bacon'
    if(tipo==1){
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                if(j!=1){
                    nova_peca.forma[i][j]=0;
                }
                else{
                    nova_peca.forma[i][j]=1;
                }
            }
        }
        return (nova_peca);
    }
    // Criar o 'zzim da zaza'
    else if(tipo==2){

    }
    // Criar o 'zzim invertido'
    else if(tipo==3){

    }
    // Criar o 'triangulo da morte'
    else if(tipo==4){

    }
    // Criar o 'Lzim'
    else if(tipo==5){

    }
    // Criar o 'Lzim invertido'
    else if(tipo==6){

    }
    // Criar o 'bloco'
    else if(tipo==7){
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                if(i==j && (i!=0 || i!=3) ){
                    nova_peca.forma[i][j]=1;
                }
                else
                    nova_peca.forma[i][j]=0;
            }
        }
        return (nova_peca);
    }
}

// Função que reorganiza as linhas da matriz, retirando
// as linhas vazias acima, subindo as demais e zerando a última linha.
peca Sobelinha(peca ps){
    int i,j;

    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(i==3){
                ps.forma[i][j]=0;
            }
            else
                ps.forma[i][j]=ps.forma[i+1][j];
        }
    }
}

// verifica se há alguma linha vazia na matriz da peça
// se houver, a função 'sobelinha' é chamada
peca VerificaLinha(peca ps){
    int i,j,k;

    for(i=0;i<3;i++){
        k=0;
        for(j=0;j<4;j++){
            if(ps.forma[i][j]==0)
                k++;
        }
        if(k==4){
            ps = Sobelinha(ps);
            return(ps);
        }
    }
    return (ps);
}

// função que faz a rotação das peças
peca Girar(peca ps){
    peca rodada;

    int i,j,temp;
    for(i=0;i<4;i++){//Rodando a matriz
        for(j=0;j<4;j++){
            rodada.forma[j][i]=ps.forma[3-i][j];
        }
        rodada = VerificaLinha(rodada); // verificando linha em branco
    }
    return rodada;
}

// função que imprime na tela as peças
void Imprime(peca ps){
    int i,j;

    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("%d|",ps.forma[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(){
    int campo[18][10];
    peca peca_atual;



    return(0);
}
