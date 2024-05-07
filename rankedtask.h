#ifndef RANKEDTASK_H
#define RANKEDTASK_H

#include "task.h"

class RankedTask {
private:
    Task* task;
    int rank;

public:
    RankedTask(Task* task, int rank);
    int getRank();
    QString getDescription();
};

#endif // RANKEDTASK_H