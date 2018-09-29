#include "person.h"

typedef struct LE ListElement;

/**
 * Model for a ListElement.
 */
struct LE {
    /// @brief person for the element
    Person content;
    /// @brief pointer to the next list element (or start)
    ListElement *next;
};

/// @brief allocate a new list element and prompt the usert to enter user data
ListElement *create_new_list_element(void);

/// @brief insert a list element into a list - it will not be tested whether it
/// already is included
void insert_list_element(ListElement *start, ListElement *newElement);

/// @brief search element in list and remove it - also frees memory
void delete_list_element(ListElement *start, ListElement *element);

/// @brief remove all elements from list - also frees memory
void clear_list(ListElement *start);

/// @brief print all elements to stdout
void print_people(ListElement *start);