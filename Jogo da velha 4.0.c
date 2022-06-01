#include <stdlib.h>                          //inclui biblioteca
#include <stdio.h>                           //inclui biblioteca
#include<string.h>                           //inclui biblioteca
///////////////////////////////////////////////acima est�o os locais nos quais as vari�veis n�o citadas se encontram

int v[3][3] = {
    {0, 0, 0},
    {0, 0, 0},			                     //Matriz que armazena campos a serem preenchidos conforme o decorrer do jogo
    {0, 0, 0}                                //Para O, matriz imprime -1; para X, matriz imprime 1
};

char m[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},		                 //Matriz com as posi��es para X e O
    {'7', '8', '9'}
};

int v1=0, v2=0;                              //Declara as vari�veis de vit�ria (v1=X, V2=O)
int quantcasa[8];                            //Vetor para a quantidade de casas para jogar
void printarM (){                             //Fun��o para imprimir a matriz
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf ("%c\t", m[i][j]);
        }
        printf ("\n\n");
    }
}

void jogadaX (int casaX, int j) {                                        //Fun��o para jogada em X
    int x;
    if (casaX <= 0 || casaX > 9 || quantcasa[casaX]==casaX) {            //Condiciona exist�ncia e disponibilidade da casa
        do{
            printf ("Digite novamente: ");                               //Pede para digitar novamente
            scanf ("%d",&casaX);                                         //(jogada inv�lida devido � posi��o inexistente ou casa ocupada)
        }while (casaX <= 0 || casaX > 9|| quantcasa[casaX]==casaX);      //Confere a disponibilidade da casa
    }
    quantcasa[casaX]=casaX;                                              //Vetor que associa as casas digitadas a X, tornando-as ocupadas
    if (casaX <= 3){                                                     //Condiciona n�mero digitado X como parte da linha 1
        x = 3 - (4 - casaX);                                             //Convers�o para posi��o
        j = x;
        m[0][j] = 'X';                                                   //Preenche posi��o com 'X'
        v[0][j] = 1;                                                     //Ocupa casa
    }
    if (casaX > 3 && casaX <= 6){                                        //Condiciona n�mero digitado X como parte da linha 2
        x = 6 - (10 - casaX);                                            //Convers�o para posi��o
        j = x;
        m[1][j] = 'X';                                                   //Preenche posi��o com 'X'
        v[1][j] = 1;                                                     //Ocupa casa
    }
    if (casaX > 6) {                                                     //Condiciona n�mero digitado X como parte da linha 3
        x = 9 - (16 - casaX);                                            //Convers�o para posi��o
        j = x;
        m[2][j] = 'X';                                                   //Preenche posi��o com 'X'
        v[2][j] = 1;                                                     //Ocupa casa
    }
}

void jogadaO (int casaO, int j) {                                         //Fun��o para jogada em O
    int y;
    if (casaO <= 0 || casaO > 9 || quantcasa[casaO]==casaO){              //Condiciona exist�ncia e disponibilidade da casa
        do{
            printf ("Digite novamente: ");                                //Pede para digitar novamente
            scanf("%d",&casaO);                                           //(jogada inv�lida devido � posi��o inexistente ou casa ocupada)
        }while (casaO <= 0 || casaO > 9|| quantcasa[casaO]==casaO);       //Confere a disponibilidade da casa
    }
    quantcasa[casaO]=casaO;                                               //Vetor que associa as casas digitadas a O, tornando-as ocupadas
    if (casaO <= 3){                                                      //Condiciona n�mero digitado O como parte da linha 1
        y = 3 - (4 - casaO);	                                          //Convers�o para posi��o
        j = y;
        m[0][j] = 'O';                                                    //Preenche posi��o com 'O'
        v[0][j] = -1;                                                     //Ocupa casa
    }
    if (casaO > 3 && casaO <= 6){                                         //Condiciona n�mero digitado O como parte da linha 2
        y = 6 - (10 - casaO);                                             //Convers�o para posi��o
        j = y;
        m[1][j] = 'O';                                                    //Preenche posi��o com 'O'
        v[1][j] = -1;                                                     //Ocupa casa
    }
    if (casaO > 6){                                                       //Condiciona n�mero digitado O como parte da linha 3
        y = 9 - (16 - casaO);                                             //Convers�o para posi��o
        j = y;
        m[2][j] = 'O';                                                    //Preenche posi��o com 'O'
        v[2][j] = -1;                                                     //Ocupa casa
    }
}

