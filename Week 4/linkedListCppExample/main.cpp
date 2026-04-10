//g++ -std=c++17 -Wall -Wextra -pedantic -O2 main.cpp LinkedList.hpp -o main

#include "LinkedList.hpp"
#include <cassert>
#include <iostream>

void printList(const LinkedList<int>& list) {
    std::cout << "LinkedList values: ";
    for (const auto& value : list) {
        std::cout << value << ' ';
    }
    std::cout << '\n';
}

int main()
{
    LinkedList<int> list;

    assert(list.empty());
    assert(list.size() == 0);
    printList(list);

    list.push_back(1);
    list.push_back(2);
    list.push_front(0);

    assert(!list.empty());
    assert(list.size() == 3);
    assert(list.front() == 0);
    assert(list.back() == 2);
    printList(list);

    list.pop_front();     // 1, 2

    assert(list.size() == 2);
    assert(list.front() == 1);
    assert(list.back() == 2);
    printList(list);

    int sum = 0;
    for (const auto& value : list) {
        sum += value;
    }
    assert(sum == 3);

    list.clear();
    assert(list.empty());
    assert(list.size() == 0);
    printList(list);
    return 0;
}