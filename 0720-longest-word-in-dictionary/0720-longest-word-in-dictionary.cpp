class Solution {
public:

    struct trieNode {
        bool isEndOfWord;
        trieNode* children[26];
    };

    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        newNode->isEndOfWord = false;

        for (int i = 0; i < 26; i++)
            newNode->children[i] = NULL;

        return newNode;
    }

    trieNode* root;

    Solution() {
        root = getNode();
    }

    void insert(string& word) {

        trieNode* crawler = root;

        for (char ch : word) {

            int idx = ch - 'a';

            if (crawler->children[idx] == NULL)
                crawler->children[idx] = getNode();

            crawler = crawler->children[idx];
        }

        crawler->isEndOfWord = true;
    }

    bool search (string &word){
        trieNode* crawler = root;
        for(auto ch: word){
            int idx=ch-'a';
            
            if(crawler->children[idx]==NULL){
                return false;
            }
            crawler=crawler->children[idx];
            if(!crawler->isEndOfWord)
            return false;

        }
        return true;
    }

    string longestWord(vector<string>& words) {
    for (string &word : words) {
        insert(word);
    }
    string ans = "";
    for (string &word : words) {
        if (search(word)) {
            if (word.length() > ans.length()) {
                ans = word;
            }
            else if (word.length() == ans.length() && word < ans) {
                ans = word;
            }
        }
    }
    return ans;
    }
};