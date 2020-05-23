#include "task3.h"

void remove_every_fifth(List* node) {
    int count = 0;
    List* prev = nullptr;
    while (node != nullptr) {
        if (++count < 5) {
            prev = node;
            node = node->next;
        }
        else {
            prev->next = node->next;
            delete node;
            node = prev->next;
            count = 0;
        }
    }
}