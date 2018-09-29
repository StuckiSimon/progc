#include "../src/list.h"
#include "../../testlib/include/test_utils.h"
#include "CUnit/Basic.h"
#include <string.h>

// setup & cleanup
static int setup(void)
{
    // Do nothing.
    return 0; // success
}

static int teardown(void)
{
    // Do nothing.
    return 0; // success
}

// tests
static void test_remove(void)
{
    ListElement start = {};
    ListElement pan
        = { .content = { .firstname = "Peter", .name = "Pan", .age = 22 } };
    ListElement *element = malloc(sizeof(ListElement));
    (void)strncpy(element->content.firstname, "Bruce", STRING_LENGTH);
    (void)strncpy(element->content.name, "Wayne", STRING_LENGTH);
    element->content.age = 30;
    start.next = &pan;
    pan.next = element;
    element->next = &start;
    (void)delete_list_element(&start, element);
    CU_ASSERT(pan.next == &start);
}

static void test_insert(void)
{
    ListElement start = {};
    start.next = &start;
    ListElement wayneJunior
        = { .content = { .firstname = "Bruce", .name = "Wayne", .age = 30 } };
    ListElement wayneSenior
        = { .content = { .firstname = "Bruce", .name = "Wayne", .age = 70 } };
    ListElement parker
        = { .content = { .firstname = "Peter", .name = "Parker", .age = 22 } };
    ListElement pan
        = { .content = { .firstname = "Peter", .name = "Pan", .age = 22 } };
    (void)insert_list_element(&start, &parker);
    (void)insert_list_element(&start, &pan);
    (void)insert_list_element(&start, &wayneJunior);
    (void)insert_list_element(&start, &wayneSenior);
    CU_ASSERT(start.next == &pan);
    CU_ASSERT(pan.next == &parker);
    CU_ASSERT(parker.next == &wayneJunior);
    CU_ASSERT(wayneJunior.next == &wayneSenior);
    CU_ASSERT(wayneSenior.next == &start);
}

static void test_clear(void)
{
    ListElement start = {};
    ListElement *elementOne = malloc(sizeof(ListElement));
    ListElement *elementTwo = malloc(sizeof(ListElement));
    elementTwo->next = &start;
    elementOne->next = elementTwo;
    start.next = elementOne;
    (void)clear_list(&start);
    CU_ASSERT(start.next == &start);
}

/**
 * @brief Registers and runs the tests.
 * @return returns 0 if test has been run
 */
int main(void)
{
    // setup, run, teardown
    TestMainBasic("UnitTestLinkedList", setup, teardown, test_insert,
        test_remove, test_clear);
    return EXIT_SUCCESS;
}
