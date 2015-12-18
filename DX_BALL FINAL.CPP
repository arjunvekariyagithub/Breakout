#include<stdio.h>
#include<conio.h>
#include<bios.h>
#include<graphics.h>
#include<dos.h>
#include<iostream.h>
#include<stdlib.h>
#include<ctype.h>
#define TRUE 1
#define FALSE 0

int x = 325, y = 455, X = 600, Y = 455, z, L_X = 275, R_X = 375, temp = TRUE,
		sec = 5, color = 15, cir_col = 0;
int rec_col = 0, exist[95], fun_var, decide_dir, slide_col = 15, n, GUN = 0,
		goli_ex = 1;
int rec_1x[95], rec_2x[95], rec_3x[95], rec_4x[95], rec_1y[95], rec_2y[95], no,
		i, j;
int rec_3y[95], rec_4y[95], poly[8], ball_col = 15, ball_style = 2, GOLY_X,
		GOLY_Y;
int mx, my, cho, magnate = FALSE, score = 0, round = 1, start, ball_size = 3,
		slide_size = 100;
int rec_lx[95], rec_rx[95], rec_y_tp[95], rec_y_bm[95], tp = 460, bm = 470,
		slide_2 = 0;
int tp2 = 10, bm2 = 20, incr_paddle_size = 0, life = 3, glob = 1;
char *main_menu[] = { { "1. Play" }, { "2. Options" }, { "3. Level" }, {
		"4. Game Rounds" } };
char *ball_colour[] = { { "1. BLUE" }, { "2. GREEN " }, { "3. BLINKING" }, {
		"4. RED" }, { "5. MAGENTA" } };
char *OPTION[] = { { "1. Ball Size" }, { "2. Ball Colours" }, {
		"3. Ball Patterns" }, { "4. Slide colours" }, { "5. Slide Size" } };
char *level[] = { { "1. Beginner" }, { "2. Intermediate" }, { "3. Expert" }, {
		"4. Return to Main menu" } };
char *ball_pat[] = { { "1. Style1" }, { "2. Style2" }, { "3. Style3" }, {
		"4. Style4" }, { "5. Style5" } };
char *BALL_SIZE[] = { { "1. Very Small " }, { "2. Small" }, { "3. Medium" }, {
		"4. BIG" }, { "5. Extra Big" } };
char *SLIDE_SIZE[] = { { "1. Very Small " }, { "2. Small" }, { "3. Medium" }, {
		"4. Long" }, { "5. Extra Long" } };

char *ROU[] = { { "1. Round1" }, { "2. Round2" } };
char *rou[] = { { "Round1" }, { "Round2" } };

char *m_m[] = { "P", "O", "L", "G" }; //"H","E"};
char *b_c[] = { "B", "G", "B", "R", "M" };
char *op[] = { "B", "B", "B", "S", "S" };
char *lv[] = { "B", "I", "E", "R" };
char *b_p[] = { "S", "S", "S", "S", "S" }, ch;
char *r_d[] = { "R", "R" };
char *b_s[] = { "V", "S", "M", "B", "E" };
char *s_s[] = { "V", "S", "M", "L", "E" };

void change1(void);
void change2(void);
void change3(void);
void change4(void);
void change5(void);
void change6(void);
void check(void);
int getkey(void);
int slide_position(int);
void design1(int);
void design2(int);
void show_game_menu(void);
void get_mm_choice(void);
void options(void);
void border(void);
void play(void);
void LEVEL(void);
void ball_color(void);
void BALL_PATTERN(void);
void ball_SIZE(void);
void slide_color(void);
void slide_SIZE(void);
void SCORE(int);
void display_score(void);
void ROUNDS(void);
void initialize(void);

void main() {

	int gdriver = DETECT, gmode;
	initgraph(&gdriver, &gmode, "C:\TC\BGI");
	mx = getmaxx();
	my = getmaxy();
	for (int i = 1; i <= 90; i++) {
		exist[i] = 1;
	}
	border();
	settextstyle(3, 0, 3);
	setcolor (RED);
	outtextxy(130, 200, "Programmed By:");
	settextstyle(1, 0, 3);
	setcolor (WHITE);
	outtextxy(330, 200, "Arjun vekariya");
	outtextxy(150, 235, "Arjun.vekariya1991@gmail.com");
	outtextxy(150, 275, "         +91 94268-73735");
	settextstyle(1, 0, 4);
	setcolor(RED);
	outtextxy(20, 360, "Press any key to see the game menu");

	getch();
	show_game_menu();

	getch();
	cleardevice();

	closegraph();
}

void play() {
	cleardevice();
	setcolor (GREEN);
	rectangle(2, 2, mx - 2, my - 2);
	setcolor (RED);
	rectangle(4, 4, mx - 4, my - 4);
	setcolor (LIGHTGRAY);
	rectangle(6, 6, mx - 6, my - 6);
	x = 325;
	y = 460 - ball_size;
	tp = 460;
	bm = 470;
//setbkcolor(1);
	setfillstyle(ball_style, ball_col);
	fillellipse(x, y, ball_size, ball_size);
	L_X = 270;
	if (incr_paddle_size == 1) {
		R_X = L_X + slide_size - 50;
	} else {
		R_X = L_X + slide_size;
	}

	setcolor(slide_col);
	rectangle(L_X, tp, R_X, bm);
	if (round == 1) {
		design1(glob);
	}
	if (round == 2) {
		design2(glob);
	}
	z = 70;
	while (z != 72) {
		start = 1;
		z = getkey();
		slide_position(z);
	}

	start = 0;
	change1();

}

