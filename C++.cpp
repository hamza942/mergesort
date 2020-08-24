#include<iostream>
#include<string.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;
int merge(vector<int>&ar,int q,int t) {
	vector<int>part_1;
	vector<int>part_2;
	int avg = ((q + t)/2) + 1;
	for (int x = q; x < avg; x++) {
		part_1.push_back(ar[x]);
	}
	for (int a = avg; a <= t; a++) {
		part_2.push_back(ar[a]);
	}
	int v = q;
	while (!part_1.empty()&& !part_2.empty()) {
		if (part_1[0] <= part_2[0]) {
			ar[v] = part_1[0];
			part_1.erase(part_1.begin() + 0);
		}
		else {
			ar[v] = part_2[0];
			part_2.erase(part_2.begin() + 0);
		}
		v++;
	}
	if (!part_1.empty()) {
		while (!part_1.empty()) {
			ar[v] = part_1[0];
			part_1.erase(part_1.begin() + 0);
			v++;
	    }
	}
	else if (!part_2.empty()) {
		while (!part_2.empty()) {
			ar[v] = part_2[0];
			part_2.erase(part_2.begin() + 0);
			v++;
		}
	}

	return 0;
}    
int mergsort(vector<int>&ar,int l,int r) {
	if (l >= r) {
		return 0;
	}
	int avg = (l + r) / 2;
	mergsort(ar, l, avg);
	mergsort(ar, avg+1, r);
	merge(ar, l, r);
    

}

int main() {
	vector<int>ar = { 1,98,13,9,7,23,4,6};
	mergsort(ar, 0,7);
	for (int x = 0; x < ar.size(); x++) {
		cout << ar[x] << " ";
	}
}

