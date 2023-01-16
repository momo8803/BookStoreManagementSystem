#include<stdio.h>  
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

void return_confirm(void);
void pre_populate(void);
int book_add(void);
int book_show(void);
int book_search(void);
int book_del(void);
int book_buy(void);
void book_return(void);

COORD coord = {0, 0};

struct books
{
	long long int isbn;
	char title[50];
	char author[50];
	char publish[50];
    char genre[50];
    int year;
	int amount;
    float price;
}books[500];

int i,k;

void return_confirm()
{
    
	printf("\npress anykey\n");
	getch();
} 

void pre_populate(){
	books[0].isbn = 166566155;
	strcpy(books[0].title, "Harry Potter");
	strcpy(books[0].author, "J.K. Rowling");
	strcpy(books[0].publish, "Harry Potter");
	strcpy(books[0].genre, "Harry Potter");
	books[0].year=1992;
	books[0].amount=50;
	books[0].price=19.5;
	k=1;
}
 
int book_add()
{
    int n;
    system("cls"); //a command to clear the output screen
    int max;
    int spaceLeft;
    do{
        printf("----------Book Add----------\n");        
        printf("how many book you wanna add? :");
        scanf("%d",&n);
        max = 500-k;
        if(n>max){
            printf("over limit, try again!\n");
        }
        else{
            spaceLeft=500-(k+n);
            printf("You have %d space left\n",spaceLeft);
        }
    }while(n>max);
    
    for(i=0;i<n;i++){
        long long int m;
        printf("please enter book %d\n",i+1);
        printf("id(isbn):");
        scanf("%lld",&books[k].isbn);
        fflush(stdin);
        printf("title:");
        scanf("%[^\n]%*c",&books[k].title);
        fflush(stdin); 
        printf("author:");
        scanf("%[^\n]%*c",&books[k].author); 
        fflush(stdin);
        printf("publish:");
        scanf("%[^\n]%*c",&books[k].publish);
        fflush(stdin); 
        printf("genre:");
        scanf("%[^\n]%*c",&books[k].genre);
        printf("year:");
        scanf("%d",&books[k].year);
        printf("amount:");
        scanf("%d",&books[k].amount);
        printf("price:");
        scanf("%f",&books[k].price);
        k++;
        printf("\n"); 
        return_confirm();	
    } 
}



