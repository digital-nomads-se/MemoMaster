#ifndef TASKBUILDER_H
#define TASKBUILDER_H

#include "headers/task.h"

class TaskBuilder {
public:
    virtual void setDescription(const QString& desc) = 0;
    virtual void setPriority(Task::Priority prio) = 0;
    virtual Task* getResult() = 0;
    virtual ~TaskBuilder() {}
};

class TaskBuilderImpl : public TaskBuilder {
private:
    QString description;
    Task::Priority priority;
public:
    void setDescription(const QString& desc) override {
        description = desc;
    }
    void setPriority(Task::Priority prio) override {
        priority = prio;
    }
    Task* getResult() override {
        return new Task(description, priority);
    }
};

#endif // TASKBUILDER_H