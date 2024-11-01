#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coef;
    int exp;
    struct Node* next;
};

struct Polynomial {
    struct Node* head;
};

struct Polynomial* create_poly() {
    struct Polynomial* poly = (struct Polynomial*)malloc(sizeof(struct Polynomial));
    poly->head = NULL;
    return poly;
}

void add_term(struct Polynomial* poly, int coef, int exp) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->coef = coef;
    new_node->exp = exp;
    new_node->next = NULL;

    if (!poly->head || poly->head->exp < exp) {
        new_node->next = poly->head;
        poly->head = new_node;
    } else {
        struct Node* current = poly->head;
        struct Node* prev = NULL;
        while (current && current->exp > exp) {
            prev = current;
            current = current->next;
        }

        if (!current) {
            prev->next = new_node;
        } else if (current->exp == exp) {
            current->coef += coef;
            free(new_node);
        } else {
            new_node->next = current;
            if (prev) {
                prev->next = new_node;
            } else {
                poly->head = new_node;
            }
        }
    }
}

void print_poly(struct Polynomial* poly) {
    struct Node* current = poly->head;
    while (current) {
        printf("%d %d ", current->coef, current->exp);
        current = current->next;
    }
    printf("\n");
}

int evaluate_poly(struct Polynomial* poly, int variable_value) {
    int result = 0;
    struct Node* current = poly->head;
    while (current) {
        result += current->coef * (int)pow(variable_value, current->exp);
        current = current->next;
    }
    return result;
}

void add_poly(struct Polynomial* result_poly, struct Polynomial* poly1, struct Polynomial* poly2) {
    struct Node* node1 = poly1->head;
    struct Node* node2 = poly2->head;

    while (node1 && node2) {
        if (node1->exp > node2->exp) {
            add_term(result_poly, node1->coef, node1->exp);
            node1 = node1->next;
        } else if (node1->exp < node2->exp) {
            add_term(result_poly, node2->coef, node2->exp);
            node2 = node2->next;
        } else {
            add_term(result_poly, node1->coef + node2->coef, node1->exp);
            node1 = node1->next;
            node2 = node2->next;
        }
    }

    while (node1) {
        add_term(result_poly, node1->coef, node1->exp);
        node1 = node1->next;
    }

    while (node2) {
        add_term(result_poly, node2->coef, node2->exp);
        node2 = node2->next;
    }
}

void destroy_poly(struct Polynomial* poly) {
    struct Node* current = poly->head;
    while (current) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(poly);
}

int main() {
    struct Polynomial* polynomials[10001] = {NULL};

    while (1) {
        char command[15];
        scanf("%s", command);

        if (command[0] == '*') {
            break;
        }

        if (command[0] == 'C') {
            int poly_id;
            scanf("%d", &poly_id);
            if (!polynomials[poly_id]) {
                polynomials[poly_id] = create_poly();
            }
        } else if (command[0] == 'A' && command[1] == 'd') {
            int poly_id, coef, exp;
            scanf("%d %d %d", &poly_id, &coef, &exp);
            if (!polynomials[poly_id]) {
                polynomials[poly_id] = create_poly();
            }
            add_term(polynomials[poly_id], coef, exp);
        } else if (command[0] == 'E') {
            int poly_id, variable_value;
            scanf("%d %d", &poly_id, &variable_value);
            if (polynomials[poly_id]) {
                int result = evaluate_poly(polynomials[poly_id], variable_value);
                printf("%d\n", result);
            } else {
                printf("0\n");
            }
        } else if (command[0] == 'A' && command[1] == 'd' && command[2] == 'd') {
            int poly_id1, poly_id2, result_poly_id;
            scanf("%d %d %d", &poly_id1, &poly_id2, &result_poly_id);
            if (!polynomials[result_poly_id]) {
                polynomials[result_poly_id] = create_poly();
            }
            add_poly(polynomials[result_poly_id], polynomials[poly_id1], polynomials[poly_id2]);
        } else if (command[0] == 'P') {
            int poly_id;
            scanf("%d", &poly_id);
            if (polynomials[poly_id]) {
                print_poly(polynomials[poly_id]);
            }
        } else if (command[0] == 'D') {
            int poly_id;
            scanf("%d", &poly_id);
            if (polynomials[poly_id]) {
                destroy_poly(polynomials[poly_id]);
                polynomials[poly_id] = NULL;
            }
        }
    }

    return 0;
}
