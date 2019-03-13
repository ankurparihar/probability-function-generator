#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int g_seed = 0;
int fastrand(){
	g_seed = (214013*g_seed+2531011); 
	return (g_seed>>16)&0x7FFF;
}

int p(){
	/* Unbiased random number generator */
	int a = fastrand() % 10;
	int b = fastrand() % 10;
	if(a==0 && b==1){
		return 0;
	}
	else if(a==1 && b==0){
		return 1;
	}
	else{
		return p();
	}
}

// function to use for task
int f(){
	/* ------------- Put generator output here ------------- */
	// Replace p with unbiased random number generator function
	// return (p() * (p() | p() * p() * p() * (p() | p() | p() * (p() | p() * (p() | p()))))); // 0.27612304687
	// return (p() * (p() | p() * p() * p() * (p() | p() * p()))); // 0.27
	return (p() | p() | p() * (p() | p() * p())); // 0.83
	/* ------------------------ End ------------------------ */
}

int main(){
	int iterations = 1000000;
	int count = 0;
	for(int i=1; i<=iterations; ++i){
		count += f();
		if(i%10000==0){
			printf("Running(10000): %d\t\t%.20f\n", i/10000, (double)count/(double)i);
		}
	}
	printf("Probability fraction (Itr=%d): %.20f\n", iterations, (double)count/iterations);
}