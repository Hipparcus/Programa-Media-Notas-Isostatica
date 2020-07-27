#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <string.h>
float SomaDosMaiores(float n1,float n2,float n3){ //(1,2,3)V       (5.6,7.8,8.6)   (2,7.6,4.6)
    float aux,soma;
    if (n1>n2){
        aux=n1;
        n1=n2;
        n2=aux;
    }else if(n1>n3){
        aux=n1;
        n1=n3;
        n3=aux;
    }
    soma=n2+n3;
    return soma;
}

void CriandoArquivoAlunos(int NumAlunos){
    FILE *arq;
    int k=0;
    float n1,n2,n3,rep,nF;
    char nome[100];
    arq=fopen("notas.txt","w");
    if (arq==NULL){
        printf("Nao pode criar arquivo");
        exit(0);
    }
    /*printf("Digite o numero total de alunos desta turma: ");
    scanf("%d",&NumAlunos);
    */
    for(int i=0;i<NumAlunos;i++){
        printf("Digite o nome do aluno: ");
        getchar();
        scanf("%99[^\n]",nome);
        printf("Digite as 3 primeiras notas: ");
        scanf("%f %f %f",&n1,&n2,&n3);
        fprintf(arq,"%s : %.2f %.2f %.2f\n",nome,n1,n2,n3);
        scanf("%99[^\n]",nome);
    }
    fclose(arq);
}

int LendoarquivoseCalculandoMedia(int NumAlunos){
    char nome[100],leitur[10000];
    float nota1,nota2,nota3,rep,fin,media;
    FILE *v,*V;
    v=fopen("notas.txt","r");
    V=fopen("medias.txt","w");
    for (int i=0;i<NumAlunos;i++){
        fscanf(v,"%[^:]: %f %f %f",nome,&nota1,&nota2,&nota3);
        media=(nota1+nota2+nota3)/3.0;
        if(media<6.66){
            printf("\nDigite reposicao de %s: ",nome);
            scanf("%f",&rep);
            if (nota1<rep||nota2<rep||nota3<rep){
                media=(SomaDosMaiores(nota1,nota2,nota3)+rep)/3.0;
            }}
        if(media<6.66){
            printf("Digite PF de %s : ",nome);
            scanf("%f",&fin);
            media=(media+fin)/2.0;
        }
        printf("%s MEDIA FINAL: %.2f",nome,media);
        fprintf(V,"%s : %.2f",nome,media);
    }
    fclose(v);
    return 0;
}
int main(){
    char b;
    int N,o,cont=0;
    printf("###Bem-Vindo ao programa de medias!###\nDesenvolvido por Thiago Laidler, estudante de programacao e astrofisica da UFRJ.\nTodos os direitos reservados\n");
    printf("#####O que gostaria de fazer?#####\n(1)Comecar o programa agora.\n(2)Ver o manual de instrucoes.\n(3)Fechar o programa.\nSe digitar um numero invalido podera tentar novamente ate 3 vezes antes do programa finalizar automaticamente!\n");
    scanf("%d",&o);
    while (o!=1&&o!=2&&o!=3){
        scanf("%d",&o);
        if (cont>=3) break;
        cont++;
    }
    switch (o){
    case 1:
        printf("###########Por favor digite o numero de alunos da sua turma###########\n");
        scanf("%d",&N);
        CriandoArquivoAlunos(N);
        LendoarquivoseCalculandoMedia(N);
        printf("\n##############Fim do programa##############\n");
        printf("Fora criado um arquivo em bloco de notas com as notas de todos seus alunos. Confira na pasta deste programa!\n");
        printf("##############Obrigado##############\n");
        break;
    case 2:
        printf("###############\nAo rodar o programa o usuario deve digitar corretamente o numero de alunos da turma\nEm seguida o programa perguntara o nome e as notas de cada aluno enquanto grava tais informacoes para um arquivo \nem bloco de notas - localizada na mesma pasta deste programa- com o nome 'notas.txt'\nO programa calculara a media de cada aluno e criara um outro arquivo com nome 'medias.txt' com elas! Este arquivo tambem estara localizado na mesma pasta que este programa\n###############\n ");
        printf("\n\nDigite qualquer tecla para comecar o programa agora!\n(Ou digite 3 se quiser fecha-lo)\n");
        getchar();
        scanf("%c",&b);
        if (b=='3') exit(0);
        else{
            printf("###########Por favor digite o numero de alunos da sua turma###########\n");
            scanf("%d",&N);
            CriandoArquivoAlunos(N);
            LendoarquivoseCalculandoMedia(N);
            printf("\n##############Fim do programa##############\n");
            printf("Fora criado um arquivo em bloco de notas com as notas de todos seus alunos. Confira na pasta deste programa!\n");
            printf("##############Obrigado##############\n");
        }
        break;
    case 3:
        printf("Programa fechado com sucesso!\nVolte Sempre\n");
        exit(0);
    default:
        printf("Maximo de opcoes invalidas digitadas.\n Finalizando programa...\n");
        exit(0);
    }
    return 0;
}
