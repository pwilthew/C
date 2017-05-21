/* Name: records.c
 * Student: Patricia Wilthew
 */

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
    struct dog *cur, *prev;
    
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

    //space alloation
    new = malloc(sizeof(struct dog));
        
    if (new == NULL) {
        printf("Error: malloc failed in append");
        return list;
    }

    //creating new node
    new->number = number;
    strcpy(new->dog_name, name);
    strcpy(new->owner_last_name, lastname);
    strcpy(new->breed, breed);
    new->next = NULL;

    for (cur = list, prev = NULL;
        cur != NULL && strcmp(new->owner_last_name, cur->owner_last_name) > 0;
        prev = cur, cur = cur->next)
    ;

    //if the new lastname exists
    if (cur != NULL && strcmp(new->owner_last_name, cur->owner_last_name) == 0) {

        //if the dog's name exists for that lastname
        if (strcmp(name, cur->dog_name) == 0) {

            printf("Dog already exists\n");
            free(new);
            return list;
        } 
        //if the dog's name does not exist for that lastname
        else {

            for (cur, prev;
                cur != NULL && strcmp(lastname, cur->owner_last_name) == 0 && strcmp(name, cur->dog_name) >= 0;
                prev = cur, cur = cur->next)
            ;

            new->next = cur;

            if (prev == NULL)
                return new;
            else {
                prev->next = new;
                return list;
            }
        }

    }

	//if the new lastname does not exist
    new->next = cur;

    if (prev == NULL)
        return new;
    else {
        prev->next = new;
        return list;
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

    printf("\n");

	for (p = list; p != NULL; p = p->next) {

        printf("%d\t", p->number);
        printf("%s\t", p->dog_name);
        printf("%s\t", p->breed);
        printf("%s\n", p->owner_last_name);
    }

    return;

}
/*
 * Deallocates all the memory used by the list
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
 * Deletes a dog node from the list
 */
struct dog* delete_from_list(struct dog *dogs) 
{
    struct dog *cur, *prev;

    int number;

    printf("Enter the patient's number to delete:\n");
    scanf("%d", &number);

    for (cur = dogs, prev = NULL;
        cur != NULL && cur->number != number;
        prev = cur, cur = cur->next)
    ;

    if (cur == NULL) {

        printf("Dog not found\n");
        return dogs;
    } 
        
    if (prev == NULL) {

        dogs = dogs->next;

    } else {

        prev->next = cur->next;
    }

    printf("Deleted: %s\n", cur->dog_name);
    free(cur);
    return dogs;
}

