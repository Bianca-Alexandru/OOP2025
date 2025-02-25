#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
	

	FILE* fp;
	int x, s = 0, i;
	//problema 1
	if (fopen_s(&fp, "in.txt", "r") != 0)
	{
		//printf("Eroare. Nu am putut deschide fisierul\n");
	}
	else {
		//printf("Am deschis fisierul cu success!\n");
		char myString[200];
		/*
		if (fgets(myString, 200, fp))
		{
			printf("Am citit din fisier: %s\n", myString);
		}
		*/
		x = 0;
		while (fgets(myString, 200, fp))
		{
			myString[strlen(myString) - 1] = '\0';
			x = 0;
			for (i = 0;i < strlen(myString);i++) {
				x = x * 10 + myString[i] - '0';
			}
			s += x;
			//printf("Am citit din fisier: %s\n", myString);
		}
	}
	printf("%d\n", s);
	//cout << "Primul laborator OOP";
	return 0;
}