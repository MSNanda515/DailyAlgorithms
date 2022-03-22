// { Driver Code Starts
//Initial template for C++

#include <unordered_map>
#include <iostream>
#include <vector>


using namespace std;

// } Driver Code Ends
//User function Template for C++

class Node {
public:
    char c;
    unordered_map<char, Node*> child;
    bool endOfWord;

    Node() {
        endOfWord = false;
    }

    Node(char c, bool endOfWord=false) {
        this->c = c;
        this->endOfWord = endOfWord;
    }

    Node* addChild(char newChar) {
        if (child.find(newChar) == child.end()) {
            // create a new node
            Node* childNode = new Node(newChar);
            child[newChar] = childNode;
            return childNode;
        }
        return child[newChar];
    }

    bool checkSubTrees() {
        vector<char> str;
        if (endOfWord && child.size() > 0) {
            for (auto it = child.begin(); it != child.end(); it++) {
                if (palindFound(str, it->second))
                    return true;
            }
        }
        return false;
    }

    bool palindFound(vector<char>& str, Node* node) {
        str.push_back(node->c);
        if (endOfWord && isVectorPalind(str)) {
            return true;
        }
        for (auto it = node->child.begin(); it != node->child.end(); it++) {
            if (palindFound(str, it->second))
                return true;
        }
        str.pop_back();
        return false;
    }

    bool isVectorPalind(vector<char>& str) {
        int len = str.size();
        for (int i = 0; i <= (len-i-1); i++) {
            if (str[i] != str[len-i-1])
                return false;
        }
        return true;
    }

    void printNode() {
        cout << "{" << c << ", [";
        for (auto it = child.begin(); it != child.end(); it++) {
            it->second->printNode();
        }
        cout << "]} ";
    }
};

class Solution{
    Node root;
    bool isStringPalind(string str) {
        int len = str.size();
        for (int i = 0; i <= (len-i-1); i++) {
            if (str[i] != str[len-i-1])
                return false;
        }
        return true;
    }
public:
    // Function to check if a palindrome pair exists
    bool palindromepair(int N, string arr[]) {
        // code here
        root = Node('*', false);
        for (int i = 0; i < N; i++) {
            if (addStringsToTrie(arr[i]))
                return true;
        }
        return false;
    }

    bool addStringsToTrie(string str) {
        Node* curNode = &root;
        Node* nextNode;
        for (int i = 0; i < str.size(); i++) {
            nextNode = curNode->addChild(str[i]);
            if (nextNode->endOfWord) {
//                cout << "End of word found: " << str << ", " << str[i] << endl;
                // if end of previous word, then check the remaining word for palind
                if (i == str.size() - 1) {
                    return true;
                }
                if (isStringPalind(str.substr(i+1)))
                    return true;
            }
            curNode = nextNode;
        }
        curNode->endOfWord = true;
        if (curNode->checkSubTrees())
            return true;
        if (str.size() == 1) {
            return false;
        }
        curNode = &root;
        for (int i = str.size()-1; i >= 0; i--) {
            nextNode = curNode->addChild(str[i]);
            if (nextNode->endOfWord) {
                // if end of previous word, then check the remaining word for palind
                if (i == 0) {
                    return true;
                }
                if (isStringPalind(str.substr(0, i)))
                    return true;
            }
            curNode = nextNode;
        }
        curNode->endOfWord = true;
        if (curNode->checkSubTrees())
            return true;
        return false;
    }
};



// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        string arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.palindromepair(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends