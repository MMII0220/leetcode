class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
        if (len % 2 == 1) return false;

        stack<char> bracketsStack;
        unordered_map<char, char> brackets = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'},
        };

        for (int i = 0; i < len; i++) {
            if (brackets.count(s[i])) {
                // Если это открывающая скобка, помещаем ее в стек
                bracketsStack.push(s[i]);
            } else {
                // Если это закрывающая скобка
                if (bracketsStack.empty() || brackets[bracketsStack.top()] != s[i]) {
                    // Если стек пуст или закрывающая скобка не соответствует последней открывающей, возвращаем false
                    return false;
                }
                // Иначе удаляем последнюю открывающую скобку из стека
                bracketsStack.pop();
            }
        }

        // Если стек не пустой после обработки всей строки, то есть открывающих скобок больше, чем закрывающих
        return bracketsStack.empty();
    }
};

// beasts 45%
