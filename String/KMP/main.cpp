#include "kmp.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string str1 = "THIS IS A TEST TEXT";
    string pattern1 = "TEST";
    cout << "Text: " << str1 << endl;
    cout << "Pattern: " << pattern1 << endl;
    cout << "Pattern found at index: " << kmp_once(str1, pattern1) << endl;
    cout << endl;

    string str2 = "AABAACAADAABAABA";
    string pattern2 = "AABA";
    cout << "Text: " << str2 << endl;
    cout << "Pattern: " << pattern2 << endl;
    vector<int> found = kmp_all(str2, pattern2);
    for (auto it=found.begin(); it!=found.end(); it++)
        cout << "Pattern found at index: " << *it << endl;

    return 0;
}
