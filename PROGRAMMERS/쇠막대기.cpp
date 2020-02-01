#include <string>
#include <vector>
using namespace std;

int solution(string arrangement) {
	int ans = 0;
	int cnt = 0;

	for (int i = 0; i < arrangement.size(); i++) {
		if (arrangement[i] == '(') cnt++;
		else {
			if (arrangement[i - 1] == ')') {
				cnt--;
				ans += 1;
			}
			else {
				cnt--;
				ans += cnt;
			}
		}
	}


	return ans;
}


