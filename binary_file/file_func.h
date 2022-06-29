#ifndef file_func_h
#define file_func_h

#include <stdio.h>

struct door_state {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int status;
    int code;
};

struct door_state read_record_from_file(FILE *pfile, unsigned long index);
void write_record_in_file(FILE *pfile, const struct door_state* record_to_write, int index);
void swap_records_in_file(FILE *pfile, int record_index1, int record_index2);
long get_file_size_in_bytes(FILE *pfile);
unsigned long get_records_count_in_file(FILE *pfile);


#endif
