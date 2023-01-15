#include <stdio.h>

#include <stdlib.h>

#include <conio.h>

#include <string.h>

int registe();

int login();

void menu();

void addrecord();

void viewrecord();

void editrecord();

void deleterecord();

struct record

{
    char ID[20];

    char  SE[20];

    char name[30];

    char place[25];

    char duration[10];

    char note[500];

    char fname[100];

    char lname[20];

    char username[20];

    char password[20];
};

int main()

{

    int ch;

    printf("\n\n\t***********************************\n");

    printf("\t*PASSWORD PROTECTED DIARY*\n");

    printf("\t***********************************");

    while (1)

    {

        printf("\n\tRegistration Menu[1]");

        printf("\n\tLogin\t\t[2]");

        printf("\n\n\tENTER YOUR CHOICE:");

        scanf("%d", &ch);

        switch (ch)

        {

        case 1:
           
            registe();
           
            break;
        case 2:
           
            login();
           
            break;

        default:

            printf("\nYOU ENTERED WRONG CHOICE..");

            printf("\nPRESS ANY KEY TO TRY AGAIN");

            getch();

            break;
        }

        system("cls");
    }

    return 0;
}

void menu()
{   
    system("cls");

    int ch;

    printf("\n\n\t***********************************\n");

    printf("\t*PASSWORD PROTECTED PERSONAL DIARY*\n");

    printf("\t***********************************");

    while (1)

    {

        printf("\n\n\t\tMAIN MENU:");

        printf("\n\n\tADD RECORD\t[1]");

        printf("\n\tVIEW RECORD\t[2]");

        printf("\n\tEDIT RECORD\t[3]");

        printf("\n\tDELETE RECORD\t[4]");

        printf("\n\tEXIT\t\t[5]");

        printf("\n\n\tENTER YOUR CHOICE:");

        scanf("%d", &ch);

        switch (ch)

        {

        case 1:

            addrecord();

            break;

        case 2:

            viewrecord();

            break;

        case 3:

            editrecord();

            break;

        case 4:

            deleterecord();

            break;

        case 5:

            printf("\n\n\t\tTHANK YOU FOR USING THE SOFTWARE ");

            getch();

            exit(0);

        default:

            printf("\nYOU ENTERED WRONG CHOICE..");

            printf("\nPRESS ANY KEY TO TRY AGAIN");

            getch();

            break;
        }

        system("cls");
    }
}

int registe()
{
    FILE *log;
    char choice;
    log = fopen("login12.txt", "w");
    struct record l;
    printf("\t\t\t\t\t*******************************\n");
    printf("\t\t\t\t\t<---Welcome to Registration system--->\n");
    printf("\t\t\t\t\t*******************************\n");
    printf("\n\t\t\t\t\tEnter first name: ");
    scanf("%s", l.fname);
    printf("\t\t\t\t\tEnter last name: ");
    scanf("%s", l.lname);
    printf("\n\t\t\t\t\tEnter username: ");
    scanf("%s", l.username);
    printf("\n\t\t\t\t\tEnter password: ");
    scanf("%s", l.password);
    fwrite(&l, sizeof(l), 1, log);
    fclose(log);

    printf("\n\n Your User name is UserID\n");
    printf("Now login with UserID and password\n");
    printf("\nPress any key to continue.....");
    getch();
    system("CLS");
    login();
}

int login()
{
    system("cls");
    char username[200], password[20];
    FILE *log;
    log = fopen("login12.txt", "r");
    struct record l;
    printf("\t\t\t\t\t*******************************\n");
    printf("\t\t\t\t\t<---Welcome to login system--->\n");
    printf("\t\t\t\t\t*******************************\n");
    printf("\n\t\t\t\t\tEnter UserID: ");
    scanf("%s", &username);
    printf("\n\t\t\t\t\tEnter password: ");
    scanf("%s", &password);
    while (fread(&l, sizeof(l), 1, log))
    {
        if (strcmp(username, l.username) == 0 && strcmp(password, l.password) == 0)
        {
            printf("\n\t\t\t\t\t*******************************\n");
            printf("\t\t\t\t\t***<---Successfully login--->***\n");
            printf("\t\t\t\t\t*******************************\n");
            menu();
        }
        else
        {
            printf("\n\n\t\tPlease enter correct UserID and password");
            printf("\n\n\t\t<---PRESS ANY KEY TO TRY AGAIN--->\n\n");

            getch();
            login();
        }
    }
    fclose(log);
}

