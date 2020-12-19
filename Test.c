#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <string.h>
#include <windows.h>

struct account {
char name[20];
char add[30];
char pnum[11];
char dob[11];
char acc_type[8];
unsigned long int acc_num;
char u_id[10]; //view
char password[10]; //update
int transaction[5];
int balance; //view
struct account *next_acc;
};
struct account *a=NULL;

struct account* fileReader(FILE *fr){

    struct account *temp = malloc(sizeof(struct account));
    char user_name[20];
    char user_add[30];
    char user_pnum[11];
    char user_dob[11];
    char type[8];
    unsigned long int num;
    char id[10];
    char pass[10];
    int t[5];
    int bal;
    int i;
    if(fr==NULL)
        return NULL;

    int fileRead = fscanf(fr,"%[^\t]%*c %[^\t]%*c %s\t %s\t %s\t %lu\t %s\t %s\t %d %d %d %d %d\t %d\n",user_name,user_add,user_pnum,user_dob,type,&num,id,pass,&t[0],&t[1],&t[2],&t[3],&t[4],&bal);
    if(fileRead != EOF){
        strcpy(temp->name,user_name);
        strcpy(temp->add,user_add);
        strcpy(temp->pnum,user_pnum);
        strcpy(temp->dob,user_dob);
        strcpy(temp->acc_type,type);
        temp->acc_num=num;
        strcpy(temp->u_id,id);
        strcpy(temp->password,pass);
        for(i=0;i<5;i++)
            temp->transaction[i]=t[i];
        temp->balance=bal;
        temp->next_acc = fileReader(fr);
    }
    if(fileRead == EOF) {
        return NULL;
    }
    return temp;
}

void fileWriter()
{
    FILE *fw;
    fw=fopen("test.txt","w");
    struct account *temp;
    temp=a;
    while(temp!=NULL)
    {
      fprintf(fw,"%s\t %s\t %s\t %s\t %s\t %lu\t %s\t %s\t %d %d %d %d %d\t %d\n",temp->name,temp->add,temp->pnum,temp->dob,temp->acc_type,temp->acc_num,temp->u_id,temp->password,temp->transaction[0],temp->transaction[1],temp->transaction[2],temp->transaction[3],temp->transaction[4],temp->balance);
      temp=temp->next_acc;
    }
    fclose(fw);
}
void display();
void user_display(char[]);
void admin_display();
//user functions
void update_user(char[]);
void user_account(char[]); //admin user
//admin functions
void view_users();
struct account* add_account(struct account**);
void delete_account();

void free_ll();
int main()
{
    FILE *fr;
    char id[]="abcd";
    fr=fopen("test.txt","r");
    a=fileReader(fr);
    fclose(fr);
    system("color C");
    display();
    user_display(id);
    display();
    admin_display();
    fileWriter();
    free_ll();
    return 0;
}
void free_ll()
{
    struct account *temp;
    temp=a;
    while(temp!=NULL)
    {
        temp=a;
        a=a->next_acc;
        free(temp);
    }
}
void display()
{
    system("cls");
    printf("\n\t\t\t------------------------");
    printf("\n\t\t\t|BANK MANAGEMENT SYSTEM|");
    printf("\n\t\t\t------------------------");
}


void user_display(char id[])
{
    char op;
    A:
        printf("\n\n\t\t USER OPTIONS");
        printf("\n\n\t1.View account Details");
        printf("\n\n\t2.Edit Personal Details");
        printf("\n\n\t3.View transaction");
        printf("\n\nEnter Valid Option");
        fflush(stdin);
        scanf("%c",&op);

    switch(op)
    {
    case '1':
        display();
        user_account(id);
        break;
    case '2':
        display();update_user(id);
        break;
    case '3':
        //display();view_transaction();
        break;
    default:
        printf("\n\t\tInvalid Option!!");
        Sleep(350);
        display();
        goto A;
        break;
    }

}

void admin_display()
{
    char id[10];
    char op;
    B:
        printf("\n\n\t\t ADMIN OPTIONS");
        printf("\n\n\t1.View Details of All Customers");
        printf("\n\n\t2.View Details of Particular Customer");
        printf("\n\n\t3.Add account");
        printf("\n\n\t4.Delete account");
        printf("\n\n\t5.Reset Password");
        printf("\n\nEnter Valid Option");
        fflush(stdin);
        scanf("%c",&op);

    switch(op)
    {
    case '1':
        display();view_users();
        break;
    case '2':
        printf("\nEnter user id to view details");
        scanf("%s",id);
        display();user_account(id);
        break;
    case '3':
        display();a=add_account(&a);
        break;
    case '4':
        display();
        delete_account();
        break;
    case '5':
        //display();reset_password();
        break;
    default:
        printf("\n\t\tInvalid Option!!");
        Sleep(350);
        display();
        goto B;
        break;
    }
}
unsigned long int X = 1;

