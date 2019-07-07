
 #include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include<malloc.h>
struct criminal{
int id;
char name[20];
int age;
char sex[10];
char height[10];
char marks[30];
char crime[50];
char insp[20];
};
struct node{
int id;
char name[20];
int age;
char sex[10];
char height[10];
char marks[30];
char crime[50];
char insp[20];
struct node*next;};
typedef struct node NODE;
FILE *fp;
NODE *newnode,*head=NULL,*temp=NULL;
int node();
int password();
int display();
int search();
int add();
int modify();
int delet();
int menu();

int main()
{
  system("color e");
  printf("\n\t\t:::::::::::::::::::::::::::::::::::::::SDF PROJECT:::::::::::::::::::::::::::::::::\n\n");
  printf("\n\t\t\t\t\t\t           *                  ");
  printf("\n\t\t\t\t\t\t        *     *                ");
  printf("\n\t\t\t\t\t\t      *         *               ");
  printf("\n\t\t\t\t\t\t    *             *             ");
  printf("\n\t\t\t\t\t\t   *       @       *             ");
  printf("\n\t\t\t\t\t\t  *       @@@       *           ");
  printf("\n\t\t\t\t\t\t  *       JIIT      *          ");
  printf("\n\t\t\t\t\t\t  *       @@@       *             ");
  printf("\n\t\t\t\t\t\t   *       @       *              ");
  printf("\n\t\t\t\t\t\t    *             *               ");
  printf("\n\t\t\t\t\t\t      *         *                 ");
  printf("\n\t\t\t\t\t\t        *     *                   ");
  printf("\n\t\t\t\t\t\t           *                      ");
  printf("\n\t\t\t\t       JAYPEE INSTITUTE OF INFORMATION TECHNOLOGY ");
  printf("\n\n\n\t\t\t\t\t\t..........BY..........");
  printf("\n\n\t\t\t\t\t\t    SHIVAM KUMAR.");
  printf("\n\t\t\t\t\t\t    SHIVAM TRIPATHI.");
  printf("\n\t\t\t\t\t\t    AYUSH AGRAWAL.");
  printf("\n\t\t\t\t\t\t    ANANT MISHRA.");
  printf("\n\n\n\tCLICK ANY KEY TO CONTINUE.....");
  getch();
  menu();
}

