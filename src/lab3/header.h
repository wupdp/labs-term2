#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "stdint.h"


typedef struct {
    uint16_t bf_type;           //тип файла 2byte
    uint32_t bf_size;           //размер файла 4byte
    uint16_t bf_reserved1;      //зарезервированные поля 2byte
    uint16_t bf_reserved2;      //зарезервированные поля 2byte
    uint32_t bf_off_bits;       //смещение до битового массива
} BIT_MAP_FILE_HEADER;          //14byte

typedef struct {
    uint32_t bi_size;            // размер структуры
    int32_t bi_width;            // ширина изображения в пикселях
    int32_t bi_height;           // высота изображения в пикселях
    uint16_t bi_planes;          // количество цветовых плоскостей  ==1
    uint16_t bi_bit_count;        // бит на пиксель     24byte
    uint32_t bi_compression;     // тип сжатия
    uint32_t bi_size_image;       // размер массива данных о пикселях
    int32_t bi_x_pixels_per_meter;    // количество пикселей на метр по горизонтали
    int32_t bi_y_pixels_per_meter;    // количество пикселей на метр по вертикали
    uint32_t bi_clr_used;         // количество цветов в палитре
    uint32_t bi_clr_important;    // количество значимых цветов в палитре
} BIT_MAP_INFO_HEADER;          //40byte

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} BGR_PIXEL;

const char *get_file_name();

FILE *file_open(const char *name);

BIT_MAP_FILE_HEADER read_file_header(FILE *f_image_bi);

BIT_MAP_INFO_HEADER read_info_header(FILE *f_image_bi);

BGR_PIXEL **read_pixels(FILE *f_image_bi, BIT_MAP_INFO_HEADER info_header);