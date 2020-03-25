#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include<windows.h>
typedef struct
{
	int age;
	char *name;
} Person;
char maxn[255];

int ScanfFiles(Person *p, FILE *f)
{
	char tmp;
	int maxage = 0,Age;
	fscanf_s(f, "%d", &Age);
	p->age = Age;
	fscanf_s(f, "%c", &tmp, 1);
	fgets(maxn,255, f);
	int sizeOfBuffer = strlen(maxn);
	p->name = (char*)malloc((sizeOfBuffer + 1) * sizeof(char));
	strcpy_s(p->name, sizeOfBuffer + 1, maxn);
	return p->age;
}


void output(Person* p)
{
	printf("%d %s", p->age, p->name);
}



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n, i = 0,age1=0,maxage=0,j=0;
	FILE *in;
	fopen_s(&in, "input.txt", "r");
	fscanf_s(in, "%d", &n);
	Person *mas = (Person*)malloc(n * sizeof(Person));
	for (int i = 0; i < n; i++)
	{
		age1=ScanfFiles(&mas[i], in);
		if (maxage < age1)
		{
			j = i;
			maxage = age1;
		}
		
	}
	for (i = 0; i < n; i++)
	{
		output(&mas[i]);
	}
	printf("\n");
	output(&mas[j]);
	fclose(in);
	free(mas);
	system("pause");
	return 0;
}