#include "main.h"
#include <time.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

t_vars	vars;

// Режим школы 21 старт

int shift_21 = 8;
// Режимы презентации 21
int s21_mode = 0;
// 0 z шифт
// 1 y шифт
// 1 x шифт
int s21_mode_count = 6;
void falling21(uint8_t x, uint8_t y, uint8_t z);
void escaping21(uint8_t x, uint8_t y, uint8_t z);
void hearbeat();
void school21() {
	if (loading) {
		clearCube();
		loading = false;
	}
	timer++;
	if (timer > modeTimer) {
		timer = 0;
		clearCube();
		if (shift_21 < -7)
		{
			shift_21 = 8;
			s21_mode++;
		}
		if (s21_mode >= s21_mode_count)
			s21_mode = 0;
		clearCube();
		switch (s21_mode) {
			case 0:
				falling21(1, 1, 3);
				falling21(1, 1, 4);
				break;
			case 1:
				hearbeat();
				break;
			case 2:
				escaping21(1, 1, 3);
				escaping21(1, 1, 4);
				break;
			case 3:
				draw21(1, 1, shift_21);
				draw21(1, 1, shift_21 + 1);
				shift_21--;
				if (shift_21 < -1)
					shift_21 = -8;
				break;
			case 4:
				draw21(1, shift_21 + 1, 3);
				draw21(1, shift_21 + 1,  4);
				shift_21--;
				break;
			case 5:
				draw21(1 + shift_21, 1, 3);
				draw21(1 + shift_21, 1,  4);
				shift_21--;
				break;
			default:
				break;
		}
	}
}

void draw21(uint8_t x, uint8_t y, uint8_t z) {
	// 2
	setVoxelSafe( x + 0, y + 4, z);
	setVoxelSafe( x + 1, y + 4, z);
	setVoxelSafe( x + 2, y + 4, z);
	setVoxelSafe( x + 0, y + 3, z);
	setVoxelSafe( x + 0, y + 2, z);
	setVoxelSafe( x + 1, y + 2, z);
	setVoxelSafe( x + 2, y + 2, z);
	setVoxelSafe( x + 2, y + 1, z);
	setVoxelSafe( x + 0, y + 0, z);
	setVoxelSafe( x + 1, y + 0, z);
	setVoxelSafe( x + 2, y + 0, z);
	// 1
	setVoxelSafe( x + 5, y + 4, z);
	setVoxelSafe( x + 5, y + 3, z);
	setVoxelSafe( x + 5, y + 2, z);
	setVoxelSafe( x + 5, y + 1, z);
	setVoxelSafe( x + 4, y + 0, z);
	setVoxelSafe( x + 5, y + 0, z);
}

int falling21_step = 0;
int falling21_step1 = -8;
int falling21_step2 = -8;
int falling21_step3 = -8;
int falling21_step4 = -8;
int falling21_step5 = -8;
int falling21_step6 = -8;
int falling21_step7 = -8;
int falling21_step8 = -8;
int falling21_step9 = -8;
int falling21_step10 = -8;
int falling21_step11 = -8;
int falling21_step12 = -8;
int falling21_step13 = -8;
int falling21_step14 = -8;
int falling21_step15 = -8;
int falling21_step16 = -8;
int falling21_step17 = -8;

