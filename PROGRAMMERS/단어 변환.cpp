#include <algorithm>
#include <vector>
#include <string>
using namespace std;
bool visit[51];
string B, T;
vector<string> words;
int ans;

void DFS(string now, string target, vector<string> words, int COUNT) {
	if (now == target) {
		ans = min(ans, COUNT);
		return;
	}

	for (int i = 0; i < words.size(); i++) {

		if (!visit[i]) {
			int cnt = 0;
			for (int a = 0; a < now.size(); a++) {
				if (now[a] != words[i][a]) cnt++;
			}

			if (cnt == 1) {
				visit[i] = true;
				DFS(words[i], target, words, COUNT + 1);
				visit[i] = false;
			}
		}

	}


}

int solution(string begi, string target, vector<string> words) {
	ans = words.size() + 1;

	DFS(begin, target, words, 0);

	if (ans == words.size() + 1) return 0;
	else return ans;
}

