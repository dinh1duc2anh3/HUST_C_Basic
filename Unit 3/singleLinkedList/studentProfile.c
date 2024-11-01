#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ALPHABET_LENS 256

//---------------------------------------------------------------------


typedef struct Profile{
    char name[ALPHABET_LENS];
    char email[ALPHABET_LENS];
    struct Profile* next;
} Profile;

void printProfile(Profile* head){
    printf("LIST PROFILE:\n");
    Profile* p = head;
    while (p != NULL){
        printf("%s %s\n",p->name , p->email);
        p = p->next;
    }
    printf("\n");
}

Profile* makeProfile(char name[ALPHABET_LENS] , char email[ALPHABET_LENS]){
    Profile* newProfile = (Profile*) malloc (sizeof(Profile));
    strcpy(newProfile->name , name);
    strcpy(newProfile->email , email);
    return newProfile;
}

Profile* addLast(Profile** head, Profile** last, char name[ALPHABET_LENS] , char email[ALPHABET_LENS]){
    Profile* newProfile = makeProfile(name , email);
    if (*head == NULL) {
        *head = newProfile;
        *last = newProfile;
        return *head;
    }

    (*last)->next = newProfile;
    *last = newProfile;
    return *head;
}

Profile* removeProfile (Profile** head , Profile **last, char name[ALPHABET_LENS]){
    if (*head == NULL) return NULL;

    if (strcmp((*head)->name , name) == 0 ) {
        Profile* tmp = *head;
        *head = (*head)->next;
        free(tmp);

        if (*head == NULL){
            *last = NULL;
        }

        return *head;
    }

    Profile* p = *head;
    Profile* pp = NULL;
    while (p != NULL){
        if (strcmp (p->name , name) == 0) break;
        pp = p;
        p = p->next;
    }


    //problem
    // Check if the profile is found
    if (p == NULL) return NULL;

    pp->next = p->next;
    free(p);

    if (pp->next == NULL){
        *last = pp;

    }

    return *head;


}

Profile* findProfile(Profile* head, char name[ALPHABET_LENS]){
    if (head == NULL) return NULL;
    Profile* p = head;
    while (p != NULL){
        if (strcmp (p->name , name) == 0) break;
        p = p->next;
    }
    return p;
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


    char name[ALPHABET_LENS];
    char email[ALPHABET_LENS];
    while (!feof(fp)){
        fscanf(fp,"%s %s",name, email);
        addLast(head , last , name, email);
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
    char name[ALPHABET_LENS];
    char email[ALPHABET_LENS];
    scanf("%s %s",name, email);
    addLast(head , last , name , email);
    printProfile(*head);
    printf("---------------------------------------\n");

}

void processRemoveProfile(Profile ** head, Profile ** last){
    char name[ALPHABET_LENS];
    scanf("%s",name);
    printProfile(removeProfile(head , last , name));

    printf("---------------------------------------\n");
}

void processFindProfile(Profile *head){
    char name[ALPHABET_LENS];
    scanf("%s",name);
    Profile* result = findProfile(head , name);
    if (result != NULL){
        printf("FIND RESULT: %s %s\n",result->name , result->email);
    }
    else printf("Cannot find %s.\n",name);
    printf("---------------------------------------\n");
}


//---------------------------------------------------------------------


int main(){
    Profile* head = NULL;
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