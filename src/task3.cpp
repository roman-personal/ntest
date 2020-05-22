#include "task3.h"

void remove_every_fifth(List* node) {
    int count = 0;
    List* prev = nullptr;
    while (node != nullptr) {
        if (count < 5) {
            count++;
            prev = node;
            node = node->next;
        }
        else {
            count = 0;
            prev->next = node->next;
            delete node;
            node = prev->next;
        }
    }
}