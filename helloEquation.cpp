#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

string solution(int n){
	for(int i = 1; i*i<=n; i++){
		if(((n-2*i) % (2+i)) == 0 && n != (2+i))
			return "YES\n";
	}
	
	return "NO\n";
}

int main(){
	int t, n;
	cin>>t;
	while(t--){
		cin>>n;
		cout<<solution(n);
	}
	return 0;
}
