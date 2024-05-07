#include "todomainwindow.h"
#include "ui_todomainwindow.h"
#include "taskfactory.h"
#include <algorithm>
#include "sortstrategy.h"
#include "rankedtask.h"

TodoMainWindow::TodoMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TodoMainWindow)
    , sortStrategy(new PrioritySort) // Default sort strategy is PrioritySort, but can be changed as needed
{
    ui->setupUi(this);
    connect(ui->todoAddButton, &QPushButton::clicked, this, &TodoMainWindow::todoAddButtonClicked);
    connect(ui->todoDeleteButton, &QPushButton::clicked, this, &TodoMainWindow::todoDeleteButtonClicked);
    connect(ui->sortAlphabeticalButton, &QPushButton::clicked, this, &TodoMainWindow::sortAlphabeticalButtonClicked);
    connect(ui->sortPriorityButton, &QPushButton::clicked, this, &TodoMainWindow::sortPriorityButtonClicked);

}

TodoMainWindow::~TodoMainWindow()
{
    delete sortStrategy;
    qDeleteAll(model);
    delete ui;
}

void TodoMainWindow::sortAlphabeticalButtonClicked()
{
    delete sortStrategy;
    sortStrategy = new AlphabeticalSort;
    updateView();
}

void TodoMainWindow::sortPriorityButtonClicked()
{
    delete sortStrategy;
    sortStrategy = new PrioritySort;
    updateView();
}

void TodoMainWindow::todoAddButtonClicked()
{
    QString desc = ui->lineEdit->text();
    Task::Priority prio = getSelectedPriority();
    Task* task = TaskFactory::createTask(desc, prio);
    model.append(task);
    updateView();
    ui->lineEdit->clear();
}

void TodoMainWindow::todoDeleteButtonClicked()
{
    int index = ui->listWidget->currentRow();
    if (index != -1) {
        delete model.takeAt(index);
        updateView();
    }
}

Task::Priority TodoMainWindow::getSelectedPriority()
{
    if (ui->radioButtonHigh->isChecked()) return Task::High;
    if (ui->radioButtonMedium->isChecked()) return Task::Medium;
    if (ui->radioButtonLow->isChecked()) return Task::Low;
    return Task::Low; // Default
}

void TodoMainWindow::updateView()
{
    ui->listWidget->clear();
    sortStrategy->sort(model);
    for (int i = 0; i < model.size(); i++) {
        RankedTask* rankedTask = new RankedTask(model[i], i + 1);
        ui->listWidget->addItem(rankedTask->getDescription());
    }
}