#include<iostream>
#include<vector>
using namespace std;

void printPascalTriangle(int n){
	vector<vector<int> > triangle(n, vector<int>(n));
	for(int i=0; i<n; i++){
		for(int j=0; j<=i; j++){
			if(j==0 || j == i){
				triangle[i][j] = 1;
			}
			else{
				triangle[i][j] = triangle[i-1][j] + triangle[i-1][j-1];
			}
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<=i; j++){
			cout<<triangle[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	int n;
	cin>>n;
	
	printPascalTriangle(n);
	
	return 0;
}
