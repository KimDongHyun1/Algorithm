#include <iostream>
#include <vector>
using namespace std;
long long f[21] = { 1 };
bool c[21];

int main() {
	for (int i = 1; i <= 20; i++) {
		f[i] = f[i - 1] * i; // 팩토리알 
	}
	int n;
	cin >> n;
	int num;
	cin >> num;
	if (num == 2) {
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		long long ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < a[i]; j++) {
				if (c[j] == false) { // 똑같은 수가 있는거는 중복되면 안되니 뺴주는거
					ans += f[n - i - 1]; // 만약에 3이라면 그전에 1,2때의 순열들을 다 더해준다는 뜻이다.
				}
			}
			c[a[i]] = true; // 똑같은 수가반복이 안되게 쓰는거임
		}
		cout << ans + 1 << '\n';
	}
	else if (num == 1) {
		long long k;
		cin >> k;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			for (int j = 1; j <= n; j++) {
				if (c[j] == true) continue;
				if (f[n - i - 1] < k) {
					k -= f[n - i - 1];
				}
				else {
					a[i] = j;
					c[j] = true;
					break;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';
	}
}