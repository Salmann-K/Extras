#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{

    int n,i; float x[20],y[20],sumx=0,sumy=0,sumxy=0,sumx2=0;
    float a,b;
    printf("Enter the value of number of terms n: ");
    scanf("%d",&n);
    printf("Enter the values of x:\n");
    for(i=0;i<=n-1;i++){
        scanf("%f",&x[i]);

    }
    printf("Enter the values of y:\n");
    for(i=0;i<=n-1;i++){
        scanf("%f",&y[i]);
    }
    printf("\nX\tY\tXY\tX2\n");
    for(i=0;i<=n-1;i++){
        sumx=sumx +x[i];
        sumx2=sumx2 +x[i]*x[i];
        sumy=sumy +y[i];
        sumxy=sumxy +x[i]*y[i];
        printf("%.2f\t%.2f\t%.2f\t%.2f\n",x[i],y[i],x[i]*y[i],x[i]*x[i]);
    }
    a=((sumx2*sumy -sumx*sumxy)*1.0/(n*sumx2-sumx*sumx)*1.0);
    b=((n*sumxy-sumx*sumy)*1.0/(n*sumx2-sumx*sumx)*1.0);
    printf("\n\nThe line is Y=%3.3f +%3.3f X\n",a,b);
    return(0);
}