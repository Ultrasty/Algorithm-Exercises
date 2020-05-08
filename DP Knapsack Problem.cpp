#include<iostream>
#include<vector>
using namespace std;

void knapsack(vector<int> v,int n,int W,vector<vector<int>>& V,
	vector<int> weight,vector<vector<int>>& keep) {
	int w;
	for (w = 0; w <= W; w++)V[0][w] = 0;
	for (int i = 1; i <= n; i++)
		for (w = 0; w <= W; w++) {
			if ((weight[i] <= w) && (v[i] + V[i - 1][w - weight[i]] > V[i - 1][w])) {
				V[i][w] = v[i] + V[i - 1][w - weight[i]];
				keep[i][w] = 1;
			}
			else {
				V[i][w] = V[i - 1][w];
				keep[i][w] = 0;
			}
		}
	int K = W;
	for(int i=n;i>=0;i--)
		if (keep[i][K] == 1) {
			cout <<"选择的物品为"<< i << " "<<endl;
			K -= weight[i];
		}
}

int main() {
	vector<vector<int>> V, keep;
	int n, W;
	cout << "输入n W:";
	cin >> n >> W;
	V.resize(n + 1);
	keep.resize(n + 1);
	for (int i = 0; i < n + 1; i++) {
		V[i].resize(W + 1);
		keep[i].resize(W + 1);
	}
	vector<int> v, weight;
	v.push_back(0);
	weight.push_back(0);
	cout << "输入n个 w v对：" << endl;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		weight.push_back(x);
		v.push_back(y);
	}
	knapsack(v, n, W, V, weight, keep);
	cout << "最大价值为" << V[n][W]<<endl;
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < W + 1; j++) {
			cout << V[i][j] << "\t";
		}
		cout << endl;
	}

}
