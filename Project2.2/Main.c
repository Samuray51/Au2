#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include<windows.h> 
#include <math.h> 
#include<locale.h>
int IntStr(char *p) 
{
	int numb = 0;
	int i = 0;
	int sign = 0; // знак числа 0 - положительное, 1 — отрицательное
	if (p[i] == '-')
	{
		sign = 1;
		i++;
	}
	while (p[i] >= 0x30 && p[i] <= 0x39) 
	{
		numb = numb + (p[i] & 0x0F);
		numb = numb * 10;
		i++;
	}
	numb = numb / 10;
	if (sign == 1)
	{
		numb = -numb;
	}
	return numb;
}

int main() 
{
	char* mas = (char*)malloc(sizeof(char));
	int i = 0, j = 0, k = 0, h = 0, count;
	int* numb = (int*)malloc(sizeof(int));
	printf("print  enter then s to stop\n");
	do
	{
		j = 0;
		do
		{
			scanf_s("%c", &mas[j], 1);
			j++;
			mas = (char*)realloc(mas, (j + 2) * sizeof(char));
		} while (mas[j - 1] != '\n' && mas[j - 1] != ' ');
		k = 0;
		for (i = 0; i < j - 1; i++)
		{
			if (isdigit(mas[i]))
			{
				k++;
			}
		}
		if (k == i && k != 0) 
		{
			numb[h] = IntStr(mas);
			h = h + 1;
			numb = (int*)realloc(numb, (h + 2) * sizeof(int));
		}

	} while (mas[j - 2] != 's');
	count = h;
	printf("\n");
	for (i = 0; i < count; i++)
	{
		printf("%.0lf ", pow(numb[i], 2));
	}
	system("pause");
	return 0;
}