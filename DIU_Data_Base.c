#include<stdio.h>
#include<string.h>

 struct student { //Student Structure Decleration//
   char Name[200];
   int Id;
   char Department[300];
   int Sassion;
 };
 struct Teacher {         // Teacher Structure Decleration//
    char Name[200];
    int Id;
    char Department[300];
   char Position[100];
 };
 struct staff { // Staff Structure Decleration//
    char Name[200];
    int Id;
    char Department[300];
    char Address[100];
 };
 //arry of structure for all the elements//
 struct student students[100];    //
 struct Teacher teachers[100];
 struct staff staffs[100];
 int studentcount=0,teachercount=0,staffcount=0;

 void addstudent()  //function for take input//
 {
    printf("Enter Student Name:");
    scanf(" %[^\n]", students[studentcount].Name);
    printf("Enter Student ID:");
    scanf("%d", &students[studentcount].Id);
    printf("Enter Student Department:");
    scanf(" %s", students[studentcount].Department);
    printf("Enter Student Sassion:");
    scanf(" %d", &students[studentcount].Sassion);
    studentcount++;
   
 }
void addteacher() { // function for take input//
   printf("Enter Teacher Name:");
   scanf("%s", teachers[teachercount].Name);
   printf("Enter Teacher ID:");
   scanf("%d", &teachers[teachercount].Id);
   printf("Teacher Department:");
   scanf("%s", teachers[teachercount].Department);
   printf("Enter Teacher Position:");
   scanf("%s", teachers[teachercount].Position);
   teachercount++;
}
void addstaff() { // function for take input//
   printf("Enter Staff Name:");
   scanf("%s",staffs[staffcount].Name);
   printf("Enter Staff ID:");
   scanf("%d", &staffs[staffcount].Id);
   printf("Enter Staff Department:");
   scanf("%s", staffs[staffcount].Department);
   printf("Enter Staff Address:");
   scanf("%s",staffs[staffcount].Address);
   staffcount++;
}
void showstudents()   //funtion for print output//
{
   printf("\n----Student List----\n" );
   for (int i = 0; i < studentcount; i++)
   {
      printf("Student Name:%s\n",students[i].Name);
      printf("Student ID: %d \n", students[i].Id);
      printf("Student Department:%s\n", students[i].Department);
      printf("Student Sassion: %d \n", students[i].Sassion);
   }
}
void showteachers() // funtion for print output// 
{
   printf("\n----Teacher List----\n");
   for (int i = 0; i < teachercount; i++) {
      printf("Teacher Name:%s\n Teacher ID: %d \n Teacher Department:%s\n Teacher Position:%s",
             teachers[i].Name, teachers[i].Id, teachers[i].Department ,
             teachers[i].Position);
   }
}
void showstaffs() // funtion for print output//
{
   printf("\n----Staff List----\n");
    for (int i = 0; i < staffcount; i++)
   {
          printf("Staff Name:%s\n Staff ID:%d\n Staff Department:%s\n Staff Address:%s",
                 staffs[i].Name, staffs[i].Id, staffs[i].Department, staffs[i].Address);
   }
}
int main()
{
   int choice;
   while (1)  // 1-> true-> infinite loop
   {
      printf("\n---DIU Data Base---\n");
      printf("1.Add Student\n");
      printf("2.Add Teacher\n");
      printf("3.Add Staff\n");
      printf("4.Show Student\n");   //Options Showcase or menu//
      printf("5.Show Teacher\n");
      printf("6.Show Staff\n");
      printf("7.Exit \n");
      printf("Enter Your Choise:");
      scanf("%d",&choice);
   
   switch (choice)
   {
   case 1:
      addstudent();
      break;
   case 2:
      addteacher();
      break;
   case 3:
      addstaff();
      break;
   case 4:
      showstudents();    //switch for choice and call the function//
      break;
   case 5:
      showteachers();
      break;
   case 6:
      showstaffs();
      break;
   case 7:
      return 0;
   default: printf("No Data");
   }
}
}