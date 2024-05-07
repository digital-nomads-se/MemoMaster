#ifndef NOTECONTROLLER_H
#define NOTECONTROLLER_H

#include <QObject>
#include <QInputDialog>
#include <QStack>
#include "headers/notemodel.h"
#include "headers/notemainwindow.h"  // Include the updated MainWindow header
#include "ui_notemainwindow.h"  // Include the correct UI header
#include <QFileDialog>
#include "headers/textfileadapter.h"

class NoteController : public QObject {
    Q_OBJECT
public:
    NoteController(NoteModel *model, NoteMainWindow *view) : model(model), view(view) {
        // Connecting new signals and slots based on the updated naming conventions
        connect(view, &NoteMainWindow::noteAddClicked, this, &NoteController::addNote);
        connect(view, &NoteMainWindow::noteRemoveClicked, this, &NoteController::removeSelectedNote);
        connect(view, &NoteMainWindow::noteUndoClicked, this, &NoteController::undo);
        connect(view, &NoteMainWindow::noteRedoClicked, this, &NoteController::redo);
        connect(model, &NoteModel::notesChanged, this, &NoteController::updateView);
        connect(view->ui->addNotesFromFileButton, &QPushButton::clicked, this, &NoteController::addNotesFromFile);
    }

public slots:
    void addNote() {
        bool ok;
        QString text = QInputDialog::getText(view, "Add Note", "Note text:", QLineEdit::Normal, "", &ok);
        if (ok && !text.isEmpty()) {
            saveState();
            model->addNote(text);
        }
    }

    void removeSelectedNote() {
        int index = view->ui->noteListWidget->currentRow();
        if (index != -1) {
            saveState();
            model->removeNote(index);
        }
    }

    void undo() {
        if (!undoStack.isEmpty()) {
            redoStack.push(model->saveState());
            model->restoreState(undoStack.pop());
        }
    }

    void redo() {
        if (!redoStack.isEmpty()) {
            undoStack.push(model->saveState());
            model->restoreState(redoStack.pop());
        }
    }

    void addNotesFromFile() {
        QString filePath = QFileDialog::getOpenFileName(view, "Open Text File", "", "Text Files (*.txt)");
        if (!filePath.isEmpty()) {
            TextFileAdapter adapter;
            QStringList notes = adapter.parseFile(filePath);
            for (const QString& note : notes) {
                if (!note.isEmpty()) {
                    saveState();
                    model->addNote(note);
                }
            }
        }
    }

private:
    void saveState() {
        undoStack.push(model->saveState());
        redoStack.clear();
    }

    void updateView() {
        view->ui->noteListWidget->clear();
        NoteMemento memento = model->saveState();
        foreach (const QString &note, memento.state) {
            view->ui->noteListWidget->addItem(note);
        }
    }

    NoteModel *model;
    NoteMainWindow *view;  // Updated type from MainWindow to NoteMainWindow
    QStack<NoteMemento> undoStack;
    QStack<NoteMemento> redoStack;
};

#endif // NOTECONTROLLER_H
