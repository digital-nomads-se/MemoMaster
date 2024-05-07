#ifndef TODO_MAIN_WINDOW_H
#define TODO_MAIN_WINDOW_H

#include <QMainWindow>
#include <QList>
#include "task.h"
#include "sortstrategy.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TodoMainWindow; }
QT_END_NAMESPACE

class TodoMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    TodoMainWindow(QWidget *parent = nullptr);
    ~TodoMainWindow();

private:
    Ui::TodoMainWindow *ui;
    QList<Task*> model;
    SortStrategy* sortStrategy;
    Task::Priority getSelectedPriority();
    void updateView();
    void todoAddButtonClicked();
    void todoDeleteButtonClicked();
    void sortAlphabeticalButtonClicked();
    void sortPriorityButtonClicked();
};

#endif // TODO_MAIN_WINDOW_H
