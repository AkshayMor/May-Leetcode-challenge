class Trie {
public:
    Trie *child[26];
    bool isWord;
    Trie(){
        isWord=false;
        for(int i=0;i<26;i++) child[i]=NULL;
    }

    /** Initialize your data structure here. */
    
    
    /** Inserts a word into the trie. */
    void insert(string word) {
       Trie *curr= this;
        for(int i=0;i<word.length();i++){
            int id=word[i]-'a';
            if(curr->child[id]==NULL)
                curr->child[id]=new Trie();
            curr=curr->child[id];
        }
        curr->isWord=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *curr= this;
        for(int i=0;i<word.length();i++){
            int id=word[i]-'a';
            if(curr->child[id]==NULL)
                return false;
            curr=curr->child[id];
        }
        return curr->isWord==true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *curr= this;
        for(int i=0;i<prefix.length();i++){
            int id=prefix[i]-'a';
            if(curr->child[id]==NULL)
                return false;
            curr=curr->child[id];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */