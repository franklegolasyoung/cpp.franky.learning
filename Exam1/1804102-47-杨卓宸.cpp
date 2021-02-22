#include<iostream>
using namespace std;
#define MAX 99999 
int n,MIN;
int f[40][40];//表示i-j区间的合并最优解 
int a[40];//数据列 
int s[40];//前i堆石子总数 
inline int sum(int i,int j){return s[j]-s[i-1];}
//转移方程：f[i][j] = min(f[i][k]+f[k+1][j]+sum[i][j]);
int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];//输入数据列 
        a[i+n]=a[i];//数据首尾相接复制，把环打开成单列 
    }
    for(int i=1;i<=2*n;i++)
    	s[i]=s[i-1]+a[i];//预先求出前缀和，方便调用 
    for(int len=1;len<n;len++){//枚举区间长度 
        for(int i=1,j=i+len;(j<2*n)&&(i<2*n);i++,j=i+len){//枚举区间起点 
            f[i][j]=MAX;
            if(j<2*n)
                for(int k=i;k<j;k++){//枚举分割点，构造状态转移方程 
                    f[i][j] = min(f[i][j],f[i][k]+f[k+1][j]+sum(i,j));
                }
        }
    }
    MIN=MAX;
    for(int i=1;i<=n;i++){//枚举环状序列的起点，长度为n
        MIN=min(MIN,f[i][i+n-1]);//求出最大值 
    }
    cout << MIN;
    return 0;
}
