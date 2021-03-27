#include <stdio.h>
#include <math.h>

double f(double x);

//Intervals has to be even

float integral(double b, int intervals)
{
    //double a = b - stepsize;
    double h,x = 0,sum=0,integral;
    
    h=fabs(b)/intervals;
    for(int i=1;i<intervals;i++)
    {
      x=0+i*h;
      if(i%2==0){
        sum=sum+2*f(x);
      }
      else{
        sum=sum+4*f(x);
      }
    }
    integral=(h/3)*(f(0)+f(b)+sum);
    
    return integral;
}

float derivative(double x)
{
    double h = 1.0e-8;
    return (f(x + h)-f(x))/h;
}

void drawfunc(double(*fun_ptr)(double), int ymin, int ymax, int xmin, int xmax, float h)
{
    int y = 0;
    int x = 0;
    double func;
    
    printf("f(x): \n\n");
    
    for(y = ymax; y >= ymin; y--)
    {
        printf("\n");
        for(x = xmin; x <= xmax; x++)
        {
            func = (*fun_ptr)(x);
            
            if(x == 0)
            {
                printf("|");
            }
            
            if(func > (y - 1) * h && func < y * h)
            {
                printf("*");
            }
    
            else if(y == 0)
            {
                if(x >= xmin || x <= xmax)
                {
                    printf("-");
                }
            }
            else
            {
                printf(" ");
            }
        }
    }
    printf("\n\n\n\n");
}

void drawderiv(int ymin, int ymax, int xmin, int xmax, float h)
{
    int y = 0;
    int x = 0;
    double func;
    
    printf("f'(x): \n\n");
    
    for(y = ymax; y >= ymin; y--)
    {
        printf("\n");
        for(x = xmin; x <= xmax; x++)
        {
            func = derivative(x);
            
            if(x == 0)
            {
                printf("|");
            }
            
            if(func > (y - 1) * h && func < y * h)
            {
                printf("*");
            }
    
            else if(y == 0)
            {
                if(x >= xmin || x <= xmax)
                {
                    printf("-");
                }
            }
            else
            {
                printf(" ");
            }
        }
    }
    printf("\n\n\n\n");
}

void drawint(int ymin, int ymax, int xmin, int xmax, float h)
{
    int y = 0;
    int x = 0;
    double func;
    
    printf("F(x): \n\n");
    
    for(y = ymax; y >= ymin; y--)
    {
        printf("\n");
        for(x = xmin; x <= xmax; x++)
        {
            func = integral(x,100);
            
            if(x == 0)
            {
                printf("|");
            }
            
            if(func > (y - 1) * h && func < y * h)
            {
                printf("*");
            }
    
            else if(y == 0)
            {
                if(x >= xmin || x <= xmax)
                {
                    printf("-");
                }
            }
            else
            {
                printf(" ");
            }
        }
    }
    printf("\n\n\n\n");
}
double f(double x)
{
  return x;
}


int add(int a, int b) {
    return a+b;
}

int sub(int a, int b) {
    return a-b;
}

int bop(int (*fun_ptr)(int,int), int a, int b) // Example Function Pointer
{
    return (*fun_ptr)(a,b);
}
   
int main()
{
    printf("%d\n", bop(&add, bop(&sub, 10,5), 6));
    //printf("Value: %f\n", derivative(1));
    //drawfunc(&f, -20, 20, -20, 20, 0.7);
    return 0;
}
