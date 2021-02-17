#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
int acc;
float bal=10000;


void load(int x,int y);
void gotoxy(int x,int y);
void pattern(int x,int y);
void main_menu(void);
int password(int);
void acc_bal(void);

void acc_bal(void)
{
    gotoxy(45,7);
    printf("*BALANCE ENQUIRY*");
    gotoxy(37,8);
    printf("YOUR ACCOUNT BALANCE IS %.2f",bal);
}
void main_menu()
{
    int n;
    float depo=0;
    int pass;
    char name[20];
re_enter:
    pattern(30,3);
    gotoxy(45,5);
    printf("WELCOME TO CODERS BANK");
    load(45,6);
        //COLLECTING INFORMATION ACC NUM,PASSWORD
    gotoxy(45,8);
    printf("ACCOUNT NUMBER:-");
    scanf("%d",&acc);
    fflush(stdin);
    gotoxy(45,9);
    printf("ACCOUNT HOLDERS NAME:-");
    gets(name);
    fflush(stdin);
        //ACQUIRING PASSWORDl
    printf("PASSWORD=>");
    scanf("%d",&pass);
        //CONDITION CHECK FOR ACCESS
    if(password(pass))
    {
        gotoxy(45,10);
        printf("1.BALANCE ENQUIRY");
        gotoxy(45,12);
        printf("2.DEPOSIT MONEY");
        gotoxy(45,14);
        printf("3.WITHDRAW MONEY");
        gotoxy(45,16);
        printf("4.TRANSFER MONEY");
        gotoxy(45,18);
        printf("5.EXIT");
        gotoxy(47,20);


        printf("SELECT OPTION");
        scanf("%d",&n);

        switch (n)
        {
        case 1:
            system("cls");
            pattern(30,3);
            acc_bal();
            printf("DO YOU WANT ANOTHER TRANSACTION");

            break;
        case 2:
            printf("Enter he amount you need to deposit:-");
            scanf("%d",&depo);
            bal-=depo;
            break;
        case 3:
            //withdraw(,);
            break;
        case 4:
            //Transfer(,);
            break;
        case 5:
            system("cls");
            pattern(30,3);
            gotoxy(45,10);
            printf("THANKS FOR COMING\n ENTER A KEY");
            getch();
            break;
        }
    }
    else
    {
        gotoxy(48,20);
        printf("WRONG PASSWORD");
        load(48,19);

        goto re_enter;
    }
}

void main()
{
    system("color 0A");
    main_menu();
    getch();
}


int password(int p)
{
    int rev=0;
    while(acc>0)
    {
        rev=rev*10+acc%10;
        acc=acc/10;
    }
    if(rev==p)
        return 1;
    else
        return 0;
}


void load(int x,int y)
{
    gotoxy(x-5,y);
    for(int i=0; i<31; i++)
    {
        for(int j=0; j<50; j++)
        {
            gotoxy(x+i-5,y);
            printf("%c",177);
        }
    }

}


void gotoxy(int x,int y)
{
    COORD z;
    z.X=x;
    z.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),z);
}

void pattern(int x,int y)
{
    for(int i=1; i<=20; i++)
    {
        gotoxy(x,y);
        y++;
        for(int j=1; j<=50; j++)
        {
            if(i==1 || i==20 || j==1 || j==50)
                printf("*");

            else
                printf(" ");
        }
        printf("\n");
    }
}

