#include <iostream>
#include <vector>
using namespace std;
string st[18];
vector <int> v[210];//动态数组
int f[18];//标记数组
int dfs(int x){
	int ans=0;
	for(auto i:v[st[x][st[x].size()-1]])//v数组是存第1个字母的一个容器
		if(!f[i]){
			f[i]=1;//标记这个字符串已经用过了
			ans=max(ans,dfs(i));//递归
			f[i]=0;//回溯
		}
	return ans+st[x].size();
}
int main(){
	int ans=0,n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin>>st[i];
		v[st[i][0]].push_back(i);//读入，放入vector容器
	}
	for(int i=1;i<=n;i++){
		f[i]=1;//标记
		ans=max(ans,dfs(i));//递归找到最优解
		f[i]=0;//回溯
	}
	cout << ans;
    return 0;
}