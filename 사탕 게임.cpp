#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;
char cost[51][51];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, cnt = 0;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> cost[i][j];
		}
	}

	int ans = 0;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				
				if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
					swap(cost[x][y], cost[nx][ny]);
					cnt = 0;
					for (int z = 0; z < n; z++) {
						if (cost[x][y] == cost[z][y]) cnt++;
						else {
							ans = max(ans, cnt);
							cnt = 0;
						}
					}
					ans = max(ans, cnt);
					cnt = 0;
					for (int z = 0; z < n; z++) {
						if (cost[x][y] == cost[x][z]) cnt++;
						else {
							ans = max(ans, cnt);
							cnt = 0;
						}
					}				
					ans = max(ans, cnt);
					swap(cost[x][y], cost[nx][ny]);
				}
			}
		}
	}

	cout << ans << '\n';
	return 0;
}