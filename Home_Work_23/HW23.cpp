#include <iostream>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <stack>
#include <vector>

class Node 
{
public:
    int data;
    Node* next;

    Node(int indata) { data = indata; next = nullptr;}
};

unsigned int uniqueWordsCount(const std::string& line);
std::string mostOccuredWord(const std::string& line);
bool areBracketsBalanced(const std::string& line);
bool has_cycle(Node* head);

int main()
{
    std::string testWordsString = "Hello Hey Hello Bye Hey";
    std::string testBracketsString1 = "{[()][]}()";
    std::string testBracketsString2 = "[{]}";
    
    unsigned int numberOfUniqueWords = uniqueWordsCount(testWordsString);
    std::cout << "Number of unique words: " << numberOfUniqueWords << std::endl;

    std::string mostOccuredWordInString = mostOccuredWord(testWordsString);
    std::cout << "Most occured word: " << mostOccuredWordInString << std::endl;

    bool firstStringTest = areBracketsBalanced(testBracketsString1);
    bool secondStringTest = areBracketsBalanced(testBracketsString2);

    std::cout << std::boolalpha <<"First brackets string balanced: " << firstStringTest << std::endl;
    std::cout << std::boolalpha << "Second brackets string balanced: " << secondStringTest << std::endl;


    Node *firstNodeFirstSequence = new Node(10);
    Node *secondNodeFirstSequence = new Node(11);
    Node *thirdNodeFirstSequence = new Node(12);
    firstNodeFirstSequence->next = secondNodeFirstSequence;
    secondNodeFirstSequence->next = thirdNodeFirstSequence;
    thirdNodeFirstSequence->next = firstNodeFirstSequence;

    bool isCycledFirstSequence = has_cycle(firstNodeFirstSequence);
    std::cout << std::boolalpha << "First sequence is cycled: " << isCycledFirstSequence << std::endl;

    Node* firstNodeSecondSequence = new Node(10);
    Node* secondNodeSecondSequence = new Node(11);
  
    firstNodeSecondSequence->next = secondNodeSecondSequence;
  
    bool isCycledSecondSequence = has_cycle(firstNodeSecondSequence);
    std::cout << std::boolalpha << "Second sequence is cycled: " << isCycledSecondSequence << std::endl;
}


unsigned int uniqueWordsCount(const std::string& line)
{
    std::set<std::string> wordsSet;
    std::string intermidiateString = "";
    std::istringstream inStringStream(line);

    while (inStringStream >> intermidiateString)
    {
        std::remove_if(intermidiateString.begin(), intermidiateString.end(), ispunct);
        std::transform(intermidiateString.begin(), intermidiateString.end(), intermidiateString.begin(), ::tolower);
        wordsSet.insert(intermidiateString);
    }

    return wordsSet.size();
}

std::string mostOccuredWord(const std::string& line) 
{
    std::map<int, std::string> wordsMap;
    std::map<std::string, int> countingMap;
    std::istringstream inStringStream(line);
    std::string intermidiateString = "";
    int position = 0;

    while (inStringStream >> intermidiateString)
    {
        std::remove_if(intermidiateString.begin(), intermidiateString.end(), ispunct);
        std::transform(intermidiateString.begin(), intermidiateString.end(), intermidiateString.begin(), ::tolower);
        wordsMap[position] = intermidiateString;
        intermidiateString = "";
        position++;
    }

    for (auto pair : wordsMap) 
    {
        countingMap[pair.second]++;
    }

    int maxOccurence = 0;
    std::string mostOccuredWord = "";
    
    for (auto pair : countingMap)
    {
        if (pair.second > maxOccurence)
        {
            maxOccurence = pair.second;
            mostOccuredWord = pair.first;
        }
       
    }

    return mostOccuredWord;
}

bool areBracketsBalanced(const std::string& line) 
{
    std::stack<char> charStack;
    for (int i = 0; i < line.length(); i++) 
    {
        if (charStack.empty()) 
        {
            charStack.push(line[i]);
        }
        else if ((charStack.top() == '(' && line[i] == ')')
            || (charStack.top() == '{' && line[i] == '}')
            || (charStack.top() == '[' && line[i] == ']'))
        {
            charStack.pop();
        }

        else 
        {
            charStack.push(line[i]);
        }
    }
    if (charStack.empty())
    {
        return true;
    }

    return false;
}

bool has_cycle(Node* head) 
{
    std::vector<Node*> nodeList;

    Node* currentHead = head;

    while (true) 
    {
        int countInList = std::count(nodeList.begin(), nodeList.end(), currentHead);
         
        if (currentHead->next == nullptr) 
        {
            return false;
        }
        else if (countInList != 0)
        {
            return true;
        }

        else
        {
            nodeList.push_back(currentHead);
            currentHead = currentHead->next;
        }
    }
}