#include <stdio.h>
#include <math.h>
//Task 01: Deal with function composition

double fx(double x){
	return pow(x + 1, 2);
}

double gx(double x){
	return 2 * x + 1;
}

int main(){
	printf("Input x: ");
	double x;
	while(scanf("%lf", &x) != 1);
	printf("The value of f(g(x)) is %lf.\n", fx(gx(x)));
}

