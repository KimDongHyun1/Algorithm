#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool check(vector<int> &num, vector<char> &sign) {
	for (int i = 0; i < sign.size(); i++) {
		if (sign[i] == '<' && (num[i] > num[i + 1])) return false;
		if (sign[i] == '>' && (num[i] < num[i + 1])) return false;
	}
	return true;
}

int main() {
	int k;
	cin >> k;

	vector<char> sign(k);
	for (int i = 0; i < k; i++) {
		cin >> sign[i];
	}

	vector<int> small(k + 1);
	vector<int> big(k + 1);

	for (int i = 0; i < k + 1; i++) {
		small[i] = i;
		big[i] = 9 - i;
	}

	do {
		if (check(small, sign)) {
			break;
		}
	} while (next_permutation(small.begin(), small.end()));

	do {
		if (check(big, sign)) {
			break;
		}
	} while (prev_permutation(big.begin(), big.end()));

	for (int i = 0; i < big.size(); i++) {
		cout << big[i];
	}
	cout << '\n';
	for (int i = 0; i < small.size(); i++) {
		cout << small[i];
	}
	cout << '\n';
	return 0;
}