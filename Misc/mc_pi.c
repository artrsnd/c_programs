/* Author: Pedro Augusto Resende

Before proceed, please read the README.md file for more information.

Note: Originally this was a work for the discipline of Operational Systems in 2/2017.
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

// Linux C libraries
#include <pthread.h>
#include <stdio_ext.h>

unsigned int total_points_circle = 0;
unsigned int gen_points = 0;
unsigned int qt_threads = 0;
pthread_mutex_t lock;

double randf(double lower, double higher);
void *occurrences(void *param);

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Unable to estimate pi. Arguments are invalid.\n");
    return -1;
  } else {
    double pi = 0;
    int i;
    int error;

    qt_threads = atoi(argv[1]);
    gen_points = atoi(argv[2]) * qt_threads;

    pthread_t tid[qt_threads];

    // Start the mutex semaphore
    if (pthread_mutex_init(&lock, NULL) != 0) {
       fprintf(stderr, "Failed to start the mutex semaphore\n");
       return -2;
    }

    srand(time(NULL)); // Starts the seed to srand function

    // Create the threads and call the function to calculate the points
    for (i = 0; i < qt_threads; i++) {
      error = pthread_create(&tid[i], NULL, occurrences, argv[2]);

      if (error != 0) {
          fprintf(stderr, "Can't create the thread number %d.\n", i);
          return -3;
       }
    }

    // Sync threads
    for (i = 0; i < qt_threads; i++){
       pthread_join(tid[i], NULL);
    }

    pthread_mutex_destroy(&lock);

    pi = ((double)  4 * total_points_circle)/(double) gen_points;

    printf("\n::: Results :::\n"
    		"* Points generated: %d\n"
    		"* Points in circle: %d\n"
    		"* Estimation of Pi value: %f\n",
    		gen_points, total_points_circle, pi);

    return 0;
  }
}

/*
 * Generates a random number in a open interval. Needs to be used with
 * srand(seed) function.
 *
 * Parameter:
 *  double lower - lower value of the interval
 *  double hiher - higher value of the interval
 * Return: (double) the random number
 */

double randf(double lower, double higher) {
    return (rand()/(double)(RAND_MAX)) * abs(lower - higher) + lower;
}

/*
 * Generates a random point (x,y) in interval [-1, 1] and checks whether it belongs to the range
 * of the circle with radius 1.
 *
 * Parameters:
 *  void * param: pointer to some void parameter
 * Return: ---
*/
void *occurrences(void *param) {
	unsigned int i;
	double x, y;
  unsigned int limit = gen_points/qt_threads;

	for (i = 0; i < limit; i++) {
		x = randf(-1.000001, 1.000001);
		y = randf(-1.000001, 1.000001);

    /* Application of the Pythagorean theorem for the calculation of the length
     * of the line with respect to the origin
     *
     * h = sqrt(opposite_leg^2 + adjacent_leg^2)
     *
     * if the lenght < 1, the point belongs to the circle.
		 */
		if (sqrt((x * x) + (y * y)) < 1) {
         pthread_mutex_lock(&lock);
         total_points_circle++;
         pthread_mutex_unlock(&lock);
      }
	}

	pthread_exit(0);
}
