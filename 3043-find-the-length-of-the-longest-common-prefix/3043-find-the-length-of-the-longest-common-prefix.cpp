class Solution {
public:
    struct triNode {
        bool isEndOfWord;
        triNode* children[10];
    };

    triNode* getNode() {
        triNode* newNode = new triNode();
        newNode->isEndOfWord = false;

        for (int i = 0; i < 10; i++)
            newNode->children[i] = NULL;

        return newNode;
    }

    triNode* root;

    Solution() {
        root = getNode();
    }

    void insert(string word) {
        
        triNode* crawler = root;

        for (char ch : word) {
            int idx = ch - '0';

            if (crawler->children[idx] == NULL)
                crawler->children[idx] = getNode();

            crawler = crawler->children[idx];
        }

        crawler->isEndOfWord = true;
    }

    int search(string word) {
        
        triNode* crawler = root;
        int cnt = 0;

        for (char ch : word) {
            int idx = ch - '0';

            if (crawler->children[idx] == NULL)
                break;

            cnt++;
            crawler = crawler->children[idx];
        }

        return cnt;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        for (int x : arr1)

            insert(to_string(x));

        int ans = 0;

        for (int x : arr2)
            ans = max(ans, search(to_string(x)));

        return ans;
    }
};