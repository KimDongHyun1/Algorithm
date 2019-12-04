#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		
		long long share = 1;
		for (int i = m; i > m - n; i--) {
			share *= i;
		}
		for (int i = 2; i <= n; i++) {
			share /= i;
		}
			
		cout << share << '\n';
	}


	return 0;
}

