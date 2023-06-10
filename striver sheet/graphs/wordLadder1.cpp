#include<bits/stdc++.h>
using namespace std;

int wordLadder(string startWord, string targerWord, vector<string> &wordList){
    queue<pair<string, int>> q;
    q.push({startWord, 1});
    unordered_set<string> st(wordList.begin(), wordList.end());
    st.erase(startWord);

    while (!q.empty())
    {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();

        if(word == targerWord) return steps;

        for(int i=0; i<word.size(); i++){
            char original = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++){
                word[i] = ch;

                if(st.find(word) != st.end()){
                    st.erase(word);
                    q.push({word, steps + 1});
                }
            }
            word[i] = original;
        }
    }
    
    return 0;
    
}

int main(){
    int n;
    string startWord, targetWord;

    cin>>n;

    vector<string> wordList(n);

    for(int i=0; i<n; i++){
        cin>>wordList[i];
    }
    cin>>startWord>>targetWord;

    int ans = wordLadder(startWord, targetWord, wordList);

    cout<<ans<<endl;
}