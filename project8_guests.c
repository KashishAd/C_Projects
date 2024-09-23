//Name: Kashish Adlakha
//This program manages and tracks the guest list for a local restaurant. Each group of guests is stored with phone number, last name and first name, and party size.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NAME_LEN 30
#define PHONE_LEN 20

struct guest{
    char phone[PHONE_LEN + 1];
    char last[NAME_LEN + 1];
    char first[NAME_LEN + 1];
    int party_size;
    struct guest *next;
};

struct guest *add_guest(struct guest *list);
void print_list(struct guest *list);
void clear_list(struct guest *list);
int read_line(char str[], int n);

int main(void)
{
    char code;

    struct guest *new_list = NULL;
    printf("Operation Code: a for adding to the list at the end, p for printing the list; q for quit.\n");
    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n')   /* skips to the end of the line */
            ;
        switch (code) {
            case 'a': new_list = add_guest(new_list);
                break;
            case 'p': print_list(new_list);
                break;
            case 'q': clear_list(new_list);
                return 0;
            default:  printf("Illegal code\n");
        }
        printf("\n");
    }
}

struct guest *add_guest(struct guest *list) {
    char phone[PHONE_LEN + 1];
    char last[NAME_LEN + 1];
    char first[NAME_LEN + 1];
    int party_size;

    // Read guest details
    printf("Enter phone number: ");
    read_line(phone, PHONE_LEN);

    // Check if the guest already exists
    struct guest *current = list;
    while (current != NULL) {
        if (strcmp(current->phone, phone) == 0) {
            printf("guest already exists.");
            return list;  // Guest already exists, no change to the list
        }
        current = current->next;
    }

    printf("Enter guest's last name: ");
    read_line(last, NAME_LEN);

    printf("Enter guest's first name: ");
    read_line(first, NAME_LEN);

    printf("Enter party size: ");
    scanf("%d", &party_size);
    while (getchar() != '\n')   /* skips to the end of the line */
        ;

    // Allocate memory for the new guest
    struct guest *new_guest = (struct guest *) malloc(sizeof(struct guest));
    if (new_guest == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    // Copy data to the new guest
    strcpy(new_guest->phone, phone);
    strcpy(new_guest->last, last);
    strcpy(new_guest->first, first);
    new_guest->party_size = party_size;
    new_guest->next = NULL;

    // Add the new guest to the end of the list
    if (list == NULL) {
        return new_guest;
    } else {
        struct guest *current = list;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_guest;
        return list;
    }
}

void print_list(struct guest *list) {
    while (list != NULL) {
        printf("%-15s%-20s%-20s%5d\n", list->phone, list->last, list->first, list->party_size);
        list = list->next;
    }
}

void clear_list(struct guest *list) {
    struct guest *current = list;
    while (current != NULL) {
        struct guest *next = current->next;
        free(current);
        current = next;
    }
}

int read_line(char str[], int n) {
    int ch, i = 0;

    while (isspace(ch = getchar()))
        ;

    str[i++] = ch;
    while ((ch = getchar()) != '\n') {
        if (i < n)
            str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}


