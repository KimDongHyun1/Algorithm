#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
string s[11];
int alphabet[26]; // A ~ Z
int n, ans;
vector<char> v;
vector<int> num;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		s[i] = str;

		for (int j = 0; j < str.size(); j++) {
			if (alphabet[str[j] - 'A'] == 0) {
				v.push_back(str[j]);
				alphabet[str[j] - 'A'] = true;
			}
		}
	}

	for (int i = 0; i < v.size(); i++) {
		num.push_back(9 - i);
	}

	// A B C
	// 7 8 9

	sort(v.begin(), v.end());
	sort(num.begin(), num.end());


	do {

		for (int i = 0; i < num.size(); i++) {
			alphabet[v[i] - 'A'] = num[i];
		}

		int sum = 0;
		for (int i = 0; i < n; i++) {
			int val = 0;
			int gob = 1;

			for (int j = s[i].size() - 1; j >= 0; j--) {
				val = val + alphabet[s[i][j] - 'A'] * gob;
				gob *= 10;
			}

			sum += val;
		}

		ans = max(ans, sum);
	} while (next_permutation(num.begin(), num.end()));

	cout << ans << '\n';
	return 0;
}
