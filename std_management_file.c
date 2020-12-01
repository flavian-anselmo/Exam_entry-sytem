#include<stdio.h>
#define N 16
#define G 5

int register_std();//students registration
int get_mark();//get_the marlks
int get_list();//get the list of students
int get_higest_low_score();//get position of student
typedef struct student{//the structure of a student
    char name[10];//get-the name of students
    int cat_mark;//cat mark
    int main_mark;//mainexam mark
    int total;//get the total
    int avg;//get the average
}std;
std arr_student[N];//the array of structure
int register_std(int j,int num){
    //student registration in the class
    int k;
    FILE *fp;//the pointer to the file structure
    //the names are stored in a file.txt
    fp=fopen("students_database.txt","a");
    //open the database in append mode
    printf("/////////////Register_student////////////\n");
    printf("Enter the number of students to register:");
    scanf("%d",&num);
    for(j=0;j<num;j++){
        printf("Enter students name:");
        scanf("%s",arr_student[j].name);
        //append student names in the system
        fprintf(fp,"%s\n",arr_student[j].name);
    }
    printf("only %d students registered successfully.../--\n",num);
    //close the databse
    fclose(fp);
}//end of registration
int get_list(){
    //get the list of students
    printf("Entered the get_list function to fetch list:\n");
    int id=1;
    char list[100];
    FILE *FP;
    FP=fopen("students_database.txt","r");
    //open the file in read mode
    printf("STD_ID\tSTD_NAME\n");
    while(!feof(FP)){
        //while not end of file display student
        fscanf(FP,"%s",list);
        //read the file with fscanf
        id++;
        printf("%d\t%s\n",id,list);
    }
    //close the database
    fclose(FP);
}//end of list of students

int get_mark(int j,int num){
    //get the marks for each student
    //get the mark for the cat and main exam
    FILE *PF;//FILE pointer to the structure
    PF=fopen("students_database.txt","r");
    printf("Enterd the get_mark function\n");
    num=0;//get the list length
    int p=1;
    char mark_list[100];
    printf("STD_ID\tSTD_NAME\n");
    while(!feof(PF)){
        //getting the nuumber of lines in the students_database.txt file
        fscanf(PF,"%s",mark_list);
        printf("%d\t%s\n",p++,mark_list);
        num++;
    }
    fclose(PF);
    //gey the marks of cat and main exam
    FILE *PL;
    PL=fopen("exam_mark.txt","a");
    printf("[+]Get the mark of each student:\n");
    //the number of students in the system is p-1
    for(j=0;j<(p-2);j++){
        printf("[+]enter mark of student with STD_ID %d\n",j+1);
        printf("Enter CAT mark:");
        scanf("%d",&arr_student[j].cat_mark);//get cat mark
        printf("Enter the main_mark:");
        scanf("%d",&arr_student[j].main_mark);//get main mark
        fprintf(PL,"%d\t%d\n",arr_student[j].cat_mark,
                            arr_student[j].main_mark);
        //write marks to the exam.txt database
    }
    printf("[+]Exam marks are written successfully.../--!\n");
    //CLOSE THE EXAM_DATABASE
    fclose(PL);
    //Open file for getting average of students
    FILE *NL;//pointer for student_database.txt file
    NL=fopen("students_database.txt","r");
    //both files are opened in read mode
    printf("STD_ID\tSTD_NAME\tCAT_MARK\tMAIN_MARK\tTOTAL\t\tAVERAGE\t\tGRADE\n");
    j=0;
    while(!feof(NL)&&j<(p-2)){
        fscanf(NL,"%s",mark_list);
        //get the total of the cats
        arr_student[j].total=((arr_student[j].cat_mark)+(arr_student[j].main_mark));
        //get the average of the of the total
        arr_student[j].avg=((arr_student[j].total)/(2));
        //get the list of perfomance
        //get the position of students

         //-GET THE GRADES OF STUDENTS
        //array of structure of grades to be assigned to students
                    //[A   B   C   D    F]
                    //[0   1   2   3   4 ]
        //array that stores the grades
        char arr_grade[G]={'A','B','C','D','F'};
        char std_grade[p-2];//array to store the grade of student
        if (arr_student[j].avg>=70){
            std_grade[j]=arr_grade[0];//A
        }
        else if (arr_student[j].avg>=60 && arr_student[j].avg<=69){
            std_grade[j]=arr_grade[1];//B
        }
        else if (arr_student[j].avg>=50 && arr_student[j].avg<=59){
            std_grade[j]=arr_grade[2];//C
        }
        else if (arr_student[j].avg>=40 && arr_student[j].avg<=49){
            std_grade[j]=arr_grade[3];//D
        }else{
            std_grade[j]=arr_grade[4];//F
        }
        //end of checking grades

        printf("%d\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%c\n",j,
                                mark_list,//name of student
                                arr_student[j].cat_mark,//the cat mark
                                arr_student[j].main_mark,//main exam mark
                                arr_student[j].total,//the total of cat and main
                                arr_student[j].avg,//the average
                                std_grade[j]);//the grade
        j++;
    }
    fclose(NL);//CLOSE THE EXAM FILE
}
int get_higest_low_score(int num,int j){
    FILE *KL;//FILE pointer to the structure
    KL=fopen("students_database.txt","r");
    num=0;//get the list length
    int p=1;
    char mark_list[100];
    while(!feof(KL)){
        //getting the nuumber of lines in the students_database.txt file
        fscanf(KL,"%s",mark_list);
        num++;
        p++;
    }
    fclose(KL);//close the student file
    //sort the array to get the largest and smallest
    //iam using bubble sort algorithm
    int TEMP;//the temporary variable
    for(j=0;j<(p-2);j++){
       for(num=0;num<(p-2);num++){
           if(arr_student[j].avg < arr_student[num].avg){
               //make the swap
               TEMP=arr_student[j].avg;
               arr_student[j].avg=arr_student[num].avg;
               arr_student[num].avg=TEMP;
               /*if the sort is in ascending order the first
               value is the lowest score and the last score is the
               highest score*/
           }
       }
    }
    printf(" The number of students in the system is..../-- :%d\n",(p-2));
    printf("***The highest student got:../--%d\n",arr_student[((p-2)-1)].avg);
    printf("***The lowest student got:../---%d\n",arr_student[0].avg);
}//end of get mark function
int main(){
    int j;//the loop variable
    int num;
    char entry[10];//enter registration function
    char entry_one[10];//enter get_list function;
    char mark_std[10];//enter get_mark functioon
    char performance[10];//get students perfomance
     //structure of the login to truck the array of names and passwords
             //[ 0   1   2   3   4   4]
    char key[]={'r','g','m','v','z','s'};//entry keys
    printf("Enter letter(r) to register_student:");
    gets(entry);
    printf("\n");
    if (entry[0]==key[0]){
        //only call the function if user input is (r)
        register_std(j,num);
    }else{
        printf("oops No registration!\n");
    }
    printf("Enter letter (g) to view the LIST of students:");
    scanf("%s",entry_one);
    printf("\n");
    if(entry_one[0]==key[1]){
        //only call the function if user input is (g)
        get_list();
    }else{
        printf("oops no list generated");
    }

    printf("Enter letter (m) to enter mark for each student:");
    scanf("%s",mark_std);
    if(mark_std[0]==key[2]){
        //only call the function if the user inputs (m)ca
        get_mark(j,num);

    }else{
        printf("oops no marks generated");
    }
    get_higest_low_score(num,j);
}//the end of main function
