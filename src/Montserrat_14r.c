/*******************************************************************************
 * Size: 14 px
 * Bpp: 1
 * Opts: --bpp 1 --size 14 --no-compress --stride 1 --align 1 --font Montserrat-Regular.ttf --symbols 0123456789/*-+,.<>!@#$%^&*()_={}[];:'"`~?qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNMйцукенгшщзхъфывапролджэячсмитьбюЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮ --format lvgl -o Montserrat_14r.c
 ******************************************************************************/

#ifdef __has_include
    #if __has_include("lvgl.h")
        #ifndef LV_LVGL_H_INCLUDE_SIMPLE
            #define LV_LVGL_H_INCLUDE_SIMPLE
        #endif
    #endif
#endif

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif



#ifndef MONTSERRAT_14R
#define MONTSERRAT_14R 1
#endif

#if MONTSERRAT_14R

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0021 "!" */
    0xfe, 0x20,

    /* U+0022 "\"" */
    0xb6, 0xd0,

    /* U+0023 "#" */
    0x11, 0x8, 0x84, 0x8f, 0xf1, 0x21, 0x10, 0x89,
    0xff, 0x22, 0x11, 0x8, 0x80,

    /* U+0024 "$" */
    0x10, 0x21, 0xf6, 0x89, 0x12, 0x34, 0x1c, 0x16,
    0x24, 0x4c, 0xb7, 0xc2, 0x4, 0x0,

    /* U+0025 "%" */
    0x70, 0x91, 0x22, 0x24, 0x45, 0x8, 0xa0, 0xeb,
    0x82, 0x88, 0x51, 0x12, 0x24, 0x44, 0x87, 0x0,

    /* U+0026 "&" */
    0x38, 0x44, 0x44, 0x4c, 0x38, 0x30, 0x49, 0x85,
    0x86, 0xc7, 0x79,

    /* U+0027 "'" */
    0xf0,

    /* U+0028 "(" */
    0x49, 0x49, 0x24, 0x92, 0x24, 0x80,

    /* U+0029 ")" */
    0x49, 0x12, 0x49, 0x24, 0xa4, 0x80,

    /* U+002A "*" */
    0x25, 0x5d, 0xf2, 0x0,

    /* U+002B "+" */
    0x10, 0x20, 0x47, 0xf1, 0x2, 0x4, 0x0,

    /* U+002C "," */
    0xe0,

    /* U+002D "-" */
    0xf0,

    /* U+002E "." */
    0x80,

    /* U+002F "/" */
    0x8, 0x44, 0x21, 0x10, 0x84, 0x42, 0x11, 0x8,
    0x40,

    /* U+0030 "0" */
    0x3c, 0x62, 0x42, 0x81, 0x81, 0x81, 0x81, 0x81,
    0x42, 0x42, 0x3c,

    /* U+0031 "1" */
    0xe4, 0x92, 0x49, 0x24, 0x80,

    /* U+0032 "2" */
    0x3d, 0x8c, 0x8, 0x10, 0x20, 0x82, 0x8, 0x20,
    0x83, 0xf8,

    /* U+0033 "3" */
    0xfe, 0x8, 0x20, 0x41, 0x7, 0x81, 0x81, 0x3,
    0xd, 0xf0,

    /* U+0034 "4" */
    0x4, 0x2, 0x2, 0x2, 0x3, 0x21, 0x11, 0x9,
    0xff, 0x2, 0x1, 0x0, 0x80,

    /* U+0035 "5" */
    0x7e, 0x81, 0x2, 0x4, 0xf, 0x81, 0x81, 0x3,
    0xd, 0xf0,

    /* U+0036 "6" */
    0x3c, 0xc1, 0x4, 0x8, 0x17, 0xb1, 0xc1, 0x82,
    0x8c, 0xf0,

    /* U+0037 "7" */
    0xff, 0x6, 0x10, 0x20, 0xc1, 0x2, 0x8, 0x10,
    0x20, 0x80,

    /* U+0038 "8" */
    0x7c, 0xc6, 0x82, 0x82, 0xc6, 0x7c, 0xc3, 0x81,
    0x81, 0xc3, 0x3c,

    /* U+0039 "9" */
    0x79, 0x8a, 0xc, 0x18, 0x28, 0xde, 0x81, 0x4,
    0x9, 0xe0,

    /* U+003A ":" */
    0x81,

    /* U+003B ";" */
    0x81, 0xc0,

    /* U+003C "<" */
    0xc, 0xcc, 0x18, 0x18, 0x10,

    /* U+003D "=" */
    0xfc, 0x0, 0x3f,

    /* U+003E ">" */
    0xc0, 0xc0, 0xc6, 0x62, 0x0,

    /* U+003F "?" */
    0x7d, 0x8c, 0x8, 0x10, 0x61, 0x82, 0x8, 0x0,
    0x0, 0x40,

    /* U+0040 "@" */
    0xf, 0x81, 0x83, 0x18, 0xc, 0x8e, 0xa8, 0x8c,
    0xc8, 0x26, 0x41, 0x32, 0x9, 0x90, 0x4c, 0x46,
    0xd1, 0xdc, 0xc0, 0x3, 0x0, 0x7, 0xc0,

    /* U+0041 "A" */
    0xc, 0x3, 0x1, 0xa0, 0x48, 0x12, 0x8, 0x42,
    0x11, 0xfe, 0x40, 0x90, 0x28, 0x4,

    /* U+0042 "B" */
    0xfe, 0x83, 0x81, 0x81, 0x83, 0xfc, 0x83, 0x81,
    0x81, 0x83, 0xfe,

    /* U+0043 "C" */
    0x1e, 0x10, 0xd0, 0x10, 0x8, 0x4, 0x2, 0x1,
    0x0, 0x40, 0x30, 0xc7, 0x80,

    /* U+0044 "D" */
    0xfc, 0x41, 0xa0, 0x50, 0x18, 0xc, 0x6, 0x3,
    0x1, 0x81, 0x41, 0xbf, 0x0,

    /* U+0045 "E" */
    0xff, 0x2, 0x4, 0x8, 0x1f, 0xa0, 0x40, 0x81,
    0x3, 0xf8,

    /* U+0046 "F" */
    0xff, 0x2, 0x4, 0x8, 0x10, 0x3f, 0x40, 0x81,
    0x2, 0x0,

    /* U+0047 "G" */
    0x1f, 0x10, 0xd0, 0x10, 0x8, 0x4, 0x6, 0x3,
    0x1, 0x40, 0x90, 0xc7, 0xc0,

    /* U+0048 "H" */
    0x81, 0x81, 0x81, 0x81, 0x81, 0xff, 0x81, 0x81,
    0x81, 0x81, 0x81,

    /* U+0049 "I" */
    0xff, 0xe0,

    /* U+004A "J" */
    0x7c, 0x10, 0x41, 0x4, 0x10, 0x41, 0x7, 0x37,
    0x80,

    /* U+004B "K" */
    0x83, 0x86, 0x84, 0x88, 0x90, 0xb0, 0xc8, 0xcc,
    0x84, 0x82, 0x81,

    /* U+004C "L" */
    0x81, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x81,
    0x3, 0xf8,

    /* U+004D "M" */
    0x80, 0x70, 0x3c, 0xe, 0x85, 0xa1, 0x64, 0x99,
    0x26, 0x31, 0x8c, 0x60, 0x18, 0x4,

    /* U+004E "N" */
    0x81, 0xc1, 0xe1, 0xa1, 0xb1, 0x99, 0x8d, 0x85,
    0x87, 0x83, 0x81,

    /* U+004F "O" */
    0x1e, 0x18, 0x64, 0xa, 0x1, 0x80, 0x60, 0x18,
    0x6, 0x1, 0x40, 0x98, 0x61, 0xe0,

    /* U+0050 "P" */
    0xfc, 0x82, 0x81, 0x81, 0x81, 0x81, 0x82, 0xfc,
    0x80, 0x80, 0x80,

    /* U+0051 "Q" */
    0x1e, 0x18, 0x64, 0xa, 0x1, 0x80, 0x60, 0x18,
    0x6, 0x1, 0x40, 0x98, 0x61, 0xe0, 0x18, 0x3,
    0xc0,

    /* U+0052 "R" */
    0xfc, 0x82, 0x81, 0x81, 0x81, 0x81, 0x82, 0xfc,
    0x84, 0x82, 0x81,

    /* U+0053 "S" */
    0x7d, 0x82, 0x4, 0xc, 0x7, 0x1, 0x81, 0x3,
    0xd, 0xf0,

    /* U+0054 "T" */
    0xfe, 0x20, 0x40, 0x81, 0x2, 0x4, 0x8, 0x10,
    0x20, 0x40,

    /* U+0055 "U" */
    0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81,
    0x81, 0x42, 0x3c,

    /* U+0056 "V" */
    0x80, 0xd0, 0x24, 0x9, 0x84, 0x21, 0x8, 0xc1,
    0x20, 0x48, 0x1c, 0x3, 0x0, 0xc0,

    /* U+0057 "W" */
    0x82, 0x6, 0xc, 0x18, 0x30, 0x91, 0x42, 0x44,
    0x89, 0x12, 0x46, 0x89, 0xa, 0x14, 0x28, 0x70,
    0xc1, 0x81, 0x6, 0x0,

    /* U+0058 "X" */
    0x41, 0x30, 0x88, 0x82, 0x81, 0xc0, 0x40, 0x50,
    0x2c, 0x22, 0x20, 0x90, 0x60,

    /* U+0059 "Y" */
    0x80, 0xa0, 0x98, 0x44, 0x41, 0x40, 0xa0, 0x20,
    0x10, 0x8, 0x4, 0x2, 0x0,

    /* U+005A "Z" */
    0xff, 0x3, 0x2, 0x4, 0x8, 0x18, 0x10, 0x20,
    0x60, 0xc0, 0xff,

    /* U+005B "[" */
    0xf2, 0x49, 0x24, 0x92, 0x49, 0xc0,

    /* U+005D "]" */
    0xe4, 0x92, 0x49, 0x24, 0x93, 0xc0,

    /* U+005E "^" */
    0x0, 0xc3, 0x12, 0x49, 0x28, 0x40,

    /* U+005F "_" */
    0xfe,

    /* U+0060 "`" */
    0xc4,

    /* U+0061 "a" */
    0x7a, 0x30, 0x5f, 0x86, 0x18, 0xdd,

    /* U+0062 "b" */
    0x81, 0x2, 0x5, 0xcc, 0x50, 0x60, 0xc1, 0x83,
    0x8a, 0xe0,

    /* U+0063 "c" */
    0x3c, 0x8e, 0x4, 0x8, 0x10, 0x11, 0x9e,

    /* U+0064 "d" */
    0x2, 0x4, 0x9, 0xd4, 0x70, 0x60, 0xc1, 0x82,
    0x8c, 0xe8,

    /* U+0065 "e" */
    0x38, 0x8a, 0xf, 0xf8, 0x10, 0x11, 0x1e,

    /* U+0066 "f" */
    0x3a, 0x11, 0xe4, 0x21, 0x8, 0x42, 0x10,

    /* U+0067 "g" */
    0x3d, 0x43, 0x81, 0x81, 0x81, 0x81, 0x43, 0x3d,
    0x1, 0x42, 0x3c,

    /* U+0068 "h" */
    0x81, 0x2, 0x5, 0xec, 0x70, 0x60, 0xc1, 0x83,
    0x6, 0x8,

    /* U+0069 "i" */
    0x9f, 0xe0,

    /* U+006A "j" */
    0x10, 0x1, 0x11, 0x11, 0x11, 0x11, 0x16,

    /* U+006B "k" */
    0x81, 0x2, 0x4, 0x28, 0x92, 0x2c, 0x6c, 0x89,
    0xa, 0x8,

    /* U+006C "l" */
    0xff, 0xe0,

    /* U+006D "m" */
    0xbc, 0xf6, 0x38, 0xe0, 0x83, 0x4, 0x18, 0x20,
    0xc1, 0x6, 0x8, 0x30, 0x41,

    /* U+006E "n" */
    0xbd, 0x8e, 0xc, 0x18, 0x30, 0x60, 0xc1,

    /* U+006F "o" */
    0x38, 0x8a, 0xc, 0x18, 0x30, 0x51, 0x1c,

    /* U+0070 "p" */
    0xb9, 0x8a, 0xc, 0x18, 0x30, 0x71, 0x5c, 0x81,
    0x2, 0x0,

    /* U+0071 "q" */
    0x3a, 0x8e, 0xc, 0x18, 0x30, 0x51, 0x9d, 0x2,
    0x4, 0x8,

    /* U+0072 "r" */
    0xbc, 0x88, 0x88, 0x88,

    /* U+0073 "s" */
    0x7a, 0x8, 0x38, 0x1c, 0x18, 0x5e,

    /* U+0074 "t" */
    0x42, 0x3c, 0x84, 0x21, 0x8, 0x41, 0xc0,

    /* U+0075 "u" */
    0x83, 0x6, 0xc, 0x18, 0x30, 0x71, 0xbd,

    /* U+0076 "v" */
    0x82, 0x42, 0x42, 0x44, 0x24, 0x28, 0x18, 0x18,

    /* U+0077 "w" */
    0x82, 0x14, 0x61, 0x46, 0x24, 0x92, 0x29, 0x22,
    0x94, 0x30, 0xc1, 0xc,

    /* U+0078 "x" */
    0x42, 0xc8, 0xa0, 0xc1, 0x85, 0x11, 0x21,

    /* U+0079 "y" */
    0x82, 0x42, 0x42, 0x44, 0x24, 0x28, 0x18, 0x18,
    0x10, 0x30, 0xe0,

    /* U+007A "z" */
    0xfc, 0x20, 0x84, 0x21, 0x4, 0x3f,

    /* U+007B "{" */
    0x69, 0x24, 0xa2, 0x49, 0x24, 0xc0,

    /* U+007D "}" */
    0xc9, 0x24, 0x8a, 0x49, 0x25, 0x0,

    /* U+007E "~" */
    0xe6, 0x70,

    /* U+0410 "А" */
    0xc, 0x3, 0x0, 0xa0, 0x48, 0x11, 0x8, 0x42,
    0x10, 0xfe, 0x40, 0x90, 0x38, 0x4,

    /* U+0411 "Б" */
    0xfe, 0x80, 0x80, 0x80, 0x80, 0xfe, 0x83, 0x81,
    0x81, 0x83, 0xfe,

    /* U+0412 "В" */
    0xfc, 0x86, 0x82, 0x82, 0x86, 0xfe, 0x83, 0x81,
    0x81, 0x83, 0xfe,

    /* U+0413 "Г" */
    0xfe, 0x8, 0x20, 0x82, 0x8, 0x20, 0x82, 0x8,
    0x0,

    /* U+0414 "Д" */
    0x3f, 0x84, 0x10, 0x82, 0x10, 0x42, 0x8, 0x41,
    0x8, 0x21, 0x4, 0x20, 0x88, 0x13, 0xff, 0xc0,
    0x18, 0x2,

    /* U+0415 "Е" */
    0xff, 0x2, 0x4, 0x8, 0x1f, 0xa0, 0x40, 0x81,
    0x3, 0xf8,

    /* U+0416 "Ж" */
    0x82, 0xa, 0x10, 0x98, 0x8c, 0x44, 0x41, 0x24,
    0xf, 0xe0, 0xc9, 0x84, 0x44, 0x42, 0x12, 0x10,
    0xa0, 0x82,

    /* U+0417 "З" */
    0x79, 0xc, 0x8, 0x10, 0x67, 0x81, 0x81, 0x3,
    0xd, 0xe0,

    /* U+0418 "И" */
    0x81, 0x83, 0x87, 0x85, 0x89, 0x99, 0x91, 0xa1,
    0xe1, 0xc1, 0x81,

    /* U+0419 "Й" */
    0x24, 0x24, 0x38, 0x81, 0x83, 0x87, 0x85, 0x89,
    0x99, 0x91, 0xa1, 0xe1, 0xc1, 0x81,

    /* U+041A "К" */
    0x82, 0x82, 0x84, 0x88, 0x88, 0xf0, 0x88, 0x88,
    0x84, 0x82, 0x83,

    /* U+041B "Л" */
    0x3f, 0x90, 0x48, 0x24, 0x12, 0x9, 0x4, 0x82,
    0x41, 0x20, 0xa0, 0x70, 0x20,

    /* U+041C "М" */
    0x80, 0x70, 0x3c, 0xe, 0x85, 0xa1, 0x64, 0x99,
    0x26, 0x31, 0x8c, 0x60, 0x18, 0x4,

    /* U+041D "Н" */
    0x81, 0x81, 0x81, 0x81, 0x81, 0xff, 0x81, 0x81,
    0x81, 0x81, 0x81,

    /* U+041E "О" */
    0x1e, 0x18, 0x64, 0xa, 0x1, 0x80, 0x60, 0x18,
    0x6, 0x1, 0x40, 0x98, 0x61, 0xe0,

    /* U+041F "П" */
    0xff, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81,
    0x81, 0x81, 0x81,

    /* U+0420 "Р" */
    0xfc, 0x82, 0x81, 0x81, 0x81, 0x81, 0x82, 0xfc,
    0x80, 0x80, 0x80,

    /* U+0421 "С" */
    0x1e, 0x10, 0xd0, 0x10, 0x8, 0x4, 0x2, 0x1,
    0x0, 0x40, 0x30, 0xc7, 0x80,

    /* U+0422 "Т" */
    0xfe, 0x20, 0x40, 0x81, 0x2, 0x4, 0x8, 0x10,
    0x20, 0x40,

    /* U+0423 "У" */
    0x40, 0xa0, 0x48, 0x44, 0x23, 0x20, 0x90, 0x70,
    0x18, 0x8, 0xc, 0x1c, 0x0,

    /* U+0424 "Ф" */
    0x4, 0x3, 0xe1, 0x93, 0x62, 0x38, 0x43, 0x8,
    0x61, 0xe, 0x23, 0x64, 0xc3, 0xe0, 0x10, 0x0,

    /* U+0425 "Х" */
    0x41, 0x11, 0x88, 0x82, 0x81, 0xc0, 0x40, 0x50,
    0x2c, 0x22, 0x20, 0x90, 0x40,

    /* U+0426 "Ц" */
    0x81, 0x20, 0x48, 0x12, 0x4, 0x81, 0x20, 0x48,
    0x12, 0x4, 0x81, 0x20, 0x4f, 0xfc, 0x1, 0x0,
    0x40, 0x10,

    /* U+0427 "Ч" */
    0x81, 0x81, 0x81, 0x81, 0x81, 0x43, 0x3d, 0x1,
    0x1, 0x1, 0x1,

    /* U+0428 "Ш" */
    0x82, 0xc, 0x10, 0x60, 0x83, 0x4, 0x18, 0x20,
    0xc1, 0x6, 0x8, 0x30, 0x41, 0x82, 0xc, 0x10,
    0x7f, 0xfe,

    /* U+0429 "Щ" */
    0x82, 0x12, 0x8, 0x48, 0x21, 0x20, 0x84, 0x82,
    0x12, 0x8, 0x48, 0x21, 0x20, 0x84, 0x82, 0x12,
    0x8, 0x4f, 0xff, 0xc0, 0x1, 0x0, 0x4, 0x0,
    0x10,

    /* U+042A "Ъ" */
    0xf0, 0x2, 0x0, 0x40, 0x8, 0x1, 0xfc, 0x20,
    0xc4, 0x8, 0x81, 0x10, 0x22, 0x8, 0x7e, 0x0,

    /* U+042B "Ы" */
    0x80, 0x60, 0x18, 0x6, 0x1, 0xfe, 0x60, 0xd8,
    0x16, 0x5, 0x81, 0x60, 0x9f, 0xc4,

    /* U+042C "Ь" */
    0x80, 0x80, 0x80, 0x80, 0xfe, 0x83, 0x81, 0x81,
    0x81, 0x82, 0xfc,

    /* U+042D "Э" */
    0x3c, 0x21, 0x80, 0x40, 0x10, 0x8, 0xfc, 0x2,
    0x1, 0x1, 0x21, 0x8f, 0x0,

    /* U+042E "Ю" */
    0x83, 0xc4, 0x61, 0xa2, 0x5, 0x20, 0x19, 0x0,
    0xf8, 0x6, 0x40, 0x32, 0x1, 0x88, 0x14, 0x61,
    0xa0, 0xf0,

    /* U+042F "Я" */
    0x3f, 0x41, 0x81, 0x81, 0x81, 0x81, 0x41, 0x3f,
    0x21, 0x41, 0x81,

    /* U+0430 "а" */
    0x7a, 0x30, 0x5f, 0x86, 0x18, 0xdd,

    /* U+0431 "б" */
    0x3, 0x3c, 0x60, 0x40, 0xbc, 0xc2, 0xc1, 0x81,
    0x81, 0xc1, 0x62, 0x3c,

    /* U+0432 "в" */
    0xfa, 0x18, 0x7e, 0x86, 0x18, 0x7e,

    /* U+0433 "г" */
    0xfc, 0x21, 0x8, 0x42, 0x10,

    /* U+0434 "д" */
    0x3e, 0x11, 0x8, 0x84, 0x42, 0x21, 0x11, 0x9,
    0xff, 0x80, 0xc0, 0x40,

    /* U+0435 "е" */
    0x38, 0x8a, 0xf, 0xf8, 0x10, 0x11, 0x1e,

    /* U+0436 "ж" */
    0xc4, 0x68, 0x88, 0x92, 0x12, 0x43, 0xf8, 0x49,
    0x11, 0x16, 0x23,

    /* U+0437 "з" */
    0x78, 0x10, 0x4e, 0x4, 0x18, 0xde,

    /* U+0438 "и" */
    0x83, 0xe, 0x2c, 0xdb, 0x34, 0x70, 0xc1,

    /* U+0439 "й" */
    0x44, 0x70, 0x4, 0x18, 0x71, 0x66, 0xd9, 0xa3,
    0x86, 0x8,

    /* U+043A "к" */
    0x85, 0x12, 0x24, 0x8f, 0x12, 0x22, 0x42,

    /* U+043B "л" */
    0x3e, 0x44, 0x89, 0x12, 0x24, 0x58, 0xe1,

    /* U+043C "м" */
    0x81, 0xc3, 0xc3, 0xa5, 0xa5, 0x99, 0x91, 0x81,

    /* U+043D "н" */
    0x83, 0x6, 0xc, 0x1f, 0xf0, 0x60, 0xc1,

    /* U+043E "о" */
    0x38, 0x8a, 0xc, 0x18, 0x30, 0x51, 0x1c,

    /* U+043F "п" */
    0xff, 0x6, 0xc, 0x18, 0x30, 0x60, 0xc1,

    /* U+0440 "р" */
    0xb9, 0x8a, 0xc, 0x18, 0x30, 0x71, 0x5c, 0x81,
    0x2, 0x0,

    /* U+0441 "с" */
    0x3c, 0x8e, 0x4, 0x8, 0x10, 0x11, 0x9e,

    /* U+0442 "т" */
    0xfe, 0x20, 0x40, 0x81, 0x2, 0x4, 0x8,

    /* U+0443 "у" */
    0x82, 0x42, 0x42, 0x24, 0x24, 0x28, 0x18, 0x18,
    0x10, 0x10, 0xe0,

    /* U+0444 "ф" */
    0x8, 0x4, 0x2, 0x7, 0xc4, 0x94, 0x46, 0x23,
    0x11, 0x88, 0xa4, 0x8f, 0x81, 0x0, 0x80, 0x40,

    /* U+0445 "х" */
    0x42, 0xc8, 0xa0, 0xc1, 0x85, 0x11, 0x21,

    /* U+0446 "ц" */
    0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0xff,
    0x1, 0x1,

    /* U+0447 "ч" */
    0x86, 0x18, 0x61, 0x7c, 0x10, 0x41,

    /* U+0448 "ш" */
    0x84, 0x30, 0x86, 0x10, 0xc2, 0x18, 0x43, 0x8,
    0x61, 0xf, 0xff,

    /* U+0449 "щ" */
    0x84, 0x50, 0x8a, 0x11, 0x42, 0x28, 0x45, 0x8,
    0xa1, 0x17, 0xff, 0x0, 0x20, 0x4,

    /* U+044A "ъ" */
    0xe0, 0x20, 0x20, 0x3e, 0x21, 0x21, 0x21, 0x3e,

    /* U+044B "ы" */
    0x81, 0x81, 0x81, 0xf9, 0x85, 0x85, 0x85, 0xf9,

    /* U+044C "ь" */
    0x82, 0x8, 0x3e, 0x86, 0x18, 0x7e,

    /* U+044D "э" */
    0x79, 0x8, 0x9, 0xf0, 0x20, 0x61, 0x3c,

    /* U+044E "ю" */
    0x87, 0x22, 0x29, 0x7, 0xc1, 0x90, 0x64, 0x18,
    0x8a, 0x1c,

    /* U+044F "я" */
    0x7e, 0x18, 0x61, 0x7d, 0x14, 0x61
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 58, .box_w = 1, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2, .adv_w = 84, .box_w = 3, .box_h = 4, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 4, .adv_w = 156, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 17, .adv_w = 138, .box_w = 7, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 31, .adv_w = 186, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 47, .adv_w = 150, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 58, .adv_w = 45, .box_w = 1, .box_h = 4, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 59, .adv_w = 74, .box_w = 3, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 65, .adv_w = 74, .box_w = 3, .box_h = 14, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 71, .adv_w = 86, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 6},
    {.bitmap_index = 75, .adv_w = 129, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 82, .adv_w = 47, .box_w = 1, .box_h = 3, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 83, .adv_w = 86, .box_w = 4, .box_h = 1, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 84, .adv_w = 47, .box_w = 1, .box_h = 1, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 85, .adv_w = 75, .box_w = 5, .box_h = 14, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 94, .adv_w = 148, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 105, .adv_w = 81, .box_w = 3, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 110, .adv_w = 127, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 120, .adv_w = 126, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 130, .adv_w = 148, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 143, .adv_w = 127, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 153, .adv_w = 136, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 163, .adv_w = 132, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 173, .adv_w = 143, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 184, .adv_w = 136, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 194, .adv_w = 47, .box_w = 1, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 195, .adv_w = 47, .box_w = 1, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 197, .adv_w = 129, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 202, .adv_w = 129, .box_w = 6, .box_h = 4, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 205, .adv_w = 129, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 210, .adv_w = 127, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 220, .adv_w = 231, .box_w = 13, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 243, .adv_w = 161, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 257, .adv_w = 169, .box_w = 8, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 268, .adv_w = 159, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 281, .adv_w = 185, .box_w = 9, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 294, .adv_w = 150, .box_w = 7, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 304, .adv_w = 142, .box_w = 7, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 314, .adv_w = 173, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 327, .adv_w = 182, .box_w = 8, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 338, .adv_w = 68, .box_w = 1, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 340, .adv_w = 112, .box_w = 6, .box_h = 11, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 349, .adv_w = 159, .box_w = 8, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 360, .adv_w = 132, .box_w = 7, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 370, .adv_w = 214, .box_w = 10, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 384, .adv_w = 182, .box_w = 8, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 395, .adv_w = 188, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 409, .adv_w = 161, .box_w = 8, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 420, .adv_w = 188, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 437, .adv_w = 162, .box_w = 8, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 448, .adv_w = 138, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 458, .adv_w = 129, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 468, .adv_w = 177, .box_w = 8, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 479, .adv_w = 156, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 493, .adv_w = 249, .box_w = 14, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 513, .adv_w = 147, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 526, .adv_w = 142, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 539, .adv_w = 146, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 550, .adv_w = 71, .box_w = 3, .box_h = 14, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 556, .adv_w = 71, .box_w = 3, .box_h = 14, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 562, .adv_w = 129, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 568, .adv_w = 112, .box_w = 7, .box_h = 1, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 569, .adv_w = 134, .box_w = 3, .box_h = 2, .ofs_x = 2, .ofs_y = 9},
    {.bitmap_index = 570, .adv_w = 132, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 576, .adv_w = 152, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 586, .adv_w = 126, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 593, .adv_w = 152, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 603, .adv_w = 135, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 610, .adv_w = 76, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 617, .adv_w = 153, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 628, .adv_w = 151, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 638, .adv_w = 60, .box_w = 1, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 640, .adv_w = 61, .box_w = 4, .box_h = 14, .ofs_x = -2, .ofs_y = -3},
    {.bitmap_index = 647, .adv_w = 134, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 657, .adv_w = 60, .box_w = 1, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 659, .adv_w = 238, .box_w = 13, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 672, .adv_w = 151, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 679, .adv_w = 140, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 686, .adv_w = 152, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 696, .adv_w = 152, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 706, .adv_w = 90, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 710, .adv_w = 109, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 716, .adv_w = 91, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 723, .adv_w = 151, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 730, .adv_w = 121, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 738, .adv_w = 197, .box_w = 12, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 750, .adv_w = 120, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 757, .adv_w = 121, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 768, .adv_w = 114, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 774, .adv_w = 75, .box_w = 3, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 780, .adv_w = 75, .box_w = 3, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 786, .adv_w = 129, .box_w = 6, .box_h = 2, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 788, .adv_w = 167, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 802, .adv_w = 163, .box_w = 8, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 813, .adv_w = 168, .box_w = 8, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 824, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 833, .adv_w = 178, .box_w = 11, .box_h = 13, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 851, .adv_w = 148, .box_w = 7, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 861, .adv_w = 226, .box_w = 13, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 879, .adv_w = 139, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 889, .adv_w = 185, .box_w = 8, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 900, .adv_w = 185, .box_w = 8, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 914, .adv_w = 157, .box_w = 8, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 925, .adv_w = 176, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 938, .adv_w = 216, .box_w = 10, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 952, .adv_w = 184, .box_w = 8, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 963, .adv_w = 191, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 977, .adv_w = 185, .box_w = 8, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 988, .adv_w = 159, .box_w = 8, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 999, .adv_w = 160, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1012, .adv_w = 132, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1022, .adv_w = 152, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1035, .adv_w = 205, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1051, .adv_w = 146, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1064, .adv_w = 185, .box_w = 10, .box_h = 14, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 1082, .adv_w = 160, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1093, .adv_w = 245, .box_w = 13, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1111, .adv_w = 250, .box_w = 14, .box_h = 14, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 1136, .adv_w = 184, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1152, .adv_w = 219, .box_w = 10, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1166, .adv_w = 159, .box_w = 8, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1177, .adv_w = 158, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1190, .adv_w = 245, .box_w = 13, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1208, .adv_w = 164, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1219, .adv_w = 131, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1225, .adv_w = 148, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1237, .adv_w = 136, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1243, .adv_w = 106, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1248, .adv_w = 146, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1260, .adv_w = 138, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1267, .adv_w = 185, .box_w = 11, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1278, .adv_w = 120, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1284, .adv_w = 154, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1291, .adv_w = 154, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1301, .adv_w = 130, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1308, .adv_w = 142, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1315, .adv_w = 177, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1323, .adv_w = 151, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1330, .adv_w = 142, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1337, .adv_w = 151, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1344, .adv_w = 154, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1354, .adv_w = 126, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1361, .adv_w = 106, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1368, .adv_w = 125, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1379, .adv_w = 176, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1395, .adv_w = 118, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1402, .adv_w = 153, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1412, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1418, .adv_w = 208, .box_w = 11, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1429, .adv_w = 208, .box_w = 11, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1443, .adv_w = 139, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1451, .adv_w = 176, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1459, .adv_w = 126, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1465, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1472, .adv_w = 194, .box_w = 10, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1482, .adv_w = 136, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 33, .range_length = 59, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 93, .range_length = 31, .glyph_id_start = 60,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 125, .range_length = 2, .glyph_id_start = 91,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 1040, .range_length = 64, .glyph_id_start = 93,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 4,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif

};

extern const lv_font_t lv_font_montserrat_14;


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t Montserrat_14r = {
#else
lv_font_t Montserrat_14r = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 17,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .static_bitmap = 0,
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = &lv_font_montserrat_14,
#endif
    .user_data = NULL,
};



#endif /*#if MONTSERRAT_14R*/
