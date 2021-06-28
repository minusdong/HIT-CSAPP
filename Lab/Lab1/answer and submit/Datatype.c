#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct info {
    char name[6];
    int age;
    double height;
    double weight;
};

union baseinfo {
    short age;
    char mychar;
    double num;
};

enum DAY{
    MON=1, TUE, WED, THU, FRI, SAT, SUN
};

struct info stru;
union baseinfo uni;
enum DAY day;

short Num = 33;
int stuID = 1190202105;
unsigned int age = 20;
char c = 'a';
char *cp = &c;
float birth = 20010214;
double IDcard = 53298200102147842; //unreal
long test = 346949234043709309;
int grade[3] = {97,98,99};

typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer start,size_t len)
{
    size_t i;
    for(i = 0; i < len; i++)
        printf("%.2x ", start[i]);
    printf("\n");
}

void show_short(short x){
    show_bytes((byte_pointer) &x, sizeof(short));
}
void show_int(int x){
    show_bytes((byte_pointer) &x, sizeof(int));
}
void show_unsigned(unsigned int x){
    show_bytes((byte_pointer) &x, sizeof(unsigned int));
}
void show_char(char x){
    show_bytes((byte_pointer) &x, sizeof(char));
}
void show_float(float x){
    show_bytes((byte_pointer) &x, sizeof(float));
}
void show_double(double x){
    show_bytes((byte_pointer) &x, sizeof(double));
}
void show_char_pointer(char *x){
    show_bytes((byte_pointer) &x, sizeof(char *));
}
void show_long(long x){
    show_bytes((byte_pointer) &x, sizeof(long));
}


int main(void)
{
    strcpy(stru.name, "FHD");
    stru.height = 178;
    stru.weight = 74.2;
    stru.age = 20;

    uni.age = 20;
    uni.mychar = 'c';

    printf("struct // %p // ", &stru);
    show_bytes((byte_pointer)&stru, sizeof(stru));
    printf("struct.char[] // %s // %p // ", stru.name, &(stru.name));
    show_bytes((byte_pointer)&(stru.name), sizeof(stru.name));
    printf("struct.int // %d // %p // ", stru.age, &(stru.age));
    show_int(stru.age);
    printf("struct.double // %.1f // %p // ", stru.height, &(stru.height));
    show_double(stru.height);
    printf("struct.double // %.1f // %p // ", stru.weight, &(stru.weight));
    show_double(stru.weight);
    printf("\n");

    printf("union // %p	// ", &uni);
    show_bytes((byte_pointer)&uni, sizeof(uni));
    uni.age = 20;
    printf("union.short // %hd // %p // ", uni.age, &(uni.age));
    show_short(uni.age);
    uni.mychar = 'c';
    printf("union.char // %c // %p // ", uni.mychar, &(uni.mychar));
    show_char(uni.mychar);
    uni.num = 897.213;
    printf("union.double // %.1f // %p // ", uni.num, &(uni.num));
    show_double(uni.num);
    printf("\n");

    day = MON;
    printf("enum // %d // %p // ", day, &day);
    show_bytes((byte_pointer)&day, sizeof(day));
    day = TUE;
    printf("enum // %d // %p // ", day, &day);
    show_bytes((byte_pointer)&day, sizeof(day));
    day = WED;
    printf("enum // %d // %p // ", day, &day);
    show_bytes((byte_pointer)&day, sizeof(day));
    printf("\n");

    printf("short // %hd // %p // ", Num, &Num);
    show_short(Num);
    printf("int // %d // %p // ", stuID, &stuID);
    show_int(stuID);
    printf("unsigned int // %u // %p // ", age, &age);
    show_unsigned(age);
    printf("char // %c // %p // ", c, &c);
    show_char(c);
    printf("char* // %p // %p // ",cp, &cp);
    show_char_pointer(cp);
    printf("float // %f // %p // ",birth, &birth);
    show_float(birth);
    printf("double // %lf // %p // ", IDcard, &IDcard);
    show_double(IDcard);
    printf("long // %ld // %p //", test, &test);
    show_long(test);

    printf("\n");
    printf("int[]  //    // %p // ", grade);
    show_bytes((byte_pointer)grade, sizeof(grade));
    printf("int[0] // %d // %p // ", grade[0], &(grade[0]));
    show_int(grade[0]);
    printf("int[1] // %d // %p // ", grade[1], &(grade[1]));
    show_int(grade[1]);
    printf("int[2] // %d // %p // ", grade[2], &(grade[2]));
    show_int(grade[2]);

    printf("\n");
    printf("main // %p \n",  &main);
    printf("printf // %p \n",  &printf);
    return 0;
}
