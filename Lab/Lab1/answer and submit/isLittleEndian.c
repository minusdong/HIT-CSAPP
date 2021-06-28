#include<stdio.h>

int main(void)
{
	int i = 1;
	char *a = (char *)&i;
	if (*a == 1)
		printf("小端");
	else
		printf("大端");
	return 0;
}