void falling21(uint8_t x, uint8_t y, uint8_t z) {
	if (falling21_step > 60) {
		falling21_step = 0;
		falling21_step1 = -8;
		falling21_step2 = -8;
		falling21_step3 = -8;
		falling21_step4 = -8;
		falling21_step5 = -8;
		falling21_step6 = -8;
		falling21_step7 = -8;
		falling21_step8 = -8;
		falling21_step9 = -8;
		falling21_step10 = -8;
		falling21_step11 = -8;
		falling21_step12 = -8;
		falling21_step13 = -8;
		falling21_step14 = -8;
		falling21_step15 = -8;
		falling21_step16 = -8;
		falling21_step17 = -8;
		s21_mode++;
	}
	if (falling21_step > 0 && falling21_step17 < 0)
		falling21_step17++;
	if (falling21_step > 3 && falling21_step16 < 0)
		falling21_step16++;
	if (falling21_step > 6 && falling21_step15 < 0)
		falling21_step15++;
	if (falling21_step > 9 && falling21_step14 < 0)
		falling21_step14++;
	if (falling21_step > 12 && falling21_step13 < 0)
		falling21_step13++;
	if (falling21_step > 15 && falling21_step12 < 0)
		falling21_step12++;
	if (falling21_step > 18 && falling21_step11 < 0)
		falling21_step11++;
	if (falling21_step > 21 && falling21_step10 < 0)
		falling21_step10++;
	if (falling21_step > 24 && falling21_step9 < 0)
		falling21_step9++;
	if (falling21_step > 27 && falling21_step8 < 0)
		falling21_step8++;
	if (falling21_step > 30 && falling21_step7 < 0)
		falling21_step7++;
	if (falling21_step > 33 && falling21_step6 < 0)
		falling21_step6++;
	if (falling21_step > 36 && falling21_step5 < 0)
		falling21_step5++;
	if (falling21_step > 39 && falling21_step4 < 0)
		falling21_step4++;
	if (falling21_step > 42 && falling21_step3 < 0)
		falling21_step3++;
	if (falling21_step > 45 && falling21_step2 < 0)
		falling21_step2++;
	if (falling21_step > 48 && falling21_step1 < 0)
		falling21_step1++;
	// 2
	setVoxelSafe( x + 0, y + 4 + falling21_step17, z);
	setVoxelSafe( x + 1, y + 4 + falling21_step15, z);
	setVoxelSafe( x + 2, y + 4 + falling21_step14, z);
	setVoxelSafe( x + 0, y + 3 + falling21_step12, z);
	setVoxelSafe( x + 0, y + 2 + falling21_step11, z);
	setVoxelSafe( x + 1, y + 2 + falling21_step9, z);
	setVoxelSafe( x + 2, y + 2 + falling21_step8, z);
	setVoxelSafe( x + 2, y + 1 + falling21_step7, z);
	setVoxelSafe( x + 0, y + 0 + falling21_step5, z);
	setVoxelSafe( x + 1, y + 0 + falling21_step3, z);
	setVoxelSafe( x + 2, y + 0 + falling21_step1, z);
	// 1
	setVoxelSafe( x + 5, y + 4 + falling21_step16, z);
	setVoxelSafe( x + 5, y + 3 + falling21_step13, z);
	setVoxelSafe( x + 5, y + 2 + falling21_step10, z);
	setVoxelSafe( x + 5, y + 1 + falling21_step6, z);
	setVoxelSafe( x + 4, y + 0 + falling21_step4, z);
	setVoxelSafe( x + 5, y + 0 + falling21_step2, z);
	falling21_step++;
}

int escaping21_step = 0;
int escaping21_step1 = 0;
int escaping21_step2 = 0;
int escaping21_step3 = 0;
int escaping21_step4 = 0;
int escaping21_step5 = 0;
int escaping21_step6 = 0;
int escaping21_step7 = 0;
int escaping21_step8 = 0;
int escaping21_step9 = 0;
int escaping21_step10 = 0;
int escaping21_step11 = 0;
int escaping21_step12 = 0;
int escaping21_step13 = 0;
int escaping21_step14 = 0;
int escaping21_step15 = 0;
int escaping21_step16 = 0;
int escaping21_step17 = 0;

