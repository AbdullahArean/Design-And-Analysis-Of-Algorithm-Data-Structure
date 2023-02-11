#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;
 
#define EMPTY_STRING ""
struct Nde
{
    char character;
    int frequency;
    Nde *left_child, *right_child;
};
Nde* getNode(char character, int frequency, Nde* left_child, Nde* right_child)
{
    Nde* node = new Nde();
 
    node->character = character;
    node->frequency = frequency;
    node->left_child = left_child;
    node->right_child = right_child;
 
    return node;
}
struct compare
{
    bool operator()(const Nde* l, const Nde* r) const
    {
        return l->frequency > r->frequency;
    }
};
bool LeafNodeorNot(Nde* root) {
    return root->left_child == nullptr && root->right_child == nullptr;
}
void Encoding(Nde* root, string string1, unordered_map<char, string> &huffmanCode)
{
    if (root == nullptr) {
        return;
    }
    if (LeafNodeorNot(root)) {
        huffmanCode[root->character] = (string1 != EMPTY_STRING) ? string1 : "1";
    }
 
    Encoding(root->left_child, string1 + "0", huffmanCode);
    Encoding(root->right_child, string1 + "1", huffmanCode);
}
void Decoding(Nde* root, int &index, string string1)
{
    if (root == nullptr) {
        return;
    }
    if (LeafNodeorNot(root))
    {
        cout << root->character;
        return;
    }
 
    index++;
 
    if (string1[index] == '0') {
        Decoding(root->left_child, index, string1);
    }
    else {
        Decoding(root->right_child, index, string1);
    }
}
void SolutionB(string text)
{
    if (text == EMPTY_STRING) {
        return;
    }
    unordered_map<char, int> frequency;
    for (char character: text) {
        frequency[character]++;
    }
    priority_queue<Nde*, vector<Nde*>, compare> pq;
    for (auto pair: frequency) {
        pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
    }
    while (pq.size() != 1)
    {
 
        Nde* left_child = pq.top(); pq.pop();
        Nde* right_child = pq.top();    pq.pop();
        int sum = left_child->frequency + right_child->frequency;
        pq.push(getNode('\0', sum, left_child, right_child));
    }
    Nde* root = pq.top();
    unordered_map<char, string> huffmanCode;
    Encoding(root, EMPTY_STRING, huffmanCode);
    string string1;
    for (char character: text) {
       string1 += huffmanCode[character];
   }
    cout << string1.length() << endl;
}
int main()
{
    char c, inp[1000009];
    string text = "";
    int n; cin>>n;getchar();
    for(int i=0; i<n; i++){
        scanf("%c", &c);
        text+=c;
    }
    SolutionB(text);
 
    return 0;
}