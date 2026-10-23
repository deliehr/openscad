#pragma once

#include <QObject>
#include <QSet>

class WindowManager : public QObject
{
  Q_OBJECT

public:
  WindowManager() = default;

  void add(class MainWindow *mainwin);
  void remove(class MainWindow *mainwin);
  void setLastActive(class MainWindow *mainwin);
  const QSet<MainWindow *>& getWindows() const;
  MainWindow *getLastActive() const;

private:
  QSet<MainWindow *> windows;
  MainWindow *lastActive = nullptr;
};