void escaping21(uint8_t x, uint8_t y, uint8_t z) {
	if (escaping21_step > 56) {
		escaping21_step = 0;
		escaping21_step1 = 0;
		escaping21_step2 = 0;
		escaping21_step3 = 0;
		escaping21_step4 = 0;
		escaping21_step5 = 0;
		escaping21_step6 = 0;
		escaping21_step7 = 0;
		escaping21_step8 = 0;
		escaping21_step9 = 0;
		escaping21_step10 = 0;
		escaping21_step11 = 0;
		escaping21_step12 = 0;
		escaping21_step13 = 0;
		escaping21_step14 = 0;
		escaping21_step15 = 0;
		escaping21_step16 = 0;
		escaping21_step17 = 0;
		s21_mode++;
	} else {
		if (escaping21_step > 0 && escaping21_step17 < 8)
			escaping21_step17++;
		if (escaping21_step > 3 && escaping21_step16 < 8)
			escaping21_step16++;
		if (escaping21_step > 6 && escaping21_step15 < 8)
			escaping21_step15++;
		if (escaping21_step > 9 && escaping21_step14 < 8)
			escaping21_step14++;
		if (escaping21_step > 12 && escaping21_step13 < 8)
			escaping21_step13++;
		if (escaping21_step > 15 && escaping21_step12 < 8)
			escaping21_step12++;
		if (escaping21_step > 18 && escaping21_step11 < 8)
			escaping21_step11++;
		if (escaping21_step > 21 && escaping21_step10 < 8)
			escaping21_step10++;
		if (escaping21_step > 24 && escaping21_step9 < 8)
			escaping21_step9++;
		if (escaping21_step > 27 && escaping21_step8 < 8)
			escaping21_step8++;
		if (escaping21_step > 30 && escaping21_step7 < 8)
			escaping21_step7++;
		if (escaping21_step > 33 && escaping21_step6 < 8)
			escaping21_step6++;
		if (escaping21_step > 36 && escaping21_step5 < 8)
			escaping21_step5++;
		if (escaping21_step > 39 && escaping21_step4 < 8)
			escaping21_step4++;
		if (escaping21_step > 42 && escaping21_step3 < 8)
			escaping21_step3++;
		if (escaping21_step > 45 && escaping21_step2 < 8)
			escaping21_step2++;
		if (escaping21_step > 48 && escaping21_step1 < 8)
			escaping21_step1++;
		// 2
		setVoxelSafe( x + 0, y + 4 + escaping21_step17, z);
		setVoxelSafe( x + 1, y + 4 + escaping21_step15, z);
		setVoxelSafe( x + 2, y + 4 + escaping21_step14, z);
		setVoxelSafe( x + 0, y + 3 + escaping21_step12, z);
		setVoxelSafe( x + 0, y + 2 + escaping21_step11, z);
		setVoxelSafe( x + 1, y + 2 + escaping21_step9, z);
		setVoxelSafe( x + 2, y + 2 + escaping21_step8, z);
		setVoxelSafe( x + 2, y + 1 + escaping21_step7, z);
		setVoxelSafe( x + 0, y + 0 + escaping21_step5, z);
		setVoxelSafe( x + 1, y + 0 + escaping21_step3, z);
		setVoxelSafe( x + 2, y + 0 + escaping21_step1, z);
		// 1
		setVoxelSafe( x + 5, y + 4 + escaping21_step16, z);
		setVoxelSafe( x + 5, y + 3 + escaping21_step13, z);
		setVoxelSafe( x + 5, y + 2 + escaping21_step10, z);
		setVoxelSafe( x + 5, y + 1 + escaping21_step6, z);
		setVoxelSafe( x + 4, y + 0 + escaping21_step4, z);
		setVoxelSafe( x + 5, y + 0 + escaping21_step2, z);
	}
	escaping21_step++;
}

int hearbeat_tick = 0;

void drawSmallHeart(uint8_t x, uint8_t y, uint8_t z) {
	setVoxelSafe(x + 0, y + 0, z);
	setVoxelSafe(x + 0, y + 1, z);
	setVoxelSafe(x + 1, y + 1, z);
	setVoxelSafe(x + 1, y + 2, z);
	setVoxelSafe(x + 2, y + 0, z);
	setVoxelSafe(x + 2, y + 1, z);
}

void drawMediumHeart(uint8_t x, uint8_t y, uint8_t z) {
	setVoxelSafe(x + 1, y + 0, z);
	setVoxelSafe(x + 3, y + 0, z);
	setVoxelSafe(x + 0, y + 1, z);
	setVoxelSafe(x + 2, y + 1, z);
	setVoxelSafe(x + 4, y + 1, z);
	setVoxelSafe(x + 0, y + 2, z);
	setVoxelSafe(x + 4, y + 2, z);
	setVoxelSafe(x + 1, y + 3, z);
	setVoxelSafe(x + 3, y + 3, z);
	setVoxelSafe(x + 2, y + 4, z);
}

