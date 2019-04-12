#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
#include <string>
using namespace std;

vector<vector<bool>> board(8, vector<bool>(8, true));

pair<int, int> king, stone;

pair<int, int> convert(string pos) {
	return make_pair('8' - pos[1], pos[0] - 'A');
}

pair<int, int> next(string pos) {
	int nr = 0, nc = 0;
	if (pos == "R") nc++;
	else if (pos == "L") nc--;
	else if (pos == "B") nr++;
	else if (pos == "T") nr--;
	else if (pos == "RT") { nc++; nr--; }
	else if (pos == "LT") { nc--; nr--; }
	else if (pos == "RB") { nc++; nr++; }
	else if (pos == "LB") { nc--; nr++; }
	return make_pair(nr, nc);
}

int main() {
	string pos;
	int n, nr, nc, snr, snc;
	pair<int, int> nxt;
	// king pos
	cin >> pos;
	king = convert(pos);
	// stone pos
	cin >> pos;
	stone = convert(pos);
	board[stone.first][stone.second] = false;
	cin >> n;
	while (n--) {
		cin >> pos;
		nxt = next(pos);
		nr = king.first + nxt.first;
		nc = king.second + nxt.second;
		// 보드를 벗어나는 경우
		if (nc < 0 || nc >= 8 || nr < 0 || nr >= 8) continue;
		// 이동 경로에 돌이 있는 경우
		if (nr == stone.first && nc == stone.second) {
			snr = stone.first + nxt.first;
			snc = stone.second + nxt.second;
			if (snc < 0 || snc >= 8 || snr < 0 || snr >= 8) continue;
			stone = make_pair(snr, snc);
		}
		// 돌이 보드를 벗어나는 경우
		king = make_pair(nr, nc);
	}
	printf("%c%c\n", king.second + 'A', '8' - king.first);
	printf("%c%c\n", stone.second + 'A', '8' - stone.first);
	return 0;
}
