// mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , todoMain(new TodoMainWindow())
    , noteMain(new NoteMainWindow())
    , noteModel(new NoteModel())
    , noteController(new NoteController(noteModel, noteMain))
{
    ui->setupUi(this);
    ui->tabWidget->addTab(todoMain, "Todo App");
    ui->tabWidget->addTab(noteMain, "Note App");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete todoMain;
    delete noteMain;
    delete noteModel;
    delete noteController;
}
