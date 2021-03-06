//2. Write a program to simulate the functioning of vector clock in 'C’.

#include<stdio.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


long *p1(int i,long *comp);
long *p2(int i,long *comp);
long *p3(int i,long *comp);
int main()
{
    srand(time(0));
    long start[]= {0,0,0},*vector;
    system("cls");
    while(!kbhit())
        p1(1,&start[0]);

    printf("\n Process Vector\n");
    vector=p1(0,&start[0]);
    printf("p1[%ld %ld %ld]\n",*vector,*(vector+1),*(vector+2));
    vector=p2(0,&start[0]);
    printf("p2[%ld %ld %ld]\n",*vector,*(vector+1),*(vector+2));
    vector=p3(0,&start[0]);
    printf("p3[%ld %ld %ld]\n",*vector,*(vector+1),*(vector+2));
    getch();
    return 0;
}
long *p1(int i,long *comp)
{
    static long a[]= {0,0,0};
    int next;
    if(i==1)
    {
        a[0]++;
        if(*(comp+1)>a[1])
            a[1]=*(comp+1);
        if(*(comp+2)>a[2])
            a[2]=*(comp+2);
        next=rand()%2;
        if(next==0)
            p2(1,&a[0]);
        else if(next==1)
            p3(1,&a[0]);
        return(&a[0]);
    }
    else
        return(&a[0]);
}
long *p2(int i,long *comp)
{
    static long b[]= {0,0,0};
    int next;
    if(i==1)
    {
        b[1]++;
        if(*comp>b[0])
            b[0]=*(comp);
        if(*(comp+2)>b[2])
            b[2]=*(comp+2);
        next=rand()%2;
        if(next==0)
            p1(1,&b[0]);
        else if(next==1)
            p3(1,&b[0]);
        return &b[0];
    }
    else
        return &b[0];
}
long *p3(int i,long *comp)
{
    static long c[]= {0,0,0};
    int next;
    if(i==1)
    {
        c[2]++;
        if(*comp>c[0])
            c[0]=*(comp);
        if(*(comp+1)>c[1])
            c[1]=*(comp+1);
        next=rand()%2;
        if(next==0)
            p1(1,&c[0]);
        return &c[0];
    }
    else
        return &c[0];
}

/*

O/P depends on how fast you click


 Process Vector
p1[304520 151852 228411]
p2[304519 151853 228411]
p3[304520 151853 228415]

Process returned 0 (0x0)   execution time : 7.339 s
Press any key to continue.


 Process Vector
p1[42874 21322 32179]
p2[42874 21323 32179]
p3[42874 21323 32180]

Process returned 0 (0x0)   execution time : 1.823 s
Press any key to continue.

*/
