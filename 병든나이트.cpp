#include "pch.h"
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
using namespace std;
int d[1000000];

int go(int n)
{
	if (n == 1) return 0;
	if (d[n] > 0) return d[n];

	d[n] = 1 + go(n - 1);
	if (n % 2 == 0) {
		int temp = 1 + go(n / 2);
		if (d[n] > temp) d[n] = temp;
	}
	if (n % 3 == 0) {
		int temp = 1 + go(n / 3);
		if (d[n] > temp) d[n] = temp;
	}
	return d[n];

}

int main()
{
	int x;
	cin >> x;
	cout << go(x) << '\n';
	return 0;
}

int main() {
	int n;
	cin >> n;

	cout << go(n) << '\n';
}

