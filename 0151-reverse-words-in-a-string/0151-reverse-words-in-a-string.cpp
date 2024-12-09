class Solution {
public:
    string reverseWords(string s) {
        vector<string> words; 
        stringstream rr(s);   
        string word;
    
        while (getline(rr, word, ' ')) {
            if (!word.empty()) {
                words.push_back(word);
            }
        }
        
        reverse(words.begin(), words.end());
        
        string result;
        for (int i = 0; i < words.size(); i++) {
            if (i > 0) {
                result += ' ';
            }
            result += words[i];
        }  
        return result;
    }
};
