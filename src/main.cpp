#include <iostream>
#include "task2.h"

int main(int, char**) {
    std::cout << "Hi there! Some tasks printout...\n\n";

    std::cout << "Task 2: count number of words in text for each word length\n";
    const char* text = "The quick brown fox jumps over the lazy dog!";
    std::cout << text << std::endl;
    auto result = count_words_by_length(text);
    for (auto entry : result) {
        std::cout << entry.second << " words with " << entry.first <<
            (entry.first > 1 ? "-letters" : "-letter") << " length\n";
    }
}
