#include<stdio.h>
#include<string.h>
#define ADMIN_PASS "12345"

typedef struct patient_management
{
    char name[100];
    int age;
    char gender[10];
    char address[100];
    char diseae[100];
    int phone;
    int date;
} pm ;

pm patients[100];
int countp=0;

void adminpanel();
void patient_info();
void doctor_info();
void appointment_info(); 
void billing_info(); 
void pharmacy_info();
void bed_info();            //

int main()
{
    int choice;
    char password[20];
    while (1)
    {
       printf("\n/======== Hospital Management System ========/\n");
       printf("1. Admin Panel\n");
       printf("2. Exit\n");
       printf("Enter Your Chooice: ");
       scanf("%d", &choice);
       switch (choice)
       {
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
                return 0;

       default:
        printf("\nAccess Denied (Admin Only)\n");
        break;
       }
    }
    return 0;
}


void adminpanel()
{   
    int choice2;
    while (1)
  {
    printf("\n||======== Welcome To Admin Panel ========||\n");
    printf("1. Patient Management\n");
    printf("2. Doctor Management\n");
    printf("3. Appointment Schedul\n");
    printf("4. Billing System\n");
    printf("5. Pharmacy Management\n");
    printf("6. Bed Management\n");
    printf("7. Exit\n");
    printf("Enter Your Choice: ");
    scanf("%d", &choice2);
    switch (choice2)
    {
    case 1: patient_info(); break;
    case 2: doctor_info(); break;
    case 3: appointment_info(); break;
    case 4: billing_info(); break;
    case 5: pharmacy_info(); break;
    case 6: bed_info(); break;
    case 7: return;
    default:
        printf("Wrong Input\n");
        break;
    }
  }
}

void patient_info()
{
void add_p();
void update_p();
void delete_p();
void search_p();
void view_p();
int choice;

while (1)
{   
    printf("\n===== Welcome To Patient Management System =====\n");
    printf("1. Add Patient\n");
    printf("2. Update Patient\n");
    printf("3. Delete Patient\n");
    printf("4. Search Patient\n");
    printf("5. View Patient\n");
    printf("6. Exit\n");
    printf("Enter Your Choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1: add_p();break;
    case 2: update_p();break;
    case 3: delete_p();break;
    case 4: search_p();break;
    case 5: view_p();break;
    case 6: return;
    
    default: printf("Wrong Input\n"); break;
    }
  }
}

void add_p()
{
  printf("Enter Patient Name: ");
  scanf(" %[^\n]", patients[countp].name);
  printf("Enter Patient Age: ");
  scanf("%d", &patients[countp].age);
  printf("Enter Patient Gender: ");
  scanf(" %[^\n]", patients[countp].gender);
  printf("Enter Patient Address: ");
  scanf(" %[^\n]", patients[countp].address);
  printf("Enter Patient Diseae: ");
  scanf(" %[^\n]", patients[countp].diseae);
  printf("Enter Patient Phone: ");
  scanf("%d", &patients[countp].phone);
  printf("Enter Admission Date: ");
  scanf("%d/%d/%d", &patients[countp].date, &patients[countp+1].date, &patients[countp+2].date);

  countp++;
  printf("Patient Admitted Successfully...!\n");
}

void view_p()
{
  if (countp==0)
  {
    printf("No Patients Found..!\n");
    return;
  }
  printf("\n=======Patients Information=======\n");
  for (int i = 0; i < countp; i++)
  {
    printf("Patient No. %d\n", i+1);
    printf("Name: %s\n", patients[i].name);
    printf("Age: %d\n", patients[i].age);
    printf("Gender: %s\n", patients[i].gender);
    printf("Diseae: %s\n", patients[i].diseae);
    printf("Address: %s\n", patients[i].address);
    printf("Phone: %d\n", patients[i].phone);
    printf("Admission Date: %d/%d/%d\n", patients[i].date,patients[i+1].date,patients[i+2].date);
  }
  
}
void update_p()
{    int phn;
     printf("Enter Patient Phonr Number: ");
     scanf("%d", &phn);
     int i;
    for ( i = 0; i < countp; i++)
    {
        if (phn==patients[i].phone)
        {
  printf("Update Patient Name: ");
  scanf(" %[^\n]", patients[i].name);

  printf("Update Patient Age: ");
  scanf("%d", &patients[i].age);

  printf("Update Patient Gender: ");
  scanf(" %[^\n]", patients[i].gender);

  printf("Update Patient Address: ");
  scanf(" %[^\n]", patients[i].address);

  printf("Update Patient Diseae: ");
  scanf(" %[^\n]", patients[i].diseae);

  printf("Update Patient Phone: ");
  scanf("%d", &patients[i].phone);

  printf("Update Admission Date: ");
  scanf("%d/%d/%d", &patients[i].date, &patients[i+1].date, &patients[i+2].date);
break;
        } 
    } 
   if (phn!=patients[i].phone)
   {
      printf("No Patients Found..!");
   } 
}
void delete_p()
{
   if(countp==0)
    {
        printf("No Records Found..!"); return;
    } 

    int search;
    printf("Enter Patient Phone Number: ");
    scanf("%d", &search);
    int i;

    for ( i = 0; i < countp; i++)
    {
        if (patients[i].phone==search)
        {
          for (int j = i; j < countp-1; j++)
          {
            patients[j]=patients[j+1];
           
          }
           countp--;
           printf("Patient  Deleted Successfully..!");
           break;
        }
    }
    if (patients[i].phone!=search)
    {
        printf("Patient Not Found..!");
    }
    
}
void search_p()
{
    if (countp==0)
    {
        printf("No Patients Found..!\n");
        return;
    }
 int search;
 printf("Enter Patient Phone Number: ");
 scanf("%d", &search);
 int i;
 for ( i = 0; i < countp; i++)
 {
    if (search==patients[i].phone)
    {
    
    printf("Patient No. %d\n", i+1);
    printf("Name: %s\n", patients[i].name);
    printf("Age: %d\n", patients[i].age);
    printf("Gender: %s\n", patients[i].gender);
    printf("Diseae: %s\n", patients[i].diseae);
    printf("Address: %s\n", patients[i].address);
    printf("Phone: %d\n", patients[i].phone);
    printf("Admission Date: %d/%d/%d\n", patients[i].date,patients[i+1].date,patients[i+2].date);
    break;
   }
 }
 if (search=!patients[i].phone)
 {
    printf("Patient Not Found..!");
 }
 
}


void doctor_info(){}
void appointment_info(){}
void billing_info() {}
void pharmacy_info(){}
void bed_info(){}
