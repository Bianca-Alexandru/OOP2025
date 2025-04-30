#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <cctype>

using namespace std;

bool isSeparator(char c) {
    return c == ' ' || c == ',' || c == '?' || c == '!' || c == '.';
}

string toLowerCase(const string& s) {
    string result = s;
    for (int i = 0; i < result.length(); ++i) {
        result[i] = tolower(result[i]);
    }
    return result;
}

struct Compare {
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) const {
        if (a.second != b.second) {
            return a.second < b.second;
        }
        return a.first > b.first; 
    }
};

int main() {
    ifstream file("input.txt");

    string line;
    getline(file, line);
    file.close();

    map<string, int> wordCount;

    int i = 0;
    while (i < line.length()) {
        while (i < line.length() && isSeparator(line[i])) {
            ++i;
        }

        if (i >= line.length()) break;

        int start = i;

        while (i < line.length() && !isSeparator(line[i])) {
            ++i;
        }

        string word = line.substr(start, i - start);
        word = toLowerCase(word);

        if (!word.empty()) {
            wordCount[word]++;
        }
    }

    priority_queue<
        pair<string, int>,                   // type of elements
        vector<pair<string, int>>,            // container
        Compare                               // custom compare
    > pq;

    for (const auto& entry : wordCount) {
        pq.push(entry);
    }

    while (!pq.empty()) {
        cout << pq.top().first << " => " << pq.top().second << endl;
        pq.pop();
    }

    return 0;
}