void addrecord()

{

    system("cls");

    FILE *fp;

    char another = 'Y', ID[20],SE[20];
      
    struct record e;

    char filename[15];

    int choice;

    printf("\n\n\t\t***************************\n");

    printf("\t\t* WELCOME TO THE ADD MENU *");

    printf("\n\t\t***************************\n\n");

    printf("\n\n\tENTER DATE OF YOUR RECORD:[yyyy-mm-dd]:");

    fflush(stdin);

    gets(filename);

    fp = fopen(filename, "ab+");

    if (fp == NULL)

    {

        fp = fopen(filename, "wb+");

        if (fp == NULL)

        {

            printf("\nSYSTEM ERROR...");

            printf("\nPRESS ANY KEY TO EXIT");

            getch();

            return;
        }
    }

    while (another == 'Y' || another == 'y')

    {

        choice = 0;

        fflush(stdin);
        printf("\n\tENTER YOUR RECORD SERIAL NO : ");
        scanf("%s", SE);
        
        printf("\n\tENTER YOUR STUDENT ID : ");

        scanf("%s", ID);

        rewind(fp);


        while (fread(&e, sizeof(e), 1, fp) == 1)

        {

            if (strcmp(e.SE, SE) == 0)

            {

                printf("\n\tTHE RECORD ALREADY EXISTS.\n");

                choice = 1;
            }
        }

        if (choice == 0)

        {

            strcpy(e.SE, SE);

            strcpy(e.ID, ID);

            printf("\tENTER NAME:");

            fflush(stdin);

            gets(e.name);

            printf("\tENTER DURATION:");

            gets(e.duration);

            fflush(stdin);

            printf("\tNOTE:");

            gets(e.note);

            fwrite(&e, sizeof(e), 1, fp);
                    
            printf("\nYOUR RECORD IS ADDED...\n");
        }

        printf("\n\tADD ANOTHER RECORD...(Y/N) ");

        fflush(stdin);

        another = getchar();
    }

    fclose(fp);

    printf("\n\n\tPRESS ANY KEY TO EXIT...");

    getch();
}

void viewrecord()

{

    FILE *fpte;

    system("cls");

    struct record customer;

    char ID[20], SE[20],choice, filename[14];

    int ch;

    printf("\n\n\t\t*******************************\n");

    printf("\t\t* HERE IS THE VIEWING MENU *");

    printf("\n\t\t*******************************\n\n");

    if (choice != 0)

    {

        return;
    }

    do

    {

        printf("\n\t\tENTER THE DATE OF RECORD TO BE VIEWED:[yyyy-mm-dd]:");

        fflush(stdin);

        gets(filename);

        fpte = fopen(filename, "rb");

        if (fpte == NULL)

        {

            puts("\n\n\t\tTHE RECORD DOES NOT EXIST...\n");

            printf("\t\tPRESS ANY KEY TO EXIT...");

            getch();

            return;
        }

        system("cls");

        printf("\n\t\t\tHOW WOULD YOU LIKE TO VIEW:\n");

        printf("\n\t\t\t1.WHOLE RECORD OF THE DAY.");

        printf("\n\t\t\t2.RECORD OF FIX ID.");

        printf("\n\n\t\t\tENTER YOUR CHOICE:");

        scanf("%d", &ch);

        switch (ch)

        {

        case 1:
            system("cls");
            printf("\n\t\tTHE WHOLE RECORD FOR %s IS:", filename);

            while (fread(&customer, sizeof(customer), 1, fpte) == 1)

            {

                printf("\n");

                printf("\n\t\tSERIAL NO: %s", customer.SE);

                printf("\n\t\tSTUDENT ID: %s", customer.ID);

                printf("\n\t\tDURATION: %s", customer.duration);

                printf("\n\t\tNOTE: %s", customer.note);
                printf("\n\n\t\t---------------------------------------------------\n");


                printf("\n");
            }

            break;

        case 2:

            fflush(stdin);

            printf("\n\t\tENTER YOUR STUDENT ID : ");

            gets(ID);
            system("cls");

            while (fread(&customer, sizeof(customer), 1, fpte) == 1)

            {

                if ( strcmp(customer.ID, ID) == 0)

                {

                    printf("\n");

                    printf("\n\t\tYOUR RECORD IS:");

                    printf("\n\t\tSERIAL NO: %s", customer.SE);

                    printf("\n\t\tSTUDENT ID: %s", customer.ID);

                    printf("\n\t\tSTUDENT NAME: %s", customer.name);

                    printf("\n\t\tDUARATION: %s", customer.duration);

                    printf("\n\t\tNOTE: %s", customer.note);
                    printf("\n\n\t\t---------------------------------------------------\n");

                    printf("\n");
                }
            }

            break;

        default:
            printf("\n\t\tYOU TYPED SOMETHING ELSE...\n");

            break;
        }

        printf("\n\n\t\tWOULD YOU LIKE TO CONTINUE VIEWING...(Y/N):");

        fflush(stdin);

        scanf("%c", &choice);

    } while (choice == 'Y' || choice == 'y');

    fclose(fpte);

    return;
}

