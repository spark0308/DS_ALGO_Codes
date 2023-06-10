#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> solution(string startWord, string targetWord, vector<string> wordList){
    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<vector<string>> q;
    q.push({startWord});
    vector<string> usedOnLevel;
    usedOnLevel.push_back(startWord);
    int level = 0;
    vector<vector<string>> ans;

    while (!q.empty())
    {
        vector<string> vec = q.front();
        q.pop();

        if(vec.size() > level){
            level++;
            for(auto it: usedOnLevel){
                st.erase(it);
            }
        }

        string word = vec.back();
        if(word == targetWord){
            if(ans.size() == 0){
                ans.push_back(vec);
            }
            else if(ans[0].size() == vec.size()){
                ans.push_back(vec);
            }
        }

        for(int i=0; i<word.size(); i++){
            char original = word[i];
            for(char c = 'a'; c<='z'; c++){
                word[i] = c;
                if(st.count(word)>0){
                    vec.push_back(word);
                    q.push(vec);
                    vec.pop_back();
                    usedOnLevel.push_back(word);
                }

            }
            word[i] = original;
        }
    }

    return ans;
    

}

int main(){
    int n;
    string startWord, endWord;
    cin>>n;
    cin>>startWord>>endWord;

    vector<string> wordList(n);

    for(int i=0; i<n; i++){
        cin>>wordList[i];
    }

    vector<vector<string>> ans = solution(startWord, endWord, wordList);

    for(auto x: ans){
        for(auto y: x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
}