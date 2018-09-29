#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "color.h"
#include "person.h"
#include "validator.h"

#define S_(x) #x
#define S(x) S_(x)

int compare_person(const Person *uno, const Person *duo)
{
    assert(uno);
    assert(duo);

    int returnValue = strncmp(uno->name, duo->name, STRING_LENGTH);
    if (returnValue == 0) {
        returnValue = strncmp(uno->firstname, duo->firstname, STRING_LENGTH);
        if (returnValue == 0) {
            returnValue = uno->age - duo->age;
        }
    }
    return returnValue;
}

/// @brief clear stdin so that the next scanf will not read unexpected input
static void purge_stdin()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

static void scan_text(char *value)
{
    assert(value);

    (void)scanf("%" S(STRING_LENGTH_SCAN) "s", value);
    (void)purge_stdin();
}

static void scan_text_with_prompt(char *value, const char *label)
{
    assert(value);
    assert(label);

    do {
        (void)printf("%s\n", label);
        (void)scan_text(value);
    } while (!is_valid_string(value));
}

static void scan_number(unsigned *value)
{
    assert(value);

    (void)scanf("%d", value);
    (void)purge_stdin();
}

static void scan_unsigned_with_prompt(unsigned *value, const char *label)
{
    assert(value);
    assert(label);

    do {
        (void)printf("%s\n", label);
        (void)scan_number(value);
    } while (!is_valid_age(*value));
}

void create_person(Person *person)
{
    assert(person);

    (void)scan_text_with_prompt(person->name, "Name: ");
    (void)scan_text_with_prompt(person->firstname, "Firstname: ");
    (void)scan_unsigned_with_prompt(&person->age, "Age: ");
}

void print_person(Person *person)
{
    assert(person);
    (void)printf(COLOR_BLU "%-25s" COLOR_MAG " %-25s" COLOR_RESET " %3d\n",
        person->name, person->firstname, person->age);
}