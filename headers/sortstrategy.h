#ifndef SORTSTRATEGY_H
#define SORTSTRATEGY_H

#include <algorithm>
#include "headers/task.h"

class SortStrategy {
public:
    virtual void sort(QList<Task*>& tasks) = 0;
    virtual ~SortStrategy() {}
};

class PrioritySort : public SortStrategy {
public:
    void sort(QList<Task*>& tasks) override {
        std::sort(tasks.begin(), tasks.end(), [](const Task* a, const Task* b) {
            return a->getPriority() < b->getPriority();
        });
    }
};

class AlphabeticalSort : public SortStrategy {
public:
    void sort(QList<Task*>& tasks) override {
        std::sort(tasks.begin(), tasks.end(), [](const Task* a, const Task* b) {
            return a->getDescription() < b->getDescription();
        });
    }
};

#endif