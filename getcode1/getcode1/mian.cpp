#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#pragma warning (disable:4996)

int main()
{
	/*FILE *fp;
	int count = 0;
	fp = fopen("get.txt", "r");
	char buf[1024] = {};
	while ((fgets(buf, 1024, fp)) != NULL)
	{
		char *tmp = buf;
		while (*tmp != '\n' && *tmp != '\0')
			tmp++;
		*tmp = '\0';
		char arr[1024] = {};
		FILE *file = NULL;
		file = fopen(buf, "r");

		while (fgets(arr, 1024, file) != NULL)
			count++;

		fclose(file);
	}

	printf("%d \n", count);
	fclose(fp);*/
	getchar();
}
