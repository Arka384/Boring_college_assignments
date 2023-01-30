#include<stdio.h>
int main()
{
	int n,s,x=1,i,j;
	printf("Enter the number of lines: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i;j++)
			printf(" ");
		for(j=0;j<=i;j++)
		{
			if(j==0 || j==i)
				x=1;
			else
				x=x*(i-j+1)/j;
			printf("%d ",x);
		}
		printf("\n");
	}
}