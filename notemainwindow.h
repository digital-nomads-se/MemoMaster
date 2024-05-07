#ifndef NOTE_MAIN_WINDOW_H
#define NOTE_MAIN_WINDOW_H

#include <QMainWindow>

namespace Ui {
class NoteMainWindow;
}

class NoteMainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit NoteMainWindow(QWidget *parent = nullptr);
    ~NoteMainWindow();

    Ui::NoteMainWindow *ui;

signals:
    void noteAddClicked();
    void noteRemoveClicked();
    void noteUndoClicked();
    void noteRedoClicked();
};

#endif // NOTE_MAIN_WINDOW_H
