#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "color.h"
#include "list.h"
#include "person.h"

ListElement *create_new_list_element(void)
{
    ListElement *newElement = malloc(sizeof(ListElement));
    if (newElement == NULL) {
        return NULL;
    }
    (void)create_person(&newElement->content);
    return newElement;
}

void insert_list_element(ListElement *start, ListElement *newElement)
{
    assert(start);
    assert(newElement);

    ListElement *element = start->next;
    ListElement *previous = start;
    while (start != element
        && compare_person(&newElement->content, &element->content) > 0) {
        previous = element;
        element = element->next;
    }
    newElement->next = element;
    previous->next = newElement;
}

static void free_list_element(ListElement *toDelete, ListElement *previous)
{
    assert(toDelete);
    assert(previous);

    previous->next = toDelete->next;
    free(toDelete);
}

void delete_list_element(ListElement *start, ListElement *elementToDelete)
{
    assert(start);
    assert(elementToDelete);

    ListElement *previous = start;
    ListElement *element = start->next;
    while (start != element
        && compare_person(&elementToDelete->content, &element->content) != 0) {
        previous = element;
        element = element->next;
    }
    if (start != element) {
        (void)free_list_element(element, previous);
    }
}

void clear_list(ListElement *start)
{
    assert(start);
    ListElement *element = start->next;
    while (element != start) {
        (void)free_list_element(element, start);
        element = start->next;
    }
}

void print_people(ListElement *start)
{
    assert(start);
    ListElement *element = start->next;
    if (element == start) {
        (void)printf(COLOR_RED "empty list\n" COLOR_RESET);
    } else {
        do {
            (void)print_person(&element->content);
            element = element->next;
        } while (element != start);
    }
    return;
}