int modify(){
    system("cls");
    printf("\n\t************************************MODIFY************************************");
    while(1){if(password()==1){
    struct criminal cri;
    int id,c=0,i;
    char ch,gh[30];
printf("\n\t\tEnter_ID_to_be_modify:");
scanf("%d",&id);
node();
temp=head;
while(temp!=NULL){
    if(temp->id==id){
system("cls");
printf("\n\t************************************MODIFY************************************");
printf("\n\n\t\t\t\t.......SELECT ITEM TO BE MODIFY.......\n");
printf("\n\t\t1:Modify_name.");
printf("\n\t\t2:Modify_age.");
printf("\n\t\t3:Modify_sex.");
printf("\n\t\t4:Modify_height.");
printf("\n\t\t5:Modify_marks.");
printf("\n\t\t6:Modify_crime.");
printf("\n\t\t7:Modify_inspector-in-charge.");
printf("\n\t\t8:NOTHING");
printf("\n\n\t\tEnter your choice :");
scanf("%d",&ch);
switch(ch)
  {
   case 1:printf("\n\nEnter_name:");
     scanf("%s",gh);
     strcpy(temp->name,gh);
     break;
   case 2:printf("\nEnter_age:");
     scanf("%d",&i);
     temp->age=i;
     break;
   case 3:printf("\nEnter_sex:");
     scanf("%s",gh);
     strcpy(temp->sex,gh);
     break;
   case 4:printf("\nEnter_height:");
     scanf("%s",gh);
     strcpy(temp->height,gh);
     break;
   case 5:printf("\nEnter_marks:");
     scanf("%s",gh);
     strcpy(temp->marks,gh);
     break;
   case 6:printf("\nEnter_crime:");
     scanf("%s",gh);
     strcpy(temp->crime,gh);
     break;
   case 7:printf("\nEnter_inspector-incharge:");
     scanf("%s",gh);
     strcpy(temp->insp,gh);
     break;
   case 8:
     break;}

     temp=temp->next;
        c++;}
    else{temp=temp->next;}
   }

   if(c==0){printf("\n\n\tNot_found....");
   printf("\n\n\tclick any key to continue....");
   getch();}
   else{printf("\n\n\tModify_successfully....");
        printf("\n\n\tclick any key to continue....");
   getch();}
   fp=fopen("criminals.txt","wb");
   temp=head;
   while(temp!=NULL){
   fwrite(temp,sizeof(cri),1,fp);
   temp=temp->next;}
   fclose(fp);
   break;}}

}
int delet(){
system("cls");
printf("\n\t************************************DELETE************************************");
while(1){if(password()==1){

struct criminal cri;
NODE *del;
int id1,c=0;
printf("\n\n\t\tEnter_ID_to_be_deleted:");
scanf("%d",&id1);
node();
if(head->id==id1){
        del=head;
        head=head->next;
        free(del);
        printf("\n\n\t\tDeleted_succesfully....");
        c++;
        }
 else{
    temp=head;
    while(temp->next!=NULL){

    if(temp->next->id==id1&&temp->next->next!=NULL){
        del=temp->next;
        temp->next=temp->next->next;
        del->next=NULL;
        free(del);
        printf("\n\n\t\tDeleted_succesfully....");
        c++;
        temp=temp->next;
        }
        else if(temp->next->next==NULL&&temp->next->id==id1){
            del=temp->next;
            temp->next=NULL;
            free(del);
            printf("\n\n\t\tDeleted_succesfully....");
            c++;
            }
    else{temp=temp->next;}}
}

   if(c==0){printf("not_found....");}
   fp=fopen("criminals.txt","wb");
   temp=head;
   while(temp!=NULL){
   fwrite(temp,sizeof(cri),1,fp);
   temp=temp->next;}
   fclose(fp);
   printf("\n\n\n\t\tclick any key to continue....");
   getch();
   break;}}
}
int node(){
struct criminal list;
head=NULL;
fp= fopen("criminals.txt","rb");
newnode=(NODE*)malloc(sizeof(NODE));
if(fp == NULL){
    printf("\n Can't open file or file doesn't exist.");}
 else{while(fread(newnode,sizeof(list),1,fp)){
    if(head==NULL){
    head=newnode;
    temp=head;
    newnode->next=NULL; }
    else{
        temp->next=newnode;
        temp=newnode;
        temp->next=NULL;}

        newnode=NULL;
        newnode=(NODE *)malloc(sizeof(NODE));}}
        fclose(fp);

}
int search(){
    system("cls");
    printf("\n\t************************************SEARCH************************************");
    char gh[20];
    int ch,i,j=0;
    while(1){
printf("\n\n\t\t\t..............ENTER_THE_MODE...............");
printf("\n\n\t\t1:Search_by_ID");
printf("\n\t\t2:Search_by_name");
printf("\n\t\t3:Search_by_height");
printf("\n\t\t4:Search_by_inspector-in-charge");
printf("\n\n\t\tEnter your choice....");
scanf("%d",&ch);
 switch(ch)
  {
   case 1:{system("cls");
     printf("\n\t************************************SEARCH************************************");
     printf("\n\t\tEnter_ID:");
     node();
     temp=head;
     scanf("%d",&i);
     while(temp!=NULL){
        if(temp->id==i){
            printf("\n\n\t\tID: %d\t\tNAME: %s\n\n\t\tAGE:%d\t\tSEX:%s\t\tHEIGHT:%s\n\n\t\tCRIME: %s\tINSPECTOR_INCHARGE: %s"
                   ,temp->id,temp->name,temp->age,temp->sex,temp->height,temp->crime,temp->insp);
            j++;
            temp=temp->next;
            }
        else
        {
            temp=temp->next;}}
    if(j==0){printf("\n\n\t\tNot found");}
      break;}

   case 2:{system("cls");
   printf("\n\t************************************SEARCH************************************");
   printf("\n\t\tEnter_name:");
   scanf("%s",gh);
   node();
   temp=head;
   while(temp!=NULL){
        if(strcmp(temp->name,gh)==0){
          printf("\n\n\t\tID: %d\t\tNAME: %s\n\n\t\tAGE:%d\t\tSEX:%s\t\tHEIGHT:%s\n\n\t\tCRIME: %s\tINSPECTOR_INCHARGE: %s"
                   ,temp->id,temp->name,temp->age,temp->sex,temp->height,temp->crime,temp->insp);
            j++;
            temp=temp->next;
            }
        else
        {temp=temp->next;}}
            if(j==0){printf("\n\n\tNot found");}
    break;}
   case 3:{system("cls");
   printf("\n\t************************************SEARCH************************************");
     printf("\n\t\tEnter_height:");
     scanf("%s",gh);
     node();
     temp=head;
     while(temp!=NULL){
        if(strcmp(temp->height,gh)==0){
        printf("\n\n\t\tID: %d\t\tNAME: %s\n\n\t\tAGE:%d\t\tSEX:%s\t\tHEIGHT:%s\n\n\t\tCRIME: %s\tINSPECTOR_INCHARGE: %s"
                ,temp->id,temp->name,temp->age,temp->sex,temp->height,temp->crime,temp->insp);
            j++;
            temp=temp->next;
            }
        else
        {temp=temp->next;}}
    if(j==0){printf("\n\n\tNot found");}
    break;}
   case 4:{system("cls");
   printf("\n\t************************************SEARCH************************************");
     printf("\n\t\tEnter_inspector-in-charge:");
     scanf("%s",gh);
     node();
     temp=head;
     while(temp!=NULL){
        if(strcmp(temp->insp,gh)==0){
        printf("\n\n\t\tID: %d\t\tNAME: %s\n\n\t\tAGE:%d\t\tSEX:%s\t\tHEIGHT:%s\n\n\t\tCRIME: %s\tINSPECTOR_INCHARGE: %s"
                ,temp->id,temp->name,temp->age,temp->sex,temp->height,temp->crime,temp->insp);
            j++;
            temp=temp->next;
            }
        else
        {temp=temp->next;}}
    if(j==0){printf("\n\n\tNot found:");}
    break;}
}printf("\n\n\n\tclick any key to continue....");
getch();
break;
}}
int password(){
     char pasword[10],ch,a[10]="17102116";
int i;
printf("\n\t\tEnter password :");
    for(i=0;i<8;i++)
    {
        ch =getch();
        pasword[i]=ch;
        ch ='*';
        printf("%c",ch);
    }
    pasword[i]= '\0';
     if( strcmp(pasword,a)==0)
        return(1);
      printf("\n\t\tINVALID PASSWORD.....\n\n\t\tRe-");
     return(0);

}
int add(){
    system("cls");
    while(1){if(password()==1){

   struct criminal cri;
   char ch;
   fp=fopen("criminals.txt","ab");
   if(fp == NULL){
    printf("\n Can't open file or file doesn't exist.");}

    do{ system("cls");
        printf("\n\t********************************ADD_RECORD*******************************");
        printf("\n\t\tEnter id:");
        scanf("%d",&cri.id);
        printf("\n\t\tEnter name:");
        scanf("%s",&cri.name);
        printf("\n\t\tEnter age:");
        scanf("%d",&cri.age);
        printf("\n\t\tEnter sex(M/F/Others):");
        scanf("%s",&cri.sex);
        printf("\n\t\tEnter height(in_cm):");
        scanf("%s",&cri.height);
        printf("\n\t\tEnter identification marks:");
        scanf("%s",&cri.marks);
        printf("\n\t\tEnter crime:");
        scanf("%s",&cri.crime);
        printf("\n\t\tInspector incharge:");
        scanf("%s",&cri.insp);
        fwrite(&cri,sizeof(cri),1,fp);
        printf("\n\n\t\tDO you want to add another record(y/n):");
        fflush(stdin);
        scanf("%c",&ch);}
        while(ch =='y'||ch =='Y');
        printf("\n\n\t\tData written successfully.....");
        printf("\n\n\t\t click any key to continue....");
        getch();
        fclose(fp);
        break;}}
        }
