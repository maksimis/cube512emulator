// Функции из проекта AlexGyver для тестирования совместимости

#include "main.h"

int my_random(int lower, int upper)
{
	int num = (rand() %
			   (upper - lower + 1)) + lower;
	return num;
}

void rain() {
	if (loading) {
		clearCube();
		loading = false;
	}
	timer++;
	if (timer > modeTimer) {
		timer = 0;
		shift(NEG_Y);
		uint8_t numDrops = my_random(0, 5);
		for (uint8_t i = 0; i < numDrops; i++) {
			setVoxel(my_random(0, 8), 7, my_random(0, 8));
		}
	}
}

void sinusFill() {
	if (loading) {
		clearCube();
		loading = false;
	}
	timer++;
	if (timer > modeTimer) {
		timer = 0;
		clearCube();
		if (++pos > 10) pos = 0;
		for (uint8_t i = 0; i < 8; i++) {
			for (uint8_t j = 0; j < 8; j++) {
				int8_t sinZ = 4 + ((float)sin((float)(i + pos) / 2) * 2);
				for (uint8_t y = 0; y < sinZ; y++) {
					setVoxel(i, y, j);
				}
			}
		}
	}
}

void sinusThin() {
	if (loading) {
		clearCube();
		loading = false;
	}
	timer++;
	if (timer > modeTimer) {
		timer = 0;
		clearCube();
		if (++pos > 10) pos = 0;
		for (uint8_t i = 0; i < 8; i++) {
			for (uint8_t j = 0; j < 8; j++) {
				int8_t sinZ = 4 + ((float)sin((float)(i + pos) / 2) * 2);
				setVoxel(i, sinZ, j);
			}
		}
	}
}

//void rain() {
//	if (loading) {
//		clearCube();
//		loading = false;
//	}
//	timer++;
//	if (timer > modeTimer) {
//		timer = 0;
//		shift(NEG_Y);
//		uint8_t numDrops = random(0, 5);
//		for (uint8_t i = 0; i < numDrops; i++) {
//			setVoxel(random(0, 8), 7, random(0, 8));
//		}
//	}
//}

uint8_t charCounter = 0;
uint8_t charPosition = 0;

void text(char *someText, int8_t textLength) {
	if (loading) {
		clearCube();
		charPosition = -1;
		charCounter = 0;
		loading = false;
	}
	timer++;
	if (timer > modeTimer) {
		timer = 0;

		shift(NEG_Z);
		charPosition++;

		if (charPosition == 7) {
			charCounter++;
			if (charCounter > textLength - 1) {
				charCounter = 0;
//				if (showResult) {         // если играли в змейку и проиграли
//					showResult = false;     // опустить флаг
//					currentEffect = lastMode;     // включить прошлый режим
//					changeMode();           // активировать режим
//					return;                 // покинуть функцию text
//				}
			}
			charPosition = 0;
		}
		if (charPosition == 0) {
			for (uint8_t i = 0; i < 8; i++) {
				int8_t thisFont = getFont(someText[charCounter], i);
				int8_t mirrorFont = 0;
				for (int8_t i = 0; i < 7; i++) {
					if (thisFont & (1 << (6 - i))) mirrorFont |= (1 << i);
					else mirrorFont |= (0 << i);
				}
				if (MIRROR_FONT) cube[i][0] = mirrorFont;
				else cube[i][0] = thisFont;
			}
		}
	}
}

void lit() {
	if (loading) {
		clearCube();
		for (uint8_t i = 0; i < 8; i++) {
			for (uint8_t j = 0; j < 8; j++) {
				cube[i][j] = 0xFF;
			}
		}
		loading = false;
	}
}

void setVoxel(uint8_t x, uint8_t y, uint8_t z) {
	cube[7 - y][7 - z] |= (0x01 << x);
}

void clearVoxel(uint8_t x, uint8_t y, uint8_t z) {
	cube[7 - y][7 - z] ^= (0x01 << x);
}

bool getVoxel(uint8_t x, uint8_t y, uint8_t z) {
	return (cube[7 - y][7 - z] & (0x01 << x)) == (0x01 << x);
}

void setPlane(uint8_t axis, uint8_t i) {
	for (uint8_t j = 0; j < 8; j++) {
		for (uint8_t k = 0; k < 8; k++) {
			if (axis == XAXIS) {
				setVoxel(i, j, k);
			} else if (axis == YAXIS) {
				setVoxel(j, i, k);
			} else if (axis == ZAXIS) {
				setVoxel(j, k, i);
			}
		}
	}
}

void shift(uint8_t dir) {

	if (dir == POS_X) {
		for (uint8_t y = 0; y < 8; y++) {
			for (uint8_t z = 0; z < 8; z++) {
				cube[y][z] = cube[y][z] << 1;
			}
		}
	} else if (dir == NEG_X) {
		for (uint8_t y = 0; y < 8; y++) {
			for (uint8_t z = 0; z < 8; z++) {
				cube[y][z] = cube[y][z] >> 1;
			}
		}
	} else if (dir == POS_Y) {
		for (uint8_t y = 1; y < 8; y++) {
			for (uint8_t z = 0; z < 8; z++) {
				cube[y - 1][z] = cube[y][z];
			}
		}
		for (uint8_t i = 0; i < 8; i++) {
			cube[7][i] = 0;
		}
	} else if (dir == NEG_Y) {
		for (uint8_t y = 7; y > 0; y--) {
			for (uint8_t z = 0; z < 8; z++) {
				cube[y][z] = cube[y - 1][z];
			}
		}
		for (uint8_t i = 0; i < 8; i++) {
			cube[0][i] = 0;
		}
	} else if (dir == POS_Z) {
		for (uint8_t y = 0; y < 8; y++) {
			for (uint8_t z = 1; z < 8; z++) {
				cube[y][z - 1] = cube[y][z];
			}
		}
		for (uint8_t i = 0; i < 8; i++) {
			cube[i][7] = 0;
		}
	} else if (dir == NEG_Z) {
		for (uint8_t y = 0; y < 8; y++) {
			for (uint8_t z = 7; z > 0; z--) {
				cube[y][z] = cube[y][z - 1];
			}
		}
		for (uint8_t i = 0; i < 8; i++) {
			cube[i][0] = 0;
		}
	}
}

void drawCube(uint8_t x, uint8_t y, uint8_t z, uint8_t s) {
	for (uint8_t i = 0; i < s; i++) {
		setVoxel(x, y + i, z);
		setVoxel(x + i, y, z);
		setVoxel(x, y, z + i);
		setVoxel(x + s - 1, y + i, z + s - 1);
		setVoxel(x + i, y + s - 1, z + s - 1);
		setVoxel(x + s - 1, y + s - 1, z + i);
		setVoxel(x + s - 1, y + i, z);
		setVoxel(x, y + i, z + s - 1);
		setVoxel(x + i, y + s - 1, z);
		setVoxel(x + i, y, z + s - 1);
		setVoxel(x + s - 1, y, z + i);
		setVoxel(x, y + s - 1, z + i);
	}
}

void lightCube() {
	for (uint8_t i = 0; i < 8; i++) {
		for (uint8_t j = 0; j < 8; j++) {
			cube[i][j] = 0xFF;
		}
	}
}

void clearCube() {
	for (uint8_t i = 0; i < 8; i++) {
		for (uint8_t j = 0; j < 8; j++) {
			cube[i][j] = 0;
		}
	}
}