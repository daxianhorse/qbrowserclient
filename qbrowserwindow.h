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
//  explicit QBrowserWindow(QWidget *parent = nullptr);
  ~QBrowserWindow() override;

  void keyPressEvent(QKeyEvent *event) override;

  void resizeEvent(QResizeEvent *ev) override;

  void closeEvent(QCloseEvent *) override;

  void setCefBrowser(const CefRefPtr<CefBrowser> &browser);

 private:
  CefRefPtr<CefBrowser> browser_ = nullptr;
  bool is_closing_ = false;
};

#endif //QBROWSERCLIENT__QBROWSERWINDOW_H_
