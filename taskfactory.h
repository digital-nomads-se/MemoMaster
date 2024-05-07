#ifndef TASKFACTORY_H
#define TASKFACTORY_H

#include "task.h"

class TaskFactory {
public:
    static Task* createTask(const QString& desc, Task::Priority prio);
};

#endif // TASKFACTORY_H