void editrecord()

{

    system("cls");

    FILE *fpte;

    struct record customer;

    char ID[20],SE[20] ,choice, filename[14];

    int num, count = 0;

    printf("\n\n\t\t*******************************\n");

    printf("\t\t* WELCOME TO THE EDITING MENU *");

    printf("\n\t\t*******************************\n\n");

    if (choice != 0)

    {

        return;
    }

    do

    {

        printf("\n\t\tENTER THE DATE OF RECORD TO BE EDITED:[yyyy-mm-dd]:");

        fflush(stdin);

        gets(filename);

        printf("\n\t\tENTER YOUR RECORD SERIAL NO  : ");

        gets(SE);

        fpte = fopen(filename, "rb+");

        if (fpte == NULL)

        {

            printf("\n\n\t\tRECORD DOES NOT EXISTS:");

            printf("\n\t\tPRESS ANY KEY TO GO BACK");

            getch();

            return;
        }

        while (fread(&customer, sizeof(customer), 1, fpte) == 1)

        {

            if (strcmp(customer.SE, SE) == 0)

            {

                printf("\n\n\t\tYOUR OLD RECORD WAS AS:");


                printf("\n\t\tRECORD SERIAL NO : %s", customer.SE);
                printf("\n\t\tSTUDENT ID : %s", customer.ID);

                printf("\n\t\tSTUDENT NAME: %s", customer.name);

                printf("\n\t\tDURATION: %s", customer.duration);

                printf("\n\t\tNOTE: %s", customer.note);

                printf("\n\n\t\tWHAT WOULD YOU LIKE TO EDIT..");

                printf("\n\t\t1.STUDENT NAME.");

                printf("\n\t\t2.DURATION.");

                printf("\n\t\t3.NOTE.");

                printf("\n\t\t4.WHOLE RECORD.");

                printf("\n\t\t5.GO BACK TO MAIN MENU.");

                do

                {

                    printf("\n\n\t\tENTER YOUR CHOICE:");

                    fflush(stdin);

                    scanf("%d", &num);

                    fflush(stdin);

                    switch (num)

                    {

                    case 1:
                        printf("\n\n\t\tENTER THE NEW DATA:");

                        printf("\n\t\tSTUDENT NAME:");

                        gets(customer.name);

                        break;

                    case 2:
                        printf("\n\t\tENTER THE NEW DATA:");

                        printf("\n\t\tDURATION:");

                        gets(customer.duration);

                        break;

                    case 3:
                        printf("\n\t\tENTER THE NEW DATA:");

                        printf("\n\t\tNOTE:");

                        gets(customer.note);

                        break;

                    case 4:
                         printf("\n\t\tENTER THE NEW DATA:");

                        printf("\n\t\tSTUDENT NAME:");

                        gets(customer.name);

                        printf("\n\t\tDURATION:");

                        gets(customer.duration);

                        printf("\n\t\tNOTE:");

                        gets(customer.note);

                        break;

                    case 5:
                        printf("\n\t\tPRESS ANY KEY TO GO BACK...\n");

                        getch();

                        return;

                        break;

                    default:
                        printf("\n\t\tYOU TYPED SOMETHING ELSE...TRY AGAIN\n");

                        break;
                    }

                } while (num < 1 || num > 6);

                fseek(fpte, sizeof(customer), SEEK_CUR);       

                fwrite(&customer, sizeof(customer), 1, fpte);

                fseek(fpte, sizeof(customer), SEEK_CUR);

                fread(&customer, sizeof(customer), 1, fpte);    

                choice = 5;

                break;
            }
        }

        if (choice == 5)

        {

            system("cls");

            printf("\n\t\tEDITING COMPLETED...\n");

            printf("--------------------\n");

            printf("THE NEW RECORD IS:\n");

            printf("--------------------\n");

            printf("\nSTUDENT NAME: %s", customer.name);

            printf("\nDURATION: %s", customer.duration);

            printf("\nNOTE: %s", customer.note);

            fclose(fpte);

            printf("\n\n\tWOULD YOU LIKE TO EDIT ANOTHER RECORD.(Y/N)");

            scanf("%c", &choice);

            count++;
        }

        else

        {

            printf("\nTHE RECORD DOES NOT EXIST::\n");

            printf("\nWOULD YOU LIKE TO TRY AGAIN...(Y/N)");

            scanf("%c", &choice);
        }

    } while (choice == 'Y' || choice == 'y');

    fclose(fpte);

    if (count == 1)

        printf("\n%d FILE IS EDITED...\n", count);

    else if (count > 1)

        printf("\n%d FILES ARE EDITED..\n", count);

    else

        printf("\nNO FILES EDITED...\n");

    printf("\tPRESS ENTER TO EXIT EDITING MENU.");
    // free(customer.SE);

    getch();
}




