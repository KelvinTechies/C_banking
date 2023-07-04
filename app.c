#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct User
{
    char fone[50];
    char ac[50];
    char pwd[50];
    float balance;
};

int main()
{

    struct User usr usr1;
    char filename[50];
    char phone[50];

    char pword[50];

    FILE *fp;
    int opt;
    char cont = 'y';
    int choice;
    float amount;

    printf("\nWhat do you want to do");
    printf("\n1. Open an account?");
    printf("\n2. Login to an Account?");

    printf("\n\n\ Your Choice:\t");

    scanf("%d", &opt);

    if (opt == 1)
    {
        system("clear");
        printf("Enter Your account Number\t");
        scanf("%s", usr.ac);
        printf("\n Enter Your Phone number\t");
        scanf("%s", usr.fone);
        printf("\nEnter Your new Password\t");
        scanf("%s", usr.pwd);
        usr.balance = 0;

        strcpy(filename, usr.fone);

        fp = fopen(strcat(filename, ".dat"), "w");
        fwrite(&usr, sizeof(struct User), 1, fp);

        if (fwrite != 0)
        {
            printf("\n\n Account Registered Successfully");
        }
        else
        {
            printf("|n\n Something Went Woring, Please Try Again");
        }
        fclose(fp);
    }

    if (opt == 2)
    {
        system("clear");
        printf("\nEnter Phone Number:\t");
        scanf("%s", phone);
        printf("\nPassword:");
        scanf("%s", pword);
        strcpy(filename, phone);
        fp = fopen(strcat(filename, ".dat"), "r");
        if (fp == NULL)
        {
            printf("\nInvalid Account Number");
        }
        else
        {

            fread(&usr, sizeof(struct User), 1, fp);
            fclose(fp);

            if (!strcmp(pword, usr.pwd))
            {
                system("clear");
                while (cont == 'y')
                {
                    printf("\n Press 1 to Check Balance\t");
                    printf("\n Press 2 to Deposit an Amount\t");
                    printf("\n Press 3 to Withdraw \t");
                    printf("\n Press 4 for Online Transfer\t ");
                    printf("\n Press 5 to Change the  Password\t");
                    printf("\n Press 5 Your Choice\t");
                    scanf("%d", &choice);

                    switch (choice)
                    {
                    case 1:
                        printf("\nYour current Balance is $%lf\t", usr.balance);
                        break;
                    case 2:
                        printf("\n Enter the Amount:\t");
                        scanf("%f", &amount);
                        usr.balance += amount;
                        fp = fopen(filename, 'w');
                        fwrite(&usr, sizeof(struct User), 1, fp);
                        if (fwrite != NULL)
                        {
                            printf("\n SUccessfully, Deposited");
                            fclose(fp);
                        }
                        break;

                    case 3:
                        printf("\n Enter the Amount:\t");
                        scanf("%f", &amount);
                        usr.balance -= amount;
                        fp = fopen(filename, 'w');
                        fwrite(&usr, sizeof(struct User), 1, fp);
                        if (fwrite != NULL)
                        {
                            printf("\n SYou have withdrawen $f", usr.balance);
                            fclose(fp);
                        }
                        break;
                    case 4:
                        printf("\n Please enter the User Phone number to Transfer\t");
                        scanf("%s", phone);
                        printf("\n Enter the amount to transfer\t");
                        scanf("%f", &amount);
                            strcpy(filename, phone);

                        fp = fopen(strcat(filename, ".dat"), "w");

                        if (fp == NULL) printf("\nAccount Number not Registered");
                        else{

                        fread(&usr1, sizeof(struct User), 1, fp);

                        if (amount > usr.balance)
                        {
                            printf("\n Insufficient Fund");
                        }
                        else
                        {

                            fclose(fp);
                            fp = fopen(filename, "w");
                            usr1.balance += amount;
                            fwrite(&usr1, sizeof(struct User), 1, fp);
                            fclose(fp);
                            if (fwrite != NULL)
                            {
                                printf("\n You have just Successfully transferred $lf %s", amount, phone);
                                fp = fopen(strcat(filename, ".dat"), "w");
                                usr.balance -= amount;
                                fwrite(&usr, sizeof(struct User), 1, fp);
                                fclose(fp);
                            }
                        }

                    default:
                        break;
                    }
                        }

                    printf("\n Do you wanat to Continue the Trasaction?");
                    scanf("%s", &cont);
                }
            }
            else
            {
                printf("\n Password MixMatched");
            }
        }
    }

    return 0;
}
