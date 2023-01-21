
struct Node {
    unordered_map<char, Node*> next;
    char val;
    bool endWord = false;
};

class Solution {
    void findTrie(string& s, int ind, Node* root) {
	if (ind == s.size()) {
	    root->endWord = true && (beg || cur->endWord);
	    return;
	}
	if (root->next.find(s[ind]) != root->next.end()) {
	    // found the char
	    findTrie(s, ind+1, root->next[s[ind]] ); 
	} else {
	    // add new node
	    Node* charNode = new Node();
	    charNode->val = s[ind];
	    root->next[s[ind]] = charNode;
	    findTrie(s, ind+1, charNode);
	}
    }

    bool findPart(string& s, int i, vector<short>& dp, Node* root, Node* cur, bool beg) {
	if (i == s.size()) {
	    return true;
	}
	if (beg && dp[i] > -1) {
	    return dp[i];
	}

	bool found = false;
	if (cur->endWord) {
	    found = findPart(s, i, dp, root, root, true);
	}
	
	if ( cur->next.find( s[i] ) != cur->next.end() ) {
	    // maybe explore as continuation of existing word
	    found = found || findPart(s, i+1, dp, root, cur->next[s[i]], false);
	}
	if (beg) {
	    dp[i] = found;
	}
	return found;
    }    

public:
    bool wordBreak(string s, vector<string>& wordDict) {
	Node* root = new Node();
	root->val = '*';
	for (int i = 0; i < wordDict.size(); i++) {	    
	    findTrie(wordDict[i], 0, root);
	}
	vector<short> dp (s.size(), -1);
	return findPart(s, 0, dp, root, root, true);
    }
};
