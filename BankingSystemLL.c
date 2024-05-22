#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
   char fSTname[100];
   char lSTname[100];
   char city[100];
   int password;
   int acc_no;
   float balance;
   int phn;
   struct node *link;
};

struct node *head=NULL;
void main_menu(){
    printf("\n");
    printf("\n(1) Create a new account\n(2) View Details\n(3) Deposit Amount\n(4) Withdraw Amount\n(5) All acount holders list\n(6) Exit\n  ");
}

int getaccountnum(struct node *head)
{
    struct node *temp, *prev;
        temp=prev=head;
        while(temp->link!=NULL){
            temp=temp->link;
        }
        temp->acc_no=prev->acc_no +10;
    return temp->acc_no;

}

struct node *createAcc(struct node *head){
    struct node *newnode, *temp;
    
    newnode=malloc(sizeof(struct node));
    
    char fname[100], lname[100], cname[100];
    printf("\nenter your first name = ");
    scanf("%s",fname);
    strncpy(newnode->fSTname, fname,sizeof(newnode->fSTname));
    printf("\nenter your last name = ");
    scanf("%s",lname);
    strncpy(newnode->lSTname, lname,sizeof(newnode->lSTname));
    printf("\nEnter city: ");
    scanf("%s",cname);
    strncpy(newnode->city, cname,sizeof(newnode->city));
    printf("\nEnter amount: Rs");
    scanf("%f",&newnode->balance);
    printf("\nContact number: ");
    scanf("%d",&newnode->phn);
    printf("\nCreate new password for account (only numbers) :");
    scanf("%d",&newnode->password);
    newnode->link=NULL;
    temp=head;
    while(temp->link!=0){
        temp=temp->link;
    }
    temp->link=newnode;

    printf("your new account no: %d\n", getaccountnum(head));
    return head;
}

void deposite(struct node*head){
    struct node *temp;
    temp=head;
    int depACC;
    float depBal;
    printf("\nenter your account number : ");
    scanf("%d", &depACC);
    printf("\nenter amount to be deposited : Rs ");
    scanf("%f", &depBal);
    while(temp!=0){
        if(temp->acc_no==depACC){
        temp->balance=temp->balance + depBal;
        printf("\nAmount Deposited \nAvailable balance : %f",temp->balance);
        break;
        }
        temp=temp->link;
    }
    
}

void withdraw(struct node*head){
    struct node *temp;
    int pass;
    temp=head;
    int withACC;
    float withBal;
    printf("\nenter your account number : ");
    scanf("%d", &withACC);
    printf("\nenter Password : ");
    scanf("%d", &pass);

    printf("\nenter amount to be withdrawal : Rs ");
    scanf("%f", &withBal);
    while(temp!=0){
        if(temp->acc_no==withACC && temp->password==pass){
           
             if(temp->balance<withBal){
                printf("\nSufficient amount is not Available in account to be withdraw\n Please check Available balance in account");
            }else{
                temp->balance=temp->balance - withBal;
        printf("\nAmount has been withdrawal \nAvailable balance : Rs %f",temp->balance);
        }
        break;
        }
       
        temp=temp->link;
    }
    
}

void all_account_holders_list(struct node *head){
    struct node *temp;
    temp=head;
    while(temp!=0) {
        printf("\nAccount holder name: ");
        printf("%s", temp->fSTname);
        printf(" %s", temp->lSTname);
        printf("\nAccount No.: %d", temp->acc_no);
        printf("\nCity: ");
        printf("%s",temp->city);
        printf("\nContact number: ");
        printf("%d",temp->phn);
        printf("\nBalance: Rs ");
        printf("%f",temp->balance);
        printf("\n");
        temp=temp->link;
        
    } 
}

void viewDetails (struct node *head){
    struct node *temp;
    temp=head;
    int depACC;
    printf("\nenter your account number : ");
    scanf("%d", &depACC);
    while(temp!=0){
        if(temp->acc_no==depACC){
        printf("\nAccount holder name: ");
        printf("%s", temp->fSTname);
        printf(" %s", temp->lSTname);
        printf("\nAccount No.: %d", temp->acc_no);
        printf("\nCity: ");
        printf("%s",temp->city);
        printf("\nContact number: ");
        printf("%d",temp->phn);
        printf("\nBalance: Rs ");
        printf("%f",temp->balance);
        printf("\n\n");
        break;
        }
        temp=temp->link;
    }

}

int main(){
    struct node *head, *newnode, *temp;
    head=NULL;
    newnode=(struct node *)malloc(sizeof(struct node));
    strncpy(newnode->fSTname, "sakshi", sizeof(newnode->fSTname));
    strncpy(newnode->lSTname, "Gokhale", sizeof(newnode->lSTname));
    strncpy(newnode->city, "Nagpur", sizeof(newnode->city));
    newnode->acc_no=620170;
    newnode->balance=174.0;
    newnode->phn=8957508;
    newnode->password=123;
    newnode->link=NULL;
    head=newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    strncpy(newnode->fSTname, "rachel", sizeof(newnode->fSTname));
    strncpy(newnode->lSTname, "michel", sizeof(newnode->lSTname));
    strncpy(newnode->city, "Newyork", sizeof(newnode->city));
    newnode->acc_no=620171;
    newnode->balance=374.0;
    newnode->phn=89990508;
    newnode->password=563;
    newnode->link=NULL;
    head->link=newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    strncpy(newnode->fSTname, "jerry", sizeof(newnode->fSTname));
    strncpy(newnode->lSTname, "kair", sizeof(newnode->lSTname));
    strncpy(newnode->city, "tokyo", sizeof(newnode->city));
    newnode->acc_no=620172;
    newnode->balance=745.0;
    newnode->phn=95790508;
    newnode->password=334;
    newnode->link=NULL;
    head->link->link=newnode;

    int choice;
    printf("WELCOME TO BANK OF NAGPUR\n");
    while(1){
    main_menu();
    printf("\n\nenter your choice\n");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            head=createAcc(head);
            printf("\nCongratulations...Your account has been created in BANK OF NAGPUR\n Now you can make transactions");
            break;
        case 2:
            viewDetails(head);
            break;
        case 3:
            deposite(head);
            break;
        case 4:
            withdraw(head);
            break;
        case 5:
            all_account_holders_list(head);
        break;
        case 6 :
            exit(0);
        default:
           printf("\nInvalid choice....\nPLEASE TRY AGAIN\n");
    }
    }
return 0;
    }


