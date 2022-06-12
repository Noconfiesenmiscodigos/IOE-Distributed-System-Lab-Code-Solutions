//LAB 2:
//MUTUAL EXCLUSION ALGORITHMS
//1. Write a program to simulate the Distributed Mutual Exclusion in ‘C’.

#include<stdio.h>
#include<conio.h>
#include<dos.h> #include<time.h>
void main()
{
    int cs=0,pro=0;
    double run=5;
    char key='a';
    time_t t1,t2;
    printf("Press a key(except q) to enter a process into critical section.\n");
    printf(" \nPress q at any time to exit.\t");
    t1 = time(NULL) - 5;
    while(key!='q')
    {
        while(!kbhit()) if(cs!=0)
            {
                t2 = time(NULL);
                if(t2-t1 > run)
                {
                    printf("\nProcess %d ",pro-1);
                    printf(" exits critical section.\n");
                    cs=0;
                }
            }
        key = getch();
        if(key!='q')
        {
            if(cs!=0)
                printf("\n\nError: Another process is currently executing critical section Please wait till its execution is over.\n");
            else
            {
                printf("\nProcess %d ",pro);
                printf(" entered critical section\n");
                cs=1;
                pro++;
                t1 = time(NULL);
            }
        }
    }
}

/*
Press a key(except q) to enter a process into critical section.

Press q at any time to exit.
Process 0  entered critical section

Process 0  exits critical section.

Process 1  entered critical section


Error: Another process is currently executing critical section Please wait till its execution is over.

Process 1  exits critical section.

Process 2  entered critical section

Process 2  exits critical section.

Process 3  entered critical section
*/
