#include <iostream>
#include <queue>
using namespace std;
int n, k;
int check[100001];

int main()
{
	cin >> n >> k;
	queue<int> q;
	q.push(n);

	while (!q.empty() && q.front() != k) {
		int x = q.front();
		q.pop();
		int num1 = x - 1;
		int num2 = x + 1;
		int num3 = x * 2;
		if (num1 >= 0 && !check[num1]) {
			check[num1] = check[x] + 1;
			q.push(num1);
		}
		if (num2 <= 100000 && !check[num2]) {
			check[num2] = check[x] + 1;
			q.push(num2);
		}
		if (num3 <= 100000 && !check[num3]) {
			check[num3] = check[x] + 1;
			q.push(num3);
		}

	}

	cout << check[k] << '\n';
}
