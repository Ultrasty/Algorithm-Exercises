#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	//����Сֵ
	int min(int a,int b) {
		return a < b ? a : b;
	}

	//���Ե����ϵĶ�̬�滮�ķ�����༭����
	int distance(string str1, string str2) {
		int len1 = str1.length();
		int len2 = str2.length();
		vector<vector<int>> op;
		op.resize(len1 + 1);
		for (int i = 0; i < len1 + 1; i++)op[i].resize(len2 + 1);
		//���춯̬�滮��ʼ��
		for (int i = 0; i < len1 + 1; i++) {
			for (int j = 0; j < len2 + 1; j++) {
				if (i == 0)op[i][j] = j;
				else if (j == 0)op[i][j] = i;
				else op[i][j] = 0;
			}
		}
		//��̬�滮
		for (int i = 0; i < len1; i++) {
			for (int j = 0; j < len2; j++) {
				if (str1[i] == str2[j]) {
					op[i + 1][j + 1] = op[i][j];
				}
				else {
					//״̬ת�Ʒ���
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