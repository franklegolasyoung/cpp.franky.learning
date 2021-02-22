#include <iostream>
#include <vector>
using namespace std;

int n,N;
int f[66666][30];  //f[s][c]是状态为s,末尾字符为c的最大复杂度
string wrd[20];
int ans;

int main(){
	cin >> n;
	N=(1<<n)-1;
	for(int i=1;i<=n;i++)
		cin >> wrd[i];
	for(int i=1;i<=n;i++){
		f[1<<(i-1)][wrd[i][wrd[i].size()-1]-'A']=wrd[i].size();
		ans=max(ans,f[1<<(i-1)][wrd[i][wrd[i].size()-1]-'A']);  //初始化
	}
	for(int i=1;i<=n;i++)  //最多n个单词嘛
		for(int j=1;j<=n;j++)  //选择使用单词j
			for(int s=0;s<=N;s++)  //状态
				if(s & (1<<(j-1))) continue;  //选过惹~
				else{
					f[s + (1<<(j-1))][wrd[j][wrd[j].size()-1]-'A']=max(f[s+ (1<<(j-1))][wrd[j][wrd[j].size()-1]-'A'],
					(int)(f[s][wrd[j][0]-'A'] +wrd[j].size()));
					ans = max(ans,f[s+(1<<(j-1))][wrd[j][wrd[j].size()-1]-'A']);
					} 
	cout << ans;
	return 0;
} 