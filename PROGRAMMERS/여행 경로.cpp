#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool DFS(string left, vector<bool>& visit, vector<string>& temp, vector<string>& ans, vector<vector<string>>& tickets, int cnt) {
	temp.push_back(left);

	if (cnt == tickets.size()) {
		ans = temp;
		return true;
	}

	for (int i = 0; i < tickets.size(); i++) {

		if (!visit[i] && left == tickets[i][0]) {
			visit[i] = true;

			if (DFS(tickets[i][1], visit, temp, ans, tickets, cnt + 1)) return true;

			visit[i] = false;
		}
	}

	temp.pop_back();
	return false;
}

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> ans, temp;
	vector<bool> visit(tickets.size(), false);

	sort(tickets.begin(), tickets.end());
	DFS("ICN", visit, temp, ans, tickets, 0);

	return ans;
}