void vitoriaColun(int somaColun){                                              //Fun��o vit�ria vertical e diagonal
    somaColun=0;                                                          //Inicia soma dos valores da coluna em 0
    for(int i=0; i<3; i++){
        somaColun=somaColun+v[i][0];                                      //Primeira coluna
            if(somaColun==3){                                             //Condiciona vit�ria de X pela primeira coluna
                system("CLS");                                            //Limpa Tela
                printf("Vitoria do jogador X\n\n");                       //Printa a vit�ria de X
                printarM();                                               //Imprime a matriz do jogo
                v1=1;                                                     //Vit�ria de X
            }
            if(somaColun==-3){                                            //Condiciona vit�ria de O pela primeira coluna
                system("CLS");                                            //Limpa Tela
                printf("Vitoria do jogador O\n\n");                       //Printa a vit�ria de O
                printarM();                                               //Imprime a matriz do jogo
                v2=1;                                                     //Vit�ria de O
            }
    }
    somaColun=0;                                                          //Reseta soma dos valores da coluna
    for(int i=0; i<3; i++){
        somaColun=somaColun+v[i][1];                                      //Segunda coluna
            if(somaColun==3){                                             //Condiciona vit�ria de X pela segunda coluna
                system("CLS");
                printf("Vitoria do jogador X\n\n");                         //Printa a vit�ria de X
                printarM();
                v1=1;                                                     //Vit�ria de X
            }
            if(somaColun==-3){                                            //Condiciona vit�ria de O pela segunda coluna
                system("CLS");
                printf("Vitoria do jogador O\n\n");                         //Printa a vit�ria de O
                printarM();
                v2=1;                                                     //Vit�ria de O
            }
    }
    somaColun=0;                                                           //Reseta soma dos valores da coluna
    for(int i=0; i<3; i++){
        somaColun=somaColun+v[i][2];                                       //Terceira coluna
            if(somaColun==3){                                              //Condiciona vit�ria de X pela terceira coluna
                system("CLS");
                printf("Vitoria do jogador X\n\n");                          //Printa a vit�ria de X
                printarM();
                v1=1;                                                      //Vit�ria de X
            }
            if(somaColun==-3){                                             //Condiciona vit�ria de O pela terceira coluna
                system("CLS");
                printf("Vitoria do jogador O\n\n");                          //Printa a vit�ria de O
                printarM();
                v2=1;                                                      //Vit�ria de O
            }
    }
}

void vitoriaDiag(int somaDiag){
    somaDiag=0;                                                           //Reseta soma dos valores para diagonal
    somaDiag = v[0][0] + v[1][1] + v[2][2];                               //Soma posi��es que formam diagonal da esquerda para a direita
    if(somaDiag==3){                                                      //Condiciona vit�ria de X pela primeira diagonal
        system("CLS");
        printf("Vitoria do jogador X\n\n");                                  //Printa a vit�ria de X
        printarM();
        v1=1;                                                              //Vit�ria de X
    }
    if(somaDiag==-3){                                                     //Condiciona vit�ria de O pela primeira diagonal
        system("CLS");
        printf("Vitoria do jogador O\n\n");                                  //Printa vit�ria de O
        printarM();
        v2=1;                                                              //Vit�ria de O
    }
    somaDiag=0;                                                           //Reseta soma dos valores para diagonal
    somaDiag=v[2][0]+v[1][1]+v[0][2];                                     //Soma posi��es que formam diagonal da direita para a esquerda
    if(somaDiag==3){                                                      //Condiciona vit�ria de X pela psegunda diagonal
        system("CLS");
        printf("Vitoria do jogador X\n\n");                                  //Printa a vit�ria de X
        printarM();
        v1=1;                                                              //Vit�ria de X
    }
    if(somaDiag==-3){                                                     //Condiciona vit�ria de O pela segunda diagonal
        system("CLS");
        printf("Vitoria do jogador O\n\n");                                  //Printa a vit�ria de O
        printarM();
        v2=1;                                                              //Vit�ria de O
    }
}

