#include <iostream>
#include <string>
using namespace std;
int m, x;
int ans = 0;
string s;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> m;

	while (m--) {
		cin >> s;

		if (s == "add") {
			cin >> x;
			x--;
			ans = ans | (1 << x);
		}
		else if (s == "remove") {
			cin >> x;
			x--;
			ans = ans & ~(1 << x);
		}
		else if (s == "check") {
			cin >> x;
			x--;
			if (((ans & (1 << x)) == (1 << x))) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (s == "toggle") {
			cin >> x;
			x--;
			ans = ans ^ (1 << x);
		}
		else if (s == "all") {
			ans = (1 << 20) - 1;
		}
		else if (s == "empty") {
			ans = 0;
		}
	}
}
