#include <stdio.h>

void ui(void);
void print_data(FILE* f);

struct door_state {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int status;
};

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
    struct door_state buf;
    if (f) {
        while (fread(&buf, sizeof(struct door_state), 1, f) == 1) {
            printf("%d %d %d %d %d %d %d\n", buf.year, buf.month, buf.day, buf.hour, buf.minute, buf.second, buf.status);
        }
    }
}
