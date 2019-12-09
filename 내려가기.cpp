// dp[100001][3] 이런식으로 해결할 경우 메모리 초과가 난다

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
int x1, x2, x3;
int pre_min[1][3]; int now_min[1][3];
int pre_max[1][3]; int now_max[1][3];

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x1 >> x2 >> x3;
		now_max[0][0] = max(pre_max[0][0], pre_max[0][1]) + x1;
		now_max[0][1] = max({ pre_max[0][0],pre_max[0][1],pre_max[0][2] }) + x2;
		now_max[0][2] = max(pre_max[0][1], pre_max[0][2]) + x3;
		pre_max[0][0] = now_max[0][0]; pre_max[0][1] = now_max[0][1]; pre_max[0][2] = now_max[0][2];

		now_min[0][0] = min(pre_min[0][0], pre_min[0][1]) + x1;
		now_min[0][1] = min({ pre_min[0][0],pre_min[0][1],pre_min[0][2] }) + x2;
		now_min[0][2] = min(pre_min[0][1], pre_min[0][2]) + x3;
		pre_min[0][0] = now_min[0][0]; pre_min[0][1] = now_min[0][1]; pre_min[0][2] = now_min[0][2];
	}

	cout << max({ now_max[0][0], now_max[0][1],now_max[0][2] }) << ' ';
	cout << min({ now_min[0][0],now_min[0][1],now_min[0][2] }) << '\n';
	return 0;
}

