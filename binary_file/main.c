#include <stdio.h>
#include "file_func.h"
// /Users/vivastan/Desktop/T14D23-0/datasets/door_state_1
void ui(void);
void print_data(FILE* f);


int main() {
    ui();
    return 0;
}
void ui() {
    char path[300];
    int x;
    FILE* f = NULL;
    if (scanf("%s", path) != 1) {
        x = -1;
    } else {
        f = fopen(path, "r+b");
        if (!f) {
            x = -1;
        } else {
            if (scanf("%d", &x) != 1)
                x = -1;
        }
    }
    switch (x) {
        case 0:
            print_data(f);
            break;
        default:
            break;
    }
    fclose(f);
    if (x == -1)
        printf("n/a");
}
void print_data(FILE* f) {
    if (!f)
        return;
    for (unsigned long i = 0; i < get_records_count_in_file(f); i++) {
        struct door_state buf = read_record_from_file(f, i);
        printf("%d %d %d %d %d %d %d %d\n", buf.year, buf.month, buf.day, buf.hour, buf.minute, buf.second, buf.status, buf.code);
    }
}
