/* Author: Pedro Augusto Resende

Note: Originally this was a work for the discipline of Operational Systems in 2/2017.

Descripton:
This is a simple implementation of the Monte Carlo Algorithm to estimate the Pi value.

The Monte Carlo technique defines a circle of radius 1 in the cartesian plane starting from the origin.
Then generates N random points with x, and belonging to the interval [-1, 1] and calculates pi by multiplying
4 to the total points that are part of the area of the circle and dividing the result by the total of points generated.

Work only on LINUX
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
// Linux C libraries
#include <pthread.h>
#include <stdio_ext.h>

unsigned int totalDePontos = 0;
unsigned int pontosPorThread;
int totalNoCirculo = 0;
pthread_mutex_t lock;

/*
 * Generates a random number in a open interval. Needs to be used with
 * srand(seed) function.
 *
 * Parameter:
 *  double lower - lower value of the interval
 *  double hiher - higher value of the interval
 * Return: (double) the random number
 */

double randf(double lower,double higher){
    return (rand()/(double)(RAND_MAX)) * abs(lower - higher) + lower;
}
void *ocorrencias(void *param);

// MAIN
int main(int argc, char **argv) {
   pthread_t tid[THREADS]; // identificador da thread
   double pi;
   int i;
   int erro;

   if (pthread_mutex_init(&lock, NULL) != 0) {
      fprintf(stderr, "\nInicializacao do semaforo de exlusao mutua (mutex) falhou\n");
      return 1;
   }

   printf("\nDigite a quantidade de pontos a ser gerados: ");
   __fpurge(stdin);
   scanf("%d", &totalDePontos);

   if (totalDePontos % 2 == 0)
      pontosPorThread = totalDePontos/THREADS;
   else
      pontosPorThread = (totalDePontos + 1)/THREADS;

   srand(time(NULL));

   // Cria as threads
   for (i = 0; i < THREADS; i++) {
     erro = pthread_create(&tid[i], NULL, ocorrencias, argv[1]);

     if (erro != 0) {
         fprintf(stderr, "Nao foi possivel criar a thread[%d].\n", i);
         return -1;
      }
   }

   // Espera execucao das threads (sincronizacao)
   for (i = 0; i < THREADS; i++){
      pthread_join(tid[i], NULL);
   }

   pthread_mutex_destroy(&lock);

   pi = ((double)  4 * totalNoCirculo)/(double)totalDePontos;
   printf("\n::: RESULTADOS :::\n"
   		"* Pontos gerados: %d\n"
   		"* Pontos no circulo: %d\n"
   		"* Valor de PI: %f\n",
   		totalDePontos, totalNoCirculo, pi);
}

/*
 * Gera um ponto (x,y) aleatorio num intervalo [-1, 1] e verifica se
 * ele esta dentro de um circulo de raio 1.
 *
 * Parametros: referencia para um parametro qualquer do tipo void
 *
 * Retorno: (void*)
*/
void *ocorrencias(void *param) {
	unsigned int i;
	double x, y;

	for (i = 0; i < pontosPorThread; i++) {
		x = randf(-1.000001, 1.000001);
		y = randf(-1.000001, 1.000001);

		/* Aplicacao do teorema de pitagoras para o calculo do comprimento
		 * da reta em relacao a origem
		 *
		 * h = sqrt(catetoOposto^2 + catetoAdjacente^2)
		 *
		 * Se o comprimento da reta for < 1, pertence a area do circulo.
		 */
		if (sqrt((x * x) + (y * y)) < 1) {
         pthread_mutex_lock(&lock);
         totalNoCirculo++;
         pthread_mutex_unlock(&lock);
      }
	}

	pthread_exit(0);
}
