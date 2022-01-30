#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
FILE *fp;
int cd=0,id=0;
char title[20],aur[20];
int page;float price;

void addbook();
void searchbook();
void showallbook();
void issuefine();
struct data {
    int id;
    char title[20];
    char aur[20];
    int page;
    float price;
}b;
int main(){
    int i;
    printf("\n||---------------------------------------------------||");
    printf("\n||***************TEAM-2******************************||");
    printf("\n||****WELCOME*************WELCOME*******WELCOME******||");
    printf("\n||***********LIBRARY MANAGEMENT**********************||");
    printf("\n||---------------------------------------------------||");
    printf("\n*******************************************************");
    printf("\n||---------------------------------------------------||");
    printf("\n||**************1.Add Book***************************||");
    printf("\n||**************2.Search Book************************||");
    printf("\n||**************3.ShowAllBook************************||");
    printf("\n||**************4.IssueFine**************************||");
    printf("\n||---------------------------------------------------||");
    printf("\n\nEnter Your Choice : ");
    scanf("%d",&i);
    switch(i){
    case 1:
        addbook();
        break;
    case 2:
        searchbook();
        break;
    case 3:
        showallbook();
        break;
    case 4:
        issuefine();
        break;
    default:
        printf("INVALID INPUT");
    }
    return;
}
void addbook(){
   system("cls");
   FILE *fp;
printf("***********ADDING BOOK***********");
printf("\n ENTER THE BOOK ID: ");
scanf("%d",&b.id);
printf("\n ENTER THE BOOK NAME: ");
scanf("%s",&b.title);
printf("\n ENTER THE AURTHOR NAME: ");
scanf("%s",&b.aur);
printf("\n ENTER THE NO.OF PAGES: ");
scanf("%d",&b.page);
printf("\n ENTER THE PRICE: ");
scanf("%f",&b.price);
fp=fopen("testdata.txt","a");
fprintf(fp,"%d %s %s %d %f",b.id,b.title,b.aur,b.page,b.price);
fclose(fp);
printf("\n SUCCESFULLY ADDED");

}
void searchbook(){
    system("cls");
    int scn,c=0;
    printf("***********SEARCH BOOK*********");
    printf("\nENTER THE BOOK ID TO SEARCH:");
    scanf("%d",&scn);
    fp=fopen("testdata.txt","r");
    fseek(fp,0,SEEK_END);
    cd=ftell(fp);
    fseek(fp,0,SEEK_SET);
    printf("\nID\tBookname\t\Author\t\Pages\t\Price");
    while(ftell(fp)!=cd){
        fscanf(fp,"%d %s %s %d %f",&id,&title,&aur,&page,&price);
        if (id==scn)
        {
            printf("\n%d\t%s\t\t%s\t%d\t%.2f",id,title,aur,page,price);
            c=1;
        }
    }
    if(c==0) printf("\nNOT FOUND !!!");
    fclose(fp);
}
void showallbook(){
    system("cls");
    fp=fopen("testdata.txt","r");
    fseek(fp,0,SEEK_END);
    cd=ftell(fp);
    fseek(fp,0,SEEK_SET);
    printf("\n***************ALL THE BOOKS************");
    printf("\nID\tBookname\tAuthor\tPages\tPrice");
    while(ftell(fp)!=cd){
        fscanf(fp,"%d %s %s %d %f",&id,&title,&aur,&page,&price);
        printf("\n%d\t%s\t%s\t%d\t%.2f",id,title,aur,page,price);
    }
    fclose(fp);
}
void issuefine(){
    system("cls");
    int d1,d2,m1,m2,y1,y2;
    printf("************ISSUE FINE*************");
    printf("\nENTER THE DATE OF SUBMISSION(DD/MM/YY): ");
    scanf("%d %d %d",&d1,&m1,&y1);
    printf("\nENTER THE DATE WHEN THE BOOK WAS SUBMITTED(DD/MM/YY): ");
    scanf("%d %d %d",&d2,&m2,&y2);
    if((d1<d2)&&(m1==m2)&&(y1==y2))
    printf("\n THE FINE AMOUNT IS: %d",(10*(d2-d1)));
    else if((m1<m2)&&(y1<=y2))
     printf("\n THE FINE AMOUNT IS:%d",(200*(m2-m1)));
    else if((d1>d2)&&(m1>m2)&&(y1<y2))
    printf("\n THE FINE AMOUNT IS:500");
    else
    printf("\n THE FINE AMOUNT IS:500");
}
