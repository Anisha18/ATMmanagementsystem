

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int pin,fact;
float amount;
struct node
{
    int pin;
    float amount;
    struct node *next;
}*first=NULL,*last=NULL,*temp=NULL;
void create()
{
    temp=(struct node *)malloc(sizeof(struct node));
    printf("Enter pin and amount\n");
    scanf("%4d%f",&temp->pin,&temp->amount);
    temp->next=NULL;
}
void insertend()
{
    if(first==NULL)
    {
        create();
        first=temp;
        last=first;
    }
    else
    {
        create();
        last->next=temp;
        last=temp;
    }
}
void atm()
{
    fact=0;
    printf("Enter your pin:");
    scanf("%4d",&pin);
    temp=first;
    while(temp!=NULL)
    {
        if(temp->pin!=pin)
            temp=temp->next;
        else
            return;
    }
    fact=1;
    return;
}
void checkbalance()
{
    atm();
    if(fact==0)
    {
        printf("\nYour balance in Rs:%.2f",temp->amount);
        return;
    }
    printf("Invalid pin\n");
    return;
}
void withdraw()
{
    atm();
    if(fact==1)
    {
        printf("Invalid pin\n");
        return;
    }
    printf("Enter the amount to withdraw:");
    scanf("%f",&amount);
    if((int)amount%100!=0)
    {
        printf("\nPlease enter amount in multiples of 100:");
        scanf("%f",&amount);
    }
    {
        if(amount>(temp->amount-500))
            printf("\nInsufficient balance\n");
        else
        {
            temp->amount=temp->amount-amount;
            printf("\nPlease collect your cash\n");
            printf("\nYour current balance is:%.2f",temp->amount);
        }
    }
    return;
}
void depositcash()
{
    atm();
    if(fact==1)
    {
        printf("Invalid pin\n");
        return;
    }
    printf("Enter the amount to deposit:");
    scanf("%f",&amount);
    temp->amount=temp->amount+amount;
    printf("\nAmount deposited successfully\n");
    printf("\nYour current balance is:%.2f",temp->amount);
    return;
}
int main()
{
    int ch,i;
    char flag;
    printf("Enter 10 valid pins(4 digits) with corresponding amount\n");
    for(i=1;i<=10;i++)
        insertend();
    printf("Valid pins\tAmount\n");
    temp=first;
    while(temp!=NULL)
    {
        printf("%d\t%.2f\n",temp->pin,temp->amount);
        temp=temp->next;
    }
    printf("\n-----Welcome to ATM-----\n");
    do
    {
        printf("1.Check balance\n");
        printf("2.Withdraw cash\n");
        printf("3.Deposit cash\n");
        printf("4.Quit\n");
        printf("***********\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:checkbalance();
                    break;
            case 2:withdraw();
                    break;
            case 3:depositcash();
                    break;
            case 4:printf("Thank you for using ATM\n");
                    exit(0);
            default:printf("Invalid choice!!!");
                    break;
        }
        printf("\nDo you wish to have another transaction?(y/n):");
        scanf(" %c",&flag);
    }while(flag=='y'||flag=='Y');
    printf("\nThanks for using ATM\n");
    return 0;
}
