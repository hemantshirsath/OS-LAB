#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *ptr = NULL;
    int choice;
    do
    {
        printf("\nEnter 1 for file creation ");
        printf("\nEnter 2 for opening a file ");
        printf("\nEnter 3 for writing to a file ");
        printf("\nnEnter 4 for reading from a file ");
        printf("\nEnter 5 for appending a data to a  file ");
        printf("\nEnter 6 for copying a file  ");
        printf("\nEnter 7 for renaming a file ");
        printf("\nEnter 8 for deleting a file  ");
        printf("\nEnter 9 for Exit");
        printf("\nEnter Your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            ptr = fopen("hemant.txt", "w");
            if (ptr != NULL)
                printf("file created Successfully ");
            else
                printf("File cant be created ");
            fclose(ptr);
            break;
        case 2:
            ptr = fopen("hemant.txt", "r");
            if (ptr == NULL)
            {
                printf("\nError opening a file");
            }
            else
            {
                printf("\nFile opened Successfully ");
            }
            fclose(ptr);
            break;

        case 3:
            ptr = fopen("hemant.txt", "w");
            if (ptr == NULL)
            {
                printf("Error!");
            }
            else
            {
                fprintf(ptr, "Hello Hemant how are you\n");
                fprintf(ptr, "Hope you are good ");
                printf("Data written to the file successfully !");
                fclose(ptr);
            }
            break;
        case 4:
            ptr = fopen("hemant.txt", "r");
            if (ptr == NULL)
            {
                printf("Error!");
            }
            else
            {
                printf("\nContents of the file are\n");
                char ch;
                while ((ch = fgetc(ptr)) != EOF)
                {
                    printf("%c", ch);
                }
                fclose(ptr);
            }
            break;
        case 5:
            ptr = fopen("hemant.txt", "a");
            if (ptr == NULL)
            {
                printf("Error opening to a file ");
            }
            else
            {
                fprintf(ptr, "\nThis is appended data to a file ");
                fclose(ptr);
            }
            break;
        case 6:
            ptr = fopen("hemant.txt", "r");
            if (ptr == NULL)
            {
                printf("Error!");
            }
            else
            {
                FILE *copy = fopen("hemant_copy.txt", "w");
                if (copy == NULL)
                {
                    printf("\nError ");
                }
                else
                {
                    char ch;
                    while ((ch = fgetc(ptr)) != EOF)
                    {
                        fputc(ch, copy);
                    }
                }
                printf("\nFile copied successfully");
                fclose(ptr);
                fclose(copy);
            }
            break;
        case 7:
            int flag = rename("hemant_copy.txt", "renamed_hemant.txt");
            if (flag == 0)
            {
                printf("\nFile renamed Successfully ");
            }
            else
            {
                printf("\nCan't rename a file ");
            }
            break;
        case 8:
            printf("\nEnter 8 for deleting a file ");
            remove("renamed_hemant.txt");
            printf("File deleted successfully ");
            break;
        case 9:
            exit(0);
        }

    } while (1);
    return 0;
}