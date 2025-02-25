#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

int main()
{
	

	FILE* fp;
	int x, s = 0, i = 0, nr[100] = { 0 };
	char c[100][100], * p;
	//problema 2
	if (fopen_s(&fp, "in.txt", "r") != 0)
	{
		//printf("Eroare. Nu am putut deschide fisierul\n");
	}
	else {
		//printf("Am deschis fisierul cu success!\n");
		char myString[200];
		
		x = 0;
		if (fgets(myString, 200, fp))
		{
			myString[strlen(myString)] = '\0';
			//strcpy_s(c[i++], myString);
		}
		//cout << myString;
		strcpy_s(c[0], "");
		for (int j = 0;j < strlen(myString);j++) {
			//cout << myString[j] << " " << (myString[j] == ' ') << endl;
			c[i][nr[i]++] = myString[j];
			if (myString[j] == ' ') {
				//c[i][nr[i]] = '\n';
				cout << i << " " << nr[i] << endl;
				i++;  
				
				strcpy_s(c[i], "");
			}
		}
		cout << endl;
		for (int j = 0;j <= i;j++) {
			for (int k = 0;k <= i;k++) {
				if (nr[j] > nr[k])
					swap(c[j], c[k]), swap(nr[j],nr[k]);
			}
		}
		cout << endl;
		for (int j = 0;j <= i;j++) {
			cout << nr[j] << endl;
		}

	}
	for (int j = 0;j <= i;j++) {
		for (int k = 0;k < nr[j];k++)
			cout << c[j][k];
		printf("\n");
	}
	//cout << "Primul laborator OOP";
	return 0;
}