#ifndef NOTEVIEW_H
#define NOTEVIEW_H

#include <QMainWindow>
#include <QPushButton>
#include <QListWidget>
#include <QVBoxLayout>

class NoteView : public QMainWindow {
    Q_OBJECT
public:
    NoteView(QWidget *parent = nullptr) : QMainWindow(parent) {
        QWidget *centralWidget = new QWidget(this);
        setCentralWidget(centralWidget);
        QVBoxLayout *layout = new QVBoxLayout(centralWidget);

        listWidget = new QListWidget(centralWidget);
        layout->addWidget(listWidget);

        QPushButton *addButton = new QPushButton("Add Note", centralWidget);
        QPushButton *removeButton = new QPushButton("Remove Selected Note", centralWidget);
        QPushButton *undoButton = new QPushButton("Undo", centralWidget);
        QPushButton *redoButton = new QPushButton("Redo", centralWidget);

        layout->addWidget(addButton);
        layout->addWidget(removeButton);
        layout->addWidget(undoButton);
        layout->addWidget(redoButton);

        connect(addButton, &QPushButton::clicked, this, &NoteView::addNoteClicked);
        connect(removeButton, &QPushButton::clicked, this, &NoteView::removeNoteClicked);
        connect(undoButton, &QPushButton::clicked, this, &NoteView::undoClicked);
        connect(redoButton, &QPushButton::clicked, this, &NoteView::redoClicked);
    }

    QListWidget *listWidget;

signals:
    void addNoteClicked();
    void removeNoteClicked();
    void undoClicked();
    void redoClicked();
};

#endif // NOTEVIEW_H
