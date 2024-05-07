#ifndef TEXTFILEADAPTER_H
#define TEXTFILEADAPTER_H

#include <QStringList>
#include <QFile>
#include <QTextStream>

class TextFileAdapter {
public:
    QStringList parseFile(const QString& filePath) {
        QStringList notes;
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            while (!in.atEnd()) {
                notes.append(in.readLine());
            }
            file.close();
        }
        return notes;
    }
};

#endif // TEXTFILEADAPTER_H