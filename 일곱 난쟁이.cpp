#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;
int cost[10];

int main()
{
	for (int i = 0; i < 9; i++) cin >> cost[i];
	sort(cost, cost+9);

	do {
		int sum = 0;
		for (int i = 0; i < 7; i++) {
			sum += cost[i];
		}
		if (sum == 100) break;
		
	} while (next_permutation(cost, cost + 9));

	for (int i = 0; i < 7; i++) {
		cout << cost[i] << ' ';
	}

	cout << '\n';
	return 0;
}

