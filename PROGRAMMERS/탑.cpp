#include "pch.h"
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
stack<pair<int, int>> S;
vector<int> heights;


vector<int> solution(vector<int> heights) {
	vector<int> answer;

	for (int i = 0; i < heights.size(); i++) {

		while (!S.empty() && S.top().first <= heights[i]) {
			S.pop();
		}

		if (S.empty()) {
			answer.push_back(0);
		}
		else {
			answer.push_back(S.top.second);
		}

		S.push({ heights[i], i + 1 });

	}

	return answer;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		heights.push_back(x);
	}

	solution(heights);
}