void change1() {
	n = 0;
	while (y >= 9) {
		n++;
		if (n == 1 || n == 2 || n == 3) {
			setcolor(slide_col);
			rectangle(L_X, tp, R_X, bm);
		}

		if (y == 7 + ball_size) {
			temp = TRUE;
		}

		if (y == 7 + ball_size && temp == TRUE && slide_2 != 1) {
			change5();
		}
		if (y == 7 + ball_size && temp == FALSE && slide_2 != 1) {
			change2();
		}
		if (y == bm2 + ball_size && slide_2 == 1 && (x >= L_X && x <= R_X)) // && x<=+50) //x<200
				{
			temp = TRUE;
			change5();
		}

		if (x == (mx - 7) - ball_size) {
			change3();
		}
		fun_var = 1;

		check();
		if ((y == bm2 + ball_size || y < bm2 + ball_size)
				&& (x < L_X - 20 || x > R_X + 20) && slide_2 == 1) //x<200 &&

						{
			cleardevice();

			delay(3000);
			display_score();

		}

		delay(sec);
		setcolor (BLACK);
		setfillstyle(1, 0);
		fillellipse(x, y, ball_size, ball_size);
		++x;
		--y;
		setcolor(ball_col);
		setfillstyle(ball_style, ball_col);
		fillellipse(x, y, ball_size, ball_size);
		if (kbhit()) {

			z = getkey();
			slide_position(z);
			z = getkey();
			slide_position(z);
		}

	}
}

void change2() {

	while (y < (460 - ball_size) + 1) {

		if (y == tp - ball_size && (x >= L_X && x <= R_X)) // && x<=+50) //x<200
				{
			temp = TRUE;
			change3();
		}
		if (y == tp - ball_size && (x >= L_X - 20 && x <= R_X + 20) && x > R_X) //x<200
				{
			temp = FALSE;
			change1();
		}
		if (x == 7 + ball_size) {
			change4();
		}
		fun_var = 2;
		check();
		if ((y == tp - ball_size || y > tp - ball_size)
				&& (x < L_X - 20 || x > R_X + 20)) //x<200 &&

				{
			cleardevice();

			delay(3000);
			display_score();

		}
		delay(sec);
		setcolor(0);
		setfillstyle(1, 0);
		fillellipse(x, y, ball_size, ball_size);
		--x;
		++y;
		setcolor(ball_col);
		setfillstyle(ball_style, ball_col);
		fillellipse(x, y, ball_size, ball_size);
		if (kbhit()) {

			z = getkey();
			slide_position(z);
			z = getkey();
			slide_position(z);
		}

	}
}

void change3() {
	n = 0;
	while (y < (460 - ball_size) + 1) {
		n++;
		if (n == 1 || n == 2 || n == 3) {
			setcolor(slide_col);
			rectangle(L_X, tp, R_X, bm);
		}

		fun_var = 3;
		check();
		if (x == 7 + ball_size) //x<200 &&

				{
			change1();
		}
		if (y == 7 + ball_size && slide_2 != 1) {
			change2();
		}
		if (y == bm2 + ball_size && slide_2 == 1 && (x >= L_X && x <= R_X)) // && x<=+50) //x<200
				{
			temp = TRUE;
			change2();
		}
		if ((y == bm2 + ball_size || y < bm2 + ball_size)
				&& (x < L_X - 20 || x > R_X + 20) && slide_2 == 1) //x<200 &&

						{

			cleardevice();
			delay(3000);
			display_score();

		}

		delay(sec);
		setcolor(0);
		setfillstyle(1, 0);
		fillellipse(x, y, ball_size, ball_size);
		--x;
		--y;
		setcolor(ball_col);
		setfillstyle(ball_style, ball_col);
		fillellipse(x, y, ball_size, ball_size);
		if (kbhit()) {

			z = getkey();
			slide_position(z);
			z = getkey();
			slide_position(z);
		}

	}
}

void change4() {
	while (y < (460 - ball_size) + 1) {

		if (y == tp - ball_size && (x >= L_X - 20 && x <= R_X + 20)) //&& x<=L_X+50) //x<200
				{
			temp = TRUE;
			change3();
		}
		if (y == tp - ball_size && (x >= L_X - 20 && x <= R_X + 20) && x > R_X) //x<200
				{
			temp = FALSE;
			decide_dir = L_X;

			change1();
		}
		fun_var = 4;
		check();
		if (x == 7 + ball_size) {
			change5();
		}
		if ((y == tp - ball_size || y > tp - ball_size)
				&& (x < L_X - 20 || x > R_X + 20)) //x<200 &&

				{
			cleardevice();

			delay(3000);
			display_score();

		}
		delay(sec);
		setcolor(0);
		setfillstyle(1, 0);
		fillellipse(x, y, ball_size, ball_size);
		--x;
		++y;
		setcolor(ball_col);
		setfillstyle(ball_style, ball_col);
		fillellipse(x, y, ball_size, ball_size);

		if (kbhit()) {

			z = getkey();
			slide_position(z);
			z = getkey();
			slide_position(z);
		}

	}
}
void change5() {
	while (y < (460 - ball_size) + 1) {

		if (y == tp - ball_size && (x >= L_X && x <= R_X)) //&& x>L_X+50) //x<200
				{
			temp = FALSE;
			change1();
		}
		if (y == tp - ball_size && (x >= L_X - 20 && x <= R_X + 20) && x < L_X) //x<200
				{
			temp = TRUE;
			change3();
		}
		fun_var = 5;
		check();
		if (x == (mx - 7) - ball_size) {
			change2();
		}
		if ((y == tp - ball_size || y > tp - ball_size)
				&& (x < L_X - 20 || x > R_X + 20)) //x<200 &&
				{
			cleardevice();
			delay(3000);
			display_score();

		}
		delay(sec);
		setcolor(0);
		setfillstyle(1, 0);
		fillellipse(x, y, ball_size, ball_size);
		++x;
		++y;
		setcolor(ball_col);
		setfillstyle(ball_style, ball_col);
		fillellipse(x, y, ball_size, ball_size);
		if (kbhit()) {

			z = getkey();
			slide_position(z);
			z = getkey();
			slide_position(z);
		}

	}
}

void change6() {
	n = 0;
	while (y > 9) {
		n++;
		if (n == 1 || n == 2 || n == 3) {
			setcolor(slide_col);
			rectangle(L_X, tp, R_X, bm);
		}

		if (x == 7 + ball_size)

		{
			change1();
		}
		fun_var = 6;
		check();
		if (y == 7 + ball_size && slide_2 != 1) {
			change2();
		}
		if (y == bm2 + ball_size && slide_2 == 1 && (x >= L_X && x <= R_X)) // && x<=+50) //x<200
				{
			temp = TRUE;
			change2();
		}
		if ((y == bm2 + ball_size || y < bm2 + ball_size)
				&& (x < L_X - 20 || x > R_X + 20) && slide_2 == 1) //x<200 &&

						{
			cleardevice();
			setcolor(15);
			settextstyle(3, 0, 4);
			outtextxy(250, 135, "GAME OVER");
			delay(3000);
			display_score();

		}

		delay(sec);
		setcolor(0);
		setfillstyle(1, 0);
		fillellipse(x, y, ball_size, ball_size);
		--x;
		--y;
		setcolor(ball_col);
		setfillstyle(1, ball_col);
		fillellipse(x, y, ball_size, ball_size);
		if (kbhit()) {

			z = getkey();
			slide_position(z);
			z = getkey();
			slide_position(z);
		}

	}
}
int getkey() {
	union REGS i, o;
	while (kbhit())

	{
		i.h.ah = 0;
		int86(22, &i, &o);
		return (o.h.ah);
	}
}

int slide_position(int z) {
	int l_x, r_x;
	if (z == 75 && (y < tp - ball_size && y > bm2 + ball_size)) //52  LEFT

			{
		l_x = L_X;
		r_x = R_X;

		L_X -= 30;
		R_X -= 30;
		if (L_X < 10) {
			L_X = 10;
			R_X = L_X + slide_size;
			setcolor (BLACK);

			rectangle(l_x, tp, r_x, bm);
			if (slide_2 == 1) {
				rectangle(l_x, tp2, r_x, bm2);
			}
			//floodfill(15,465,0);
			setcolor(slide_col);
			rectangle(L_X, tp, R_X, bm);
			if (slide_2 == 1) {
				rectangle(L_X, tp2, R_X, bm2);
			}
		} else {
			setcolor(0);

			rectangle(l_x, tp, r_x, bm);
			if (slide_2 == 1) {

				rectangle(l_x, tp2, r_x, bm2);
			}
			setcolor(slide_col);
			if (slide_2 == 1) {

				rectangle(L_X, tp2, R_X, bm2);
			}
			rectangle(L_X, tp, R_X, bm);
		}
	}

	else if (z == 77 && (y < tp - ball_size && y > bm2 + ball_size)) //54  RIGHT
			{
		l_x = L_X;
		r_x = R_X;
		L_X += 30;
		R_X += 30;
		if (R_X > 630) {
			R_X = 630;
			L_X = R_X - slide_size;
			setcolor(0);

			rectangle(l_x, tp, r_x, bm);
			if (slide_2 == 1) {

				rectangle(l_x, tp2, r_x, bm2);
			}
			setcolor(slide_col);

			rectangle(L_X, tp, R_X, bm);
			if (slide_2 == 1) {

				rectangle(L_X, tp2, R_X, bm2);
			}
		} else {
			setcolor(0);

			rectangle(l_x, tp, r_x, bm);
			if (slide_2 == 1) {

				rectangle(l_x, tp2, r_x, bm2);
			}
			setcolor(slide_col);

			rectangle(L_X, tp, R_X, bm);
			if (slide_2 == 1) {

				rectangle(L_X, tp2, R_X, bm2);
			}

		}
	}

	else if (z == 75
			&& (y == tp - ball_size || (y == bm2 + ball_size && slide_2 == 1))
			&& (magnate == 1 || start == 1)) //52  LEFT

			{
		l_x = L_X;
		r_x = R_X;

		L_X -= 30;
		R_X -= 30;
		int X = x;
		x -= 30;
		if (L_X < 10) {
			x = x - L_X;
			L_X = 10;
			R_X = L_X + slide_size;
			x = L_X + x;
			setcolor (BLACK);

			rectangle(l_x, tp, r_x, bm);
			if (slide_2 == 1) {
				setfillstyle(1, 0);
				fillellipse(X, y, ball_size, ball_size);

				rectangle(l_x, tp2, r_x, bm2);
			}
			setfillstyle(1, 0);
			fillellipse(X, y, ball_size, ball_size);

			setcolor(slide_col);

			rectangle(L_X, tp, R_X, bm);
			if (slide_2 == 1) {

				rectangle(L_X, tp2, R_X, bm2);
				setfillstyle(ball_style, ball_col);

				fillellipse(x, y, ball_size, ball_size);

			}
			setfillstyle(ball_style, ball_col);
			fillellipse(x, y, ball_size, ball_size);

		} else {
			setcolor(0);

			rectangle(l_x, tp, r_x, bm);
			if (slide_2 == 1) {
				rectangle(l_x, tp2, r_x, bm2);
				setfillstyle(1, 0);
				fillellipse(X, y, ball_size, ball_size);

			}
			setfillstyle(1, 0);
			fillellipse(X, y, ball_size, ball_size);
			setcolor(slide_col);

			rectangle(L_X, tp, R_X, bm);
			if (slide_2 == 1) {
				rectangle(L_X, tp2, R_X, bm2);
				setfillstyle(ball_style, ball_col);
				fillellipse(x, y, ball_size, ball_size);

			}
			setfillstyle(ball_style, ball_col);
			fillellipse(x, y, ball_size, ball_size);
		}
	}

	else if (z == 77
			&& (y == tp - ball_size || (y == bm2 + ball_size && slide_2 == 1))
			&& (magnate == 1 || start == 1)) //54  RIGHT
			{
		l_x = L_X;
		r_x = R_X;
		L_X += 30;
		R_X += 30;
		int X = x;
		x += 30; /**/
		if (R_X > 630) {
			x = x - L_X;
			R_X = 630;
			L_X = R_X - slide_size;
			x = L_X + x;
			setcolor(0);

			rectangle(l_x, tp, r_x, bm);
			if (slide_2 == 1) {
				setfillstyle(1, 0);
				fillellipse(X, y, ball_size, ball_size);
				rectangle(l_x, tp2, r_x, bm2);
			}
			setfillstyle(1, 0);
			fillellipse(X, y, ball_size, ball_size);
			setcolor(slide_col);

			rectangle(L_X, tp, R_X, bm);
			if (slide_2 == 1) {
				setfillstyle(ball_style, ball_col); /**/
				fillellipse(x, y, ball_size, ball_size); /**/

				rectangle(L_X, tp2, R_X, bm2);
			}
			setfillstyle(ball_style, ball_col); /**/
			fillellipse(x, y, ball_size, ball_size); /**/

		} else {
			setcolor(0);

			rectangle(l_x, tp, r_x, bm);
			if (slide_2 == 1) {
				setfillstyle(1, 0);
				fillellipse(X, y, ball_size, ball_size); /**/

				rectangle(l_x, tp2, r_x, bm2);
			}
			setfillstyle(1, 0);
			fillellipse(X, y, ball_size, ball_size); /**/
			setcolor(slide_col);

			rectangle(L_X, tp, R_X, bm);
			if (slide_2 == 1) {
				setfillstyle(ball_style, ball_col); /**/
				fillellipse(x, y, ball_size, ball_size); /**/

				rectangle(L_X, tp2, R_X, bm2);
			}
			setfillstyle(ball_style, ball_col); /**/
			fillellipse(x, y, ball_size, ball_size); /**/

		}
	} else if (z == 72 && y != tp - ball_size) {
		if (tp > 400) {
			setcolor(0);

			rectangle(L_X, tp, R_X, bm);

			tp = tp - 20;
			bm = bm - 20;
			setcolor(slide_col);

			rectangle(L_X, tp, R_X, bm);

		} else {
			return 0;
		}

	} else if (z == 72 && y == tp - ball_size && (magnate == 1 || start == 1)) {
		if (tp > 400) {

			setcolor(0);

			rectangle(L_X, tp, R_X, bm);
			setfillstyle(1, 0);
			fillellipse(x, y, ball_size, ball_size);
			y = y - 20;
			tp = tp - 20;
			bm = bm - 20;
			setcolor(slide_col);

			rectangle(L_X, tp, R_X, bm);
			setfillstyle(ball_style, ball_col); /**/
			fillellipse(x, y, ball_size, ball_size); /**/

		} else {
			return 0;
		}
	}

	else if (z == 80 && y != tp - ball_size) {
		l_x = L_X;
		r_x = R_X;

		if (bm < 470) {
			setcolor(0);

			rectangle(L_X, tp, R_X, bm);
			tp = tp + 20;
			bm = bm + 20;
			setcolor(slide_col);

			rectangle(L_X, tp, R_X, bm);

		} else {
			return 0;
		}

	} else if (z == 80 && y == tp - ball_size && (magnate == 1 || start == 1)) {
		l_x = L_X;
		r_x = R_X;

		if (bm < 470) {

			setcolor(0);

			rectangle(L_X, tp, R_X, bm);
			setfillstyle(1, 0);
			fillellipse(x, y, ball_size, ball_size);
			y = y + 20;
			tp = tp + 20;
			bm = bm + 20;
			setcolor(slide_col);

			rectangle(L_X, tp, R_X, bm);
			setfillstyle(ball_style, ball_col); /**/
			fillellipse(x, y, ball_size, ball_size); /**/

		} else {
			return 0;
		}

		return 0;
	}

	else {
		return 0;
	}
}

