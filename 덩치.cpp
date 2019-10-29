#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	int ans[50];
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back(make_pair(x, y));
		ans[i] = 1;
	}


	for (int i = 0; i < n; i++) {
		
		for (int j = 0; j < n; j++) {
			if ( (v[i].first < v[j].first) && (v[i].second < v[j].second)) ans[i]++;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
	return 0;
}

