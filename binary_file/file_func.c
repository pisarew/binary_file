#include "file_func.h"

struct door_state read_record_from_file(FILE *pfile, unsigned long index) {
    unsigned long offset = index * sizeof(struct door_state);
    fseek(pfile, offset, SEEK_SET);
    struct door_state record;
    fread(&record, sizeof(struct door_state), 1, pfile);
    rewind(pfile);
    return record;
}
void write_record_in_file(FILE *pfile, const struct door_state *record_to_write, int index) {
    int offset = index * sizeof(struct door_state);
    fseek(pfile, offset, SEEK_SET);
    fwrite(record_to_write, sizeof(struct door_state), 1, pfile);
    fflush(pfile);
    rewind(pfile);
}
void swap_records_in_file(FILE *pfile, int record_index1, int record_index2) {
    struct door_state record1 = read_record_from_file(pfile, record_index1);
    struct door_state record2 = read_record_from_file(pfile, record_index2);
    write_record_in_file(pfile, &record1, record_index2);
    write_record_in_file(pfile, &record2, record_index1);
}
long get_file_size_in_bytes(FILE *pfile) {
    long size = 0;
    fseek(pfile, 0, SEEK_END);
    size = ftell(pfile);
    rewind(pfile);
    return size;
}

unsigned long get_records_count_in_file(FILE *pfile) {
    return get_file_size_in_bytes(pfile) / sizeof(struct door_state);
}
