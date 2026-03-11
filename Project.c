#include <stdio.h>
#include <stdlib.h>

// MAKING SUITABLE FOR EVERY TYPE OF OS (Windows or Linux).
#ifdef _WIN32
#include <windows.h>
void sleep_ms(int ms) { Sleep(ms); }
#else
#include <unistd.h>
void sleep_ms(int ms) { usleep(ms * 1000); }
#endif

typedef struct Student
{
    char name[100];
    char course[20];
    char roll_num[10];
    int obtained_marks[5];
} data;

// FUNTION PROTOTYPE
void p_line(const char *line, float seconds);
void clear_screen(void);

int main()
{
    clear_screen();

    // GREETINGS AND MENU
    p_line("\n================| STUDENT RECORD SYSTEM |================\n\n", 0.5);

    int choice;

    do
    {
        p_line("~ Please choose any option:-\n\n", 0.05);

        printf("  1 => Add Student Record\n");
        printf("  2 => View All Records\n");
        printf("  3 => Search Student\n");
        printf("  4 => Update Student Record\n");
        printf("  5 => Delete Student Record\n");
        printf("  6 => Calculate Result\n");
        printf("  7 => Exit\n");

        // INPUT CHOSE OPTION
        p_line("\n=> Enter Your Choice: ", 0.05);

        if (scanf("%d", &choice) != 1 || choice < 1 || choice > 8)
        {
            printf("\nInvalid Choice!\n");
            printf("SORRY! We're Exiting");
            p_line("...\n", 1.5);
            return 1;
        }

        getchar(); // REMOVE NEW LINE

        switch (choice)
        {
        case 1:
            p_line("\n\t       Loading Servers", 0.2);
            p_line("....\n", 0.5);
            clear_screen();
            break;

        case 2:
            p_line("\n\t       Loading Servers", 0.2);
            p_line("....\n", 0.5);
            clear_screen();
            break;

        case 3:
            p_line("\n\t       Loading Servers", 0.2);
            p_line("....\n", 0.5);
            clear_screen();
            break;

        case 4:
            p_line("\n\t       Loading Servers", 0.2);
            p_line("....\n", 0.5);
            clear_screen();
            break;

        case 5:
            p_line("\n\t       Loading Servers", 0.2);
            p_line("....\n", 0.5);
            clear_screen();
            break;

        case 6:
            p_line("\n\t       Loading Servers", 0.2);
            p_line("....\n", 0.5);
            clear_screen();
            break;

        case 7:
            p_line("\n\n\t---| Bye! Visit Us Again |---", 0.7);
            p_line("\n|===========================================|\n\n", 0.1);
            return 1;
            break;

        default:
            printf("\n\t\tUnable to fetch details\n");
            printf("\t\tSORRY! We're Exiting");
            p_line("...\n", 1.5);
            return 1;
            break;
        }

    } while (choice != 7);
}

// FUNCTION DEFINATION

//  TO CLEAR SCREEN
void clear_screen(void)
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// PRINT LINE WITH DELAY
void p_line(const char *line, float seconds)
{
    int len = strlen(line);
    if (len == 0 || seconds <= 0) // BASE CONDITION FOR NO LINE
        return;

    int total_ms = (int)(seconds * 1000); // SETTING TIME IN MICROSECONDS
    int per_char_delay = total_ms / len;

    // PRINTING LINE
    if (per_char_delay < 1)
        per_char_delay = 1;

    for (int i = 0; line[i] != '\0'; i++)
    {
        putchar(line[i]);
        fflush(stdout);
        sleep_ms(per_char_delay);
    }
}