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
  QBrowserWindow() = default;
  ~QBrowserWindow() override = default;

  explicit QBrowserWindow(const CefString &url);

  void setCefBrowser(const CefRefPtr<CefBrowser> &browser);

  void setBrowserUrl(const QString &url);

  void setLoadingState(bool isLoading, bool canGoBack, bool canGoForward);

  void setClosingState(bool isClosing);

  void resizeEvent(QResizeEvent *ev) override;

  void closeEvent(QCloseEvent *) override;

 private:
  CefRefPtr<CefBrowser> browser_ = nullptr;
  QString browser_url_;
  bool is_closing_ = false;
  bool is_loading_ = false;
  bool can_go_back_ = false;
  bool can_go_forward_ = false;
};

#endif //QBROWSERCLIENT__QBROWSERWINDOW_H_
