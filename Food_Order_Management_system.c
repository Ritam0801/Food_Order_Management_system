#include<stdio.h>
#include <string.h>

struct employee
{
    int id;
    char fname[10];
    char lname[10];
    int dob;
}employee;



void admin(void);
void user(void);
void main_menu(void);
void order_food(void);
void veg(void);
void nonveg(void);

void employee_record(void);

int main()
{
    system("clear");
    int choice;
    printf(" ----------------------------------------------------------------------------\n");
    printf("                              WELCOME TO OUR KITCHEN                               \n ");
    printf(" ----------------------------------------------------------------------------\n\n\n\n");
    printf("1. login as Admin \n2. login as user\n\n\n\n");
    scanf("%d",&choice);
    if (choice == 1)
    {
        admin();
    }
    else if(choice == 2)
    {
        user();
    }
    else
    {
        printf("invalid choice...!!!!!\n");
    }

    return 0;
}

void admin()
{
    system("clear");
    int choice ,p_choice;
    char password[100];
    const char main[100] = "Ritam123";
   // printf("welcome sir\n");
    printf("please enter your admin password to login: \n");
    scanf("%s", &password);

    if (strcmp(password, main) != 0)  // strcmp is to compare the two passwords
    {
        //printf("Sorry that didn't work..!!!!!!\n");
        printf("Entered password is wrong!!! Do you want to continue? \n\n");
        printf("\n1. yes\n2. no\n\n\n");
        scanf("%d",&p_choice);
        if(p_choice == 1)
        {
            admin();
        }
        else
        {
            printf("Good bye\n");
            exit(0);
        }
       // admin();
        return 0;
    }
    else
    {
        printf("\n");
        printf("login successful !!!\n\n");
        printf("Enter your activity\n");
        printf("1. View emplotyee list\n\n2. See project perticipants... \n\n");

        scanf("%d", &choice);
        if (choice == 1)
        {
            employee_record();
        }
        else if(choice == 2)
        {
            printf("perticipant 1. Ritam Adhya(I.T 2)\nperticipant 2. Sulogna Paul(I.T 1)");
        }
    }
    return 0;

}

void user()
{
     system("clear");
    int choice,e;
    printf("*************************Welcome to User Section************************** \n\n\n\n");
    printf("please let us know your choice :\n ");
    printf("1. View our menu \n\n 2. order food \n\n 3. exit.. ");
    scanf("%d", &choice);
    if(choice == 1)
    {
        main_menu();
    }

   /* else if(choice == 2)
    {
        order_food();
    } */

    else if(choice ==3)
    {
        printf("Do you really exit?\n press 1 for yes and 2 for no. \n\n");
        scanf("%d",&e);
        if (e== 1)
        {
            printf("Have a great day\n");
            main();
        }
        else
            user();
    }
}

void main_menu()
{
    system("clear");
    int choice;
    printf("enter the order as per your preferences:\n");
    printf("1. veg\n\n2. Non veg\n\n");
    scanf("%d",&choice);
    if (choice == 1)
    {
        veg();
    }
    else if (choice == 2)
    {
        nonveg();
    }
}

void veg()
{
    system("clear");
    FILE *ptr = NULL;
    char string[1000];
    printf("Welcome to food menu:\n");
    ptr = fopen("vegmenu.txt","r+");
   // fscanf(ptr,"%s",string);
    //printf("the menu is presented by:%s",string);
   // cin.getline();
    //system("pause");

     while(fgets(string,1001,ptr))
    {
        puts(string);
    }

    fclose(ptr);

   //order_food();

}

void nonveg()
{
    system("clear");
    FILE *ptr = NULL;
    char string[1000];
    printf("Welcome to food menu:\n");
    ptr = fopen("nonvegmenu.txt","r");

   // printf("the menu is presented by:\n\n");

    while(fgets(string,1001,ptr))
    {
        puts(string);
    }


    fclose(ptr);
   // cin.getline();
   // system("pause");

  // printf("welcome to veg menu");
   // order_food();

}

void employee_record()
{
    system("clear");
    int choice;
    printf("Enter your choice\n\n");
    printf("1. view existing record\n\n2. add new record\n\n3. search record\n\n4. delete existing record\n");
    scanf("%d",&choice);
    if (choice == 2)
    {
        add_record();
    }
    else if(choice == 1)
    {
        view_record();
    }
    else if(choice == 3)
    {
        search_record();
    }
    /*else if(choice == 4)
    {
        delete_record();
    }*/
    else
    {
        printf("please enter a valid choice\n");
        employee_record();
    }

}

