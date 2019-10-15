#include <iostream>
#include <vector>
using namespace std;
vector<int> lotto;

void check(vector<int> &a, int index, int cnt) {
	if (cnt == 6) {
		for (int i = 0; i < lotto.size(); i++) {
			cout << lotto[i] << ' ';
		}
		cout << '\n';
		return;
	}

	if (a.size() == index) return;
	lotto.push_back(a[index]);
	check(a, index + 1, cnt + 1);
	lotto.pop_back();
	check(a, index + 1, cnt);
}

int main() {

	while (true) {
		int k;
		cin >> k;
		if (k == 0) break;
		vector<int> a(k);
		for (int i = 0; i < k; i++) {
			cin >> a[i];
		}

		check(a, 0, 0);
		cout << '\n';
	}
}