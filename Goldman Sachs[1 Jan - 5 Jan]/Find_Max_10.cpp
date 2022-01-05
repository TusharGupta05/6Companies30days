// Find max 10 numbers in a list having 10M entries.
// Time Complexity: O(2*n)=O(n)

#include<bits/stdc++.h>
using namespace std;
class Solution {
	int findMax(vector<int>& nums, int st, int n) {
		int idx = st;
		for (st++; st < n; st++) {
			if (nums[idx] < nums[st]) {
				idx = st;
			}
		}
		return idx;
	}
public:
	vector<int> findMax10(vector<int>& nums) {
		vector<int> ans;
		vector<int> temp(10);
		for (int i = 0; i < 10; i++) {
			temp[i] = findMax(nums, i * 1e6, (i + 1) * 1e6);
		}
		while (ans.size() < 10) {
			int idx = findMax(temp, 0, 10);
			ans.push_back(nums[temp[idx]]);
			if (ans.size() == 10) {
				break;
			}
			nums[temp[idx]] = -1;
			temp[idx] = findMax(nums, idx * 1e6, (idx + 1) * 1e6);
		}
		return ans;
	}
};

int main() {
	vector<int> nums;
	for (int i = 0; i < 1e7; i++) {
		nums.push_back(rand());
	}
	for (int i : Solution().findMax10(nums)) {
		cout << i << " ";
	}
}