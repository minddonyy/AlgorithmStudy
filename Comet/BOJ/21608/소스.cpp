using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
int length;
int num, a, b, c, d;
int arr[20][20] = { 0 };
int manjok[5] = { 0, 1, 10, 100, 1000 };
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { 1, -1, 0, 0 };
int friends[401][4] = { 0 };
struct yx
{
	int y, x, blank;
};
bool blankcompare(const yx& a, const yx& b) {
	return a.blank > b.blank;
}
bool yxcompare(const yx& a, const yx& b) {
	if (a.y == b.y) {
		return a.x < b.x;
	}
	else {
		return a.y < b.y;
	}
}
vector<yx> find() {
	vector<yx> ret;
	int max_cnt = 0;
	int ny, nx;
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length; ++j) {
			if (arr[i][j] != 0) continue;
			int cnt = 0;
			int blk = 0;
			for (int k = 0; k < 4; ++k) {
				ny = i + dy[k]; nx = j + dx[k];
				if (ny < 0 || ny >= length || nx < 0 || nx >= length) continue;
				if (arr[ny][nx] == 0) {
					++blk;
					continue;
				}
				if (arr[ny][nx] == a) ++cnt;
				else if (arr[ny][nx] == b) ++cnt;
				else if (arr[ny][nx] == c) ++cnt;
				else if (arr[ny][nx] == d) ++cnt;
			}
			if (cnt > max_cnt) {
				ret.clear();
				ret.push_back({ i, j , blk });
				max_cnt = cnt;
			}
			else if (cnt == max_cnt) {
				ret.push_back({ i, j , blk });
			}
		}
	}
	return ret;
}
vector<yx> many_blanks(vector<yx>& ret) {
	int gijun = ret[0].blank;
	vector<yx> newRet;
	for (auto& datas : ret) {
		if (datas.blank == gijun) {
			newRet.push_back(datas);
		}
		else {
			break;
		}
	}
	return newRet;
}
void print() {
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length; ++j) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
}
int main()
{	
	cin >> length;
	int limit = length * length;
	for (int rep = 0; rep < limit; ++rep) {
		cin >> num >> a >> b >> c >> d;
		friends[num][0] = a;
		friends[num][1] = b;
		friends[num][2] = c;
		friends[num][3] = d;
		// 1. 비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정한다.
		vector<yx> ret = find();
		if (ret.size() == 1) {
			arr[ret[0].y][ret[0].x] = num;
			continue;
		}
		// 1을 만족하는 칸이 여러 개이면, 인접한 칸 중에서 비어있는 칸이 가장 많은 칸으로 자리를 정한다.
		sort(ret.begin(), ret.end(), blankcompare);

		ret = many_blanks(ret);
		if (ret.size() == 1) {
			arr[ret[0].y][ret[0].x] = num;
			continue;
		}
		// 2를 만족하는 칸도 여러 개인 경우에는 행의 번호가 가장 작은 칸으로, 그러한 칸도 여러 개이면 열의 번호가 가장 작은 칸으로 자리를 정한다.
		sort(ret.begin(), ret.end(), yxcompare);
		arr[ret[0].y][ret[0].x] = num;
	}
	// 최종 만족도 구하기.
	int ny, nx;
	int result = 0;
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length; ++j) {
			int cnt = 0;
			auto& abcd = friends[arr[i][j]];
			for (int k = 0; k < 4; ++k) {
				ny = i + dy[k]; nx = j + dx[k];
				if (ny < 0 || ny >= length || nx < 0 || nx >= length) continue;
				if (arr[ny][nx] == abcd[0]) ++cnt;
				else if (arr[ny][nx] == abcd[1]) ++cnt;
				else if (arr[ny][nx] == abcd[2]) ++cnt;
				else if (arr[ny][nx] == abcd[3]) ++cnt;
			}
			result += manjok[cnt];
		}
	}
	print();
	cout << result << '\n';
	return 0;
}