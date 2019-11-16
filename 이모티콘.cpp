#include "pch.h"
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int visited[2001][2001];
int cnt[2001][2001];
int n;


int main()
{
	cin >> n;
	queue<pair<int, int>> Q;
	Q.push(make_pair(1, 0));
	visited[1][0] = 1;

	while (!Q.empty()) {
		int num = Q.front().first;
		int clip = Q.front().second;
		Q.pop();

		if (num == n) {
			cout << cnt[num][clip] << '\n';
			return 0;
		}

		//clip에 저장한다.
		if (!visited[num][num]) {
			visited[num][num] = true;
			cnt[num][num] = cnt[num][clip] + 1;
			Q.push(make_pair(num, num));
		}

		//clip의 내용을 저장한다.(추가한다)
		if (!visited[num + clip][clip] && num + clip <= 1000) {
			visited[num + clip][clip] = true;
			cnt[num + clip][clip] = cnt[num][clip] + 1;
			Q.push(make_pair(num + clip, clip));
		}

		//-1한다.
		if (!visited[num - 1][clip] && num - 1 >= 0) {
			visited[num - 1][clip] = true;
			cnt[num - 1][clip] = cnt[num][clip] + 1;
			Q.push(make_pair(num - 1, clip));
		}
	}

	return 0;
}

