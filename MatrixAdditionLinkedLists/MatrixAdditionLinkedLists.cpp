//20009320 Lukas Jehle

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


struct Node {  //declaration
    int row;
    int column;
    int value;
    Node* next;
};
Node* A, * B, * C;  //declaration
int row, col;

int search(Node* a, int x, int y) {
    Node* current = a;
    while (current != NULL) {
        if (current->row == x && current->column == y) {
            return current->value;
        }
        else {
            current = current->next;
        }
    }
    return 0;
}
void add_node(Node*& a, int i, int j, int value) {
    Node* current = a;
    if (current != NULL) {
        while (current->next != NULL) {
            current = current->next;
        }
    }

    Node* temp = new Node;
    temp->row = i;
    temp->column = j;
    temp->value = value;
    temp->next = NULL;
    if (current != NULL) {
        current->next = temp;
    }
    else {
        a = temp;
    }

}
void read_matrix(Node*& a, char* file_name) {
    //reads a matrix from a file

    col = 0,
        row = 0;
    int value = 0;
    FILE* input = NULL;
    input = fopen(file_name, "r");

    if (input == NULL) {
        printf("Cannot open file %s. Exiting.\n", file_name);
        exit(0);
    }
    //reads the matrix dimensions from the first line 
    fscanf(input, "%d %d", &row, &col);

    //read matrix 
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            //reads each value from this row (second line onwards)
            fscanf(input, "%d", &value);
            if (value == 0) continue;
            if (value != 0) {
                add_node(a, i, j, value);
                //printf("Element at (%d %d) is different than zero and it is: %d ", i, j, value);
            }

        }
        //the next line is for debbuging purposes, it can be commented out later
       // printf("\n");
    }

    fclose(input);
}
void print_LL(Node* a) {
    Node* current = a;

    while (true) {
        if (current == NULL) {
            break;
        }
        else {
            printf("%d ", current->value);
            current = current->next;
        }
    }
    printf("\n");
}
void print_matrix(Node* a) {
    Node* current = a;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (current != NULL) {
                if (current->row == i && current->column == j) {
                    printf("%d ", current->value);
                    current = current->next;
                }
                else {
                    printf("0 ");
                }
            }
            else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}
void add_matrix(Node* a, Node* b, Node*& c) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int element1 = search(a, i, j);
            int element2 = search(b, i, j);
            int result = element1 + element2;
            if (result != 0) {
                add_node(c, i, j, result);
            }
        }
    }
}

int main(int argc, char** argv) {
    if (argc != 3) { printf("needs two matrices \n"); exit(0); }
    C = NULL;
    read_matrix(A, argv[1]);
    read_matrix(B, argv[2]);

    printf("Matrix 1: ");
    print_LL(A);
    print_matrix(A);

    printf("Matrix 2: ");
    print_LL(B);
    print_matrix(B);

    add_matrix(A, B, C);
    printf("Matrix Result: ");
    print_LL(C);
    print_matrix(C);
}