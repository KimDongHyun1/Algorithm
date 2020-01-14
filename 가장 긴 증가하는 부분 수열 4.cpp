#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a[1001];
int dp[1001];
int n;
vector<int> v[1001];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 0; i < n; i++) {
		v[i].push_back(a[i]);
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i] && v[j].size()+1 > v[i].size()) {
				for (int k = 0; k < v[j].size(); k++) {
					v[i][k] = v[j][k];
				}
				v[i].push_back(a[i]);
			}
		}
	}

	int Max = 0;
	int index = 0;
	for (int i = 0; i < n; i++) {
		if (Max < v[i].size()) {
			Max = v[i].size();
			index = i;
		}
	}

	cout << v[index].size() << '\n';
	for (int i = 0; i < v[index].size(); i++) {
		cout << v[index][i] << ' ';
	}

	return 0;
}

