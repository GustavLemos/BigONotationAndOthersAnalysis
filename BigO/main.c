#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <winbase.h>
#include <psapi.h>

#define N 10000

double get_memory_used_MB()
{
    PROCESS_MEMORY_COUNTERS info;
    GetProcessMemoryInfo( GetCurrentProcess( ), &info, sizeof(info) );
    return (double)info.PeakWorkingSetSize/ (1024*1024);
}

float distanciaDoisPontos(int x1,int x2, int y1, int y2){   //Complexidade da funçao = f(n)= 1 e notação big (O) = O(1)

    float distancia;
    distancia = sqrt( pow(x2-x1, 2) + pow(y2-y1, 2) ); //1 = O(1)
    return distancia;                                  //1 = O(1)
}

double acharMenorDist(float vet[N]){    //Complexidade da funçao = f(n)= n e notação big (O) = O(n)

    double menor = 1000000000000;       //1 = O(1)

    for(int i=0; i < N; i++){           //f(n)= n
        if(vet[i]<menor){               //A < n =   1 = O(1)
            menor = vet[i];             //1 = O(1)
        }
    }

    return menor;                       //1 = O(1)
}


int main(){ // Complexidade da funçao main = f(n) = n + n + n = 3n logo f(n) = 3*n e notação Big(O) = O(n)

    clock_t start_time, end_time;
    double cpu_time_used, memory_used;
    size_t peakSize;

    start_time = clock();



    struct Ponto{
      int x;
      int y;
    };

    //construçao de vetor dinamico
    struct Ponto *vetor = malloc(N * sizeof(struct Ponto));

    float distancias[N];

    for(int i = 0; i < N; i++){                                     //|1|f(n) = n e O(n)
        //scanf("%d %d",&vetor[i].x,&vetor[i].y);
        vetor[i].x = rand() % 1000;
        vetor[i].y = rand() % 1000;
    }

    //printf("\nDigite o ponto p\n");

    struct Ponto p;
    //scanf("%d %d",&p.x,&p.y);
    p.x = rand() % 1000;
    p.y = rand() % 1000;

    for(int i = 0; i < N; i ++){                                            //|2|f(n) = n e O(n)
        distancias[i] = distanciaDoisPontos(p.x,vetor[i].x,p.y,vetor[i].y); //f(n) = 1 e O(1) - já verificado
        printf(" \n %f",distancias[i]);
    }

    double menor = acharMenorDist(distancias);                              //|3|f(n) = n e O(n)

    printf("\nMenor distancia entre os pontos:%f \n",menor);



    end_time = clock();
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    memory_used = get_memory_used_MB();

    printf("Tempo: %0.2f segundos - Memoria: %0.2f MB\n",cpu_time_used, memory_used);




    //liberando espaço aloccado
    free(vetor);

    return 0;
}
