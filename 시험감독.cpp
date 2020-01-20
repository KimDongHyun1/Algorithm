#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;
int A[1000001];
int N, B, C;
long long ans;


int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	cin >> B >> C;

	for (int i = 1; i <= N; i++) {

		A[i] -= B; // 총 감독관 사용
		ans++;

		if (A[i] <= 0) continue;

		ans += (A[i] + C - 1) / C;


	}


	cout << ans << '\n';
	return 0;
}