int display(){
    system("cls");
    printf("\n\t****************************************DISPLAY***************************************");
      node();
      if(head==NULL){
        printf("\n\tNO_DATA_FOUND....");
      }
      else{
      printf("\n\n\t\tID\tNAME\tAGE\tSEX\tHEIGHT\tCRIME\tINSPECTOR INCHARGE\n");
      temp=head;
     while(temp!=NULL){
        printf("\n\t\t%d\t%s\t%d\t%s\t%s\t%s\t%s",temp->id,temp->name,temp->age,temp->sex,temp->height,temp->crime,temp->insp);
        temp=temp->next;}}
        printf("\n\n\n\t\tclick any key to continue....");
        getch();

}
int menu(){

    int choice;
while(1){
        system("cls");
    printf("\n\t********************************MENU********************************");
    printf("\n\n\t\t1: Display_Record.");
    printf("\n\t\t2: Search_Record.");
   // printf("\n\t\t3: List_Record.");
    printf("\n\t\t3: Add_Record(need password).");
    printf("\n\t\t4: Modify_Record(need password).");
    printf("\n\t\t5: Delete_Record(need password).");
    printf("\n\t\t6: exit.");
    printf("\n\n\n\t\tEnter your choice:");
    scanf("%d",&choice);
    switch(choice){
        case 1:printf("\n THE_RECORD_ARE : ");
         display();
         break;
        case 2:search();
        break;
        //case 3:list();
        //break;
        case 3:add();
        break;
        case 4:modify();
        break;
        case 5:delet();
        break;
        case 6:exit(0);}
}}
