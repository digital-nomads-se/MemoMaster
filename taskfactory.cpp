#include "taskfactory.h"
#include "taskbuilder.h"

Task* TaskFactory::createTask(const QString& desc, Task::Priority prio) {
    TaskBuilderImpl builder;
    builder.setDescription(desc);
    builder.setPriority(prio);
    return builder.getResult();
}