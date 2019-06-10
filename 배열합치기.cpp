#include <iostream>
#include <vector>
using namespace std;
int a[1000000];
int b[1000000];
vector<int> ans;

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	int i = 0, j = 0;
	while (true) {
		if (a[i] < b[j]) {
			ans.push_back(a[i]);
			i++;
		}
		else {
			ans.push_back(b[j]);
			j++;
		}

		if (i == n) {
			while (j != m) {
				ans.push_back(b[j]);
				j++;
			}
			break;
		}
		if (j == m) {
			while (i != n) {
				ans.push_back(a[i]);
				i++;
			}
			break;
		}
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
	return 0;
}