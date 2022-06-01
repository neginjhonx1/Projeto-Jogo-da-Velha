#include <stdlib.h>                          //inclui biblioteca
#include <stdio.h>                           //inclui biblioteca
#include<string.h>                           //inclui biblioteca
///////////////////////////////////////////////acima estão os locais nos quais as variáveis não citadas se encontram

int v[3][3] = {
    {0, 0, 0},
    {0, 0, 0},			                     //Matriz que armazena campos a serem preenchidos conforme o decorrer do jogo
    {0, 0, 0}                                //Para O, matriz imprime -1; para X, matriz imprime 1
};

char m[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},		                 //Matriz com as posições para X e O
    {'7', '8', '9'}
};

int v1=0, v2=0;                              //Declara as variáveis de vitória (v1=X, V2=O)
int quantcasa[8];                            //Vetor para a quantidade de casas para jogar
void printarM (){                             //Função para imprimir a matriz
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf ("%c\t", m[i][j]);
        }
        printf ("\n\n");
    }
}

void jogadaX (int casaX, int j) {                                        //Função para jogada em X
    int x;
    if (casaX <= 0 || casaX > 9 || quantcasa[casaX]==casaX) {            //Condiciona existência e disponibilidade da casa
        do{
            printf ("Digite novamente: ");                               //Pede para digitar novamente
            scanf ("%d",&casaX);                                         //(jogada inválida devido à posição inexistente ou casa ocupada)
        }while (casaX <= 0 || casaX > 9|| quantcasa[casaX]==casaX);      //Confere a disponibilidade da casa
    }
    quantcasa[casaX]=casaX;                                              //Vetor que associa as casas digitadas a X, tornando-as ocupadas
    if (casaX <= 3){                                                     //Condiciona número digitado X como parte da linha 1
        x = 3 - (4 - casaX);                                             //Conversão para posição
        j = x;
        m[0][j] = 'X';                                                   //Preenche posição com 'X'
        v[0][j] = 1;                                                     //Ocupa casa
    }
    if (casaX > 3 && casaX <= 6){                                        //Condiciona número digitado X como parte da linha 2
        x = 6 - (10 - casaX);                                            //Conversão para posição
        j = x;
        m[1][j] = 'X';                                                   //Preenche posição com 'X'
        v[1][j] = 1;                                                     //Ocupa casa
    }
    if (casaX > 6) {                                                     //Condiciona número digitado X como parte da linha 3
        x = 9 - (16 - casaX);                                            //Conversão para posição
        j = x;
        m[2][j] = 'X';                                                   //Preenche posição com 'X'
        v[2][j] = 1;                                                     //Ocupa casa
    }
}

void jogadaO (int casaO, int j) {                                         //Função para jogada em O
    int y;
    if (casaO <= 0 || casaO > 9 || quantcasa[casaO]==casaO){              //Condiciona existência e disponibilidade da casa
        do{
            printf ("Digite novamente: ");                                //Pede para digitar novamente
            scanf("%d",&casaO);                                           //(jogada inválida devido à posição inexistente ou casa ocupada)
        }while (casaO <= 0 || casaO > 9|| quantcasa[casaO]==casaO);       //Confere a disponibilidade da casa
    }
    quantcasa[casaO]=casaO;                                               //Vetor que associa as casas digitadas a O, tornando-as ocupadas
    if (casaO <= 3){                                                      //Condiciona número digitado O como parte da linha 1
        y = 3 - (4 - casaO);	                                          //Conversão para posição
        j = y;
        m[0][j] = 'O';                                                    //Preenche posição com 'O'
        v[0][j] = -1;                                                     //Ocupa casa
    }
    if (casaO > 3 && casaO <= 6){                                         //Condiciona número digitado O como parte da linha 2
        y = 6 - (10 - casaO);                                             //Conversão para posição
        j = y;
        m[1][j] = 'O';                                                    //Preenche posição com 'O'
        v[1][j] = -1;                                                     //Ocupa casa
    }
    if (casaO > 6){                                                       //Condiciona número digitado O como parte da linha 3
        y = 9 - (16 - casaO);                                             //Conversão para posição
        j = y;
        m[2][j] = 'O';                                                    //Preenche posição com 'O'
        v[2][j] = -1;                                                     //Ocupa casa
    }
}

