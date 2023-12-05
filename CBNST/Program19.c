/*
#include <stdio.h>
void calculateQuadratic(float x[], float y[], int n, float *a, float *b, float *c) {
    float sumX = 0, sumX2 = 0, sumX3 = 0, sumX4 = 0, sumXY = 0, sumX2Y = 0;
    
    for (int i = 0; i < n; i++) {
        float xSquare = x[i] * x[i];
        sumX += x[i];
        sumX2 += xSquare;
        sumX3 += xSquare * x[i];
        sumX4 += xSquare * xSquare;
        sumXY += x[i] * y[i];
        sumX2Y += xSquare * y[i];
    }
    
    float denominator = n * sumX2 * sumX4 + sumX * sumX * sumX2 - sumX2 * sumX2 - n * sumX3 * sumX3 - sumX * sumX4;
    *a = (sumXY * (sumX2 * sumX4 - sumX3 * sumX3) + sumX * (sumX3 * sumX2Y - sumX4 * sumXY) + sumX2 * (n * sumX3 * sumXY - sumX * sumX2Y)) / denominator;
    *b = (n * sumX2Y * sumX2 * sumX4 + sumXY * sumX * sumX2 * sumX2 - sumX2 * sumX * sumX2Y - sumXY * sumX3 * sumX4 - n * sumX * sumX3 * sumXY + sumX * sumX4 * sumXY) / denominator;
    *c = (n * sumX2 * sumX2Y + sumX * sumX * sumX2Y - sumX2 * sumX2Y - n * sumX4 * sumXY - sumX3 * sumX * sumX2Y + sumX3 * sumX4 * sumXY) / denominator;
}

int main() {
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    float x[n], y[n];
    printf("Enter the x and y values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f %f", &x[i], &y[i]);
    }

    float a, b, c;
    calculateQuadratic(x, y, n, &a, &b, &c);

    printf("Quadratic equation: y = %.2fx^2 + %.2fx + %.2f\n", a, b, c);

    return 0;
}
*/

#include<stdio.h>
#include<math.h>
int main(){
    float xy[20][20], matrix[3][4], ratio, a;
    float sum_x = 0, sum_y = 0, sum_x2 = 0, sum_x3 = 0, sum_x4 = 0, sum_xy = 0, sum_x2y = 0;
    int i, j , k, n;
    printf("Enter no of data: ");
    scanf("%d", &n);
    printf("Enter the data: \n");
    for(i = 0; i < 2; i++){
        for(j = 0; j < n; j++){
            scanf("%f", &xy[i][j]);
        }
    }
    printf("\nX\tY\tX2\tX3\tX4\tXY\tX2Y\n");
    for(i = 0; i < n; i++){
        sum_x += xy[0][i];
        sum_y += xy[1][i];
        sum_x2 += pow(xy[0][i], 2);
        sum_x3 += pow(xy[0][i], 3);
        sum_x4 += pow(xy[0][i], 4);
        sum_xy += xy[0][i]*xy[1][i];
        sum_x2y += pow(xy[0][i], 2) * xy[1][i];
        printf("%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",xy[0][i],xy[1][i],pow(xy[0][i], 2),pow(xy[0][i], 3),
        pow(xy[0][i], 4),xy[0][i]*xy[1][i],pow(xy[0][i], 2) * xy[1][i]);
        
    }

    matrix[0][0] = n;
    matrix[0][1] = sum_x;
    matrix[0][2] = sum_x2;
    matrix[0][3] = sum_y;
    matrix[1][0] = sum_x;
    matrix[1][1] = sum_x2;
    matrix[1][2] = sum_x3;
    matrix[1][3] = sum_xy;
    matrix[2][0] = sum_x2;
    matrix[2][1] = sum_x3;
    matrix[2][2] = sum_x4;
    matrix[2][3] = sum_x2y;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if(i!=j){
                ratio = matrix[j][i]/matrix[i][i];
                for(k = 0; k < 4; k++){
                    matrix[j][k] -= ratio * matrix[i][k];
                }
            }
        }
    }
    for(i = 0; i < 3; i++){
        a = matrix[i][i];
        for(j = 0; j < 4; j++){
            matrix[i][j] /= a;
        }
    }
    
    for(i = 0; i < 3; i++){
        printf("\n%c => %.2f", 97+i, matrix[i][3]);
    }
}

