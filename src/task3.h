#pragma once

struct List {
    struct List* next;
    int payload;
};

void remove_every_fifth(List* node);