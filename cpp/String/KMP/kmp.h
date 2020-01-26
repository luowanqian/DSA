#ifndef DSA_KMP_H
#define DSA_KMP_H

#include <vector>
#include <string>

std::vector<int> kmp_all(std::string& text, std::string& pattern);
int kmp_once(std::string& text, std::string& pattern);

#endif //DSA_KMP_H
