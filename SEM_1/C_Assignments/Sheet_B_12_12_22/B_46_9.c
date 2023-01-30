#include <stdio.h>
#include <string.h>

char reVal(int num)
{
	if (num >= 0 && num <= 9)
		return (char)(num + '0');
	else
		return (char)(num - 10 + 'A');
}

void strev(char *str)
{
	int len = strlen(str);
	int i;
	for (i = 0; i < len/2; i++)
	{
		char temp = str[i];
		str[i] = str[len-i-1];
		str[len-i-1] = temp;
	}
}

char* fromDeci(char res[], int base, int inputNum)
{
	int index = 0;
	
	if(base == 1) {	//special case;
		int i=1;
		for(i=1;i<=inputNum;i++)
			res[index++] = reVal(1);
		res[index] = '\0';
		return res;
	}

	while (inputNum > 0)
	{
		res[index++] = reVal(inputNum % base);
		inputNum /= base;
	}
	res[index] = '\0';
	strev(res);

	return res;
}

int main()
{
	int inputNum, base;
	char res[100];

    printf("\nEnter the decimal number: ");
    scanf("%d", &inputNum);
    printf("\nEnter the output base required: ");
    scanf("%d", &base);

	printf("Equivalent of decimal %d in base %d is: %s\n", inputNum, base, fromDeci(res, base, inputNum));
	return 0;
}
