#include "pch.h"
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int kx, ky, sx, sy, n;
int nkx, nky, nsx, nsy;
string s1, s2, cur;

int main(void) {
	cin >> s1 >> s2 >> n;
	ky = s1[0] - 'A' + 1; kx = s1[1] - '0';
	sy = s2[0] - 'A' + 1; sx = s2[1] - '0';

	while (n--) {
		cin >> cur;
		nkx = kx; nky = ky; nsx = sx; nsy = sy;

		if (cur == "R") {
			nky = ky + 1;
			nsy = sy + 1;
		}
		else if (cur == "L") {
			nky = ky - 1;
			nsy = sy - 1;
		}
		else if (cur == "B") {
			nkx = kx - 1;
			nsx = sx - 1;
		}
		else if (cur == "T") {
			nkx = kx + 1;
			nsx = sx + 1;
		}
		else if (cur == "RT") {
			nky = ky + 1;
			nsy = sy + 1;
			nkx = kx + 1;
			nsx = sx + 1;
		}
		else if (cur == "LT") {
			nky = ky - 1;
			nsy = sy - 1;
			nkx = kx + 1;
			nsx = sx + 1;
		}
		else if (cur == "RB") {
			nky = ky + 1;
			nsy = sy + 1;
			nkx = kx - 1;
			nsx = sx - 1;
		}
		else if (cur == "LB") {
			nky = ky - 1;
			nsy = sy - 1;
			nkx = kx - 1;
			nsx = sx - 1;
		}

		if (nkx >= 1 && nkx <= 8 && nky >= 1 && nky <= 8) {
			if (nkx == sx && nky == sy) {
				if (nsx >= 1 && nsx <= 8 && nsy >= 1 && nsy <= 8) {
					kx = nkx;
					ky = nky;
					sx = nsx;
					sy = nsy;
				}
			}
			else {
				kx = nkx;
				ky = nky;
			}
			
		}

		//cout << char(ky + 'A' - 1) << kx << '\n';
		//cout << char(sy + 'A' - 1) << sx << '\n';
	}

	cout << char(ky + 'A' - 1) << kx << '\n';
	cout << char(sy + 'A' - 1) << sx << '\n';
}