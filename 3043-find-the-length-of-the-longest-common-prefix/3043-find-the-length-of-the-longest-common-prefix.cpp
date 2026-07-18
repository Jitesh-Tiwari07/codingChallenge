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

    void insert(int num) {
        string s = to_string(num);
        triNode* node = root;

        for (char ch : s) {
            int idx = ch - '0';

            if (node->children[idx] == NULL)
                node->children[idx] = getNode();

            node = node->children[idx];
        }

        node->isEndOfWord = true;
    }

    int search(int num) {
        string s = to_string(num);
        triNode* node = root;
        int cnt = 0;

        for (char ch : s) {
            int idx = ch - '0';

            if (node->children[idx] == NULL)
                break;

            cnt++;
            node = node->children[idx];
        }

        return cnt;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        for (int x : arr1)
            insert(x);

        int ans = 0;

        for (int x : arr2)
            ans = max(ans, search(x));

        return ans;
    }
};