#include "header.h"

//TODO VERIFY BMP FILE
//TODO BLACK-WHITE

int main() {
    const char *name_of_file = get_file_name();
    FILE *f_image_bi = file_open(name_of_file);
    BIT_MAP_FILE_HEADER file_header = read_file_header(f_image_bi);
    BIT_MAP_INFO_HEADER info_header = read_info_header(f_image_bi);
    BGR_PIXEL **image_pixels_mas = read_pixels(f_image_bi, info_header);
    free_mas_pix(&image_pixels_mas, info_header);
    fclose(f_image_bi);
    return 0;
}
