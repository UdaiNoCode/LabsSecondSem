#ifndef DIRECTORYCOUNTER_H
#define DIRECTORYCOUNTER_H

#include <QDir>
#include <QFile>
#include <QString>

class DirectoryCounter {
 public:
  DirectoryCounter();

 public:
  void allFilesAndDirsCount(const QString& path, int& filesCount,
                            int& dirCount);
  QString getFileNames();

 private:
  QString fileNames = "";
};
#endif  // DIRECTORYCOUNTER_H
