#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "person.h"

#define EXIT_COMMAND 'e'
#define INSERT_COMMAND 'i'
#define DELETE_COMMAND 'r'
#define SHOW_COMMAND 's'
#define CLEAR_COMMAND 'c'

int main(const int argc, const char *argv[])
{
    char action;
    char input[STRING_LENGTH];
    ListElement listStart;
    listStart.next = &listStart;
    while (action != EXIT_COMMAND) {
        (void)printf("What do you want to do?\n");
        (void)printf("i(nsert), r(emove), s(how), c(lear), e(xit) >");
        (void)fgets(input, STRING_LENGTH_SCAN, stdin);
        (void)sscanf(input, "%c", &action);
        switch (action) {
        case 'i':
            (void)insert_list_element(&listStart, create_new_list_element());
            break;
        case 'r':
            (void)delete_list_element(&listStart, create_new_list_element());
            break;
        case 's':
            (void)print_people(&listStart);
            break;
        case 'c':
            (void)clear_list(&listStart);
            break;
        case EXIT_COMMAND:
            (void)printf("it was a pleasure serving you\n");
            break;
        default:
            (void)printf("sorry, I do not know this command\n");
        }
    }

    return EXIT_SUCCESS;
}