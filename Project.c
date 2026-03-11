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

// DEFINING COLOR
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define PURPLE "\033[35m"
#define BACKGROUND "\033[44m"
#define ITALIC "\033[3m"
#define BOLD "\033[1m"
#define RESET "\033[0m"

// FUNCTION PROTOTYPE
void p_line(const char *line, float seconds);
void clear_screen(void);

int main()
{
    clear_screen();

    // GREETINGS AND MENU
    p_line(BACKGROUND BOLD"\t\t\t\t\t :-----------------------------------: \n", 0.1);
    p_line("\t\t\t\t\t |       STUDENT RECORD SYSTEM       | \n", 0.1);
    p_line("\t\t\t\t\t :-----------------------------------: \n" RESET, 0.1);

    int choice;

    do
    {
        p_line(GREEN BOLD"~ Please choose any option:-\n" RESET, 0.05);

        printf(ITALIC PURPLE "  1." RESET " Add Student Record\n");
        printf(ITALIC PURPLE "  2." RESET " View All Records\n");
        printf(ITALIC PURPLE "  3." RESET " Search Student\n");
        printf(ITALIC PURPLE "  4." RESET " Update Student Record\n");
        printf(ITALIC PURPLE "  5." RESET " Delete Student Record\n");
        printf(ITALIC PURPLE "  6." RESET " Calculate Result\n");
        printf(ITALIC PURPLE "  7." RESET " Exit\n");

        // INPUT CHOSE OPTION
        p_line(BLUE "\n Enter Your Choice: " RESET, 0.05);

        if (scanf("%d", &choice) != 1 || choice < 1 || choice > 7)
        {
            printf(RED ITALIC"\nInvalid Input!\n" RESET);
            printf("SORRY! We're Exiting");
            p_line("...\n\n", 1.5);
            return 1;
        }

        getchar(); // REMOVE NEW LINE
    } while (choice != 7);
}

// FUNCTION PROTOTYPE

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