void drawBigHeart(uint8_t x, uint8_t y, uint8_t z) {
	setVoxelSafe(x + 1, y + 0, z);
	setVoxelSafe(x + 2, y + 0, z);
	setVoxelSafe(x + 4, y + 0, z);
	setVoxelSafe(x + 5, y + 0, z);
	setVoxelSafe(x + 0, y + 1, z);
	setVoxelSafe(x + 3, y + 1, z);
	setVoxelSafe(x + 6, y + 1, z);
	setVoxelSafe(x + 0, y + 2, z);
	setVoxelSafe(x + 6, y + 2, z);
	setVoxelSafe(x + 0, y + 3, z);
	setVoxelSafe(x + 6, y + 3, z);
	setVoxelSafe(x + 5, y + 4, z);
	setVoxelSafe(x + 1, y + 4, z);
	setVoxelSafe(x + 2, y + 5, z);
	setVoxelSafe(x + 4, y + 5, z);
	setVoxelSafe(x + 3, y + 0, z);
}

void hearbeat() {
	if (hearbeat_tick > 35)
	{
		s21_mode++;
		hearbeat_tick = 0;
	}
	switch (hearbeat_tick) {
		case 1:
			setVoxelSafe(3, 3, 3);
			break;
		case 2:
			drawSmallHeart(2, 2, 3);
			drawSmallHeart(2, 2, 4);
			break;
		case 3:
			drawMediumHeart(1, 1, 3);
			drawMediumHeart(1, 1, 4);
			break;
		case 4:
			drawBigHeart(0, 0, 3);
			drawBigHeart(0, 0, 4);
			break;
		case 5:
			drawBigHeart(0, 0, 3);
			drawBigHeart(0, 0, 4);
			break;
		case 6:
			drawMediumHeart(1, 1, 3);
			drawMediumHeart(1, 1, 4);
			break;
		case 7:
			drawSmallHeart(2, 2, 3);
			drawSmallHeart(2, 2, 4);
			break;
		case 8:
			setVoxelSafe(3, 3, 3);
			break;
		case 9:
			setVoxelSafe(3, 4, 3);
			break;
		case 10:
			drawSmallHeart(2, 3, 3);
			drawSmallHeart(2, 3, 4);
			break;
		case 11:
			drawMediumHeart(1, 2, 3);
			drawMediumHeart(1, 2, 4);
			break;
		case 12:
			drawBigHeart(0, 1, 3);
			drawBigHeart(0, 1, 4);
			break;
		case 13:
			drawBigHeart(0, 1, 3);
			drawBigHeart(0, 1, 4);
			break;
		case 14:
			drawMediumHeart(1, 2, 3);
			drawMediumHeart(1, 2, 4);
			break;
		case 15:
			drawSmallHeart(2, 3, 3);
			drawSmallHeart(2, 3, 4);
			break;
		case 16:
			setVoxelSafe(3, 4, 3);
			break;
		case 17:
			setVoxelSafe(4, 3, 3);
			break;
		case 18:
			drawSmallHeart(3, 2, 3);
			drawSmallHeart(3, 2, 4);
			break;
		case 19:
			drawMediumHeart(2, 1, 3);
			drawMediumHeart(2, 1, 4);
			break;
		case 20:
			drawBigHeart(1, 0, 3);
			drawBigHeart(1, 0, 4);
			break;
		case 21:
			drawBigHeart(1, 0, 3);
			drawBigHeart(1, 0, 4);
			break;
		case 22:
			drawMediumHeart(2, 1, 3);
			drawMediumHeart(2, 1, 4);
			break;
		case 23:
			drawSmallHeart(3, 2, 3);
			drawSmallHeart(3, 2, 4);
			break;
		case 24:
			setVoxelSafe(4, 3, 3);
			break;
		case 25:
			setVoxelSafe(4, 4, 3);
			break;
		case 26:
			drawSmallHeart(3, 3, 3);
			drawSmallHeart(3, 3, 4);
			break;
		case 27:
			drawMediumHeart(2, 2, 3);
			drawMediumHeart(2, 2, 4);
			break;
		case 28:
			drawBigHeart(1, 1, 3);
			drawBigHeart(1, 1, 4);
			break;
		case 29:
			drawBigHeart(1, 1, 3);
			drawBigHeart(1, 1, 4);
			break;
		case 30:
			drawMediumHeart(2, 2, 3);
			drawMediumHeart(2, 2, 4);
			break;
		case 31:
			drawSmallHeart(3, 3, 3);
			drawSmallHeart(3, 3, 4);
			break;
		case 32:
			setVoxelSafe(4, 4, 3);
			break;
		default:
			draw21(1, 1, 3);
			draw21(1, 1, 4);
			break;
	}
	hearbeat_tick++;
}

