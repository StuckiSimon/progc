#ifndef PERSON_H
#define PERSON_H

#define STRING_LENGTH 20
#define STRING_LENGTH_SCAN 19

/**
 * Definition of a person
 */
typedef struct {
    /// @brief lastname of the person
    char name[STRING_LENGTH];
    /// @brief firstname of the person
    char firstname[STRING_LENGTH];
    /// @brief current age of the person
    unsigned age;
} Person;

int compare_person(const Person *uno, const Person *duo);

void create_person(Person *person);

void print_person(Person *person);

#endif
