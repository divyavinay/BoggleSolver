#include <string>

using namespace std;

struct Node {
	bool is_end;
	bool is_word[26];
	//int prefix_count;
	struct Node* child[26];
	

};
class Dictionary
{
public:
	Dictionary();
	void addWord(string word);
	bool isWord(string word);
	bool isPrefix(string word);
	/*Dictionary(string file);
	void PrintWords(string prefix);
	int wordCount();*/
private:
	Node * root;
	int numWords;
	// Your private helper methods go here
}; 