void design1(int a) {
	int no, k = 1, i, j;
	rec_1x[1] = 100;
	rec_2x[1] = 100;
	rec_3x[1] = 150;
	rec_4x[1] = 150;
	rec_1y[1] = 100;
	rec_2y[1] = 115;
	rec_3y[1] = 115;
	rec_4y[1] = 100;

	for (i = 1; i <= 10; i++) {
		if (i > 1) {
			rec_1y[i] = rec_1y[i - 1] + 20;
			rec_2y[i] = rec_2y[i - 1] + 20;
			rec_3y[i] = rec_3y[i - 1] + 20;
			rec_4y[i] = rec_4y[i - 1] + 20;
		}

		if (i % 2 == 0) {
			no = 8;
			rec_1x[k] = 125;
			rec_2x[k] = 125;
			rec_3x[k] = 175;
			rec_4x[k] = 175;
		} else {
			no = 9;
			rec_1x[k] = 100;
			rec_2x[k] = 100;
			rec_3x[k] = 150;
			rec_4x[k] = 150;
		}

		for (j = 1; j <= no; j++) {
			if (exist[k] == 1) {

				setcolor(15);
				poly[0] = rec_1x[k]; /* 1st vertex */
				poly[1] = rec_1y[i];

				poly[2] = rec_2x[k]; /* 2nd */
				poly[3] = rec_2y[i];

				poly[4] = rec_3x[k] - 10; /* 3rd */
				poly[5] = rec_3y[i];

				poly[6] = rec_4x[k] - 10; /*4th vertex*/
				poly[7] = rec_4y[i];
				if (k == 12 || k == 22 || k == 45) {
					setfillstyle(1, 0);
					fillpoly(4, poly);
					settextstyle(1, 0, 1);
					outtextxy(rec_1x[k] + 2, rec_1y[i] - 4, "MAG");
				} else if (k == 74 || k == 25) {
					setfillstyle(1, 0);
					fillpoly(4, poly);
					settextstyle(1, 0, 1);
					outtextxy(rec_1x[k] + 2, rec_1y[i] - 4, "POW");
				} else {
					setfillstyle(i, j);
					fillpoly(4, poly);

				}
				k++;
				rec_1x[k] = rec_1x[k - 1] + 45;
				rec_2x[k] = rec_2x[k - 1] + 45;
				rec_3x[k] = rec_3x[k - 1] + 45;
				rec_4x[k] = rec_4x[k - 1] + 45;
			} else {
				if (k == a) {
					setcolor(0);
					poly[0] = rec_1x[k]; /* 1st vertex */
					poly[1] = rec_1y[i];

					poly[2] = rec_2x[k]; /* 2nd */
					poly[3] = rec_2y[i];

					poly[4] = rec_3x[k] - 10; /* 3rd */
					poly[5] = rec_3y[i];

					poly[6] = rec_4x[k] - 10; /*4th vertex*/
					poly[7] = rec_4y[i];
					for (int l = 1; l <= 5; l++) {
						setfillstyle(l, l);
						/* draw a filled polygon */
						fillpoly(4, poly);
						delay(0);
					}
					setfillstyle(11, 0);
					/* draw a filled polygon */
					fillpoly(4, poly);
				}
				k++;
				rec_1x[k] = rec_1x[k - 1] + 45;
				rec_2x[k] = rec_2x[k - 1] + 45;
				rec_3x[k] = rec_3x[k - 1] + 45;
				rec_4x[k] = rec_4x[k - 1] + 45;
				continue;
			}
		}
	}
}

