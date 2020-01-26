#include "kmp.h"
using namespace std;

vector<int> compute_prefix(string& pattern)
{
    if (pattern.empty())
        return vector<int>();

    int len, pos;
    vector<int> prefix(pattern.size(), 0);

    len = 0;
    prefix[len] = 0;
    pos = 1;
    while (pos < pattern.size()) {
        if (pattern[pos] == pattern[len]) {
            len++;
            prefix[pos] = len;
            pos++;
        } else {
            if (len != 0) {
                len = prefix[len-1];
            } else {
                prefix[pos] = 0;
                pos++;
            }
        }
    }

    return prefix;
}

vector<int> kmp_all(string& text, string& pattern)
{
    int i, j;
    int text_len, pattern_len;
    vector<int> found, prefix;

    text_len = text.size();
    pattern_len = pattern.size();

    // compute the length of longest prefix of pattern
    prefix = compute_prefix(pattern);

    i = 0;  // index for text
    j = 0;  // index for pattern
    while (i < text_len) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == pattern_len) {
            found.push_back(i - j);
            j = prefix[j-1];
        } else if (i < text_len && text[i] != pattern[j]) {
            if (j != 0)
                j = prefix[j-1];
            else
                i = i + 1;
        }
    }

    return found;
}

int kmp_once(string& text, string& pattern)
{
    int i, j;
    int text_len, pattern_len;
    vector<int> prefix;

    text_len = text.size();
    pattern_len = pattern.size();

    // compute the length of longest prefix of pattern
    prefix = compute_prefix(pattern);

    i = 0;  // index for text
    j = 0;  // index for pattern
    while (i < text_len) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == pattern_len) {
            return i - j;
        } else if (i < text_len && text[i] != pattern[j]) {
            if (j != 0)
                j = prefix[j-1];
            else
                i = i + 1;
        }
    }

    return -1;
}