void vitoriaColun(int somaColun){                                              //Função vitória vertical e diagonal
    somaColun=0;                                                          //Inicia soma dos valores da coluna em 0
    for(int i=0; i<3; i++){
        somaColun=somaColun+v[i][0];                                      //Primeira coluna
            if(somaColun==3){                                             //Condiciona vitória de X pela primeira coluna
                system("CLS");                                            //Limpa Tela
                printf("Vitoria do jogador X\n\n");                       //Printa a vitória de X
                printarM();                                               //Imprime a matriz do jogo
                v1=1;                                                     //Vitória de X
            }
            if(somaColun==-3){                                            //Condiciona vitória de O pela primeira coluna
                system("CLS");                                            //Limpa Tela
                printf("Vitoria do jogador O\n\n");                       //Printa a vitória de O
                printarM();                                               //Imprime a matriz do jogo
                v2=1;                                                     //Vitória de O
            }
    }
    somaColun=0;                                                          //Reseta soma dos valores da coluna
    for(int i=0; i<3; i++){
        somaColun=somaColun+v[i][1];                                      //Segunda coluna
            if(somaColun==3){                                             //Condiciona vitória de X pela segunda coluna
                system("CLS");
                printf("Vitoria do jogador X\n\n");                         //Printa a vitória de X
                printarM();
                v1=1;                                                     //Vitória de X
            }
            if(somaColun==-3){                                            //Condiciona vitória de O pela segunda coluna
                system("CLS");
                printf("Vitoria do jogador O\n\n");                         //Printa a vitória de O
                printarM();
                v2=1;                                                     //Vitória de O
            }
    }
    somaColun=0;                                                           //Reseta soma dos valores da coluna
    for(int i=0; i<3; i++){
        somaColun=somaColun+v[i][2];                                       //Terceira coluna
            if(somaColun==3){                                              //Condiciona vitória de X pela terceira coluna
                system("CLS");
                printf("Vitoria do jogador X\n\n");                          //Printa a vitória de X
                printarM();
                v1=1;                                                      //Vitória de X
            }
            if(somaColun==-3){                                             //Condiciona vitória de O pela terceira coluna
                system("CLS");
                printf("Vitoria do jogador O\n\n");                          //Printa a vitória de O
                printarM();
                v2=1;                                                      //Vitória de O
            }
    }
}

void vitoriaDiag(int somaDiag){
    somaDiag=0;                                                           //Reseta soma dos valores para diagonal
    somaDiag = v[0][0] + v[1][1] + v[2][2];                               //Soma posições que formam diagonal da esquerda para a direita
    if(somaDiag==3){                                                      //Condiciona vitória de X pela primeira diagonal
        system("CLS");
        printf("Vitoria do jogador X\n\n");                                  //Printa a vitória de X
        printarM();
        v1=1;                                                              //Vitória de X
    }
    if(somaDiag==-3){                                                     //Condiciona vitória de O pela primeira diagonal
        system("CLS");
        printf("Vitoria do jogador O\n\n");                                  //Printa vitória de O
        printarM();
        v2=1;                                                              //Vitória de O
    }
    somaDiag=0;                                                           //Reseta soma dos valores para diagonal
    somaDiag=v[2][0]+v[1][1]+v[0][2];                                     //Soma posições que formam diagonal da direita para a esquerda
    if(somaDiag==3){                                                      //Condiciona vitória de X pela psegunda diagonal
        system("CLS");
        printf("Vitoria do jogador X\n\n");                                  //Printa a vitória de X
        printarM();
        v1=1;                                                              //Vitória de X
    }
    if(somaDiag==-3){                                                     //Condiciona vitória de O pela segunda diagonal
        system("CLS");
        printf("Vitoria do jogador O\n\n");                                  //Printa a vitória de O
        printarM();
        v2=1;                                                              //Vitória de O
    }
}

