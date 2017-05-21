/*
 * Ask the user to enter patient number, dog's name, dog's breed, and owner's last
 * name, and then add the dog to the end of the linked list
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "readline.h"
#include "dogs.h"

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
