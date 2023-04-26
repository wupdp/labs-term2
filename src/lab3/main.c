#include "header.h"

int main() {
    const char* name_of_file = get_file_name();
    FILE* f_image_bi = file_open(name_of_file);
    BIT_MAP_FILE_HEADER file_header;
}
