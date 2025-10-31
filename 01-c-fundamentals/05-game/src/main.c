#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ROW_COUNT 32
#define MAX_COL_COUNT 32

typedef enum {
    map_element_path,
    map_element_wall,
    map_element_visited
} map_element;

typedef enum {
    direction_up = 'C',
    direction_down = 'B',
    direction_left = 'E',
    direction_right = 'D'
} direction;

int main(void) {
    int row_count, col_count;
    scanf("%d %d", &row_count, &col_count);

    int map[MAX_ROW_COUNT][MAX_COL_COUNT];

    for (int row = 0; row < row_count; row++) {
        for (int col = 0; col < col_count; col++) {
            scanf("%d", &map[row][col]);
        }
    }

    int x_j, y_j;
    scanf("%d %d", &y_j, &x_j);
    int x_f, y_f;
    scanf("%d %d", &y_f, &x_f);

    // Ensure positions are zero-indexed
    x_j--;
    y_j--;
    x_f--;
    y_f--;

    char movement_priority[4];
    scanf("%s", movement_priority);

    const char *sep = "";
    while (true) { // Breaks only if end is reached or couldn't move
        map[y_j][x_j] = map_element_visited;
        printf("%s(%d,%d)", sep, y_j + 1, x_j + 1);
        sep = " ";

        if (x_j == x_f && y_j == y_f) { // Check if end was reached
            break;
        }

        bool moved = false;
        for (int i = 0; i < 4; i++) {
            int dx = 0;
            int dy = 0;

            switch (movement_priority[i]) {
                case direction_up:
                    dy--;
                    break;
                case direction_down:
                    dy++;
                    break;
                case direction_left:
                    dx--;
                    break;
                case direction_right:
                    dx++;
                    break;
            }

            int new_x_j = x_j + dx;
            int new_y_j = y_j + dy;

            bool x_valid = new_x_j >= 0 && new_x_j < col_count;
            bool y_valid = new_y_j >= 0 && new_y_j < row_count;
            bool target_is_path = map[new_y_j][new_x_j] == map_element_path;
            if (x_valid && y_valid && target_is_path) {
                x_j = new_x_j;
                y_j = new_y_j;
                moved = true;
                break;
            }
        }

        if (!moved) {
            break;
        }
    }

    putchar('\n');

    return EXIT_SUCCESS;
}
