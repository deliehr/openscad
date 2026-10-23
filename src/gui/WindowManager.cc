#include "gui/WindowManager.h"

#include <QSet>

#include "gui/MainWindow.h"

void WindowManager::add(MainWindow *mainwin)
{
  this->windows.insert(mainwin);
}

void WindowManager::remove(MainWindow *mainwin)
{
  this->windows.remove(mainwin);
  if (this->lastActive == mainwin) {
    this->lastActive = nullptr;
  }
}

void WindowManager::setLastActive(MainWindow *mainwin)
{
  this->lastActive = mainwin;
}

const QSet<MainWindow *>& WindowManager::getWindows() const
{
  return this->windows;
}

MainWindow *WindowManager::getLastActive() const
{
  if (this->lastActive) {
    return this->lastActive;
  }
  return this->windows.empty() ? nullptr : *this->windows.begin();
}
