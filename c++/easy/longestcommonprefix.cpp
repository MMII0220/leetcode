#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// std::string longestCommonPrefix(std::vector<std::string>& v) {
//     std::string ans="";
//     std::sort(v.begin(),v.end());
//     int n=v.size();
//     std::string first=v[0],last=v[n-1];
//     for(int i=0;i<std::min(first.size(),last.size());i++){
//         if(first[i]!=last[i]){
//             return ans;
//         }
//         ans+=first[i];
//     }
//     return ans;
// }

std::string longestCommonPrefix(std::vector<std::string>& strs) {
    if (strs.empty()) {
        return "";
    }

    // Перебираем символы в первой строке
    for (int i = 0; i < strs[0].size(); ++i) {
        char currentChar = strs[0][i];

        // Проверяем, содержится ли текущий символ в остальных строках на той же позиции
        for (int j = 1; j < strs.size(); ++j) {
            if (i >= strs[j].size() || strs[j][i] != currentChar) {
                // Если текущий символ не совпадает во всех строках, возвращаем префикс до этой позиции
                return strs[0].substr(0, i);
            }
        }
    }

    // Если мы дошли до этой точки, то весь первый строка - общий префикс
    return strs[0];
}

int main() {
    // std::vector<std::string> v = {"tanga", "fanta", "sange"};
    std::vector<std::string> v = {"ca", "ba", "ta"};
    longestCommonPrefix(v);
    std::cout<<longestCommonPrefix(v)<<std::endl;
    return 0;
}

