#define	_CRT_SECURE_NO_WARNINGS 1

//����Ǯ���⣺�м��ַ���
#include<iostream>
using namespace std;
int main() {
	int a[10], n, i, j, sum, dp[10][100];
	cout << "��������Ǯ���ࣺ";
	cin >> n;
	cout << "��������Ǯ��";
	cin >> sum;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	dp[0][0] = 1;
	for (i = 0; i <= sum; i++) {
		if (i % a[0] == 0) {
			dp[0][i] = 1;
		}
		else
			dp[0][i] = 0;
	}
	for (i = 1; i < n; i++)
		dp[i][0] = 1;
	for (i = 1; i < n; i++) {
		for (j = 1; j <= sum; j++) {
			if (j < a[i])
				dp[i][j] = dp[i - 1][j];
			else {
				dp[i][j] = dp[i - 1][j] + dp[i][j - a[i]];
			}
		}
	}
	cout << dp[n - 1][sum] << endl;
}

//��������

//��������
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int f(int w[], int p[], int n, int v) {
//	int dp[100], i, j;
//	memset(dp, 0, sizeof(dp));
//	for (i = 1; i <= n; i++) {
//		for (j = v; j >= 1; j--) {
//			if (j >= w[i]) {
//				dp[j] = max(dp[j], dp[j - w[i]] + p[i]);
//			}
//			else
//				dp[j] = dp[j];
//		}
//	}
//	return dp[n];
//}
//int main() {
//	int w[10], p[10], dp[10][10], i, j, n, v;
//	cout << "��������Ʒ����";
//	cin >> n;
//	cout << "���������������";
//	cin >> v;
//	for (i = 1; i <= n; i++) {
//		cin >> w[i] >> p[i];
//	}
//	memset(dp, 0, sizeof(dp));
//	for (i = 1; i <= n; i++) {
//		for (j = 1; j <= v; j++) {
//	//���ܷŵ��������Ʒʱ�����������Ʒ����ֵ���ӣ����ǿռ��С������ֵ��dp[i - 1][j - w[i]] + p[i]
//	//�����������Ʒʱ���ռ����Ʒ���ǵ�i - 1������ֵ��dp[i - 1][j]
//	//�Ƚ���������С��ȡ���ģ�����dp[i][j]
//			if (j >= w[i]) {
//				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + p[i]);
//			}
//			else
//				dp[i][j] = dp[i - 1][j];
//		}
//	}
//	cout << dp[n][v] << endl;
//	cout << f(w, p, n, v) << endl;
//}

//�����������

//����˼�룺�� X=(x1,x2,.....xn)�� Y={y1,y2,.....ym} ���������У�
//�� X �� Y ������������м�ΪLCS(X,Y)��
//��� xn=ym����X�����һ��Ԫ����Y�����һ��Ԫ����ͬ����˵����Ԫ��һ��λ�ڹ����������С�
//��ˣ�����ֻ��Ҫ�ң�LCS(Xn-1��Ym-1)�ͺã�LCS(X,Y)=LCS(Xn-1��Ym-1)+1��
//���xn != ym������Ҫ�鷳һ�㣬��Ϊ�����������������⣺LCS(Xn-1��Ym) �� LCS(Xn��Ym-1)��

//��̬�滮�ⷨ���ȴ���һ����ռ伴���飬
//��Ϊ�������������ַ���������һά����洢�����ݣ�
//����Ҫ����һ����ά���飬���ַ���X��n��ֵ���ַ���Y��m��ֵ����Ҫ����һ����m + 1�� * ��n + 1���Ķ�ά���飬
//��ά����ÿ��λ�ã�i��j����������Ϊi��X�Ӵ��볤��Ϊj��Y���Ӵ����ǵ�������Ӵ���
//֮����Ҫ�ഴ��һ����Ϊ�˽��߽�ֵ�����ȥ��
//�߽�ֵ���ǵ�һ�и���һ�У�ָX����Ϊ0����Y����Ϊ0ʱ����Ȼ��Ҫ��0��
//����λ��������ʱ����������λ��������ͬ��dp[i][j] = dp[i - 1][j - 1] + 1��
//��������λ�����ֲ���ͬʱ��dp[i][j] = Math.max(dp[i][j - 1], dp[i - 1][j])��
//����ά���������½ǵ�ֵ��������Ӵ���

//#include<iostream>
//#include<algorithm>
//using namespace std;
//int main() {
//	int dp[10][10], i, j, m, n;
//	char s1[10], s2[10];
//	cin >> s1 >> s2;
//	memset(dp, 0, sizeof(dp));
//	m = strlen(s1);
//	n = strlen(s2);
//	for (i = 1; i < m+1; i++) {
//		for (j = 1; j < n+1; j++) {
//			if (s1[i] == s2[j])
//				dp[i][j] = dp[i - 1][j - 1] + 1;
//			else
//				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//		}
//	}
//	cout << dp[m][n] << endl;
//}

//#include<iostream>
//using namespace std;
//int f(int a[], int n) {
//	int i, sum = a[0],max = a[0];
//	for (i = 1; i < n; i++) {
//		if (sum > 0)
//			sum += a[i];
//		else
//			sum = a[i];
//		if (sum > max)
//			max = sum;
//	}
//	return max;
//}
//
//int f2(int a[], int n) {
//	int dp[100], i, j, max;
//	for (i = 0; i < n; i++)
//		dp[i] = 1;
//	for (i = 0; i < n; i++) {
//		for (j = 0; j < i; j++) {
//			if (a[i] > a[j] && dp[i] < dp[j] + 1)
//				dp[i] = dp[j] + 1;
//		}
//	}
//	max = dp[0];
//	for (i = 1; i < n; i++) {
//		if (dp[i] > max)
//			max = dp[i];
//	}
//	return max;
//}
//
//int main() {
//	int a[10]={0}, dp[10], i, max, n;
//	cin >> n;
//	for (i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//	memset(dp, 0, sizeof(dp));
//	dp[0] = a[0];
//	for (i = 1; i < n; i++) {
//		if (dp[i - 1] > 0)
//			dp[i] = a[i] + dp[i - 1];
//		else
//			dp[i] = a[i];
//	}
//	max = dp[0];
//	for (i = 1; i < n; i++) {
//		if (dp[i] > max)
//			max = dp[i];
//	}
//	cout << f(a, n) << endl;
//	cout << max << endl;
//	cout << f2(a, n) << endl;
//}

//����

//#include<iostream>
//#include<algorithm>
//using namespace std;
//int main() {
//	int a[10][10], dp[10], i, j, n;
//	cin >> n;
//	for (i = 0; i < n; i++) {
//		for (j = 0; j <= i; j++)
//			cin >> a[i][j];
//	}
//	memset(dp, 0, sizeof(dp));
//	for (i = 0; i < n; i++)
//		dp[i] = a[n - 1][i];
//	for (i = n - 2; i >= 0; i--) {
//		for (j = 0; j <= i; j++) {
//			dp[j] = max(dp[j], dp[j + 1]) + a[i][j];
//		}
//	}
//	cout << dp[0] << endl;
//}

//��������
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int main() {
//	int a[10][10], dp[10], i, j;
//	int n;
//	cin >> n;
//	for (i = 0; i < n; i++) {
//		for (j = 0; j <= i; j++)
//			cin >> a[i][j];
//	}
//	memset(dp, 0, sizeof(dp));
//	for (i = 0; i < n; i++)
//		dp[i] = a[n-1][i];
//	for (i = n - 2; i >= 0; i--) {
//		for (j = 0; j <= i; j++) {
//			dp[j] = max(dp[j], dp[j + 1]) + a[i][j];
//		}
//	}
//	cout << dp[0] << endl;
//}

//������������к�

//��b[j]��ʾ��λ�� j Ϊ�յ�������������к�����һ����
//�����⣺��jΪ�յ����������������λ��j - 1, ����j - 1Ϊ�յ������������Ȼ���������У�
//���b[j - 1] > 0, ��ô��Ȼb[j] = b[j - 1] + a[j]����֮ǰ����һ������a[j]���ɣ���Ϊa[j]�������������
//���b[j - 1] <= 0, ��ôb[j] = a[j], ��Ϊ��Ȼ���ǰ��ĸ�����Ȼ����ʹ�����

//#include<iostream>
//using namespace std;
//int main() {
//	int a[100], dp[100], i,max;
//	int n;
//	cin >> n;
//	for (i = 0; i < n; i++) {
//		cin >> a[i];
//		dp[i] = 0;
//	}
//	dp[0] = a[0];
//	max = dp[0];
//	for (i = 1; i < n; i++) {
//		if (dp[i - 1] > 0)
//			dp[i] = dp[i - 1] + a[i];
//		else
//		{
//			dp[i] = a[i];
//		}
//		if (dp[i] > max)
//			max = dp[i];
//	}
//	cout << max << endl;
//}

//#include<iostream>
//using namespace std;
//int main() {
//	int a[10], i, Max,sum=0,n;
//	cin >> n;
//	for (i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//	Max = a[0];
//	for (i = 1; i < n; i++) {
//		sum = max(a[i] + sum, a[i]);
//		if (sum > Max)
//			Max = sum;
//	}
//	cout << Max << endl;
//}

//�����������

//#include<iostream>
//using namespace std;
//int main() {
//	int a[10] = { 1,4,7,2,5,8,3,6,9 }, i, j, dp[9];
//	for (i = 0; i < 9; i++)
//		dp[i] = 1;
//	
//	//memset(dp, 1, sizeof(dp));
//	//��Ϊ��һ�����������a���ַ��͵ģ��ַ���ռ���ڴ��С��1Byte��
//	//��memset����Ҳ�����ֽ�Ϊ��λ���и�ֵ�ģ����������û�����⡣
//	//���ڶ�������a�����͵ģ�ʹ��memset���ǰ��ֽڸ�ֵ��������ֵ���Ժ�
//	//ÿ������Ԫ�ص�ֵʵ������0x01010101��ʮ���Ƶ�16843009��
//
//	for (i = 1; i < 9; i++) {
//		for (j = 0; j < i; j++) {
//			if (a[i] > a[j] && dp[i] < dp[j] + 1) {
//				dp[i] = dp[j] + 1;
//			}
//		}
//	}
//	int max = dp[0];
//	for (i = 1; i < 9; i++) {
//		if (dp[i] > max)
//			max = dp[i];
//	}
//	cout << max << endl;
//}