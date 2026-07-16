class Trie {
public:
    struct trieNode{
        bool isEndOfWord;
        trieNode* children[26];
    };
    trieNode* getNode(){
        trieNode* newNode= new trieNode();
        newNode->isEndOfWord=false;
        for(int i=0;i<26;i++){
            newNode->children[i]=NULL;
        }
        return newNode;
    }

    trieNode* root;
    Trie() {
        root=getNode();
    }
    
    void insert(string word) {
        trieNode* crawl=root;
        for(int i=0;i<word.length();i++){
            char ch =word[i];
            int index=ch-'a';
            if(crawl->children[index]==NULL){
                crawl->children[index]= getNode();
            }
            crawl=crawl->children[index];
        }
        crawl->isEndOfWord=true;
    }
    
    bool search(string word) {
        trieNode* crawl=root;
        for(int i=0;i<word.length();i++){
            char ch =word[i];
            int index=ch-'a';
            if(crawl->children[index]==NULL){
                return false;
            }
            crawl=crawl->children[index];
        }
        if(crawl!=NULL && crawl->isEndOfWord==true){
            return true;
        }
        return false;
        
    }
    
    bool startsWith(string prefix) {
        trieNode* crawl=root;
        int i=0;
        for(i;i<prefix.length();i++){
            char ch =prefix[i];
            int index=ch-'a';
            if(crawl->children[index]==NULL){
                return false;
            }
            crawl=crawl->children[index];
        }
        if(i==prefix.length()){
            return true;
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */