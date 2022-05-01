//
// Created by liang on 22-4-20.
//

#ifndef QBROWSERCLIENT__QBROWSERWINDOW_H_
#define QBROWSERCLIENT__QBROWSERWINDOW_H_

#include <QQuickWindow>
#include "cef_browser.h"

class QBrowserWindow : public QQuickWindow {
 Q_OBJECT

 public:
  friend class QBrowserClient;
  ~QBrowserWindow() override;

  void resizeEvent(QResizeEvent *ev) override;

  void closeEvent(QCloseEvent *) override;

 private:
  CefRefPtr<CefBrowser> browser_ = nullptr;
  bool is_closing_ = false;

  void setCefBrowser(const CefRefPtr<CefBrowser> &browser);
};

#endif //QBROWSERCLIENT__QBROWSERWINDOW_H_
