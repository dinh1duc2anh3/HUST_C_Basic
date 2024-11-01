#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    char email[100];
} Student;

typedef struct TreeNode {
    Student student;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct {
    TreeNode* root;
} StudentDatabase;

TreeNode* create_node(Student student) {
    TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));
    strcpy(new_node->student.name, student.name);
    strcpy(new_node->student.email, student.email);
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

TreeNode* insert(TreeNode* node, Student student) {
    if (node == NULL) {
        return create_node(student);
    }

    if (strcmp(student.name, node->student.name) < 0) {
        node->left = insert(node->left, student);
    } else if (strcmp(student.name, node->student.name) > 0) {
        node->right = insert(node->right, student);
    }

    return node;
}

Student* find(TreeNode* node, const char* name) {
    if (node == NULL) {
        return NULL;
    }

    if (strcmp(name, node->student.name) == 0) {
        return &(node->student);
    } else if (strcmp(name, node->student.name) < 0) {
        return find(node->left, name);
    } else {
        return find(node->right, name);
    }
}

void display(TreeNode* node) {
    if (node != NULL) {
        display(node->left);
        printf("Name: %s, Email: %s\n", node->student.name, node->student.email);
        display(node->right);
    }
}

void free_tree(TreeNode* node) {
    if (node != NULL) {
        free_tree(node->left);
        free_tree(node->right);
        free(node);
    }
}

int main() {
    StudentDatabase database;
    database.root = NULL;

    while (1) {
        char command[100];
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "Load") == 0) {
            char file_name[100];
            scanf("%s", file_name);

            FILE* file = fopen(file_name, "r");
            if (file == NULL) {
                printf("File not found.\n");
            } else {
                Student student;
                while (fscanf(file, "%s %s", student.name, student.email) != EOF) {
                    database.root = insert(database.root, student);
                }
                fclose(file);
                printf("Data loaded successfully.\n");
            }
        } else if (strcmp(command, "Find") == 0) {
            char name[100];
            scanf("%s", name);

            Student* student = find(database.root, name);
            if (student != NULL) {
                printf("Found student - Name: %s, Email: %s\n", student->name, student->email);
            } else {
                printf("Student not found.\n");
            }
        } else if (strcmp(command, "Insert") == 0) {
            Student student;
            scanf("%s %s", student.name, student.email);

            database.root = insert(database.root, student);
            printf("Student inserted successfully.\n");
        } else if (strcmp(command, "Display") == 0) {
            display(database.root);
        } else if (strcmp(command, "Quit") == 0) {
            free_tree(database.root);
            printf("Exiting program.\n");
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}
