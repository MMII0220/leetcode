string longestCommonPrefix(vector<string>& strs) {
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
