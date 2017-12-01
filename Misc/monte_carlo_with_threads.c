/* UNIVERSIDADE CATOLICA DE BRASILIA - UCB
 * DISCIPLINA: Sistemas Operacionais (2/2017) [Operational Systems]
 * PROFESSOR: José Adalberto Gualeve [Professor]
 * ALUNO: Pedro Augusto Resende [Student]
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <pthread.h>

#define LINUX

#ifdef LINUX
  #include <stdio_ext.h>
#endif

// ===== Variaveis Globais =====
unsigned int totalDePontos = 0;
int totalNoCirculo = 0;

// ===== Indice de funcoes =====

double randf(double menor,double maior);
void *ocorrencias(void *param);

// MAIN
int main(int argc, char **argv) {
   pthread_t tid; // identificador da thread
   double pi;

   printf("================== CALCULO DE PI PELA TECNICA DE MONTE CARLO ==================\n"
   		"\nUNIVERSIDADE CATOLICA DE BRASILIA - UCB"
   		"\nDISCIPLINA: Sistemas Operacionais (2/2017)"
   		"\nPROFESSOR: José Adalberto Gualeve"
   		"\nALUNO: Pedro Augusto Resende"
   		"\n--------------------------------------------------------------------------------"
   		"\nResumo:\n"
   		"\nA tecnica de Monte Carlo define um circulo de raio 1 no plano cartesiano"
   		"\npartindo da origem, gera N pontos aleatorios com x,y pertencente ao intervalo"
   		"\n[-1, 1] e faz o calculo de pi multiplicando 4 ao total de pontos que fazem"
   		"\nparte da area do circulo e dividindo pelo total de pontos gerados.\n"
   		"\n\n>> pi = (4 * totalNoCirculo)/totalDePontos <<\n"
   		"\n===============================================================================\n");

   printf("\nDigite a quantidade de pontos a ser gerados: ");
   __fpurge(stdin);
   scanf("%d", &totalDePontos);

   srand(time(NULL));

   // Cria a thread
   pthread_create(&tid, NULL, ocorrencias, argv[1]);

   // Espera execucao da thread (sincronizacao)
   pthread_join(tid, NULL);

   pi = ((double)  4 * totalNoCirculo)/(double)totalDePontos;
   printf("\n::: RESULTADOS :::\n"
   		"* Pontos gerados: %d\n"
   		"* Pontos no circulo: %d\n"
   		"* Valor de PI: %f\n",
   		totalDePontos, totalNoCirculo, pi);
}

/*
 * Gera um numero aleatorio entre um intervalo aberto definido.
 *
 * Parametros:
 *  double menor - valor inferior do intervalo
 *  double maior - valor superior do intervalo
 * Retorno: (double) valor gerado randomicamente
 */

double randf(double menor,double maior){
    return (rand()/(double)(RAND_MAX)) * abs(menor - maior) + menor;
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

	for (i = 0; i < totalDePontos; i++) {
		x = randf(-1.000001, 1.000001);
		y = randf(-1.000001, 1.000001);

		/* Aplicacao do teorema de pitagoras para o calculo do comprimento
		 * da reta em relacao a origem
		 *
		 * h = sqrt(catetoOposto^2 + catetoAdjacente^2)
		 *
		 * Se o comprimento da reta for < 1, pertence a area do circulo.
		 */
		if (sqrt((x * x) + (y * y)) < 1) totalNoCirculo++;
	}

	pthread_exit(0);
}