void design2(int a) {
	int no, k = 1, i, j;
	rec_1x[1] = 50;
	rec_2x[1] = 50;
	rec_3x[1] = 100;
	rec_4x[1] = 100;
	rec_1y[1] = 100;
	rec_2y[1] = 115;
	rec_3y[1] = 115;
	rec_4y[1] = 100;

	for (i = 1; i <= 10; i++) {
		if (i > 1) {
			rec_1y[i] = rec_1y[i - 1] + 20;
			rec_2y[i] = rec_2y[i - 1] + 20;
			rec_3y[i] = rec_3y[i - 1] + 20;
			rec_4y[i] = rec_4y[i - 1] + 20;
		}
		no = 9;
		rec_1x[k] = 50;
		rec_2x[k] = 50;
		rec_3x[k] = 100;
		rec_4x[k] = 100;

		for (j = 1; j <= no; j++) {
			if (exist[k] == 1) {

				setcolor(15);
				poly[0] = rec_1x[k]; /* 1st vertex */
				poly[1] = rec_1y[i];

				poly[2] = rec_2x[k]; /* 2nd */
				poly[3] = rec_2y[i];

				poly[4] = rec_3x[k] - 10; /* 3rd */
				poly[5] = rec_3y[i];

				poly[6] = rec_4x[k] - 10; /*4th vertex*/
				poly[7] = rec_4y[i];
				if (k == 12 || k == 22 || k == 45) {
					setfillstyle(1, 0);
					fillpoly(4, poly);
					settextstyle(1, 0, 1);
					outtextxy(rec_1x[k] + 2, rec_1y[i] - 4, "MAG");
				} else if (k == 74 || k == 25) {
					setfillstyle(1, 0);
					fillpoly(4, poly);
					settextstyle(1, 0, 1);
					outtextxy(rec_1x[k] + 2, rec_1y[i] - 4, "POW");
				} else {
					setfillstyle(i, j);
					fillpoly(4, poly);

				}
				k++;
				if (k % 3 == 1) {
					rec_1x[k] = rec_1x[k - 1] + 105;
					rec_2x[k] = rec_2x[k - 1] + 105;
					rec_3x[k] = rec_3x[k - 1] + 105;
					rec_4x[k] = rec_4x[k - 1] + 105;

				} else {
					rec_1x[k] = rec_1x[k - 1] + 45;
					rec_2x[k] = rec_2x[k - 1] + 45;
					rec_3x[k] = rec_3x[k - 1] + 45;
					rec_4x[k] = rec_4x[k - 1] + 45;
				}
			} else {
				if (k == a) {
					setcolor(0);
					poly[0] = rec_1x[k]; /* 1st vertex */
					poly[1] = rec_1y[i];

					poly[2] = rec_2x[k]; /* 2nd */
					poly[3] = rec_2y[i];

					poly[4] = rec_3x[k] - 10; /* 3rd */
					poly[5] = rec_3y[i];

					poly[6] = rec_4x[k] - 10; /*4th vertex*/
					poly[7] = rec_4y[i];
					for (int l = 1; l <= 5; l++) {
						setfillstyle(l, l);
						/* draw a filled polygon */
						fillpoly(4, poly);
						delay(0);
					}
					setfillstyle(11, 0);
					/* draw a filled polygon */
					fillpoly(4, poly);
				}
				k++;
				if (k % 3 == 1) {
					rec_1x[k] = rec_1x[k - 1] + 105;
					rec_2x[k] = rec_2x[k - 1] + 105;
					rec_3x[k] = rec_3x[k - 1] + 105;
					rec_4x[k] = rec_4x[k - 1] + 105;

				} else {
					rec_1x[k] = rec_1x[k - 1] + 45;
					rec_2x[k] = rec_2x[k - 1] + 45;
					rec_3x[k] = rec_3x[k - 1] + 45;
					rec_4x[k] = rec_4x[k - 1] + 45;
				}

			}
		}
	}
}

