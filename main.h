#ifndef FT_CUBE_H
# define FT_CUBE_H

#include <unistd.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "mlx/mlx.h"

uint8_t cube[8][8];
uint16_t timer;
uint16_t modeTimer;
int8_t pos;
int loading;

#define INVERT_Y 1    // инвертировать по вертикали (если дождь идёт вверх)
#define INVERT_X 0    // инвертировать по горизонтали (если текст не читается)
#define MIRROR_FONT 1 // зеркалить текст

#define XAXIS 0
#define YAXIS 1
#define ZAXIS 2

#define POS_X 0
#define NEG_X 1
#define POS_Z 2
#define NEG_Z 3
#define POS_Y 4
#define NEG_Y 5


void renderCube();
void lit();
void setVoxel(uint8_t x, uint8_t y, uint8_t z);
void clearVoxel(uint8_t x, uint8_t y, uint8_t z);
bool getVoxel(uint8_t x, uint8_t y, uint8_t z);
void setPlane(uint8_t axis, uint8_t i);
void shift(uint8_t dir);
void drawCube(uint8_t x, uint8_t y, uint8_t z, uint8_t s);
void lightCube();
void clearCube();
void sinusFill();
void sinusThin();
void rain();
uint8_t getFont(uint8_t font, uint8_t row);
void text(char *someText, int8_t textLength);
void setVoxelSafe(uint8_t x, uint8_t y, uint8_t z);
void draw21(uint8_t x, uint8_t y, uint8_t z);

#endif