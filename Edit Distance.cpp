#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	//求最小值
	int min(int a,int b) {
		return a < b ? a : b;
	}

	//用自底向上的动态规划的方法求编辑距离
	int distance(string str1, string str2) {
		int len1 = str1.length();
		int len2 = str2.length();
		vector<vector<int>> op;
		op.resize(len1 + 1);
		for (int i = 0; i < len1 + 1; i++)op[i].resize(len2 + 1);
		//构造动态规划初始解
		for (int i = 0; i < len1 + 1; i++) {
			for (int j = 0; j < len2 + 1; j++) {
				if (i == 0)op[i][j] = j;
				else if (j == 0)op[i][j] = i;
				else op[i][j] = 0;
			}
		}
		//动态规划
		for (int i = 0; i < len1; i++) {
			for (int j = 0; j < len2; j++) {
				if (str1[i] == str2[j]) {
					op[i + 1][j + 1] = op[i][j];
				}
				else {
					//状态转移方程
					op[i + 1][j + 1] = 1 + min(min(op[i + 1][j], op[i][j + 1]), op[i][j]);
				}
			}
		}
		return op[len1][len2];
	}
};

int main() {
	Solution s;
	cout<<s.distance("fab", "afa");
}