unsigned long int getrand(void)
{
    X = X * 1103515245 + 12345;
    return (unsigned long int)(X >> 16) & 0x7ffff;
}
struct account* add_account(struct account **h)
{
    struct account *temp;
    temp=*h;
    struct account *newnode = malloc(sizeof(struct account));
    printf("\nEnter the name : ");
    fflush(stdin);
    gets(newnode->name);
    printf("\nEnter your dob (dd/mm/yyyy): ");
    fflush(stdin);
    gets(newnode->dob);
    printf("\nEnter your address: ");
    fflush(stdin);
    gets(newnode->add);
    printf("\nEnter you phone number: ");
    fflush(stdin);
    scanf("%s",newnode->pnum);
    printf("\nEnter your account type: ");
    fflush(stdin);
    scanf("%s",newnode->acc_type);
    printf("\nThis is your account number: %lu",newnode->acc_num=getrand());
    printf("\nEnter your user id: ");
    fflush(stdin);
    scanf("%s",newnode->u_id);
    printf("\nEnter your password: ");
    fflush(stdin);
    scanf("%s",newnode->password);
    printf("\nPlease deposit some amount (Deposit minimum Rs.500 to open the account): ");
    fflush(stdin);
    scanf("%d",&newnode->balance);

    newnode->next_acc = NULL;

    if(*h == NULL)
        {
            *h = newnode;
        }
    else
    {
        while(temp->next_acc!=NULL)
            temp = temp->next_acc;
        temp->next_acc = newnode;
    }
    return *h;

}

void delete_account()
{
    struct account *temp;
    unsigned long int checkacc_num;
    printf("\nEnter the account number you want to delete: ");
    scanf("%lu",&checkacc_num);
    //if(struct node *start == NULL)
        //printf("\nList is empty");
    if(a->acc_num==checkacc_num)
    {
        temp = a;
        a = a->next_acc;
        free(temp);
        printf("\nAccount deleted successfully");
        return;
    }
    else
    {
        struct account *current = a;
        while(current->next_acc!=NULL)
        {
            if(current->next_acc->acc_num==checkacc_num)
            {
                temp = current->next_acc;
                current->next_acc = current->next_acc->next_acc;
                free(temp);
                printf("\nAccount deleted successfully");
                break;
            }
            else
                current = current->next_acc;
        }
        if(current->next_acc==NULL)
        {printf("\nRecord not found!!");
        getch();
        }
    }


}
void view_users()
{
    struct account *ptr=a;
    if(ptr==NULL)
    {
        printf("\nNO ENTRIES!!\n");
        getch();
        return;
    }
    printf("\n\t%-20s%-30s%-15s%-15s%-15s%-15s%-15s%-15s","Name","Address","Phone Num","DOB","Account Type","Account Number","UserId","Balance");
    while(ptr!=NULL)
    {
        printf("\n\t%-20s%-30s%-15s%-15s%-15s%-15lu%-15s%-10d",ptr->name,ptr->add,ptr->pnum,ptr->dob,ptr->acc_type,ptr->acc_num,ptr->u_id,ptr->balance);
        ptr=ptr->next_acc;
    }
    getch();

}
void user_account(char id[])
{
    struct account *ptr=a;
    if(ptr==NULL)
    {
        printf("\nNO ENTRIES!!\n");
        getch();
        return;
    }
    while(ptr!=NULL)
    {
        if(strcmp(ptr->u_id,id)==0)
        {
            printf("\n\t%-20s%-30s%-15s%-15s%-15s%-15s%-15s%-15s","Name","Address","Phone Num","DOB","Account Type","Account Number","UserId","Balance");
            printf("\n\t%-20s%-30s%-15s%-15s%-15s%-15lu%-15s%-15d",ptr->name,ptr->add,ptr->pnum,ptr->dob,ptr->acc_type,ptr->acc_num,ptr->u_id,ptr->balance);
            break;
        }
        ptr=ptr->next_acc;
    }
    if(ptr==NULL)
        printf("\nNo such entry");
    getch();
}

void update_user(char id[])
{
    struct account *ptr=a;
    char ch;
    if(ptr==NULL)
    {
        printf("\nNO ENTRIES!!");
        getch();
        return;
    }
    while(ptr!=NULL)
    {
        if(strcmp(ptr->u_id,id)==0)
        {
            U:
                printf("\nEnter 1 to update address");
                printf("\nEnter 2 to update phone number");
                printf("\nEnter 3 to update password");
                printf("\nEnter 4 to exit");
                fflush(stdin);
                scanf("%c",&ch);
                switch(ch)
                {
                case '1':
                    printf("Enter new address");
                    fflush(stdin);
                    gets(ptr->add);
                    printf("Address updated successfully\n");
                    break;
                case '2':
                    printf("Enter new Phone Number");
                    fflush(stdin);
                    gets(ptr->pnum);
                    printf("Phone number updated successfully\n");
                    break;
                case '3':
                    printf("Enter new Password");
                    fflush(stdin);
                    gets(ptr->password);
                    printf("Password updated successfully\n");
                    break;
                case '4':
                    return;
                default:
                    printf("Invalid Option!!\n");
                    goto U;
            }
        }

}
}

