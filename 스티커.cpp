#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int d[2][100001]; // 

int main() {
	int k;
	cin >> k;

	while (k--) {
		int n;
		cin >> n;
		int arr[2][100001];

		for (int i = 0; i < 2; i++) {
			for (int j = 2; j <= n + 1; j++) {
				cin >> arr[i][j];
			}
		}

		for (int i = 2; i <= n + 1; i++) {
			d[0][i] = max(max(d[1][i - 1] + arr[0][i], d[0][i - 1]), d[1][i - 2] + arr[0][i]);
			d[1][i] = max(max(d[0][i - 1] + arr[1][i], d[1][i - 1]), d[0][i - 2] + arr[1][i]);
		}

		cout << max(d[0][n + 1], d[1][n + 1]) << '\n';
	}
}