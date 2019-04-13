#include <cstdio>
using namespace std;

char cube[12][9];


void initCube() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 9; j++) {
			if (i < 3) {
				if (j > 2 && j < 6) cube[i][j] = 'o';
			} else if (i < 6) {
				if (j < 3) cube[i][j] = 'g';
				else if (j < 6) cube[i][j] = 'w';
				else cube[i][j] = 'b';
			} else if (i < 9) {
				if (j > 2 && j < 6) cube[i][j] = 'r';
			} else {
				if (j > 2 && j < 6) cube[i][j] = 'y';
			}
		}
	}
}

void rotate(char d, int r, int c) {
	char buf;
	if (d = '+') {
		buf = cube[r][c];
		cube[r][c] = cube[r + 2][c];
		cube[r + 2][c] = cube[r + 2][c + 2];
		cube[r + 2][c + 2] = cube[r][c + 2];
		cube[r][c + 2] = buf;
		buf = cube[r][c + 1];
		cube[r][c + 1] = cube[r + 1][c];
		cube[r + 1][c] = cube[r + 2][c + 1];
		cube[r + 2][c + 1] = cube[r + 1][c + 2];
		cubr[r + 1][c + 2] = buf;
	} else {
		buf = cube[r][c];
		cube[r][c] = cube[r][c + 2];
		cube[r][c + 2] = cube[r + 2][c + 2];
		cube[r + 2][c + 2] = cube[r + 2][r];
		cube[r + 2][r] = buf;
		buf = cube[r][c + 1];
		cube[r][c + 1] = cube[r + 1][c + 2]; 
		cube[r + 1][c + 2] = cube[r + 2][c + 1];
		cube[r + 2][c + 1] = cube[r + 1][c];
		cube[r + 1][c] = buf;
	}
}

void move(char p, char d) {
	char buf[3];
	int index;
	if (p == 'L') {
		rotate(d, 3, 0);
		if (d == '+')  {
			for (int i = 9; i < 12; i++) buf[i] = cube[i][3];
			for (int i = 0; i < 9; i++) cube[i + 3] = cube[i][3];
			for (int i = 0; i < 3; i++) cube[i][3] = buf[i];
		} else {
			for (int i = 0; i < 3; i++) buf[i] = cube[i][3];
			for (int i = 0; i < 9; i++) cube[i][3] = cube[i + 3][3];
			for (int i = 9; i < 12; i++) cube[i][3] = buf[i];
		}
	} else if (p == 'R') {
		rotate(d, 3, 6);
		if (d == '+') {
			for (int i = 9; i < 12; i++) buf[i] = cube[i][5];
			for (int i = 0; i < 9; i++) cube[i + 3] = cube[i][5];
			for (int i = 0; i < 3; i++) cube[i][5] = buf[i];
		} else {
			for (int i = 0; i < 3; i++) buf[i] = cube[i][5];
			for (int i = 0; i < 9; i++) cube[i][5] = cube[i + 3][5];
			for (int i = 9; i < 12; i++) cube[i][5] = buf[i];
		}
	} else if (p == 'U') {
		rotate(d, 3, 3);
		if (d == '+') {
			buf[0] = cube[2][3];
			cube[2][3] = cube[5][2];
			cube[5][2] = cube[6][5];
			cube[6][5] = cube[3][6];
			cube[3][6] = buf[0];
			buf[0] = cube[2][4];
			cube[2][4] = cube[4][2];
			cube[4][2] = cube[6][4];
			cube[6][4] = cube[4][6]; 
			cube[4][6] = buf[0];
			buf[0] = cube[2][5];
			cube[2][5] = cube[3][2];
			cube[3][2] = cube[6][3];
			cube[6][3] = cube[5][6];
			cube[5][6] = buf[0];
		} else {
			buf[0] = cube[2][3];
			cube[2][3] = cube[3][6];
			cube[3][6] = cube[6][5];
			cube[6][5] = cube[5][2];
			cube[5][2] = buf[0];
			buf[0] = cube[2][4];
			cube[2][4] = cube[4][6];
			cube[4][6] = cube[6][4];
			cube[6][4] = cube[4][2];
			cube[4][2] = buf[0];
			buf[0] = cube[2][5];
			cube[2][5] = cube[5][6];
			cube[5][6] = cube[6][3];
			cube[6][3] = cube[3][2];
			cube[3][2] = buf[0];
		}
	} else if (p == 'D') {
		
		rotate(d, 9, 3);
	} else if (p == 'F') {
		rotate(d, 6, 3);

	} else if (p == 'B') {
		rotate(d, 0, 3);

	}
}

int main() {
	int t, n;
	char cmd[3];
	initCube();
	scanf("%d %d", &t)
	while (t--) {
		scanf("%d", &n);
		while (n--) {
			scanf("%s", cmd);
			move(cmd[0], cmd[1]);
		}
	}
	return 0;
}
