#include<stdio.h>
int main(){
 int n, i;
 float x[20], y[20], sumX=0, sumX2=0, sumY=0, sumXY=0, a, b;
 printf("Number of data points\n");
 scanf("%d", &n);
 printf("Enter The Values Of X:\n");
 for(i=1;i<=n;i++){
  scanf("%f", &x[i]);
 }
 printf("Enter The Values Of Y:\n");
 for(i=1;i<=n;i++){
    scanf("%f", &y[i]);
 }

 for(i=1;i<=n;i++){
  sumX = sumX + x[i];
  sumX2 = sumX2 + x[i]*x[i];
  sumY = sumY + y[i];
  sumXY = sumXY + x[i]*y[i];
 }
 b = (n*sumXY-sumX*sumY)/(n*sumX2-sumX*sumX);
 a = (sumY - b*sumX)/n;
 printf("Values are: a=%0.2f and b = %0.2f",a,b);
 printf("\nEquation of best fit is: y = %0.2f + %0.2fx",a,b);
 return(0);
}