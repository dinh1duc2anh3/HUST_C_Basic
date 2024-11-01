#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ALPHABET_LEN 256

//---------------------------------------------------------------------

typedef struct Profile {
    char name[ALPHABET_LEN];
    char email[ALPHABET_LEN];
    struct Profile* prev;
    struct Profile* next;
} Profile;

void printProfile(Profile* head){
    Profile* p = head;
    while (p != NULL){
        printf("%s %s ",p->name,p->email);
        printf("\n");
         p =p->next;
    }
    printf("\n");

}

Profile* makeProfile(char name[ALPHABET_LEN] , char email[ALPHABET_LEN]){
    Profile* newProfile = (Profile*) malloc(sizeof(Profile));
    strcpy(newProfile->name , name);
    strcpy(newProfile->email , email);
    newProfile->prev = NULL;
    newProfile->next = NULL;
    return newProfile;
}

Profile* addLast(Profile** head, Profile** last, char name[ALPHABET_LEN] , char email[ALPHABET_LEN]){
    Profile* newProfile = makeProfile(name , email);

    if (*head == NULL ) {
        *head = newProfile;
        *last = newProfile;
        return *head;
    }

    (*last)->next = newProfile;
    newProfile->prev = *last;
    *last = newProfile;
    return *head;
}

Profile* findProfile(Profile* head, char name[ALPHABET_LEN] ){
    Profile* p = head;
    while (p != NULL){
        if ( strcmp(p->name , name) == 0 ){
            return p;
        }
        p = p->next;
    }
    printf("cannot find %s.\n",name);
    return NULL;
}

Profile* removeProfile(Profile** head, Profile** last, char name[ALPHABET_LEN] ){
    if (* head == NULL) return NULL;
    Profile* p = findProfile(*head , name);
    if (p != NULL){
        if ( p == *head){
            *head = (*head)->next;

            if (*head != NULL){
                (*head)->prev = NULL;
            }
            else {
                *last = NULL;
            }

            free(p);
            return *head;
        }

        if (p == *last){
            *last = (*last)->prev;
            (*last)->next = NULL;
            free(p);
            return *head;
        }

        p->next->prev  = p->prev;
        p->prev->next = p->next;
        free(p);
        return *head;        
    }
}


void freeProfile(Profile* head){
    Profile* p = head;
    Profile* np = NULL;
    while (p != NULL){
        np = p->next;
        free(p);
        p = np;
    }
}

//---------------------------------------------------------------------


void load(char * filename , Profile** head , Profile ** last){
    FILE* fp = fopen(filename , "r");
    if (fp == NULL) {
        printf("Cannot open file %s.\n",filename);
        return;
    }

    char name[ALPHABET_LEN];
    char email[ALPHABET_LEN];
    while (fscanf(fp,"%s %s",name, email) == 2){
         
        *head = addLast(head , last , name, email);
    }
    fclose(fp);
}



void store(char * desFilename ,Profile* head ){
    FILE* fp = fopen(desFilename , "w");
    if (fp == NULL){
        printf("Cannot store in %s.\n",desFilename);
        return;
    }

    Profile* p = head;
    int cnt = 1;
    while (p != NULL){
        fprintf(fp, "Profile %d : %s %s\n",cnt,p->name , p->email);
        cnt ++;
        p = p->next;
    }
    printf("Stored succesfully in %s.\n",desFilename);
    fclose(fp);

}


//---------------------------------------------------------------------


void processCommand(){
    printf("-------------List of Commands-------------\n");
    printf("command \n");
    printf("addLast \n");
    printf("remove\n");
    printf("find\n");
    // printf("removeAll \n");
    // printf("reverse \n");
    // printf("deleteMin \n");
    // printf("deleteMax \n");
    printf("print \n");
    printf("store \n");
    printf("exit \n");
    printf("---------------------------------------\n");
}

void processAddLast(Profile ** head, Profile ** last){
    char name[ALPHABET_LEN];
    char email[ALPHABET_LEN];
    scanf("%s %s",name, email);
    addLast(head , last , name , email);
    printProfile(*head);
    printf("---------------------------------------\n");

}

void processRemoveProfile(Profile ** head, Profile ** last){
    char name[ALPHABET_LEN];
    scanf("%s",name);
    printProfile(removeProfile(head , last , name));

    printf("---------------------------------------\n");
}

void processFindProfile(Profile *head){
    char name[ALPHABET_LEN];
    scanf("%s",name);
    Profile* result = findProfile(head , name);
    if (result != NULL){
        printf("FIND RESULT: %s %s\n",result->name , result->email);
    }
    else printf("Cannot find %s.\n",name);
    printf("---------------------------------------\n");
}

//---------------------------------------------------------------------



int main (){
    Profile*  head =NULL;
    Profile* last = NULL;

    char* filename = "studentProfile.txt";
    char* desFilename = "studentProfileDes.txt";
    load(filename , &head , &last);

    processCommand();

    while (1) {
        char cmd[30];
        scanf("%s",cmd);
        

        if (strcmp(cmd, "exit") == 0) break;
        else if (strcmp(cmd, "command") == 0) processCommand();
        else if (strcmp(cmd, "addLast") == 0) processAddLast(&head , &last);
        else if (strcmp(cmd, "remove") == 0) processRemoveProfile(&head , &last);
        else if (strcmp(cmd, "find") == 0) processFindProfile(head);
        // else if (strcmp(cmd, "removeAll") == 0) processRemoveAll();
        // else if (strcmp(cmd, "reverse") == 0) processReverse();
        // else if (strcmp(cmd, "deleteMin") == 0) processDeleteMin();
        // else if (strcmp(cmd, "deleteMax") == 0) processDeleteMax();
        else if (strcmp(cmd, "print") == 0) printProfile(head);
        else if (strcmp(cmd, "store") == 0) store(desFilename , head);
    }
    
    freeProfile(head);
    return 0;
}