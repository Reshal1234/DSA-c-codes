#include<bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    TrieNode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
};
class Trie{
    public:
    TrieNode* root;
    Trie(){
        root=new TrieNode('\0');
    }
    void insertUtil(TrieNode* root,string word){
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }
        //asumming word will be in caps
        int index=word[0]-'A';
        TrieNode* child;
        if(root->children[index]!=NULL){
            //present
            child=root->children[index];
        }
        else{
            //absent
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }
        //recursion
        insertUtil(child,word.substr(1));
    }
    void insertWord(string word){
        insertUtil(root,word);
    }
    bool searchUtil(TrieNode* root,string word){
        if(word.length()==0){
            return root->isTerminal;
        }
        int index=word[0]-'A';
        TrieNode* child;
        if(root->children[index]!=NULL){
            //present
            child=root->children[index];
        }
        else{
            //absent
            return false;
        }
        //recursion
        return searchUtil(child,word.substr(1));
    }
    bool searchWord(string word){
        return searchUtil(root,word);
    }
    bool isEmpty(TrieNode* root){
        for(int i=0;i<26;i++){
            if(root->children[i]!=NULL){
                return false;
            }
        }
        return true;
    }
    TrieNode* deleteUtil(TrieNode* root,string word){
        if(root==NULL){
            return NULL;
        }
        if(word.length()==0){
            if(root->isTerminal){
                root->isTerminal=false;
            }
            if(isEmpty(root)){
                delete root;
                root=NULL;
            }
            return root;
        }
        int index=word[0]-'A';
        root->children[index]=deleteUtil(root->children[index],word.substr(1));
        if(isEmpty(root)&&root->isTerminal==false){
            delete root;
            root=NULL;
        }
        return root;
    }
    TrieNode* deleteWord(string word){
        return deleteUtil(root,word);
    }
};
int main(){
    Trie *t=new Trie();
    t->insertWord("ABCD");
    cout<<"present or not "<<t->searchWord("ABCD")<<endl;
    t->deleteWord("ABCD");
    cout<<"present or not "<<t->searchWord("ABCD")<<endl;
    return 0;
}