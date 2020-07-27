# Programa Media Notas Isostatica
 **Calculadora de medias dos alunos de Isostatica UFRJ**

  * Este programa foi feito para auxiliar um professor do curso de **Isostática da UFRJ** a calcular a média de seus alunos.
  * É de fundamental importância considerar o como era feito a média de sua turma. 

       **Havendo 3 avaliações + uma prova de reposição (que substitui a menor nota das 3, mas *exclusivos para alunos de média inferior a 7*) + uma prova final. Eram aparovados direto aqueles com nota >=7.**
  ***Apartir da feitura da prova final a média necessária para aprovação passava a ser 5.0***

  * O programa lê o numero de pessoas da turma. Depois, pede o nome de cada aluno, assim como suas notas. Calcula a média e a salva em *um arquivo (.txt)* aparte. Em seguida, pergunta a nota final daqueles que ficaram para a *final* (Isso pois é impossível um aluno com nota >= 7.0 fazer a prova final). 

  * Ao final, há um segundo arquivo com a lista de todos os alunos inseridos e suas devidas médias.

  1. (N1 + N2 + N3)/3 = Média inicial **(MI)**
  1. Se **MI** <6.6 então há uma **NR**(reposição) que substituirá a menor nota das três.
     * *ex*:  (2.5 + 5.5 + 6.0)/3 = MI = 4,7 --> NR=6.0 então: Média nova **(MN)** = (6.0 + 5.5 + 6.0)/3 = 5.8 
           Como 5.8 < 7 --> Haverá PF (prova final), supondo PF = 7.5:
                        5.8+7.5/2 = **6.6** --> ***Aprovado.***
  1. Após digitado a nota de todos os alunos, o programa salvará duas listas. Uma mostrando suas notas e outra com suas médias.


 ***OBS***: *Escreva as casas decimais com **. (ponto)** invés de **, (vírgula)** para que o programa funcione normalmente*
  *Alunos com media 6.6 são considerados aprovados, sem a necessidade de passar por uma PF ou reposição, como se tivessem média 7.0.*

    *Thiago L V Cunha*

    
