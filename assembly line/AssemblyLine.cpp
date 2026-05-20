#include "AssemblyLine.h"
#include <iostream>
#include <algorithm>

using namespace std;

void AssemblyLineScheduling(int n, vector<vector<int>>& a, vector<vector<int>>& t, int e[], int x[]) {
	// n: number of stations;  a: processing times;  t: transfer times;  e: entry times;  x: exit times

	vector<int> f1(n + 1), f2(n + 1);  // f1[j]: min time to leave station j on line 1;  f2[j]: min time to leave station j on line 2
	vector<int> L1(n + 1), L2(n + 1);  // L1[j]: line chosen at station j on line 1;  L2[j]: line chosen at station j on line 2

	// Initialization: go to the first station
	f1[1] = e[0] + a[0][0];
	f2[1] = e[1] + a[1][0];

	for (int j = 2; j <= n; j++) {
		// Compute min time to get to station j on line 1
		if (f1[j - 1] <= f2[j - 1] + t[1][j - 2]) {
			f1[j] = f1[j - 1] + a[0][j - 1];
			L1[j] = 1;
		}
		else {
			f1[j] = f2[j - 1] + t[1][j - 2] + a[0][j - 1];
			L1[j] = 2;
		}
		// Compute min time to get to station j on line 2
		if (f2[j - 1] <= f1[j - 1] + t[0][j - 2]) {
			f2[j] = f2[j - 1] + a[1][j - 1];
			L2[j] = 2;
		}
		else {
			f2[j] = f1[j - 1] + t[0][j - 2] + a[1][j - 1];
			L2[j] = 1;
		}
	}

	int total_time, final_line;
	if (f1[n] + x[0] <= f2[n] + x[1]) {
		total_time = f1[n] + x[0];
		final_line = 1;
	}
	else {
		total_time = f2[n] + x[1];
		final_line = 2;
	}

	cout << "min time: " << total_time << endl;

	int curr_line = final_line;
	for (int j = n; j >= 2; j--) {
		if (curr_line == 1) {
			cout << "Station " << j << " on Line 1 " << endl;
			curr_line = L1[j];
		}
		else {
			cout << "Station " << j << " on Line 2 " << endl;
			curr_line = L2[j];
		}
	}
	cout << "Station 1 on Line " << curr_line << endl;
}