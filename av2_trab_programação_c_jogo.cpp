#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <conio.c>
#include <windows.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
 
    printf("\n\n\n\n\n");
    printf("\t\t\t\t\t******************************************\n" );
    printf("\t\t\t\t\t* Bem vindo ao nosso jogo de adivinha��o *\n");
    printf("\t\t\t\t\t******************************************\n");

    int nivel, dificuldade;
    int jogar_novamente = 1;
    
    while(jogar_novamente == 1){
    system ("color F0")	;	
    printf("\nPara iniciar escolha o n�vel em que deseja jogar!\n");
    printf("1 - F�cil   [0 - 10]\n");
    printf("2 - M�dio   [0 - 100]\n");
    printf("3 - Dif�cil [0 - 1000]\n\n");
    scanf("%d", &nivel);

    while(nivel < 1 || nivel > 3){
    	textbackground (0);
    	textcolor (RED);
        printf("\nOp��o Inv�lida! Tente uma op��o entre 1 e 3!\n");
        textbackground (15);
        textcolor (0);
        printf("\nPara iniciar escolha o n�vel em que deseja jogar!\n");
        printf("1 - F�cil   [0 - 10]\n");
        printf("2 - M�dio   [0 - 100]\n");
        printf("3 - Dif�cil [0 - 1000]\n\n");
        scanf("%d", &nivel);
    }
    switch (nivel){
        case 1:
        dificuldade = 10;
        printf("\nTente adivinhar em qual n�mero eu estou pensando!\n");
        break;
        case 2:
        dificuldade = 100;
        printf("\nTente adivinhar em qual n�mero eu estou pensando!\n");
        break;
        case 3:
        dificuldade = 1000;
        printf("\nTente adivinhar em qual n�mero eu estou pensando!\n");
        break;
    }

        
    int computador;
    srand(time(NULL));
    computador = rand() % dificuldade;  //Gera n�meros aleat�rios 

    int player, minimo = 0, maximo = dificuldade, jogadas = 0;

    do{
        printf("\nDigite um n�mero: ");
        scanf("%d", &player);
        jogadas++;
        if(player > dificuldade){
        	printf("\nHmm! Deixa eu pensar!\n");
        	Sleep(700);
            printf("\nN�mero alto demais! Tente outro entre 0 e %d\n", dificuldade);
        }else if(player > computador){
            maximo = player;
            printf("\nHmm! Deixa eu pensar!\n");
            Sleep(700);
            printf("\nO n�mero que eu pensei est� entre %d e %d\n", minimo, maximo);
        }else if(player < computador){
            minimo = player;
            printf("\nHmm! Deixa eu pensar!\n");
            Sleep(700);
            printf("\nO n�mero que eu pensei est� entre %d e %d\n\n", minimo, maximo);
        }else{
        	printf("\nHmm! Deixa eu pensar!\n\n");
            Sleep(700);
        	textcolor (2);
        	textbackground(0);
            printf("PARAB�NS VOC� ACERTOU!!! Voc� acertou com %d jogadas.", jogadas);
            textbackground(15);
			textcolor (0);
        }
    } while(player != computador);
    fflush(stdin);
    printf("\n\nDeseja Jogar Novamente? [1 - Sim | 2 - N�o]: ");
    scanf("%d", &jogar_novamente);
    system("cls");
    }
    
    return 0;
}
