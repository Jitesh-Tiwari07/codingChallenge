class Solution {
public:
    struct trieNode {
        bool isEndOfWord;
        trieNode* children[26];
    };

    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        newNode->isEndOfWord = false;

        for (int i = 0; i < 26; i++) {
            newNode->children[i] = NULL;
        }

        return newNode;
    }
    trieNode* root;

    Solution() {
        root = getNode();
    }

    void insert(string word) {
        trieNode* crawler = root;
        for (char ch : word) {
            int idx = ch - 'a';

            if (crawler->children[idx] == NULL) {
                crawler->children[idx] = getNode();
            }
            crawler = crawler->children[idx];
        }
        crawler->isEndOfWord = true;
    }

    string searchRoot(string word) {
        trieNode* crawler = root;

        for (int i=0;i<word.length();i++) {
            int idx = word[i] - 'a';
            if (crawler->children[idx] == NULL) {
                return word;
            }
            crawler = crawler->children[idx];
            if (crawler->isEndOfWord) {
                return word.substr(0,i+1);
            }
        }

        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {

        
        for (string &word : dictionary) {
            insert(word);
        }

        stringstream ss(sentence);
        string word;
        string result = "";

        while(getline(ss,word,' ')){                
            result += searchRoot(word)+" ";
        }

        
        result.pop_back();

        return result;
    }
};