void deleterecord()

{

    system("cls");

    FILE *fp, *fptr;

    struct record file;

    char filename[15], another = 'Y', ID[20];
    ;

    int choice, check;

    printf("\n\n\t\t*************************\n");

    printf("\t\t* WELCOME TO DELETE MENU*");

    printf("\n\t\t*************************\n\n");

    if (check == 1)

    {

        return;
    }

    while (another == 'Y')

    {

        printf("\n\n\t\tHOW WOULD YOU LIKE TO DELETE.");

        printf("\n\n\t\t#DELETE WHOLE RECORD\t\t\t[1]");

        printf("\n\t\t#DELETE A PARTICULAR RECORD BY ID\t[2]");

        do

        {

            printf("\n\n\t\tENTER YOU CHOICE:");

            scanf("%d", &choice);

            switch (choice)

            {

            case 1:

                printf("\n\t\tENTER THE DATE OF RECORD TO BE DELETED:[yyyy-mm-dd]:");

                fflush(stdin);

                gets(filename);

                fp = fopen(filename, "wb");

                if (fp == NULL)

                {

                    printf("\n\n\t\tTHE FILE DOES NOT EXISTS");

                    printf("\n\t\tPRESS ANY KEY TO GO BACK.");

                    getch();

                    return;
                }

                fclose(fp);

                remove(filename);

                printf("\n\t\tDELETED SUCCESFULLY...");

                break;

            case 2:

                printf("\n\t\tENTER THE DATE OF RECORD:[yyyy-mm-dd]:");

                fflush(stdin);

                gets(filename);

                fp = fopen(filename, "rb");

                if (fp == NULL)

                {

                    printf("\n\n\t\tTHE FILE DOES NOT EXISTS");

                    printf("\n\n\t\tPRESS ANY KEY TO GO BACK.");

                    getch();

                    return;
                }

                fptr = fopen("temp", "wb");

                if (fptr == NULL)

                {

                    printf("\n\t\tSYSTEM ERROR");

                    printf("\n\t\tPRESS ANY KEY TO GO BACK");

                    getch();

                    return;
                }

                printf("\n\t\tENTER THE STUDENT ID RECORD TO BE DELETED: ");

                fflush(stdin);

                gets(ID);

                while (fread(&file, sizeof(file), 1, fp) == 1)

                {

                    if (strcmp(file.ID, ID) != 0)

                        fwrite(&file, sizeof(file), 1, fptr);
                }

                fclose(fp);

                fclose(fptr);

                remove(filename);

                rename("temp", filename);

                printf("\n\t\tDELETED SUCCESFULLY...");

                break;

            default:

                printf("\n\t\tYOU ENTERED WRONG CHOICE");

                break;
            }

        } while (choice < 1 || choice > 2);

        printf("\n\t\tDO YOU LIKE TO DELETE ANOTHER RECORD.(Y/N):");

        fflush(stdin);

        scanf("%c", &another);
    }

    printf("\n\n\tPRESS ANY KEY TO EXIT...");

    getch();
}