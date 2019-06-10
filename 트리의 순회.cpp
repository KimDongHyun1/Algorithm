#include <iostream>
#include <vector>
using namespace std;
int in[100001];
int post[100001];
int position[100001];
int n, root;

void pre(int is, int ie, int ps, int pe) {
	if (is > ie) return;
	root = post[pe];
	cout << root << ' ';

	int p = position[root];
	int left = p - is;


	pre(is, p - 1, ps, ps + left - 1);
	pre(p + 1, ie, ps + left, pe - 1);
}



int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> in[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> post[i];
	}
	for (int i = 0; i < n; i++) {
		position[in[i]] = i;
	}

	pre(0, n - 1, 0, n - 1);
}