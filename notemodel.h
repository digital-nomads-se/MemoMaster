#ifndef NOTEMODEL_H
#define NOTEMODEL_H

#include <QObject>
#include <QStringList>
#include "notememento.h"

class NoteModel : public QObject {
    Q_OBJECT
public:
    NoteModel() {}

    void addNote(const QString &note) {
        notes << note;
        emit notesChanged();
    }

    void removeNote(int index) {
        if (index >= 0 && index < notes.size()) {
            notes.removeAt(index);
            emit notesChanged();
        }
    }

    NoteMemento saveState() {
        NoteMemento memento;
        memento.state = notes;
        return memento;
    }

    void restoreState(const NoteMemento &memento) {
        notes = memento.state;
        emit notesChanged();
    }

signals:
    void notesChanged();

private:
    QStringList notes;
};

#endif // NOTEMODEL_H