// Режим школы 21 финиш

// Дополнительная функция, которую надо скопировать в скетч, чтобы не париться по поводу
// прорисовки за пределами куба
void setVoxelSafe(uint8_t x, uint8_t y, uint8_t z) {
	if (x >= 0 && x <= 7 && y >= 0 && y <= 7 && z >= 0 && z <= 7)
		setVoxel(x, y, z);
}

void renderNext()
{
	//school21();
	 rain();
	// text("Хаюшки", 6);
	renderCube();
}

int	key_hook(int keycode, t_vars *vars)
{
	printf("Key pressed!\n");
	mlx_clear_window(vars->mlx, vars->win);
	renderNext();
	return (0);
}

int main(int argc, char **argv)
{

	clearCube();
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1280, 1080, "Cube 512");
	timer = 0;
	modeTimer = 0;
	pos = 0;
	loading = 0;

	mlx_clear_window(vars.mlx, vars.win);
	renderNext();
	mlx_key_hook(vars.win, key_hook, &vars);

	mlx_loop(vars.mlx);
	return (1);
}

// Размер между светодиодами
int size = 100;
// Пропорция по высоте
int left_prop = 15;
// Пропорция по ширине
int right_prop = 50;
// Цвет основного пикселя
int low_color = 0xFFFFFF;
// Цвет светящегося пикселя
int hight_color = 0xFF0000;

// Отрисовка "светящегося" пикселя
void put_big_pixel(int x, int y) {
	mlx_pixel_put(vars.mlx, vars.win, x-1, y, hight_color);
	mlx_pixel_put(vars.mlx, vars.win, x-2, y, hight_color);
	mlx_pixel_put(vars.mlx, vars.win, x, y, hight_color);
	mlx_pixel_put(vars.mlx, vars.win, x+1, y, hight_color);
	mlx_pixel_put(vars.mlx, vars.win, x+2, y, hight_color);
	mlx_pixel_put(vars.mlx, vars.win, x, y-1, hight_color);
	mlx_pixel_put(vars.mlx, vars.win, x, y-2, hight_color);
	mlx_pixel_put(vars.mlx, vars.win, x, y, hight_color);
	mlx_pixel_put(vars.mlx, vars.win, x, y + 1, hight_color);
	mlx_pixel_put(vars.mlx, vars.win, x, y + 2, hight_color);
}
// Отрисовка линии в кубе
void renderLine(uint8_t l, uint8_t i, uint8_t j) {
	for (uint8_t z = 0; z < 8; z++) {
		int y = 100 + i * size + j * left_prop;
		int x = size * (z + 1) + j * right_prop;
		if (l & (1 << z))
		{
			put_big_pixel(x, y);
		} else
		{
			mlx_pixel_put(vars.mlx, vars.win, x, y, low_color);
		}
	}
}
// Отрисовка куба
void renderCube() {
	for (uint8_t i = 0; i < 8; i++) {
		if (INVERT_Y) {
			for (uint8_t j = 0; j < 8; j++) {
				if (INVERT_X) renderLine(cube[i][j], i, j);
				else renderLine(cube[7 - i][j], i, j);
			}
		} else {
			for (uint8_t j = 0; j < 8; j++) {
				if (INVERT_X) renderLine(cube[7 - i][j], i, j);
				else renderLine(cube[i][j], i, j);
			}
		}
	}
}
