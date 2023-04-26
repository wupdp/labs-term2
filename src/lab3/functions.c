#include "header.h"

const char *get_file_name() {
    char *name = calloc(1, 1);

    printf("Enter image name or address\n");
    gets(name);
    return (const char *) name;
}

FILE *file_open(const char *name) {
    FILE *f_image_bi = fopen(name, "rb");

    if (f_image_bi == NULL) {
        printf("File is not exist\n");
        exit(EXIT_SUCCESS);
    }
    return f_image_bi;
}

BIT_MAP_FILE_HEADER read_file_header(FILE *f_image_bi) {
    BIT_MAP_FILE_HEADER file_header;

    fread(&file_header, sizeof(BIT_MAP_FILE_HEADER), 1, f_image_bi);
    return file_header;
}

BIT_MAP_INFO_HEADER read_info_header(FILE *f_image_bi) {
    BIT_MAP_INFO_HEADER info_header;

    fread(&info_header, sizeof(BIT_MAP_INFO_HEADER), 1, f_image_bi);
    return info_header;
}

BGR_PIXEL **read_pixels(FILE *f_image_bi, BIT_MAP_INFO_HEADER info_header) {
    BGR_PIXEL **image_pixels = malloc(sizeof(BGR_PIXEL *) * info_header.bi_height);
    int padding = (int) ((4 - (info_header.bi_width * sizeof(BGR_PIXEL)) % 4) % 4);

    for (int i = 0; i < info_header.bi_height; i++) {
        image_pixels[i] = malloc(sizeof(BGR_PIXEL) * info_header.bi_width);
        for (int j = 0; j < info_header.bi_width; j++) {
            if (feof(f_image_bi))
                puts("ERROR_F");
            image_pixels[i][j].blue = getc(f_image_bi);
            image_pixels[i][j].green = getc(f_image_bi);
            image_pixels[i][j].red = getc(f_image_bi);
            fseek(f_image_bi, padding, SEEK_CUR);
        }
    }
    return image_pixels;
}
