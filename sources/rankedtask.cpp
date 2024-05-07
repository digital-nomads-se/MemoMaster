#include "headers/rankedtask.h"

RankedTask::RankedTask(Task* task, int rank) : task(task), rank(rank) {}

int RankedTask::getRank() {
    return rank;
}

QString RankedTask::getDescription() {
    return QString::number(rank) + ". " + task->getDescription();
}