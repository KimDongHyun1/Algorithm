#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int num = 665;
	int sum = 0;

	while (true) {

		num++;
		
		int cnt = 0;
		int mok = num;
		do {
			int nmg = mok % 10;
			mok = mok / 10;

			if (cnt > 0 && nmg != 6) cnt = 0;
			if (nmg == 6) cnt++;
			if (cnt == 3) break;
		} while (mok);


		if (cnt == 3) sum++;
		if (sum == n) break;

	}

	cout << num << '\n';
	return 0;
}

