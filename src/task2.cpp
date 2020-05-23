#include "task2.h"
#include <cstring>

std::map<int, int> count_words_by_length(const char *text) {
    const char *delimiters = ",.:;!?\"'-\\/ ";
    std::map<int, int> result;
    if (text != nullptr) {
        char inp[strlen(text) + 1];
        strcpy(inp, text);
        char *token = std::strtok(inp, delimiters);
        while (token != nullptr) {
            int len = strlen(token);
            if (len > 0) {
                auto entry = result.find(len);
                if (entry != result.end())
                    result[len] = entry->second + 1;
                else
                    result[len] = 1;
            }
            token = std::strtok(nullptr, delimiters);
        }
    }
    return result;
}