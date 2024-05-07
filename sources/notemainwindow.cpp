#include "headers/notemainwindow.h"
#include "ui_notemainwindow.h"

NoteMainWindow::NoteMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NoteMainWindow)
{
    ui->setupUi(this);

    // Explicitly enable the buttons
    ui->noteAddButton->setEnabled(true);
    ui->noteRemoveButton->setEnabled(true);
    ui->noteUndoButton->setEnabled(true);
    ui->noteRedoButton->setEnabled(true);

    connect(ui->noteAddButton, &QPushButton::clicked, this, &NoteMainWindow::noteAddClicked);
    connect(ui->noteRemoveButton, &QPushButton::clicked, this, &NoteMainWindow::noteRemoveClicked);
    connect(ui->noteUndoButton, &QPushButton::clicked, this, &NoteMainWindow::noteUndoClicked);
    connect(ui->noteRedoButton, &QPushButton::clicked, this, &NoteMainWindow::noteRedoClicked);

    qDebug() << "Is noteAddButton visible?" << ui->noteAddButton->isVisible();
    qDebug() << "Is noteAddButton enabled?" << ui->noteAddButton->isEnabled();

}

NoteMainWindow::~NoteMainWindow() {
    delete ui;
}
