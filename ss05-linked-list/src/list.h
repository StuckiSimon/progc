#include "person.h"

typedef struct LE ListElement;

/**
 * Model for a ListElement.
 */
struct LE {
    /// @brief person for the element
    Person content;
    /// @brief pointer to the next list element (or start)
    ListElement* next;
};

ListElement *create_new_list_element(void);

void insert_list_element(ListElement *start, ListElement *newElement);

void delete_list_element(ListElement *start, ListElement *element);

void clear_list(ListElement* start);

void print_people(ListElement* start);