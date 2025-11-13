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
void loaddata();
void savedata();
void addstudent();
void viewstudent();
void searchbyname();
void searchbyroll();
void searchbydepartment();
void updatestudent();
void deletestudent();
void adminpanel();
void sortbyroll_asc();
void sortbyroll_des();
void sortbycgpa_asc();
void sortbycgpa_desc();
void sortbyname_asc();
void sortbyname_desc();

int main() {
    loaddata();
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
                savedata();
                return 0;

            default:
                printf("\nAccess Denied (Admin Only)\n");
                break;
        }
    }
    return 0;
}


void loaddata()
{
    FILE *fp = fopen("student.txt", "r"); 
    if (fp != NULL)
    {
        count = 0;
        while (fscanf(fp,"Name :%s\nRoll :%d\nDepartment :%s\nCGPA :%f\n", student[count].name,&student[count].roll,
            student[count].department,&student[count].cgpa) == 4)
    {
            count++;
            }
        printf("\n");
        fclose(fp);
        printf("%d students loaded from File\n", count);   
        }
    else
    {
        printf("No Record in File\n");
        
    }
}


void savedata()
{
    FILE *fp = fopen("student.txt", "w");
    if (fp != NULL)
    {
        for (int i = 0; i < count; i++)
        {
            fprintf(fp,"Name :%s\nRoll :%d\nDepartment :%s\nCGPA :%.2f\n", student[i].name, student[i].roll,
            student[i].department, student[i].cgpa);
        }
        printf("\n");
        fclose(fp);
        printf("%d students data saved to File\n", count);
    }
    else
    {
        printf("Unable to save data.\n");
    }
}

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
    printf("8. Sort by Roll(Ascending)\n");
    printf("9. Sort by Roll(Descending)\n");
    printf("10. Sort by Cgpa(Ascending)\n");
    printf("11. Sort by Cgpa(Descending)\n");
    printf("12. Sort by Name(Ascending)\n");
     printf("13. Sort by Name(Descending)\n");
    printf("14. Exit Admin Panel\n");
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
                        case 8: sortbyroll_asc(); break;
                        case 9: sortbyroll_des(); break;
                        case 10: sortbycgpa_asc(); break;
                        case 11: sortbycgpa_desc(); break;
                        case 12: sortbyname_asc(); break;
                        case 13: sortbyname_desc(); break;
                        case 14: return;
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
    savedata();
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
            
    }
    break;
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

void sortbyroll_asc()
{
    if(count==0)
    {
        printf("No Records Found..!");
    }
     for (int i = 0; i < count-1; i++)
     {
        for (int j = 0; j < count-i-1; j++)
        {
            if (student[j].roll>student[j+1].roll)
            {
                student[count+1]=student[j];
                student[j]=student[j+1];
                student[j+1]=student[count+1];
            }
            
        }
        
     }
     printf("\nSort by Roll (Ascending)\n");
     for (int j = 0; j < count; j++)
        {
            printf("Name: %s\n", student[j].name);
            printf("Roll: %d\n", student[j].roll);
            printf("Department: %s\n", student[j].department);
            printf("CGPA: %.2f\n", student[j].cgpa);
            printf("\n");
        }
     
}

void sortbyroll_des()
{
    if(count==0)
    {
        printf("No Records Found..!");
    }
     for (int i = 0; i < count-1; i++)
     {
        for (int j = 0; j < count-i-1; j++)
        {
            if (student[j].roll<student[j+1].roll)
            {
                student[count+1]=student[j];
                student[j]=student[j+1];
                student[j+1]=student[count+1];
            }
            
        }
        
     }
     printf("\nSort by Roll (Descending)\n");
     for (int j = 0; j < count; j++)
        {
            printf("Name: %s\n", student[j].name);
            printf("Roll: %d\n", student[j].roll);
            printf("Department: %s\n", student[j].department);
            printf("CGPA: %.2f\n", student[j].cgpa);
            printf("\n");
        }
     
}

void sortbycgpa_asc()
{
    if (count==0)
    {
       printf("No Record Found...!");
    }
    for (int i = 0; i < count-1; i++)
    {
        for (int j = 0; j < count-i-1; j++)
        {
            if (student[j].cgpa> student[j+1].cgpa)
            {
                student[count+1]=student[j];
                student[j]=student[j+1];
                student[j+1]=student[count+1];
            }
            
        }
        
    }
    printf("\nSort By CGPA (Ascending)\n");
    for (int j = 0; j < count; j++)
    {
            printf("Name: %s\n", student[j].name);
            printf("Roll: %d\n", student[j].roll);
            printf("Department: %s\n", student[j].department);
            printf("CGPA: %.2f\n", student[j].cgpa);
            printf("\n");
    }
    
}

void sortbycgpa_desc()
{
    if (count==0)
    {
       printf("No Record Found...!");
    }
    for (int i = 0; i < count-1; i++)
    {
        for (int j = 0; j < count-i-1; j++)
        {
            if (student[j].cgpa < student[j+1].cgpa)
            {
                student[count+1]=student[j];
                student[j]=student[j+1];
                student[j+1]=student[count+1];
            }
            
        }
        
    }
    printf("\nSort By CGPA (Descending)\n");
    for (int j = 0; j < count; j++)
    {
            printf("Name: %s\n", student[j].name);
            printf("Roll: %d\n", student[j].roll);
            printf("Department: %s\n", student[j].department);
            printf("CGPA: %.2f\n", student[j].cgpa);
            printf("\n");
    }
}


void sortbyname_asc()
{
    if (count==0)
    {
       printf("No Record Found...!");
    }
    for (int i = 0; i < count-1; i++)
    {
        for (int j = 0; j < count-i-1; j++)
        {
          if (strcmp(student[j].name, student[j + 1].name) > 0)
            {
                student[count+1]=student[j];
                student[j]=student[j+1];
                student[j+1]=student[count+1];
            }
            
        }
        
    }
    printf("\nSort By Name (Ascending)\n");
    for (int j = 0; j < count; j++)
    {
            printf("Name: %s\n", student[j].name);
            printf("Roll: %d\n", student[j].roll);
            printf("Department: %s\n", student[j].department);
            printf("CGPA: %.2f\n", student[j].cgpa);
            printf("\n");
    }
}
void sortbyname_desc()
{
    if (count==0)
    {
       printf("No Record Found...!");
    }
    for (int i = 0; i < count-1; i++)
    {
        for (int j = 0; j < count-i-1; j++)
        {
          if (strcmp(student[j].name, student[j + 1].name) < 0)
            {
                student[count+1]=student[j];
                student[j]=student[j+1];
                student[j+1]=student[count+1];
            }
            
        }
        
    }
    printf("\nSort By Name (Descending)\n");
    for (int j = 0; j < count; j++)
    {
            printf("Name: %s\n", student[j].name);
            printf("Roll: %d\n", student[j].roll);
            printf("Department: %s\n", student[j].department);
            printf("CGPA: %.2f\n", student[j].cgpa);
            printf("\n");
    }
}
