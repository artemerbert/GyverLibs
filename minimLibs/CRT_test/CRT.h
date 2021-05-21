#ifndef CRT_h
#define CRT_h

// таблица для 8 бит CRT
static const uint8_t _CRTgammaPGM[256] PROGMEM = {
  0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
  2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 5,
  5, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 8,
  9, 10, 10, 10, 10, 11, 11, 12, 12, 12, 12, 13, 13, 13, 14, 14,
  15, 15, 15, 16, 17, 17, 17, 17, 18, 18, 19, 20, 20, 20, 20, 21,
  22, 22, 23, 23, 23, 24, 25, 25, 26, 26, 27, 27, 28, 28, 29, 30,
  30, 31, 31, 32, 33, 33, 34, 35, 35, 36, 37, 37, 38, 38, 39, 40,
  41, 41, 42, 43, 44, 45, 45, 46, 47, 47, 48, 49, 50, 51, 52, 53,
  54, 54, 55, 56, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67,
  68, 69, 69, 70, 71, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 84,
  85, 86, 87, 89, 90, 91, 93, 94, 95, 96, 97, 98, 100, 101, 102, 103,
  105, 106, 108, 109, 110, 111, 113, 115, 117, 118, 119, 121, 122, 123, 124, 127,
  128, 130, 131, 133, 134, 136, 137, 139, 140, 143, 145, 146, 147, 148, 151, 153,
  154, 156, 158, 159, 162, 163, 165, 167, 169, 171, 173, 174, 176, 179, 180, 182,
  185, 186, 188, 190, 192, 194, 196, 199, 201, 202, 205, 207, 209, 211, 214, 216,
  218, 220, 223, 225, 226, 230, 231, 235, 236, 240, 241, 245, 246, 250, 251, 255,
};

// 8 бит CRT из таблицы
uint8_t CRT8_table(uint8_t val) {
  return pgm_read_byte(&(_CRTgammaPGM[val]));
}

// 8 бит CRT квадратичный
uint8_t CRT8_square(uint8_t val) {
  return ((long)val * val + 255) >> 8;  
}

// 10 бит CRT квадратичный
int CRT10_square(int val) {
  return ((long)val * val + 1023) >> 10;
}

// 8 бит CRT кубический
uint8_t CRT8_cubic(uint8_t val) {
  return ((long)val * val * val + 130305) >> 16;
}

// 10 бит CRT кубический
int CRT10_cubic(int val) {
  return ((long)val * val * val + 2094081) >> 20;
}

#endif