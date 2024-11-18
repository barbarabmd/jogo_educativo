#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

typedef struct { 
    int dificuldade; 
    int valor1; 
    int valor2; 
    int operacao; 
    int resultado; 
} Calcular;

int pontuacao = 0;

void jogar(Calcular *calcular);
int somar(int valor1, int valor2);
int subtrair(int valor1, int valor2);
int multiplicar(int valor1, int valor2);
int dividir(int valor1, int valor2);
void mostrarInfo(Calcular *calcular);

int main(){

    int opcao;

    Calcular *calcular = (Calcular*)malloc(sizeof(calcular));

    do{

        printf("\n>>>>>JOGUINHO DE CALCULO<<<<<\n");
        printf("Opcoes: \n");
        printf("1- Jogar\n");
        printf("2- Mostrar informacoes\n");
        printf("3- Sair.\n");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            jogar(calcular);
            break;
        case 2:
            mostrarInfo(calcular);
            break;
        case 3:
            printf("\nTchauzinho...\n");
            printf("\nSua pontuacao final foi %d\n", pontuacao);
            break;
        default:
            printf("\nDigite uma opcao valida!\n");
            break;
        }

    } while (opcao!=3);

    return 0;   
}

void mostrarInfo(Calcular *calcular) {
    
    printf("Dificuldade: Nivel %d\n", calcular->dificuldade);

    printf("Valor1: %d\n", calcular->valor1);

    printf("Valor2: %d\n", calcular->valor2);

    printf("Operacao: %d\n", calcular->operacao);

    printf("Resultado esperado: %d\n", calcular->resultado);
}

int somar(int valor1,int valor2){
    printf("quanto e %d + %d?", valor1, valor2);
    int resultado = valor1+valor2;
    int resposta;
    scanf ("%d",&resposta);
    getchar();

    if (resposta==resultado){
        printf("\nParabens, voce acertou! :)\n");
        pontuacao += 1;
    }else {
        printf("\nQue pena, voce errou :(\n");
        printf("\nO resultado era %d\n", resultado);
    }
    return resultado;
}

int subtrair(int valor1,int valor2){
    printf("quanto e %d - %d?", valor1, valor2);
    int resultado = valor1-valor2;
    int resposta;
    scanf ("%d",&resposta);
    getchar();

    if (resposta==resultado){
        printf("\nParabens, voce acertou! :)\n");
        pontuacao += 1;
    }else {
        printf("\nQue pena, voce errou :(\n");
        printf("\nO resultado era %d\n", resultado);
    }
    return resultado;
  
}

int multiplicar(int valor1, int valor2){
    printf("quanto e %d * %d?", valor1, valor2);
    int resultado = valor1*valor2;
    int resposta;
    scanf ("%d",&resposta);
    getchar();

    if (resposta==resultado){
        printf("\nParabens, voce acertou! :)\n");
        pontuacao += 1;
    }else {
        printf("\nQue pena, voce errou :(\n");
        printf("\nO resultado era %d\n", resultado);
    }
    return resultado;
}

int dividir(int valor1,int valor2){
    printf("quanto e %d / %d?", valor1, valor2);
    int resultado = valor1/valor2;
    int resposta;
    scanf ("%d",&resposta);
    getchar();

    if (resposta==resultado){
        printf("Parabens, voce acertou! :)");
        pontuacao += 1;
    }else {
        printf("Que pena, voce errou :(");
        printf("\nO resultado era %d\n", resultado);
    }
    return resultado;
}


void jogar(Calcular *calcular){
    int nivel;
    int min = 0;
    int max;
    int resultado;
    srand(time(NULL));

    do{   
        printf("\n\nNivel 1 (Facil): Valores entre 0 e 10.");
        printf("\nNivel 2 (Medio): Valores entre 0 e 100.");
        printf("\nNivel 3 (Dificil): Valores entre 0 e 1000.");
        printf("\nNivel 4 (Insano): Valores entre 0 e 10000.");
        printf("\nEscolha um nivel para iniciar seu jogo: ");

        scanf("%d", &nivel);
        getchar();

    } while(nivel != 1 && nivel != 2 && nivel != 3 &&nivel != 4 );

    switch (nivel){
        case 1:
            max = 10;
            break;
        case 2:
            max = 100;
            break;
        case 3:
            max = 1000;
            break;
        case 4:
            max = 10000;
            break;
        default:
            break;
    }
    
    calcular->dificuldade = nivel;
    
    calcular->operacao = rand() % 4;
    calcular->valor1 = rand() % (max + 1);
    calcular->valor2 = rand() % (max + 1);

    switch (calcular->operacao){
    case 0:
        printf("\nA operacao sorteada foi soma!\n");
        calcular->resultado = somar(calcular->valor1, calcular->valor2);
        break;
    case 1:
        printf("\nA operacao sorteada foi subtracao!\n");
        calcular->resultado = subtrair(calcular->valor1, calcular->valor2);
        break;
    case 2:
        printf("\nA operacao sorteada foi multiplicacao!\n");
        calcular->resultado = multiplicar(calcular->valor1, calcular->valor2);
        break;
    case 3:
        printf("\nA operacao sorteada foi divisao!\n");
        if(calcular->valor2 == 0){
            calcular->valor2 = rand() % (max + 1);
        }
        calcular->resultado = dividir(calcular->valor1, calcular->valor2);
        break;
    default:
        break;
    }
}
