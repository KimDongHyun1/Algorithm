#include "pch.h"
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;
string save[10001];
int visit[10001];
int T, A, B, num, flag;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	while (T--) {
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i <= 10000; i++) {
			save[i] = "";
		}

		cin >> A;
		cin >> B;
		
		queue<int> Q;
		Q.push(A);
		visit[A] = true;
		
		while (!Q.empty()) {
			int size = Q.size();
			
			flag = false;
			while (size--) {
				int x = Q.front();
				Q.pop();

				if (x == B) {
					cout << save[B] << '\n';
					flag = true;
					break;
				}

				num = (x * 2) % 10000;
				if (!visit[num]) {
					visit[num] = true;
					Q.push(num);
					save[num] = save[x] + "D";
				}

				if (x == 0) {
					num = 9999;
					if (!visit[num]) {
						visit[num] = true;
						Q.push(num);
						save[num] = save[x] + "S";
					}
				}
				else {
					num = x - 1;
					if (!visit[num]) {
						visit[num] = true;
						Q.push(num);
						save[num] = save[x] + "S";
					}
				}

				num = (x % 1000) * 10 + x / 1000;
				if (!visit[num]) {
					visit[num] = true;
					Q.push(num);
					save[num] = save[x] + "L";
				}

				num = (x % 10) * 1000 + x / 10;
				if (!visit[num]) {
					visit[num] = true;
					Q.push(num);
					save[num] = save[x] + "R";
				}
			}
			if (flag) break;
		}
		
	}
}

