//2.	Write a program to implement Ring algorithm in C.

#include<stdio.h>
#include<conio.h> #include<process.h>
struct proc
{
    int live;
    int identifier;
}
process[10];
int n,cordinator=1; /* DISPLAY PROCESSES */
void display()
{
    int i;
    printf("\n PROCESSES ARE\n\n");
    printf("Processes ");
    for(i=1; i<=n; i++)
    {
        printf("P%d\t",i);
    }
    printf("\nlive       ");
    for(i=1; i<=n; i++)
    {
        printf("%d\t",process[i].live);
    }
    printf("\nidentifier ");
    for(i=1; i<=n; i++)
    {
        printf("%d\t",process[i].identifier);
    }
}
/* RING ALGORITHM */
void ring()
{
    int ch,c,id,i=0,init,max=-99,last;
    for(i=1; i<=n; i++)
    {
        if(process[cordinator].identifier<process[i].identifier&&process[i].live==1) cordinator=i;
    }
    printf("\n\n CURRENT CO-ORDINATOR IS=P%d",cordinator);
    while(ch!=4)
    {
        printf("\n\n\n *** RING ALGORITHM ***");
        printf("\n1.Crash a Process\n2.Activate Process\n3.Display\n4.Exit");
        printf("\nENTER UR CHOICE ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\n Enter the process id to crash ");
            scanf("%d",&id);
            if(process[id].live==0)
            {
                printf("\n Already crashed process");
            }
            else
            {
                process[id].live=0;
                printf("\n process P%d is crashed",id);
                if(id==cordinator)
                {
                    while(1)
                    {
                        printf("\n Enter process id who intiates election ");
                        scanf("%d",&init);
                        if(process[init].live==0)
                        {
                            printf("\n the selected process is crashed");
                        }
                        else
                        {
                            last=init;
                            printf("\nElection MSG sent from =%d",last);
                            for(i=init+1; i<=n; i++)
                            {
                                if(i!=init) printf(" ->%d",i);
                            }
                            for(i=1; i<init; i++)
                            {
                                if(i!=init) printf("->%d",i);
                                last=i;
                            }
                            for(i=init+1; i<=n; i++)
                            {
                                if(max<process[i].identifier && process[i].live==1)
                                {
                                    cordinator=i;
                                    max=process[i].identifier;
                                }
                            }
                            for(i=1; i<=init; i++)
                            {
                                if(max<process[i].identifier && process[i].live==1)
                                {
                                    cordinator=i;
                                    max=process[i].identifier;
                                }
                            }
                            printf("\n\n NEW CO-ORDINATOR IS=P%d",cordinator);
                            break;
                        }
                    }
                }
            }
            break;
        case 2:
            printf("\n Enter process id to activate ");
            scanf("%d",&id);
            if(process[id].live==1)
            {
                printf("\n Process %d is already active",id);
            }
            else
            {
                process[id].live=1;
                printf("\n Process %d activated",id);
                if(process[id].identifier>process[cordinator].identifier)
                {
                    printf("\n NEW CO-ORDINATOR IS=P%d\n\n",id);
                    cordinator=id;
                }
            }
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        }
    }
}
void main()
{
    int ch,i,c;
    printf("\n ENTER NO. OF PROCESSES ");
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        printf("\nEnter P%d process live or not(0/1) ",i);
        scanf("%d",&process[i].live);
        printf("\nEnter P%d process identifier ",i);
        scanf("%d",&process[i].identifier);
    }
    display();
    ring();
    getch();
}

/*

 ENTER NO. OF PROCESSES 4

Enter P1 process live or not(0/1) 1

Enter P1 process identifier 2

Enter P2 process live or not(0/1) 0

Enter P2 process identifier 3

Enter P3 process live or not(0/1) 1

Enter P3 process identifier 4

Enter P4 process live or not(0/1) 0

Enter P4 process identifier 4

 PROCESSES ARE

Processes P1    P2      P3      P4
live       1    0       1       0
identifier 2    3       4       4

 CURRENT CO-ORDINATOR IS=P3


 *** RING ALGORITHM ***
1.Crash a Process
2.Activate Process
3.Display
4.Exit
ENTER UR CHOICE 2

 Enter process id to activate 2

 Process 2 activated


 *** RING ALGORITHM ***
1.Crash a Process
2.Activate Process
3.Display
4.Exit
ENTER UR CHOICE 2

 Enter process id to activate 3

 Process 3 is already active


 *** RING ALGORITHM ***
1.Crash a Process
2.Activate Process
3.Display
4.Exit
ENTER UR CHOICE 2

 Enter process id to activate 4

 Process 4 activated


 *** RING ALGORITHM ***
1.Crash a Process
2.Activate Process
3.Display
4.Exit
ENTER UR CHOICE 3

 PROCESSES ARE

Processes P1    P2      P3      P4
live       1    1       1       1
identifier 2    3       4       4


 *** RING ALGORITHM ***
1.Crash a Process
2.Activate Process
3.Display
4.Exit
ENTER UR CHOICE 1

 Enter the process id to crash 4

 process P4 is crashed


 *** RING ALGORITHM ***
1.Crash a Process
2.Activate Process
3.Display
4.Exit
ENTER UR CHOICE 1

 Enter the process id to crash 2

 process P2 is crashed


 *** RING ALGORITHM ***
1.Crash a Process
2.Activate Process
3.Display
4.Exit
ENTER UR CHOICE 3

 PROCESSES ARE

Processes P1    P2      P3      P4
live       1    0       1       0
identifier 2    3       4       4


 *** RING ALGORITHM ***
1.Crash a Process
2.Activate Process
3.Display
4.Exit
ENTER UR CHOICE 1

 Enter the process id to crash 2

 Already crashed process


 *** RING ALGORITHM ***
1.Crash a Process
2.Activate Process
3.Display
4.Exit
ENTER UR CHOICE
*/