void check() {
	int no, p = 1, i, j, poly[8], n = 0;
	if (round == 1) {
		rec_lx[1] = 100;
		rec_rx[1] = 150;
		rec_y_tp[1] = 100;
		rec_y_bm[1] = 115;
	}
	if (round == 2) {
		rec_lx[1] = 50;
		rec_rx[1] = 100;
		rec_y_tp[1] = 100;
		rec_y_bm[1] = 115;
	}

	for (i = 1; i <= 10; i++) {
		if (i > 1) {
			rec_y_tp[i] = rec_y_tp[i - 1] + 20;
			rec_y_bm[i] = rec_y_bm[i - 1] + 20;
		}
		if (round == 1) {
			if (i % 2 == 0) {
				no = 8;
				rec_lx[p] = 125;
				rec_rx[p] = 175;

			} else {
				no = 9;
				rec_lx[p] = 100;
				rec_rx[p] = 150;
			}
		}
		if (round == 2) {
			no = 9;
			rec_lx[p] = 50;
			rec_rx[p] = 100;
		}

		for (j = 1; j <= no; j++) {

			if (((x >= rec_lx[p] + ball_size || x >= rec_lx[p] - ball_size)
					&& (x <= rec_rx[p] + ball_size || x <= rec_rx[p] - ball_size))
					&& ((y >= rec_y_tp[i] - ball_size /*|| y>=rec_y_tp[i]+ball_size*/)
							&& (/*y<=rec_y_bm[i]-ball_size ||*/y
									<= rec_y_bm[i] + ball_size))
					&& exist[p] == 1) {
				glob = p;
				exist[p] = 0;
				SCORE(p);
				if (p == 12 || p == 22 || p == 45) {
					magnate = TRUE;
					setcolor(0);
					rectangle(L_X, tp + 15, L_X + 10, tp);
					rectangle(R_X - 10, tp + 15, R_X, tp);

				}
				if (p == 74) {

					magnate = FALSE;
					slide_2 = TRUE;
					rectangle(L_X, tp2, R_X, bm2);

					//get_gun_power(p);
				}
				if (p == 25) {
					incr_paddle_size = 1;
					setcolor(0);
					slide_size += 50;
					rectangle(L_X, tp, R_X, bm);
					if (slide_2 == 1) {
						rectangle(L_X, tp2, R_X, bm2);
					}
					L_X -= 50;
					if (L_X < 10) {
						L_X += 50;
						int diff = L_X - 10;
						L_X = 10;
						R_X += 50 - diff;
					}

					setcolor(15);
					rectangle(L_X, tp, R_X, bm);
					if (slide_2 == 1) {
						rectangle(L_X, tp2, R_X, bm2);
					}

				}
				setcolor(0);
				sound(5000);
				delay(5);
				nosound();

				poly[0] = 45;
				poly[1] = 95;

				poly[2] = 45;
				poly[3] = 310;

				poly[4] = 620;
				poly[5] = 310;

				poly[6] = 620;
				poly[7] = 95;

				setfillstyle(1, BLACK);

				fillpoly(4, poly);

				if (round == 1) {
					design1(p);
				}
				if (round == 2) {
					design2(p);
				}

				if (y == 100 - ball_size || y == 120 - ball_size
						|| y == 140 - ball_size || y == 160 - ball_size
						|| y == 180 - ball_size || y == 200 - ball_size
						|| y == 220 - ball_size || y == 240 - ball_size
						|| y == 260 - ball_size || y == 280 - ball_size) {
					if (fun_var == 5) {
						change1();
					}
					if (fun_var == 2) {
						change3();
					}
				}
				if (y == 115 + ball_size || y == 135 + ball_size
						|| y == 155 + ball_size || y == 175 + ball_size
						|| y == 195 + ball_size || y == 215 + ball_size
						|| y == 235 + ball_size || y == 255 + ball_size
						|| y == 275 + ball_size || y == 295 + ball_size)

						{
					if (fun_var == 1) //&& decide_dir<325)
							{
						change5();
					}
					if (fun_var == 3) // && decide_dir>325)
							{
						change2();
					}
				}

				if (y > rec_y_tp[i] - ball_size
						&& y < rec_y_bm[i] + ball_size) {
					if (fun_var == 3) {
						change1();
					}
					if (fun_var == 2) {
						change5();
					}
					if (fun_var == 5) {
						change2();
					}
					if (fun_var == 1) {
						change3();
					}

				}

			}

			if (magnate == TRUE
					&& (y == tp - ball_size
							|| (y == bm2 + ball_size && slide_2 == 1))
					&& (x >= L_X && x <= R_X)) {
				while (z != 72) {
					z = getkey();
					slide_position(z);
				}

			}

			p++;
			if (1) {
				int flag = 1;
				for (int m = 1; m <= 90; m++) {
					if (exist[m] == 1) {
						flag = 0;
						break;
					}
				}
				if (flag == 1) {
					cleardevice();
					border();
					settextstyle(3, 0, 5);
					outtextxy(50, 140, "C O N G R A T U L A T I O N");
					outtextxy(50, 190, "YOU HAVE COMPELETED");
					settextstyle(1, 0, 5);
					outtextxy(150, 250, rou[round - 1]);
					while (!kbhit())
						;
					display_score();
				}
			}

			if (round == 2 && p % 3 == 1) {
				rec_lx[p] = rec_lx[p - 1] + 105;
				rec_rx[p] = rec_rx[p - 1] + 105;
			} else {
				rec_lx[p] = rec_lx[p - 1] + 45;
				rec_rx[p] = rec_rx[p - 1] + 45;
			}

		}
	}
}

void show_game_menu() {
	cleardevice();
	border();
	settextstyle(1, 0, 5);
	setcolor (GREEN);
	outtextxy(50, 140, "G A M E  M E N U");

	settextstyle(3, 0, 5);

	for (i = 0; i < 4; i++) {
		setcolor (WHITE);
		outtextxy(67, 190 + (45 * i), main_menu[i]);
		setcolor (RED);
		outtextxy(130, 190 + (45 * i), m_m[i]);
	}
	get_mm_choice();
}

void get_mm_choice() {
	get: char ch = getch();
	int cho = toascii(ch);
	if (cho == 49) {
		play();
	} else if (cho == 50) {
		options();
	}

	else if (cho == 51) {
		LEVEL();
	} else if (cho == 52) {
		ROUNDS();
	} else {
		goto get;
	}

	//case 75: hiscore();
	//	   break;

	// case 76: exit();
	//	   break;

}

