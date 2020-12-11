/* This is a simple log in system that allows users to 
register username and passwords and from that they can log in with
there credentials */
#include<stdio.h>
#include<string.h>
#define S 20
//include stdio and stdin
//function prototypes
extern void registration_pssw();//password and user name registration
extern void log_in();//login into the sytem
typedef union login_sys
{//use union to save on memeory
    char user_name[10];
    char password[10];
}log;
log reg_pswd;
log reg_user;
 //structure of the login to truck the array of names and passwords
 
void  registration_pssw(char keyboard[]){
     //registration of password
    //open a data base to store the passwords
    //         [ 0   1   2]
    ////
    FILE *fpointer;//our file pointer
    fpointer = fopen("login_database.txt","a+");
    //open file in append mode
    //registration of password
    //open a data base to store the passwords
    printf("////////REGISTER YOUR USRE_NAME AND PASSWORD////////////\n");
    //get the user name and store in the file 
    printf("Enter user_name:");
    scanf("%s",reg_user.user_name);
    fprintf(fpointer,"%s\n",reg_user.user_name);
    //get the password and store in the file 
    printf("Enter your password:");
    scanf("%s",reg_pswd.password);
    fprintf(fpointer,"%s\n",reg_pswd.password);
    fclose(fpointer);
    //call the login function to login to the system
    log_in(keyboard);
}//the end of registration functiion

void log_in(char keyboard[]){
    FILE *fpointer_2;
    fpointer_2=fopen("login_database.txt","r");
    char wordlist[100];/*this array will store the username and password from the file 
                        from where we can access the items*/
    //open file read mode
    printf("////////////ENTER PASSWORD AND USER_NAME TO LOGIN///////////\n");
    char user_name_entry[10];
    char pswd_entry[10];
    //log in to the system
    //user_name
    printf("Enter your user_name:");
    scanf("%s",user_name_entry);
    //user passsword
    printf("Entry your password:");
    scanf("%s",pswd_entry);
    int j=0;
    while (!feof(fpointer_2)){
        fscanf(fpointer_2,"%s",&wordlist[j]);
        strcpy(reg_pswd.password,wordlist);
        if (strcmp(reg_pswd.password,user_name_entry)==0){
            //compare the user name and password in the file  with that of user entry
            printf("//////WELCOME TO THE EXAM ENTRY SYSTEM///////////\n");
            break;
        }
        else{
            printf(".");
        }
    }
    fclose(fpointer_2);//close the the file opened 
}//end of login function
