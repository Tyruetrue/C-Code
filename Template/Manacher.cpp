#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
string a,s;
int n;
int p[32000005];
int main(){
	scanf("%d",&n); 
	cin>>a;
	s+="~#";
	for(int i=0;i<a.size();i++){
		s+=a[i];
		s+="#";
	}
	int mxp=1,mid=1,ans=-1;
	for(int i=1;i<s.size();i++){
		if(i<mxp){
			p[i]=min(mxp-i,p[mid*2-i]);
		}else{
			p[i]=1;
		}
		while(s[i-p[i]]==s[i+p[i]]){
			p[i]++;
		}
		if(mxp<i+p[i]){
			mid=i;
			mxp=i+p[i];
		}
		ans=max(ans,p[i]-1);
	}
	printf("%d",ans);
	return 0;
}