void add_record()
{

    system("clear");
    int choice, t;
    FILE *emp;
    emp = fopen("employee.txt","ab");
    if(emp == NULL)
    {
        printf("Error opening file!!\n\n");
        exit(1);
    }
    else
    {
       // system("clear");
        printf("Enter employee id \n");
        scanf("%d", &t); // t is for storing the id temporarily

        emp = fopen("employee.txt","rb");
        while(fread(&employee, sizeof(employee), 1, emp) == 1)
        {
            if(employee.id == t)
            {
                printf("\n\nEmployee already existed!! \nTry another one \n\n");
                //system("clear");
                add_record();

            }
        }
        employee.id = t;
        printf("Enter first name\n");

        scanf("%s",employee.fname);
       //gets(employee.fname);
       //getchar();

       fflush(stdin);
        printf("Enter last name\n");
        scanf("%s",employee.lname);
        //gets(employee.lname);
        fflush(stdin);
        //getchar();
        printf("Enter Date of Birth in DD/MM/YYYY format\n");
        scanf("%lld",&employee.dob);
        getchar();
        fwrite(&employee, sizeof(struct employee),1,emp);
        printf("Data entered successfully...\n\n");

        /*emp = fopen("employee.txt","rb");
        fread(&employee, sizeof(struct employee),1,emp);
        printf("Employee id is %d\n",employee.id);
        printf("Employee name is %c %c\n",employee.fname,employee.lname );
        printf("Employee DOB is %d\n",employee.dob);
        */

        printf("Do you enter more details? press 1 for yes and 2 for no\n\n");
        scanf("%d",&choice);
        if(choice == 1)
        {
            add_record();
        }
        else if(choice == 2)
        {
            printf(" your enterded details are \n\n");
            fread(&employee,sizeof(employee),1,emp);

            printf("\n employee ID  %d\n\n",employee.id);
            printf("\n employee Name  %s s%s\n\n",employee.fname ,employee.lname);
            printf("\n employee DOB is %d\n",employee.dob);


        }

        fclose(emp);
    }
  }


void view_record()
{
    char c;
    system("clear");
    FILE *ptr;
    printf("employee details are\n");
    printf(" id    fname    lname    DOB\n\n");
    ptr = fopen("employee.txt","r");

    while(fread(&employee, sizeof(employee),1,ptr) == 1) // this while loop will continue until the last employee detail is displayed
          {
                printf(" %d    ",employee.id);
                printf(" %s    ",employee.fname);
                printf(" %s    ",employee.lname);
                printf(" %d    ",employee.dob);
                printf("\n");
          }

     printf("\n\nWant to go back to admin section again? Y?/N \n\n");
     getchar();
     scanf("%c",&c);
     if(c == 'y')
        admin();

     else
        exit(0);

     fclose(ptr);
     return 0;
}

void search_record()
{
    system("clear");
    FILE *emp;
    int choice,x,q; // x for storing the id number to be searched
    char y;
    printf(" Welcome to our employee searching section \n");
    printf(" Enter your preferences :\n");
    printf("1. search employee by their respective id \n");
    printf("2. search employee by their respective first name \n");
    scanf("%d",&q);
    if(q == 1)
    {
        system("clear");
         //emp = fopen("employee.txt","rb");
        // printf("1. search by id\n");
        // scanf("%d",&choice);
        // emp = fopen("employee.txt","rb");
     printf("enter id\n");
     scanf("%d",&x);
     emp = fopen("employee.txt","rb");
    while(fread(&employee,sizeof(employee),1,emp)==1)
    {
        if (employee.id == x)
     {
         printf("record found...\n");
         printf("employee id is %d\n",employee.id);
          printf("employee name is %s %s\n",employee.fname, employee.lname);

        printf("employee DOB is %d\n",employee.dob);
        break;

     }
    /* else
     {
        printf("no such record found!!!\n");
     }*/
    }
    if(employee.id != x)
    {
        printf("No such record found!!\n");
    }

   printf("continue searching? y/n\n");
   getchar();
    scanf("%c",&y);
    if(y == 'y')
    {
        search_record();
    }
    else
    {
        return 0;
    }


    fclose(emp);
    }
    else if(q == 2)
    {
        system("clear");
    char c[10];
    FILE *emp;
    printf("enter first name:\n");
    scanf("%s",&c);
    emp = fopen("employee.txt","rb");
    while(fread(&employee,sizeof(employee),1,emp) == 1)
    {
        if(strcmp(c,employee.fname) == 0)
        {
            printf("record found\n");
            printf("employee id is %d\n",employee.id);
            printf("employee name is %s %s\n",employee.fname, employee.lname);
            printf("employee DOB is %d\n",employee.dob);
            break;

        }

    }
    if(strcmp(c,employee.fname) != 0)
    {
        printf("no record found\n");
    }

    char y;
    printf("continue searching? y/n\n");
   getchar();
    scanf("%c",&y);
    if(y == 'y')
    {
        main();
    }
    else
    {
        return 0;
    }

    fclose(emp);
    return 0;

    }
}

