#include "header.h"

#define BGR_SUM ((*image_pixels_mas)[i][j].blue + (*image_pixels_mas)[i][j].green + (*image_pixels_mas)[i][j].red)
#define GREEN (*image_pixels_mas)[i][j].green
#define BLUE (*image_pixels_mas)[i][j].blue
#define RED (*image_pixels_mas)[i][j].red
#define PIX_MAS_POINTER BGR_PIXEL ***image_pixels_mas
#define INFO BIT_MAP_INFO_HEADER info_header

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

BGR_PIXEL **read_pixels(FILE *f_image_bi, INFO) {
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

BGR_PIXEL **pixel_mas_copy(BGR_PIXEL **source, INFO) {
    BGR_PIXEL **image_pixels_mas = malloc(sizeof(BGR_PIXEL *) * info_header.bi_height);

    for (int i = 0; i < info_header.bi_height; i++) {
        image_pixels_mas[i] = malloc(sizeof(BGR_PIXEL) * info_header.bi_width);
        for (int j = 0; j < info_header.bi_width; j++) {
            image_pixels_mas[i][j].blue = source[i][j].blue;
            image_pixels_mas[i][j].green = source[i][j].green;
            image_pixels_mas[i][j].red = source[i][j].red;
        }
    }
    return image_pixels_mas;
}

void converting_image_monochrome(PIX_MAS_POINTER, INFO) {
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

void converting_image_negative(PIX_MAS_POINTER, INFO) {
    for (int i = 0; i < info_header.bi_height; i++) {
        for (int j = 0; j < info_header.bi_width; j++) {
            BLUE = 255 - BLUE;
            GREEN = 255 - GREEN;
            RED = 255 - RED;
        }
    }
}

void create_image_bmp(BIT_MAP_FILE_HEADER file_header, INFO, BGR_PIXEL **image_pixels_mas) {
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

void free_mas_pix(PIX_MAS_POINTER, INFO) {
    for (int i = 0; i < info_header.bi_height; i++) {
        free((*image_pixels_mas)[i]);
        (*image_pixels_mas)[i] = NULL;
    }
    free((*image_pixels_mas));
    (*image_pixels_mas) = NULL;
}

int brightness_cmp(BGR_PIXEL pix1, BGR_PIXEL pix2) {
    if (pix1.green + pix1.blue + pix1.red > pix2.green + pix2.blue + pix2.red)
        return 1;
    return 0;
}

void swap(BGR_PIXEL *a, BGR_PIXEL *b) {
    BGR_PIXEL temp = *a;
    *a = *b;
    *b = temp;
}

void insertion_sort_pixels(int len, BGR_PIXEL *mas) {
    for (int i = 1; i < len; i++)
        for (int j = i; j > 0 && brightness_cmp(mas[j - 1], mas[j]); j--)
            swap(&(mas[j - 1]), &(mas[j]));
}

BGR_PIXEL
get_medial_pixel(BGR_PIXEL **image_pixels_mas, int medial_par, int i, int j, INFO) {
    BGR_PIXEL *medial_pixel = (BGR_PIXEL *) calloc(medial_par * medial_par, sizeof(BGR_PIXEL));
    int k = 0;
    for (int x = 0; x < medial_par; x++) {
        for (int y = 0; y < medial_par; y++) {
            if ((i - medial_par / 2 + x) >= 0 && (j - medial_par / 2 + y) >= 0 &&
                (i - medial_par / 2 + x) < info_header.bi_height && (j - medial_par / 2 + y) < info_header.bi_width)
                medial_pixel[k] = image_pixels_mas[i - medial_par / 2 + x][j - medial_par / 2 + y];
            else {
                medial_pixel[k].red = 0;
                medial_pixel[k].green = 0;
                medial_pixel[k].blue = 0;
            }
            k++;
        }
    }
    insertion_sort_pixels(medial_par * medial_par, medial_pixel);
    return medial_pixel[k / 2 + 1];  //medial_par * medial_par / 2
}

void
medial_filtering(BGR_PIXEL ***source, PIX_MAS_POINTER, INFO, int medial_par) {
    for (int i = 0; i < info_header.bi_height; i++) {
        for (int j = 0; j < info_header.bi_width; j++) {
            (*image_pixels_mas)[i][j] = get_medial_pixel(*source, medial_par, i, j, info_header);
        }
    }
}