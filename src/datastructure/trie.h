#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Trie
{
    map<char, Trie *> mChildren = {}; // 当前节点的子节点
    int mPrefix = 0;                  // 每一个节点对应一个可能的前缀
    bool mEnd = 0;                    // 叶子节点，也就是完整的一个word
    int mDepth = 0;                   // 当前节点的所在层数

public:
    Trie() = default;
    Trie(int depth) : mDepth(depth) {}

    int getDepth() { return mDepth; }
    bool isChild(const char &c) { return mChildren.find(c) != mChildren.end(); }
    bool isEnd() { return mEnd; }
    void setEnd() { mEnd = 1; }
    void insert(const string &word);
    int matchLength(const string &prefix);
    vector<string> getAllWords();
    vector<string> autoComplete(const string &prefix);
    void addKey(const char &c);
    Trie *to(const char &c);
    bool hasPrefix(const string &prefix);
    bool search(const string &word);
    bool startsWith(const string &prefix);
};

// 对当前节点增加子节点
void Trie::addKey(const char &c)
{
    if (!isChild(c))
    {
        mChildren[c] = new Trie(mDepth + 1);
    }
    mPrefix++;
}

Trie *Trie::to(const char &c) // 移动到该节点
{
    if (!isChild(c))
    {
        return nullptr;
    }
    return mChildren[c];
}

// 插入，忽略重复
void Trie::insert(const string &word)
{
    Trie *cur = this; // 根节点
    for (char c : word)
    {
        cur->addKey(c);
        cur = cur->to(c);
    }
    cur->setEnd(); // 插入结束标志
}

// 能匹配多少字符就返回多少
int Trie::matchLength(const string &prefix)
{
    Trie *cur = this;
    int match = 0;
    for (char c : prefix)
    {
        if (cur->isChild(c))
        {
            match++;
            cur = cur->to(c);
        }
        else
        {
            return match;
        }
    }
    return match;
}

// 当前节点之后的所有带结束标志的字符串，找叶子节点，
vector<string> Trie::getAllWords()
{
    vector<string> res = {};
    for (auto it : mChildren)
    {
        char c = it.first;
        Trie *t = it.second;
        if (t->isEnd())
        {
            res.push_back(string("") + c);
        }
        for (auto word : t->getAllWords())
        { // 下沉寻找
            res.push_back(c + word);
        }
    }
    return res;
}

// 自动补全
vector<string> Trie::autoComplete(const string &prefix)
{
    if (!hasPrefix(prefix))
    {
        return {};
    }
    vector<string> res = {};

    Trie *cur = this;
    for (char c : prefix)
    {
        if (cur->isChild(c))
        {
            cur = cur->to(c);
        }
        else
        {
            break;
        }
    }
    if (cur->isEnd())
    {
        res.push_back(prefix);
    }
    for (auto restWord : cur->getAllWords())
    {
        res.push_back(prefix + restWord);
    }

    return res;
}

// 字典树中是否保存该前缀
bool Trie::hasPrefix(const string &prefix)
{
    return matchLength(prefix) == prefix.size(); // 不相等意味着不完全匹配
}

bool Trie::search(const string &word)
{
    Trie *cur = this;
    for (char c : word)
    {
        if (cur->isChild(c))
        {
            cur = cur->to(c);
        }
        else
        {
            return false;
        }
    }

    return cur->isEnd();
}

bool Trie::startsWith(const string &prefix)
{
    Trie *cur = this;
    for (char c : prefix)
    {
        if (cur->isChild(c))
        {
            cur = cur->to(c);
        }
        else
        {
            return false;
        }
    }

    return true;
}