void options() {
	cleardevice();
	border();
	settextstyle(3, 0, 5);
	setcolor (GREEN);
	outtextxy(50, 140, "O P T I O N");
	for (i = 0; i < 5; i++) {
		setcolor (WHITE);
		outtextxy(67, 190 + (45 * i), OPTION[i]);
		setcolor (RED);
		outtextxy(130, 190 + (45 * i), op[i]);

	}

	get: cho = bioskey(0);
	cho = cho >> 8;
	switch (cho) {
	case 2:
	case 25:
	case 28:
	case 79:
		ball_SIZE();
		break;

	case 3:
	case 24:
	case 80:
		ball_color();
		break;

	case 4:
	case 23:
	case 81:
		BALL_PATTERN();

		break;

	case 5:
	case 35:
	case 75:
		slide_color();
		break;

	case 6:
	case 18:
	case 76:
		slide_SIZE();
		break;
	default:
		goto get;
	}

	show_game_menu();
}

void border() {
	setcolor (GREEN);
	rectangle(2, 2, mx - 2, my - 2);
	setcolor (RED);
	rectangle(4, 4, mx - 4, my - 4);
	setcolor (LIGHTGRAY);
	rectangle(6, 6, mx - 6, my - 6);
	settextstyle(4, 0, 5);
	setcolor(GREEN);
	outtextxy(180, 40, "DX-BALL");
	setcolor (YELLOW);
	line(165, 88, 390, 88);
	setcolor(RED);
	line(165, 90, 390, 90);
}
void ball_color() {
	cleardevice();
	border();
	settextstyle(3, 0, 5);
	setcolor (GREEN);
	outtextxy(50, 140, "B A L L   C O L O R S");

	for (i = 0; i < 5; i++) {
		setcolor (WHITE);
		outtextxy(67, 190 + (45 * i), ball_colour[i]);
		setcolor (RED);
		outtextxy(130, 190 + (45 * i), b_c[i]);

	}
	ch = getch();
	cho = toascii(ch);
	if (cho == 49) {
		ball_col = 1;
	}
	if (cho == 50) {
		ball_col = 2;
	}
	if (cho == 51) {
		ball_col = 3;
	}
	if (cho == 52) {
		ball_col = 4;
	}
	if (cho == 53) {
		ball_col = 5;
	}
	show_game_menu();

}
void BALL_PATTERN() {
	cleardevice();
	border();
	settextstyle(3, 0, 5);
	setcolor (GREEN);
	outtextxy(50, 140, "P A T T E R N S");

	for (i = 0; i < 5; i++) {
		setcolor(15);
		outtextxy(67, 190 + (45 * i), ball_pat[i]);
		setcolor (RED);
		outtextxy(130, 190 + (45 * i), b_p[i]);

	}
	ch = getch();
	cho = toascii(ch);
	if (cho == 49) {
		ball_style = 1;
	}
	if (cho == 50) {
		ball_style = 2;
	}
	if (cho == 51) {
		ball_style = 3;
	}
	if (cho == 52) {
		ball_style = 4;
	}
	if (cho == 53) {
		ball_style = 5;
	}
// options();
	show_game_menu();
}
void ball_SIZE() {
	cleardevice();
	border();
	settextstyle(3, 0, 5);
	setcolor (GREEN);
	outtextxy(50, 140, "B A L L   S I Z E S");

	for (i = 0; i < 5; i++) {
		setcolor (WHITE);
		outtextxy(67, 190 + (45 * i), BALL_SIZE[i]);
		setcolor (RED);
		outtextxy(130, 190 + (45 * i), b_s[i]);

	}
	ch = getch();
	cho = toascii(ch);
	if (cho == 49) {
		ball_size = 2;
	}
	if (cho == 50) {
		ball_size = 3;
	}
	if (cho == 51) {
		ball_size = 5;
	}
	if (cho == 52) {
		ball_size = 7;
	}
	if (cho == 53) {
		ball_size = 10;
	}
	// options();
	show_game_menu();

}

void slide_color() {
	cleardevice();
	border();
	settextstyle(3, 0, 5);
	setcolor (GREEN);
	outtextxy(50, 140, "S L I D E    C O L O R S");

	for (i = 0; i < 5; i++) {
		setcolor (WHITE);
		outtextxy(67, 190 + (45 * i), ball_colour[i]);
		setcolor (RED);
		outtextxy(130, 190 + (45 * i), b_c[i]);

	}
	ch = getch();
	cho = toascii(ch);
	if (cho == 49) {
		slide_col = 1;
	}
	if (cho == 50) {
		slide_col = 2;
	}
	if (cho == 51) {
		slide_col = 128;
	}
	if (cho == 52) {
		slide_col = 4;
	}
	if (cho == 53) {
		slide_col = 5;
	}
	// options();
	show_game_menu();

}
void slide_SIZE() {
	cleardevice();
	border();
	settextstyle(3, 0, 5);
	setcolor (GREEN);
	outtextxy(50, 140, "S L I D E    S I Z E S");

	for (i = 0; i < 5; i++) {
		setcolor (WHITE);
		outtextxy(67, 190 + (45 * i), SLIDE_SIZE[i]);
		setcolor (RED);
		outtextxy(130, 190 + (45 * i), s_s[i]);

	}
	ch = getch();
	cho = toascii(ch);
	if (cho == 49) {
		L_X = 300;
		R_X = 340;
		slide_size = 40;
	}
	if (cho == 50) {
		L_X = 285;
		R_X = 355;
		slide_size = 70;
	}
	if (cho == 51) {
		L_X = 270;
		R_X = 370;
		slide_size = 100;
	}
	if (cho == 52) {
		L_X = 245;
		R_X = 395;
		slide_size = 150;
	}
	if (cho == 53) {
		L_X = 220;
		R_X = 420;
		slide_size = 200;
	}
	// options();
	show_game_menu();

}

