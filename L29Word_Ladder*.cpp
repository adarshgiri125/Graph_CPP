int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        queue<pair<string,int> > q;
        unordered_set<string> st(wordList.begin(), wordList.end());
        
        q.push({startWord,1});
        
        st.erase(startWord);
        
        while(!q.empty()){
            string word = q.front().first;
            int length = q.front().second;
            q.pop();
            if(word == targetWord) return length;
            
            for(int i = 0; i<word.length(); i++){
                char original = word[i];
                for(char j = 'a'; j<= 'z'; j++){
                    word[i] = j;
                    
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word,length+1});
                    }
                }
                word[i] = original;
            }
            
        }
        return 0;
    }