#include <stdio.h>
#include <stdio.h>
#include <string.h>

int utf8len(char* str) {
    int count = 0;
    while (*str != '\0') {
        if ((*str >> 7) == 0)
            str++;
        else if ((*str >> 5) == 6)
            str = str + 2;
        else if ((*str >> 4) == 14)
            str = str + 3;
        else //(*str >> 4) == 15
            str = str + 4;
        count++;
    }
    return count;
}

int main(void)
{
	char str[] = "1190202105傅浩东";
	printf("utf8len = %d\n", utf8len(str));
    printf("strlen = %d\n", strlen(str));
	return 0;
}
