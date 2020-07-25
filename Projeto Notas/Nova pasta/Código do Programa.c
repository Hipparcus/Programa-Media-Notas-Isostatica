#include <stdio.h>
#include <stdlib.h>
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
    for(int i=0;i<NumAlunos;i++){
        printf("Digite o nome do aluno: ");
        scanf("%99[^\n]",nome);
        getchar();
        printf("Digite as 3 primeiras notas: ");
        scanf("%f %f %f",&n1,&n2,&n3);
        fprintf(arq,"%s : %.2f %.2f %.2f\n",nome,n1,n2,n3);
        scanf("%99[^\n]",nome);
        getchar();
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
    int N;
    printf("Bem-Vindo ao programa de medias do Thiaguinho Vidal!\n");
    printf("###########Por favor digite o numero de alunos da sua turma###########\n");
    scanf("%d",&N);
    CriandoArquivoAlunos(N);
    LendoarquivoseCalculandoMedia(N);
    printf("\n##############Fim do programa##############\n");
    printf("##############Obrigado##############\n");
    system("pause");
    return 0;
}
