    cur = list;
    prev = NULL;
    for (cur, prev;
        cur != NULL && strcmp(lastname, cur->owner_last_name) > 0;
        prev = cur, cur = cur->next)
    ; //loop will stop when it finds a lastname with same name or greater, or when cur == NULL

    //if list is empty
    if (cur == NULL && prev == NULL) {
        return new;
    }
    //if it gets to the end of the list
    else if (cur == NULL ) {
        prev->next = new;
        return list;
    }
    if (prev == NULL) {
        //prev->next = new;
        printf("HI THERE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        return new;
    }

    //if it found that lastname in the list
    if (cur != NULL && strcmp(lastname, cur->owner_last_name) == 0) {

        //and if the dog's name is also the same
        if (strcmp(name, cur->dog_name) == 0) {

            printf("Dog already exists\n");
            free(new);
            return list;
        } 

        //getting to an equal or greater lastname
        for (cur, prev;
            cur != NULL && strcmp(lastname, cur->owner_last_name) == 0 && strcmp(name, cur->dog_name) >= 0;
            prev = cur, cur = cur->next)
        ;
/*       
        if (cur == NULL) {

            printf("HI THERE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        }*/

        if (cur != NULL && strcmp(name, cur->dog_name) < 0) {
            prev->next = new;
            new->next = cur;
            return list;
        } 
        else {
            new->next = cur->next;
            cur->next = new;
            return list;
        }
        
    } //if the new dog's owner's lastname is less than cur
    else if (cur != NULL && strcmp(lastname, cur->owner_last_name) < 0) {

        prev->next = new;
        new->next = cur;
        return list;
    }


}