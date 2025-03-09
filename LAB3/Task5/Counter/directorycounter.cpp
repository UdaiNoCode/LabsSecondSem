#include "directorycounter.h"

DirectoryCounter::DirectoryCounter() {}

void DirectoryCounter::allFilesAndDirsCount(const QString& path,
                                            int& filesCount, int& dirCount) {
  QDir dir(path);

  if (!dir.exists()) {
    qDebug() << "No path";
    return;
  }

  dir.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot | QDir::Hidden |
                QDir::NoSymLinks);

  QFileInfoList fileList = dir.entryInfoList();

  for (const QFileInfo& elem : fileList) {
    if (elem.isDir()) {
      dirCount += 1;
      allFilesAndDirsCount(elem.filePath(), filesCount, dirCount);
    } else if (elem.isFile()) {
      filesCount += 1;
      this->fileNames.append(elem.filePath() + "\n");
    }
  }
}

QString DirectoryCounter::getFileNames() {
  return this->fileNames;
}
