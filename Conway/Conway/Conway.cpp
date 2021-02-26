#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int R, L, next, current;
    vector<int> currentLine, lastLine;
    cin >> R >> L;

    currentLine.push_back(R);
    for (int i = 1; i < L;i++) {
        int j = 0;
        while (j < currentLine.size()) {
            current = 1;
            next = currentLine[j++];
            while (j < currentLine.size() && currentLine[j] == currentLine[j - 1]) {
                current++;
                j++;
            }
            lastLine.push_back(current);
            lastLine.push_back(next);
        }
        currentLine = lastLine;
        lastLine.clear();
    }

    for (int i = 0; i < currentLine.size() - 1; i++)
        cout << currentLine[i] << " ";

    cout << currentLine[currentLine.size() - 1] << endl;
}