void vitoriaLin(int somaLin){                                              //Função vitória horizontal
    somaLin=0;                                                             //Inicia soma dos valores da linha em 0
    for(int j=0; j<3; j++){
        somaLin=somaLin+v[0][j];                                           //Primeira linha
            if(somaLin==3){                                                //Condiciona vitória de X pela primeira linha
                system("CLS");
                printf("Vitoria do jogador X\n\n");                          //Printa a vitória de X
                printarM();
                v1=1;                                                      //Vitória de X
            }
            if(somaLin==-3){                                               //Condiciona vitória de O pela primeira linha
                system("CLS");
                printf("Vitoria do jogador O\n\n");                          //Printa a vitória de O
                printarM();
                v2=1;                                                      //Vitória de O
            }
    }
    somaLin=0;                                                             //Reseta soma dos valores para linha
    for(int j=0; j<3; j++){
        somaLin=somaLin+v[1][j];                                           //Segunda linha
            if(somaLin==3){                                                //Condiciona vitória de X pela segunda linha
                system("CLS");
                printf("Vitoria do jogador X\n\n");                          //Printa a vitória de X
                printarM();
                v1=1;                                                      //Vitória de X
            }
            if(somaLin==-3){                                               //Condiciona vitória de O pela segunda linha
                system("CLS");
                printf("Vitoria do jogador O\n\n");                          //Printa a vitória de O
                printarM();
                v2=1;                                                      //Vitória de O
            }
    }
    somaLin=0;                                                             //Reseta soma dos valores para linha
    for(int j=0; j<3; j++){
        somaLin=somaLin+v[2][j];                                           //Terceira linha
            if(somaLin==3){                                                //Condiciona vitória de X pela terceira linha
                system("CLS");
                printf("Vitoria do jogador X\n\n");                        //Printa a vitória de X
                printarM();                                                //Imprime a matriz do jogo
                v1=1;                                                      //Vitória de X
            }
            if(somaLin==-3){                                               //Condiciona vitória de O pela terceira linha
                system("CLS");
                printf("Vitoria do jogador O\n\n");                        //Printa a vitória de O
                printarM();                                                //Imprime a matriz do jogo
                v2=1;                                                      //Vitória de O
            }
    }
}

int main (){                                                               //Inicia função main
    int casaX, casaO, j, somaColun, velha=0, somaLin;                      //Declara variáveis inteiras
    do{
        system("cls");                                                     //Limpa tela
        printarM();                                                        //Imprime a matriz do jogo
        printf("Digite a casa para jogar o X: ");                         //Pede para 'X' jogar

        scanf("%d", &casaX);                                               //Lê a variável e associa a X
        jogadaX(casaX, j);                                                 //Entra na função X

        vitoriaColun(somaColun);                                           //Entra na função de vitória de vertical
        vitoriaLin(somaLin);                                               //Entra na função de vitória de linha
        vitoriaDiag(somaColun);                                            //Entra na função de vitória de diagonal
        velha=velha+1;                                                     //Conta o número de jogadas para conferir se "deu velha"

        if(v1==1 || v2==1 || velha==9){                                    //Condiciona vitória de X, O ou velha
            break;                                                         //Interrompe loop
        }

        system("cls");                                                     //Limpa tela
        printarM();                                                        //Imprime a matriz do jogo
        printf("Digite a casa para jogar o O: ");                         //Pede para 'O' jogar

        scanf("%d", &casaO);                                               //Lê a variável e associa a X
        jogadaO(casaO, j);                                                 //Entra na função O

        vitoriaColun(somaColun);                                           //Entra na função de vitória de vertical e diagonal
        vitoriaLin(somaLin);                                               //Entra na função de vitória de linha
        vitoriaDiag(somaColun);                                            //Entra na função de vitória de diagonal
        velha=velha+1;                                                     //Conta o número de jogadas para conferir se "deu velha"

        if(v1==1 || v2==1){                                                //Condiciona vitória de X ou O
            break;                                                         //Interrompe loop
        }
    }while(v1<1 && v2<1);                                                  //Confere se não houve vitória para continuar o loop

    if(velha==9 && v1!=1 && v2!=1){                                        //Condiciona velha
        system("CLS");
        printarM();                                                         //Imprime a matriz do jogo
        printf("\nDeu velha!!!\n");                                        //Printa velha
    }
}
