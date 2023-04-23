#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int> arr){
	for(auto x: arr){
		cout<<x<<" ";
	}
	cout<<endl;
}

void kadanesAlgo(vector<int> arr){
	int highest, sum = 0;
	highest = arr[0];

	vector<int> subarr;
	vector<int> ans;

	for(auto x: arr){
		sum += x;
		if(sum < 0){
			sum = 0;
			subarr.clear();
		}
		else{
			subarr.push_back(x);
		}
		if(highest < sum){
			highest = sum;
			ans = subarr;
		}
	}

	cout<<highest<<endl;
	printVector(ans);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> array(n);
		for(auto &x: array){
			cin>>x;
		}
		
		kadanesAlgo(array);
	}
	return 0;
}
