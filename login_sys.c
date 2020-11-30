#include<stdio.h>
#define S 20
//include stdio and stdin
//function prototypes
void registration_pssw();//password and user name registration
void log_in();//login into the sytem
typedef union login_sys
{//use union to save on memeory
    char user_name[10];
    char password[10];
}log;
log arr_login[S];
 //structure of the login to truck the array of names and passwords
void  registration_pssw(){
     //registration of password
    //open a data base to store the passwords
    //         [ 0   1   2]
    char key[]={'r','u','p'};//key_board keys
    char entry_reg[0];
    char entry_pas[0];
    char entry_user[1];
    FILE *fpointer;
    fpointer=fopen("login_database.txt","a+");//open the database
    printf("///////////////WELCOME TO EXAM ENTRY SYSTEM/////////////////\n");
    printf("/////////////Register_password////////////\n");
    printf("----*Press any key if you dont want to register a password*---\n");
    printf("Enter [r] to register a user_name:");
    scanf("%s",entry_reg);
    if (entry_reg[0]==key[0]){
        //enter the name
        printf("Press [u] to enter the user_name:");
        scanf("%s",entry_user);
        if (entry_user[1]==key[1]){
            printf("Enter the user_name:");
            scanf("%s",arr_login->user_name);
            fprintf(fpointer,"%s\n",arr_login->user_name);
        }    
        //enter the password
        printf("Press [p] to enter the password:");
        scanf("%s",entry_pas);
        if(entry_pas[0]==key[2]){
            printf("Enter your password:");
            scanf("%s",arr_login->password);
            fprintf(fpointer,"%s\n",arr_login->password);
        }  
        printf("//////Successfully registered../--\n");  

    }else{
        printf("!oops cant register");
    }
    

    fclose(fpointer);
    printf("end of registration\n");
}
void log_in(){
    char p[10];//entry password
    char u[10];//entry user_name
    char ch[100];
    int j=0;
    int h;
    //use the registerd credentials to view the system
    //open the database
    FILE *fpointer_2;
    //open the file in read mode
    fpointer_2=fopen("login_database.txt","r");
    printf("#############Enter your credentials to login#############\n");
    //enter the user name
    printf("Enter the user_name:");
    scanf("%s",p);  
    //enter the password
    printf("Enter the password:");
    scanf("%s",u);
    //readthrough the file and fetch the user name and password
    while(!feof(fpointer_2)){
        fscanf(fpointer_2,"%s",&ch[j]);
        j++;
        h=ch[j];
    }
    fclose(fpointer_2);
}
int main(void){
    registration_pssw();
    log_in();
}
