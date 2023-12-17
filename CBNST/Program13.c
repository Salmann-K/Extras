#include<stdio.h>
#include<math.h>

/* Define function here */
#define f(x) 1/(1+pow(x,2))

int main()
{
 float lower, upper, integration=0.0, stepSize, k;
 int i, subInterval;
 printf("Enter lower limit of integration: ");
 scanf("%f", &lower);
 printf("Enter upper limit of integration: ");
 scanf("%f", &upper);
 printf("Enter number of sub intervals: ");
 scanf("%d", &subInterval);
 stepSize = (upper - lower)/subInterval;
 printf("X\t\tY");
 printf("\n%0.4f\t\t%0.4f",lower,f(lower));
 integration = f(lower) + f(upper);
 for(i=1; i<= subInterval-1; i++)
 {
  k = lower + i*stepSize;
  integration = integration + 2 * f(k);
  printf("\n%0.4f\t\t%0.4f",k,f(k));
 }
 integration = integration * stepSize/2;
 printf("\nRequired value of integration is: %.3f", integration);
 return 0;
}

// 0 6 6
