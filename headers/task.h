#ifndef TASK_H
#define TASK_H

#include <QString>

class Task {
public:
    enum Priority { High, Medium, Low };
    Task(QString description, Priority priority);
    QString getDescription() const;
    Priority getPriority() const;

private:
    QString desc;
    Priority prio;
};

#endif // TASK_H