void LEVEL() {
	cleardevice();
	border();
	setcolor(4);
	settextstyle(1, 0, 5);
	setcolor (GREEN);
	outtextxy(50, 140, "L E V E L S");
	for (i = 0; i < 4; i++) {

		setcolor(15);
		outtextxy(67, 190 + (45 * i), level[i]);
		setcolor (RED);
		outtextxy(130, 190 + (45 * i), lv[i]);

	}
	get: ch = getch();
	cho = toascii(ch);
	if (cho == 49) {
		sec = 8;
	} else if (cho == 50) {
		sec = 5;
	} else if (cho == 51) {
		sec = 3;
	} else if (cho == 52) {
		show_game_menu();
	}

	else {
		goto get;
	}

	show_game_menu();
}
void ROUNDS() {
	cleardevice();
	border();
	settextstyle(3, 0, 5);
	setcolor (GREEN);
	outtextxy(50, 140, "G A M E   R O U N D S");

	for (i = 0; i < 2; i++) {
		setcolor(15);
		outtextxy(67, 190 + (45 * i), ROU[i]);
		setcolor (RED);
		outtextxy(130, 190 + (45 * i), r_d[i]);

	}

	get: ch = getch();
	cho = toascii(ch);
	if (cho == 49) {
		round = 1;
	} else if (cho == 50) {
		round = 2;
	} else {
		goto get;
	}
	show_game_menu();
}

void SCORE(int p) {
	if (p == 12 || p == 22 || p == 45 || p == 74 || p == 25) {
		score = score + 20;
	} else {
		score = score + 5;
	}

}

void display_score() {
	life--;
	if (life > 0) {
		cleardevice();
		slide_2 = 0;
		magnate = 0;
		border();
		settextstyle(1, 0, 5);
		setcolor (MAGENTA);
		outtextxy(50, 180, "LIFES REMAINING :");
		char *c;
		ltoa(life, c, 10);
		setcolor (WHITE);
		outtextxy(450, 180, c);

		settextstyle(1, 0, 5);
		setcolor (GREEN);
		outtextxy(140, 250, "SCORE : ");

		ch = ' ';
		char *s;
		ltoa(score, s, 10);
		setcolor(WHITE);

		outtextxy(350, 250, s);
		setcolor (RED);

		line(130, 300, 450, 300);
		setcolor(WHITE);
		line(130, 302, 450, 302);
		setcolor(WHITE);
		settextstyle(1, 0, 3);
		outtextxy(100, 400, "Press Space Bar To Continue Playing");

		while (cho != 32) {
			ch = getch();
			cho = toascii(ch);
		}
		play();
	}

	border();
	settextstyle(1, 0, 5);
	setcolor (MAGENTA);
	outtextxy(130, 180, "GAME  OVER");

	settextstyle(1, 0, 5);
	setcolor (GREEN);
	outtextxy(140, 250, "SCORE : ");

	ch = ' ';
	char *s;
	ltoa(score, s, 10);
	setcolor (WHITE);

	outtextxy(350, 250, s);
	setcolor (RED);

	line(130, 300, 450, 300);
	setcolor(WHITE);
	line(130, 302, 450, 302);

	while (!kbhit()) {
		for (i = 1; i <= 14; i++) {
			setcolor(i);
			line(130, 300, 450, 300);
			setcolor(i + 1);
			line(130, 302, 450, 302);

			delay(200);
		}
	}
	settextstyle(4, 0, 5);
	setcolor(WHITE);
	int left;
	outtextxy(15, 350, "Wish to continue ? Press Space");
	rectangle(125, 420, 180, 450);
	settextstyle(1, 0, 1);
	outtextxy(130, 425, "YES");
	outtextxy(285, 425, "NO");
	z = 70;
	get: if (kbhit()) {
		z = getkey();
	}

	if (z == 75) {
		left = 280;
		setcolor(0);
		rectangle(left, 420, 335, 450);
		setcolor(15);
		left = 125;
		rectangle(left, 420, 180, 450);

	} else if (z == 77) {
		left = 125;
		setcolor(0);
		rectangle(left, 420, 180, 450);
		setcolor(15);
		left = 280;
		rectangle(left, 420, 335, 450);
	} else {
		goto get;
	}
	ch = getch();
	cho = toascii(ch);

	if (cho == 32 && left == 125) {
		initialize();
	} else if (cho == 32 && left == 280) {
		free(rec_1x);
		free(rec_2x);
		free(rec_3x);
		free(rec_4x);
		free(rec_y_tp);
		free(rec_y_bm);
		free(rec_1y);
		free(rec_2y);
		free(rec_3y);
		free(rec_4y);
		free(rec_lx);
		free(rec_rx);
		free(OPTION);
		free(main_menu);
		free(level);
		free(ball_colour);
		free(BALL_SIZE);
		free(SLIDE_SIZE);
		free(ball_pat);
		free(m_m);
		free(op);
		free(lv);
		free(ROU);
		free(b_p);
		free(r_d);
		free(b_c);
		free(b_s);
		free(s_s);

		free(exist);

		exit(0);
	} else {
		goto get;
	}
}
void initialize() {
	x = 325, y = 455, X = 600, Y = 455, L_X = 275, R_X = 375, temp = TRUE,sec =
			5, color = 15, cir_col = 0;
	rec_col = 0, exist[95], fun_var, slide_col = 15, n;
	ball_col = 15, ball_style = 2, life = 3;
	magnate = FALSE,score = 0, round = 1, ball_size = 3, slide_size = 100;
	tp = 460, bm = 470, slide_2 = 0;
	tp2 = 10, bm2 = 20;
	for (int i = 1; i <= 90; i++) {
		exist[i] = 1;
	}
	cleardevice();
	delay(2000);
	show_game_menu();
}
