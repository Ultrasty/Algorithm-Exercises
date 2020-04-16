#include<iostream>
#include<vector>
using namespace std;

class Nqueen{
public:
	Nqueen(int nn) {
		n = nn;
		x.resize(nn);
		matrix.resize(nn);
		for (int i = 0; i < n; i++) {
			matrix[i].resize(nn);
		}
	}

	bool placetest(int k,int i) {
		for (i = 0; i < k; i++) {
			if (x[i] == x[k] || abs(x[i] - x[k]) == abs(i - k)) return false;
		}
		return true;
	}

	void run(int k) {
		if (k >= n) {
			for (int i = 0; i < n; i++) {
				matrix[i][x[i]] = 1;
			}
			cout << endl;

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (matrix[i][j] == 0)cout << "¡õ";
					else cout << "¡ö";
					matrix[i][j] = 0;
				}
				cout << endl;
			}
		}
		else {
			for (int i = 0; i < n; i++) {
				x[k] = i;
				if (placetest(k,i)){
					run(k + 1);
				}
			}
		}
	}
private:
	vector<int> x;
	vector<vector<int>> matrix;
	int n;
};


int main() {
	int n;
	cout << "n= ";
	cin >> n;
	Nqueen nqueen(n);
	nqueen.run(0);
}