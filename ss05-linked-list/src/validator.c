#include <stdlib.h>
#include <string.h>

#define MAX_AGE 200

int is_valid_age(int age) {
    return age >= 0 && age < MAX_AGE ? 1 : 0;
}

int is_valid_string(char *string, int strlen) {
    return strnlen(string, strlen) == 0 ? 0 : 1;
}