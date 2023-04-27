#include "header.h"

#define BGR_SUM ((*image_pixels_mas)[i][j].blue + (*image_pixels_mas)[i][j].green + (*image_pixels_mas)[i][j].red)
#define GREEN (*image_pixels_mas)[i][j].green
#define BLUE (*image_pixels_mas)[i][j].blue
#define RED (*image_pixels_mas)[i][j].red

const char *get_file_name() {
    char *name = calloc(1, 1);

    printf("Enter image name or address\n");
    gets(name);
    return (const char *) name;
}

int verify_bmp_file(const char *name_of_file) {
    if (strstr(name_of_file, ".bmp") == NULL)
        return 0;
    return 1;
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
    BGR_PIXEL **image_pixels_mas = malloc(sizeof(BGR_PIXEL *) * info_header.bi_height);
    int padding = (int) ((4 - (info_header.bi_width * sizeof(BGR_PIXEL)) % 4) % 4);

    for (int i = 0; i < info_header.bi_height; i++) {
        image_pixels_mas[i] = malloc(sizeof(BGR_PIXEL) * info_header.bi_width);
        for (int j = 0; j < info_header.bi_width; j++) {
            if (feof(f_image_bi)) {
                puts("ERROR_F");
                exit(1);
            }
            image_pixels_mas[i][j].blue = getc(f_image_bi);
            image_pixels_mas[i][j].green = getc(f_image_bi);
            image_pixels_mas[i][j].red = getc(f_image_bi);
            fseek(f_image_bi, padding, SEEK_CUR);
        }
    }
    return image_pixels_mas;
}

void converting_image_monochrome(BGR_PIXEL ***image_pixels_mas, BIT_MAP_INFO_HEADER info_header) {
    uint8_t gray_pixel;
    for (int i = 0; i < info_header.bi_height; i++) {
        for (int j = 0; j < info_header.bi_width; j++) {
            gray_pixel = BGR_SUM / 3;
            BLUE = gray_pixel;
            GREEN = gray_pixel;
            RED = gray_pixel;
        }
    }
}

void converting_image_negative(BGR_PIXEL ***image_pixels_mas, BIT_MAP_INFO_HEADER info_header) {
    for (int i = 0; i < info_header.bi_height; i++) {
        for (int j = 0; j < info_header.bi_width; j++) {
            BLUE = 255 - BLUE;
            GREEN = 255 - GREEN;
            RED = 255 - RED;
        }
    }
}

void create_image_bmp(BIT_MAP_FILE_HEADER file_header, BIT_MAP_INFO_HEADER info_header, BGR_PIXEL **image_pixels_mas) {
    FILE *f_image_bmp = fopen("photo_new.bmp", "wb");
    int padding = (int) ((4 - (info_header.bi_width * sizeof(BGR_PIXEL)) % 4) % 4);
    fwrite(&file_header, sizeof(file_header), 1, f_image_bmp);
    fwrite(&info_header, sizeof(info_header), 1, f_image_bmp);

    for (int i = 0; i < info_header.bi_height; i++) {
        fwrite(image_pixels_mas[i], sizeof(BGR_PIXEL), info_header.bi_width, f_image_bmp);
        fwrite(0x00, padding, 1, f_image_bmp);
    }
    fclose(f_image_bmp);
}

void free_mas_pix(BGR_PIXEL ***image_pixels_mas, BIT_MAP_INFO_HEADER info_header) {
    for (int i = 0; i < info_header.bi_height; i++) {
        free((*image_pixels_mas)[i]);
        (*image_pixels_mas)[i] = NULL;
    }
    free((*image_pixels_mas));
    (*image_pixels_mas) = NULL;
}