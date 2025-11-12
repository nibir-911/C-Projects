#include <stdio.h>
#include <string.h>
#define ADMIN_PASS "cis25322"

typedef struct Computing_and_information_system { 
    
    char name[100];
    int roll;
    char department[100];
    float cgpa;
} cis;

cis student[100];
int count = 0;

// Function declarations
//void loaddata();
//void savedata();
void addstudent();
void viewstudent();
void searchbyname();
void searchbyroll();
void searchbydepartment();
void updatestudent();
void deletestudent();
void adminpanel();

int main() {
    //loaddata();
    char password[20];
    int choice, choice2;

    while (1) {  //1 -> infitie loop
        printf("\n|------ STUDENT MANAGEMENT SYSTEM ------|\n");
        printf("1. Admin Panel\n");
        printf("2. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                
                printf("Enter Password: ");
                scanf("%s", password);
                if (strcmp(password, ADMIN_PASS) == 0) {
                    adminpanel();
                } 
                else
                {
                    printf("\nWrong Password... Try Again\n");
                }
                break;

            case 2:
                printf("Exiting...\n");
                //savedata();
                return 0;

            default:
                printf("\nAccess Denied (Admin Only)\n");
                break;
        }
    }
    return 0;
}

/*void loaddata() {
    FILE *fp = fopen("student.txt", "r");
    if (fp == NULL) return;
    count=0;
    while (fscanf(fp, "%s %d %s %f", student[count].name, &student[count].roll,
                  student[count].department, &student[count].cgpa) != EOF)
        count++;
    fclose(fp);
}

void savedata() {
    FILE *fp = fopen("student.txt", "w");
    for (int i = 0; i < count; i++)
        fprintf(fp, "\nName: %s\n Roll: %d\n Department: %s\n CGPA: %.2f\n", student[i].name, student[i].roll,
                student[i].department, student[i].cgpa);
    fclose(fp);
}*/
void adminpanel()
{
    int choice2;
    while (1)
    {
    printf("\nWelcome To Admin Pannel. Choose an option:");
    printf("\n------------------------------------------\n");
    printf("1. Add Student\n");
    printf("2. View Students\n");
    printf("3. Search Student by Name\n");
    printf("4. Search Student by Roll\n");
    printf("5. Search Student by Department\n");
    printf("6. Update Student\n");
    printf("7. Delete Student\n");
    printf("8. Exit Admin Panel\n");
    printf("Enter choice: ");
    scanf("%d", &choice2);

                    switch (choice2) {
                        case 1: addstudent(); break;
                        case 2: viewstudent(); break;
                        case 3: searchbyname(); break;
                        case 4: searchbyroll(); break;
                        case 5: searchbydepartment(); break;
                        case 6: updatestudent(); break;
                        case 7: deletestudent(); break;
                        case 8: return;
                        default: printf("Wrong selection.... Try Again\n"); break;
                    }
}
    }
    
    
void addstudent() {
    printf("Enter Student Name: ");
    scanf(" %[^\n]", student[count].name);

    printf("Enter Student Roll: ");
    scanf("%d", &student[count].roll);

    printf("Enter Student Department: ");
    scanf(" %[^\n]", student[count].department);

    printf("Enter Student CGPA: ");
    scanf("%f", &student[count].cgpa);

    count++;
   // savedata();
    printf("Student Added Successfully\n");
}

void viewstudent() {
    if (count == 0) {
        printf("No records found.\n");
        return;
    }

    printf("\n|--- Student List ---|\n");
    for (int i = 0; i < count; i++) {
        printf("\nStudent No.%d\n", i + 1);
        printf("Name: %s\n", student[i].name);
        printf("Roll: %d\n", student[i].roll);
        printf("Department: %s\n", student[i].department);
        printf("CGPA: %.2f\n", student[i].cgpa);
    }
}


void searchbyname()
{ 
    if (count == 0) {
        printf("No records found.\n");
        return;
    }

    char search[100];
    int found = 0;

    printf("Enter Name: ");
    scanf(" %[^\n]", search); 
    
    for (int i = 0; i < count; i++) 
      {
       if (strcmp(student[i].name, search) == 0) 
        {
            printf("\nStudent Found!\n");
            printf("Name: %s\n", student[i].name);
            printf("Roll: %d\n", student[i].roll);
            printf("Department: %s\n", student[i].department);
            printf("CGPA: %.2f\n", student[i].cgpa);
            found = 1;
            break;
    }
    }

    if(!found) 
    {
        printf("Student Not Found!\n");
    }
}

void searchbyroll() 
{ 
    if (count==0)
        {
           printf("No records found.\n");
        }
        printf("Enter Roll: ");
        int search;
        scanf("%d", &search);
         int i;
       for ( i = 0; i < count; i++)
       {
           if (student[i].roll==search)
           {
            printf("\nStudent Found!\n");
            printf("Name: %s\n", student[i].name);
            printf("Roll: %d\n", student[i].roll);
            printf("Department: %s\n", student[i].department);
            printf("CGPA: %.2f\n", student[i].cgpa);
            
            break;
           }
           
       }
       if (student[i].roll!=search)
       {
           printf("Student Not Found!\n");
       }
        
    }

void searchbydepartment() 
{ 
   if (count == 0) {
        printf("No records found.\n");
        return;
    }

    char search[100];
    int found = 0;

    printf("Enter Department Name: ");
    scanf(" %[^\n]", search); 
    
    for (int i = 0; i < count; i++) 
    {
    if (strcmp(student[i].department, search) == 0) 
    {
            printf("\nStudent Found!\n");
            printf("Name: %s\n", student[i].name);
            printf("Roll: %d\n", student[i].roll);
            printf("Department: %s\n", student[i].department);
            printf("CGPA: %.2f\n", student[i].cgpa);
            found = 1;
            break;
    }
}
    if(!found) 
    {
        printf("Student Not Found!\n");
    }
}

void updatestudent() 
{ 
     if (count==0)
        {
           printf("No records found.\n");
        }
        printf("Enter Roll: ");
        int search;
        scanf("%d", &search);
         int i;
       for ( i = 0; i < count; i++)
       {
           if (student[i].roll==search)
           {  
    printf("Update Student Name: ");
    scanf(" %[^\n]", student[i].name);

    printf("Update Student Roll: ");
    scanf("%d", &student[i].roll);

    printf("Update Student Department: ");
    scanf(" %[^\n]", student[i].department);

    printf("Update Student CGPA: ");
    scanf("%f", &student[i].cgpa);
}

}
if (student[i].roll!=search)
{
    printf("Student Not Found");
}

}


void deletestudent() 
{ 
    if(count==0)
    {
        printf("No Records Found..!");
    } 

    int search;
    printf("Enter Student Roll No. To Delete: ");
    scanf("%d", &search);
    int i;

    for ( i = 0; i < count; i++)
    {
        if (student[i].roll==search)
        {
          for (int j = i; j < count-1; j++)
          {
            student[j]=student[j+1];
            printf("Student Deleted Successfully..!");
           count--;
           
          }
           
        }
    }
    return;
    if (student[i].roll!=search)
    {
        printf("Student Not Found..!");
    }
    
}
