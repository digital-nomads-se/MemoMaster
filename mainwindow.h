#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "notecontroller.h"
#include "notemodel.h"
#include "notemainwindow.h"
#include "todomainwindow.h"

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
