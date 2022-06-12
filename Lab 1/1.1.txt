//LAB 1: CLOCK SYNCHRONIZATION ALGORITHMS
//1. Write a program to simulate the functioning of Lamport’s logical clock in 'C’.

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void main()
{
    int i,j,k;
    int x=0;
    char a[10][10];
    int n,num[10],b[10][10];
    printf("Enter the no. of physical clocks: ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("\nNo. of nodes for physical clock %d: ",i+1);
        scanf("%d",&num[i]);
        x=0;
        for(j=0; j<num[i]; j++)
        {
            printf("\nEnter the name of process: ");
            scanf("%s",&a[i][j]);
            b[i][j]=x + rand() % 10;
            x=b[i][j]+1;
        }
    }
    printf("\nPress a key for watching timestamp of physical clocks ");
    getch();
    for(i=0; i<n; i++)
    {
        printf("\n\nPhysical Clock %d: ",i+1);
        for(j=0; j<num[i]; j++)
        {
            printf("\nProcess: %c ",a[i][j]);
            printf(" has P.T. : %d ",b[i][j]);
            printf("\n");
        }
    }
    printf("\nPress a key for watching timestamp of logical clocks \n");
    getch();
    x=0;
    for(i=0; i<10; i++) for(j=0; j<n; j++) for(k=0; k<num[j]; k++) if(b[j][k]==i)
                {
                    x = rand() % 10 + x;
                    printf("\nLogical Clock Timestamp for process %c ",a[j][k]);
                    printf(":%d ",x);
                }
    getch();
    return;
}

/*
Enter the no. of physical clocks: 2

No. of nodes for physical clock 1: 2

Enter the name of process: a

Enter the name of process: b

No. of nodes for physical clock 2: 2

Enter the name of process: c

Enter the name of process: d

Press a key for watching timestamp of physical clocks

Physical Clock 1:
Process: a  has P.T. : 1

Process: b  has P.T. : 9


Physical Clock 2:
Process: c  has P.T. : 4

Process: d  has P.T. : 5

Press a key for watching timestamp of logical clocks

Logical Clock Timestamp for process a :9
Logical Clock Timestamp for process c :13
Logical Clock Timestamp for process d :21
Logical Clock Timestamp for process b :29
*/
