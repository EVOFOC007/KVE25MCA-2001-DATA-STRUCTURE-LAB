#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 100

int main() {
    int setA[MAX_ELEMENTS], setB[MAX_ELEMENTS];
    int limitA, limitB, i, j;

    printf("Enter the number of elements in the first set \n");
    scanf("%d", &limitA);
    printf("Enter the elements of set A \n");
    for (i = 0; i < limitA; i++) {
        scanf("%d", &setA[i]);
    }

    printf("Enter the number of elements in the second set \n");
    scanf("%d", &limitB);
    printf("Enter the elements of set B \n");
    for (i = 0; i < limitB; i++) {
        scanf("%d", &setB[i]);
    }

    printf("setA = { ");
    for (i = 0; i < limitA; i++) {
        printf("%d, ", setA[i]);
    }
    printf("\b\b } \n"); 


    printf("setB = { ");
    for (i = 0; i < limitB; i++) {
        printf("%d, ", setB[i]);
    }
    printf("\b\b } \n");

    printf("Union of sets A and B = { ");

    for (i = 0; i < limitA; i++) {
        printf("%d, ", setA[i]);
    }

    for (i = 0; i < limitB; i++) {
        int isDuplicate = 0;
        for (j = 0; j < limitA; j++) {
            if (setB[i] == setA[j]) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            printf("%d, ", setB[i]);
        }
    }
    printf("\b\b } \n");

    printf("Intersection of set A and B = { ");
    for (i = 0; i < limitA; i++) {
        for (j = 0; j < limitB; j++) {
            if (setA[i] == setB[j]) {
                printf("%d, ", setA[i]);
                break; 
            }
        }
    }
    printf("\b\b } \n");

    printf("Set Difference A - B = { ");
    for (i = 0; i < limitA; i++) {
        int isDuplicate = 0;
        for (j = 0; j < limitB; j++) {
            if (setA[i] == setB[j]) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            printf("%d, ", setA[i]);
        }
    }
    printf("\b\b } \n");

    return 0;
}
