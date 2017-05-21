#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define NAME_LEN 30

struct dog{
	int number;
	char dog_name[NAME_LEN+1];
	char owner_last_name[NAME_LEN+1];
	char breed[NAME_LEN+1];
	struct dog *next;
};

struct dog *append(struct dog *list);
void search(struct dog *list);
int find(int number, struct dog *list);
void print(struct dog *list);
void clear(struct dog *list);
int read_line(char str[], int n);

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
    char code;

    struct dog *dog_list = NULL;  

    printf("Operation Code: a for appending to the list, s for finding a dog"
        ", p for printing the list; q for quit.\n");
   
    for (;;) {

        printf("Enter operation code: ");
        scanf(" %c", &code);

        while (getchar() != '\n')   /* skips to end of line */
        ;

        switch (code) {
            case 'a': dog_list = append(dog_list);
                break;
            case 's': search(dog_list);
                break;
            case 'p': print(dog_list);
                break;
            case 'q': clear(dog_list);
		        return 0;
            default:  printf("Illegal code\n");
        }

    printf("\n");

    }

    return(0);
}
/*
 * Ask the user to enter patient number, dog's name, dog's breed, and owner's last
 * name, and then add the dog to the end of the linked list
 */
struct dog *append(struct dog *list){

    int number;
    char name[NAME_LEN+1];
    char breed[NAME_LEN+1];
    char lastname[NAME_LEN+1];

    struct dog *new;
    struct dog *p;
    
    int flag = 0;

    printf("\nEnter patient number:\n");
    scanf("%d", &number);

   //if dog already exists
    if (find(number, list)) {
        printf("Patient number %d is already in the list.\n", number);
        return list;
    }

    //if dog does not exist
    printf("Enter the dog's name:\n");
	read_line(name, NAME_LEN+1);

    printf("Enter the dog's breed:\n");
	read_line(breed, NAME_LEN+1);

    printf("Enter the owner's last name:\n");
	read_line(lastname, NAME_LEN+1);

	//if list is empty, flag will be 1, otherwise, will be 0
    if (list == NULL)
        flag = 1;
    else
        flag = 0;

    //creating new dog
    new = malloc(sizeof(struct dog));
        
    if (new == NULL) {
        printf("Error: malloc failed in append");
    }

    new->number = number;
    strcpy(new->dog_name, name);
    strcpy(new->owner_last_name, lastname);
    strcpy(new->breed, breed);
    new->next = NULL;

    //if the list is empty (flag==1), return the new element
    if (flag) {
    
        printf("Patient added successfully\n");
        return(new);
    }
    else { //if the list is not empty, add element to the end and return updated list

        for (p = list; p->next != NULL; p = p->next)
        ;

        p->next = new;

        printf("Patient added successfully\n");
        return(list);
    }
}
/*
 * Find the dog by name, print all the dog's information that matches the name.
 * If the dog is not found, print a message
 */
void search (struct dog *list)
{
	struct dog *p;
    char name[NAME_LEN+1];
    int flag = 0;

	if (list == NULL) {
        printf("List of patients is empty\n");
        return;
    }

    printf("Enter the patient's name to search:\n");
	read_line(name, NAME_LEN+1);

    for (p = list; p != NULL; p = p->next) {

        if (strcmp(p->dog_name,name)==0) {
        
            printf("%d\t", p->number);
            printf("%s\t", p->dog_name);
            printf("%s\t", p->breed);
            printf("%s\n", p->owner_last_name);
            flag = 1;
        }

    }

    if (!flag)
        printf("Patient name not found\n");
    
    return;
}
/*
 * Boolean function that returns 1 if a dogs name is in the list
 */
int find(int number, struct dog *list)
{
    struct dog *p;

    if (list == NULL)
        return(0);
    else
        for (p = list; p != NULL; p = p->next) {

            if (p->number == number) 
                return(1);

        }

    return(0);
    
}
/*
 * Prints the name and number of all the dogs
 */
void print(struct dog *list) 
{
    struct dog *p;

    if (list == NULL) {
        printf("List of patients is empty\n");
        return;
    }

	for (p = list; p != NULL; p = p->next) {

        printf("%d\t", p->number);
        printf("%s\t", p->dog_name);
        printf("%s\t", p->breed);
        printf("%s\n", p->owner_last_name);
    }

    return;

}
/*
 * Deallocate all the memory used by the list
 */
void clear(struct dog *list)
{
    struct dog *p;

    while (list != NULL) {

        p = list;
        list = list->next;

        if (p != NULL)
            free(p);
    }

    printf("Clear success\n");
}
/*
 * Read dogs' names, breeds, and owner last names
 */
int read_line(char str[], int n)
{
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
