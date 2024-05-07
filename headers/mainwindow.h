#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "headers/notecontroller.h"
#include "headers/notemodel.h"
#include "headers/notemainwindow.h"
#include "headers/todomainwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    NoteMainWindow *noteMain;
    TodoMainWindow *todoMain;
    NoteModel *noteModel;
    NoteController *noteController;
};

#endif // MAINWINDOW_H
