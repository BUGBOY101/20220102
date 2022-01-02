#define	_CRT_SECURE_NO_WARNINGS 1

//找零钱问题：有几种方法
#include<iostream>
using namespace std;
int main() {
	int a[10], n, i, j, sum, dp[10][100];
	cout << "请输入零钱种类：";
	cin >> n;
	cout << "请输入零钱：";
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

//背包问题

//滚动数组
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
//	cout << "请输入物品数：";
//	cin >> n;
//	cout << "请输入最大容量：";
//	cin >> v;
//	for (i = 1; i <= n; i++) {
//		cin >> w[i] >> p[i];
//	}
//	memset(dp, 0, sizeof(dp));
//	for (i = 1; i <= n; i++) {
//		for (j = 1; j <= v; j++) {
//	//当能放得下这个物品时，放下这个物品，价值增加，但是空间减小，最大价值是dp[i - 1][j - w[i]] + p[i]
//	//当不放这个物品时，空间大，物品还是到i - 1，最大价值是dp[i - 1][j]
//	//比较这两个大小，取最大的，就是dp[i][j]
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

//最长公共子序列

//具体思想：设 X=(x1,x2,.....xn)和 Y={y1,y2,.....ym} 是两个序列，
//将 X 和 Y 的最长公共子序列记为LCS(X,Y)，
//如果 xn=ym，即X的最后一个元素与Y的最后一个元素相同，这说明该元素一定位于公共子序列中。
//因此，现在只需要找：LCS(Xn-1，Ym-1)就好，LCS(X,Y)=LCS(Xn-1，Ym-1)+1；
//如果xn != ym，这下要麻烦一点，因为它产生了两个子问题：LCS(Xn-1，Ym) 和 LCS(Xn，Ym-1)。

//动态规划解法：先创建一个解空间即数组，
//因为给定的是两个字符串即两个一维数组存储的数据，
//所以要创建一个二维数组，设字符串X有n个值，字符串Y有m个值，需要创建一个（m + 1） * （n + 1）的二维数组，
//二维数组每个位置（i，j）代表当长度为i的X子串与长度为j的Y的子串他们的最长公共子串，
//之所以要多创建一个是为了将边界值填入进去，
//边界值就是第一行跟第一列，指X长度为0或者Y长度为0时，自然需要填0，
//其他位置填数字时，当这两个位置数字相同，dp[i][j] = dp[i - 1][j - 1] + 1；
//当这两个位置数字不相同时，dp[i][j] = Math.max(dp[i][j - 1], dp[i - 1][j])。
//最后二维数组最右下角的值就是最大子串。

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

//数塔

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

//滚动数组
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

//最大连续子序列和

//令b[j]表示以位置 j 为终点的所有子区间中和最大的一个；
//子问题：如j为终点的最大子区间包含了位置j - 1, 则以j - 1为终点的最大子区间必然包括在其中；
//如果b[j - 1] > 0, 那么显然b[j] = b[j - 1] + a[j]，用之前最大的一个加上a[j]即可，因为a[j]必须包含进来；
//如果b[j - 1] <= 0, 那么b[j] = a[j], 因为既然最大，前面的负数必然不能使你更大。

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

//最长有序子序列

//#include<iostream>
//using namespace std;
//int main() {
//	int a[10] = { 1,4,7,2,5,8,3,6,9 }, i, j, dp[9];
//	for (i = 0; i < 9; i++)
//		dp[i] = 1;
//	
//	//memset(dp, 1, sizeof(dp));
//	//因为第一个程序的数组a是字符型的，字符型占据内存大小是1Byte，
//	//而memset函数也是以字节为单位进行赋值的，所以你输出没有问题。
//	//而第二个程序a是整型的，使用memset还是按字节赋值，这样赋值完以后，
//	//每个数组元素的值实际上是0x01010101即十进制的16843009。
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