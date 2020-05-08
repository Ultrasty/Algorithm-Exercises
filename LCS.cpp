#include<iostream>
#include<vector>
#include<string>
using namespace std;

void length(string x, string y, vector<vector<int>>& c, vector<vector<int>>& b) {
	int m = x.length();
	int n = y.length();
	
	for (int i = 1; i < m + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (x[i-1] == y[j-1]) {
				c[i][j] = c[i - 1][j - 1]+1;
				b[i][j] = -1;//↖
			}
			else if (c[i - 1][j] >= c[i][j - 1]) {
				c[i][j] = c[i - 1][j];
				b[i][j] = 0;//↑
			}
			else {
				c[i][j] = c[i][j - 1];
				b[i][j] = 1;//←
			}
		}
	}
}

string getLCS(string x,string y, vector<vector<int>>& b) {
	string LCS;
	int i = x.length()-1;
	int j = y.length()-1;
	while (i != -1 && j != -1) {
		switch (b[i+1][j+1]){
		case -1:
			LCS = x[i]+LCS;
			i--; j--; break;
		case 0:
			i--; break;
		case 1:
			j--; break;
		}
	}
	return LCS;
}

int main() {
	string x,y;
	cin >> x;
	cin >> y;
	int m = x.length();
	int n = y.length();
	vector<vector<int>> c(m + 1);
	vector<vector<int>> b(m + 1);
	for (int i = 0; i < m + 1; i++) {
		c[i].resize(n + 1);
		b[i].resize(n + 1);
	}
	length(x, y, c, b);
	/*for (int i = 0; i < m + 1; i++) {
		for (int j = 0; j < n + 1; j++)
			cout << c[i][j] << " ";
		cout << endl;
	}
	for (int i = 0; i < m + 1; i++) {
		for (int j = 0; j < n + 1; j++)
			cout << b[i][j] << " ";
		cout << endl;
	}这是用来检查矩阵的*/
	cout << getLCS(x,y,b);
}