void gotoxy (int x, int y)
{
coord.X = x; coord.Y = y; // X and Y coordinates
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int book_show()
{    
	int i,f=0,j=1;
	system("cls");
    printf("id\t\ttitle\t\tauthor\t\tpublish\t\tgenre\t\tyear\t\tamount\t\tprice\n");
	for(i=0;i<k;i++)
	{
        gotoxy(0,j);
        printf("%d",books[i].isbn);
        gotoxy(16,j);
        printf("%s",books[i].title);
        gotoxy(32,j);
        printf("%s",books[i].author);
        gotoxy(48,j);
        printf("%s",books[i].publish);
        gotoxy(64,j);
        printf("%s",books[i].genre);
        gotoxy(80,j);
        printf("%d",books[i].year);
        gotoxy(96,j);
        printf("%d",books[i].amount);
        gotoxy(112,j);
        printf("%.2f",books[i].price);
        j++;	
	} 
	getch();
	return i;	
}

int book_search()
{
	int n,i,f=0,j=2;
	char nam[30];
	system("cls");
	fflush(stdin);
	printf("please enter the book title: ");
	scanf("%[^\n]%*c",&nam);
    printf("id\t\ttitle\t\tauthor\t\tpublish\t\tgenre\t\tyear\t\tamount\t\tprice\n");
	for(i=0;i<500;i++) //k not 500
	{
    
		if(strcmp(books[i].title,nam)==0)
		{
            gotoxy(0,j);
			printf("%d",books[i].isbn);
            gotoxy(16,j);
			printf("%s",books[i].title);
            gotoxy(32,j);
			printf("%s",books[i].author);
            gotoxy(48,j);
			printf("%s",books[i].publish);
            gotoxy(64,j);
            printf("%s",books[i].genre);
            gotoxy(80,j);
            printf("%d",books[i].year);
            gotoxy(96,j);
            printf("%d",books[i].amount);
            gotoxy(112,j);
            printf("%.2f\n",books[i].price);
            j++;
			n=i;
			f=1;

			}
	}
    if(f==0)
    {

        printf("\ncant find any\n");
        getch();
        return -1;
    }
    printf("Do you want to search again?(Y / N):");
    if(getch()=='y')
    {
        book_search();
    }
    else
    {
    return_confirm();
    
    }

    return n;
}


int book_del()
{
    int i,num,j;
	system("cls");
	printf("enter book id:");
	scanf("%lld",&num);
	for(i=0;i<500;i++)
	{
    
		if(books[i].isbn==num)
		{
    
			for(j=i;j<500;j++)
			{
                //books[j]=books[j+1];
				books[j].isbn=books[j+1].isbn;
				strcpy(books[j].title,books[j+1].title);
				strcpy(books[j].author,books[j+1].author);
                strcpy(books[j].publish,books[j+1].publish);
                strcpy(books[j].genre,books[j+1].genre);
                books[j].year=books[j+1].year;
                books[j].amount=books[j+1].amount;
                books[j].price=books[j+1].price;
                
            }
            k--;
			getch();
            printf("is deleted!!!\n");
            getch();
			return i;
                
			
		}	
	} 
	printf("cant find any\n");
	return_confirm();
	return -1;
}


int book_buy()
{ 
	int n,s,i,d;
	system("cls");
    printf("enter the book id:");
    scanf("%lld",&n);
    //int index = search_by_isbn(isbn);
    //if (index == -1)
    //    sorry no book! 
    //    return;  
    for(i=0;i<500;i++) // should be k
    {
        if(n==books[i].isbn)
        {
            printf("how many you wanna buy:");
		    scanf("%d",&d); 
	
		    books[i].amount=books[i].amount-d;	
        
            printf("you have bought the book ID:%d and there is %d left",books[i].isbn,books[i].amount);
            getch();
            break;
            return i;
        }
    }
        if(n!=books[i].isbn||books[i].amount==0){
            printf("book ID is not correct or it is sold out \n\n");
            return_confirm();
        }
}

void book_return()
{
    int n,s,i,d;
	system("cls");
	printf("enter the book id:");
	scanf("%lld",&n);
    
    for(i=0;i<500;i++)
        {
            if(n==books[i].isbn)
            {
		    printf("how many you wanna return?:");
		    scanf("%d",&d); 
                if(d>0){
	            books[i].amount=books[i].amount+d;	
                printf("success return. the amount of this book before is %d, now is %d",books[i].amount-d,books[i].amount);
                getch();
                break;
                }
                else
                {
                printf("amount not right\n");
                getch();
                break;
                }
            }
        }
	        if(n!=books[i].isbn)
	        {
		    printf("book ID is not correct\n\n");
            return_confirm();
            }
}  

int main()
{
    int choice;
    pre_populate();
    system("cls");
	menu:
    do{
        printf("\n\n\t========Wellcome to Book Store Management System========\n");
        printf("\t\t1.Add book\t\t2.show book\n"
                "\t\t3.search book\t\t4.delete book\n" 
                "\t\t5.Buy book\t\t6.return buy\n" 
                "\t\t7.exit\t\t\n"  
                "Please enter your choice: ");
        scanf("%d",&choice);
        if(choice<=0||choice>=8){
            printf("Wrong choice, please enter again!\n");
        }
    }while(choice<=0||choice>=8);
 
	switch(choice)
	{    
		case 1: book_add();    break;
		case 2: book_show();   break;
		case 3: book_search(); break;
		case 4: book_del();    break;
		case 5: book_buy();    break;
		case 6: book_return(); break;
		case 7: printf("Thank you for using Book Store Management System\nBye Bye!");
                exit(50000);        
	}    
	goto menu;	
 } 