void vitoriaLin(int somaLin){                                              //Fun��o vit�ria horizontal
    somaLin=0;                                                             //Inicia soma dos valores da linha em 0
    for(int j=0; j<3; j++){
        somaLin=somaLin+v[0][j];                                           //Primeira linha
            if(somaLin==3){                                                //Condiciona vit�ria de X pela primeira linha
                system("CLS");
                printf("Vitoria do jogador X\n\n");                          //Printa a vit�ria de X
                printarM();
                v1=1;                                                      //Vit�ria de X
            }
            if(somaLin==-3){                                               //Condiciona vit�ria de O pela primeira linha
                system("CLS");
                printf("Vitoria do jogador O\n\n");                          //Printa a vit�ria de O
                printarM();
                v2=1;                                                      //Vit�ria de O
            }
    }
    somaLin=0;                                                             //Reseta soma dos valores para linha
    for(int j=0; j<3; j++){
        somaLin=somaLin+v[1][j];                                           //Segunda linha
            if(somaLin==3){                                                //Condiciona vit�ria de X pela segunda linha
                system("CLS");
                printf("Vitoria do jogador X\n\n");                          //Printa a vit�ria de X
                printarM();
                v1=1;                                                      //Vit�ria de X
            }
            if(somaLin==-3){                                               //Condiciona vit�ria de O pela segunda linha
                system("CLS");
                printf("Vitoria do jogador O\n\n");                          //Printa a vit�ria de O
                printarM();
                v2=1;                                                      //Vit�ria de O
            }
    }
    somaLin=0;                                                             //Reseta soma dos valores para linha
    for(int j=0; j<3; j++){
        somaLin=somaLin+v[2][j];                                           //Terceira linha
            if(somaLin==3){                                                //Condiciona vit�ria de X pela terceira linha
                system("CLS");
                printf("Vitoria do jogador X\n\n");                        //Printa a vit�ria de X
                printarM();                                                //Imprime a matriz do jogo
                v1=1;                                                      //Vit�ria de X
            }
            if(somaLin==-3){                                               //Condiciona vit�ria de O pela terceira linha
                system("CLS");
                printf("Vitoria do jogador O\n\n");                        //Printa a vit�ria de O
                printarM();                                                //Imprime a matriz do jogo
                v2=1;                                                      //Vit�ria de O
            }
    }
}

int main (){                                                               //Inicia fun��o main
    int casaX, casaO, j, somaColun, velha=0, somaLin;                      //Declara vari�veis inteiras
    do{
        system("cls");                                                     //Limpa tela
        printarM();                                                        //Imprime a matriz do jogo
        printf("Digite a casa para jogar o X: ");                         //Pede para 'X' jogar

        scanf("%d", &casaX);                                               //L� a vari�vel e associa a X
        jogadaX(casaX, j);                                                 //Entra na fun��o X

        vitoriaColun(somaColun);                                           //Entra na fun��o de vit�ria de vertical
        vitoriaLin(somaLin);                                               //Entra na fun��o de vit�ria de linha
        vitoriaDiag(somaColun);                                            //Entra na fun��o de vit�ria de diagonal
        velha=velha+1;                                                     //Conta o n�mero de jogadas para conferir se "deu velha"

        if(v1==1 || v2==1 || velha==9){                                    //Condiciona vit�ria de X, O ou velha
            break;                                                         //Interrompe loop
        }

        system("cls");                                                     //Limpa tela
        printarM();                                                        //Imprime a matriz do jogo
        printf("Digite a casa para jogar o O: ");                         //Pede para 'O' jogar

        scanf("%d", &casaO);                                               //L� a vari�vel e associa a X
        jogadaO(casaO, j);                                                 //Entra na fun��o O

        vitoriaColun(somaColun);                                           //Entra na fun��o de vit�ria de vertical e diagonal
        vitoriaLin(somaLin);                                               //Entra na fun��o de vit�ria de linha
        vitoriaDiag(somaColun);                                            //Entra na fun��o de vit�ria de diagonal
        velha=velha+1;                                                     //Conta o n�mero de jogadas para conferir se "deu velha"

        if(v1==1 || v2==1){                                                //Condiciona vit�ria de X ou O
            break;                                                         //Interrompe loop
        }
    }while(v1<1 && v2<1);                                                  //Confere se n�o houve vit�ria para continuar o loop

    if(velha==9 && v1!=1 && v2!=1){                                        //Condiciona velha
        system("CLS");
        printarM();                                                         //Imprime a matriz do jogo
        printf("\nDeu velha!!!\n");                                        //Printa velha
    }
}
