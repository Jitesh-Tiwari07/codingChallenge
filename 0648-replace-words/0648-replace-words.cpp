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
        string ans = "";

        for (char ch : word) {
            int idx = ch - 'a';

            if (crawler->children[idx] == NULL) {
                return word;
            }

            ans += ch;
            crawler = crawler->children[idx];

            if (crawler->isEndOfWord) {
                return ans;
            }
        }

        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {

        
        for (string &rootWord : dictionary) {
            insert(rootWord);
        }

        stringstream ss(sentence);
        string word;
        string result = "";

        while (ss >> word) {                //while(getline(ss,word,' '))
            result += searchRoot(word)+" ";
        }

        
        result.pop_back();

        return result;
    }
};