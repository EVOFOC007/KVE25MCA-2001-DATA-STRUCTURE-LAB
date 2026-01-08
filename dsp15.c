#include <stdio.h>
#define MAX 10
#define INF 999

int main() {
    int vertex_array[MAX], vertex_count = 0;
    int cost_matrix[MAX][MAX], visited[MAX] = {0};
    int edge_count = 0, count = 1, sum_cost = 0, min_cost;
    int row_no = 0, column_no = 0;

    printf("Total number of vertices: ");
    scanf("%d", &vertex_count);

    printf("\n-- Enter vertex labels -- \n");
    for (int counter = 1; counter <= vertex_count; counter++) {
        printf("Vertex %d: ", counter);
        scanf("%d", &vertex_array[counter]);
    }

    printf("\n-- Enter cost matrix of size %d x %d --\n", vertex_count, vertex_count);
    for (int row = 1; row <= vertex_count; row++) {
        for (int column = 1; column <= vertex_count; column++) {
            scanf("%d", &cost_matrix[row][column]);
           
            if (cost_matrix[row][column] == 0 && row != column) {
                cost_matrix[row][column] = INF;
            }
        }
    }

    printf("\n");
    visited[1] = 1; 
    edge_count = vertex_count - 1; 

    while (count <= edge_count) {
        min_cost = INF;

        for (int row = 1; row <= vertex_count; row++) {
            if (visited[row]) { 
                for (int column = 1; column <= vertex_count; column++) {
                    if (!visited[column] && cost_matrix[row][column] < min_cost) {
                        min_cost = cost_matrix[row][column];
                        row_no = row;
                        column_no = column;
                    }
                }
            }
        }

        if (!visited[column_no]) {
            printf("Edge %d : (%d -> %d) with cost : %d \n", 
                   count++, vertex_array[row_no], vertex_array[column_no], min_cost);
            
            sum_cost = sum_cost + min_cost;
            visited[column_no] = 1;

            cost_matrix[row_no][column_no] = cost_matrix[column_no][row_no] = INF;
        }
    }

    printf("\nMinimum cost = %d \n", sum_cost);
    return 0;
}
