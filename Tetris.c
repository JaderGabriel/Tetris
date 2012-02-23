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

typedef struct peca{
    int tipo;
    int rota;
    int forma[4][4];
}peca;

//== Declaração de protótipos de funções ==

 void pri(peca ps);
 peca gerar();
 peca sobelinha(  peca ps);
 peca cumelinha(  peca ps);
 peca girar(  peca ps);

//== Corpo das funções ==

// Gera a peça do 'bancon'
peca gerar(){
    int i,j;
    peca ps;

    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(j!=2){
                ps.forma[i][j]=0;
            }
            else{
                ps.forma[i][j]=1;
            }
            //printf("%d",ps.forma[i][j]);
        }
        //printf("\n");

    }
    return ps;
}

// Função que reorganiza as linhas da matriz, retirando
// as linhas vazias acima, subindo as demais e zerando a última linha.
peca sobelinha(peca ps){
    int i,j;

    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(i==3){
                //printf("\n entrou \n");
                ps.forma[i][j]=0;
            }
            else
                ps.forma[i][j]=ps.forma[i+1][j];
        }
    }
    printf("\n Funcao sobelinha\n");
    pri(ps);
}

// verifica se há alguma linha vazia na matriz da peça
// se houver, a função 'sobelinha' é chamada
peca cumelinha(peca ps){
    int i,j,k;

    for(i=0;i<=3;i++){
        k=0;
        for(j=0;j<=3;j++){
            if(ps.forma[i][j]==0)
                k++;
        }
        if(k==4)
            ps = sobelinha(ps);
    }
    return ps;
}

// função que faz a rotação das peças
peca girar(peca ps){
    peca rodada;

    int k,i,j,temp;
    for(i=0;i<=3;i++){//Rodando a matriz
        for(j=0;j<=3;j++){
            rodada.forma[j][i]=ps.forma[3-i][j];
        }
        rodada = cumelinha(rodada); // verificando linha em branco
    }
    printf("\nrodada o/\n");
    pri(rodada);
    return rodada;
}

// função que imprime na tela a peça
void pri(peca ps){
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
    peca proxima_peca, peca_atual;
    int i,j;

    proxima_peca.forma[0][0]=0;
    proxima_peca.forma[0][1]=1;
    proxima_peca.forma[0][2]=0;
    proxima_peca.forma[0][3]=0;
    proxima_peca.forma[1][0]=0;
    proxima_peca.forma[1][1]=1;
    proxima_peca.forma[1][2]=1;
    proxima_peca.forma[1][3]=0;
    proxima_peca.forma[2][0]=0;
    proxima_peca.forma[2][1]=1;
    proxima_peca.forma[2][2]=0;
    proxima_peca.forma[2][3]=0;
    proxima_peca.forma[3][0]=0;
    proxima_peca.forma[3][1]=0;
    proxima_peca.forma[3][2]=0;
    proxima_peca.forma[3][3]=0;

    peca_atual = gerar(peca_atual);
    printf("peca atual \n");
    pri(peca_atual);
/*    printf("\n proxima peca\n");
    pri(proxima_peca); //ok
    proxima_peca = girar(proxima_peca);
    printf("\n peca girada\n");
    pri(proxima_peca);
    //proxima_peca = girar(proxima_peca);
    //pri(proxima_peca);
*/
    return 0;
}

