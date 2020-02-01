// 깔끔하게 다시 풀어보기
// 시간을 1초씩 계속 증가시켜주면서
// queue에 값을 하나씩 (값, 시간)을 넣는다.
// 만약 queue에 값을 더한 값 + 다음 truck의 값을 넣기 가능하다면 넣어주고 시간들을 + 1
// 안되면 그냥 시간들을 + 1

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<int> truck_weights;
queue<pair<int, int>> Q; // 값(무게) , 타임
int cnt, truck_index, sum;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	
	while (true) {
		if (truck_weights.size() == truck_index && Q.empty()) break;

		if (Q.empty()) {
			cnt++;
			Q.push({ truck_weights[truck_index++], 1 });
			
		}
		else {
			cnt++;
			// 7 4 5 6  || 2초
			while (!Q.empty() && Q.front().second == bridge_length) Q.pop();

			sum = 0; // 몸무게 합
			for (int i = 0; i < Q.size(); i++) {
				sum += Q.front().first;
				Q.push({ Q.front().first, Q.front().second + 1});
				Q.pop();
			}

			
			if (truck_index < truck_weights.size() && truck_weights[truck_index] + sum <= weight)
				Q.push({ truck_weights[truck_index++], 1 });
			
		}
	}

	return cnt;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		truck_weights.push_back(x);
	}

	int bridge_length, weight;
	cin >> bridge_length >> weight;
	solution(bridge_length, weight, truck_weights);
}

