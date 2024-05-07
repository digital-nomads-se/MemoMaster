
#include "task.h"

Task::Task(QString description, Priority priority) : desc(description), prio(priority) {}

QString Task::getDescription() const {
    return desc;
}

Task::Priority Task::getPriority() const {
    return prio;
}
