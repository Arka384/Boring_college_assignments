#include<stdio.h>
#include<math.h>
float sum(float n,float x)
{
	int fact=1,i;
	for(i=1;i<=2*n-2;i++)
		fact=fact*i;
	if(n==1)
		return 1;
	return((pow(-1,n+1))*(pow(x,2*n-2)/fact)+sum(n-1,x));
}

int main()
{
    float x,l,i,n;
    printf("Enter the value of x:");
    scanf("%f",&x);
    x=(180*x)/3.14;
    x=90-x;
    while(x>90 || x<-90)
    {
        if(x>360)
          x=x-360;
        else if(x<-360)
          x=x+360;
        else if (x>90 && x<360)
          x=180-x;
        else
          x=360+x;
    }
    x=90-x;
    x=(x*3.14)/180;
    printf("\nEnter the number of terms:");
    scanf("%f",&n);
    l=sum(n,x);
    printf("\nThe sum of cos x series is %f",l);
    return 0;
}
