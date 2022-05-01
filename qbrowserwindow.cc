//
// Created by liang on 22-4-20.
//

#include <iostream>
#include "qbrowserwindow.h"

#ifdef __linux__
#include <X11/Xlib.h>
#endif

void QBrowserWindow::resizeEvent(QResizeEvent *ev) {
  ::Display *display = cef_get_xdisplay();
  DCHECK(display);
  ::Window window = browser_->GetHost()->GetWindowHandle();

  XResizeWindow(display, window, this->geometry().width() * 1.25, this->geometry().height() * 1.25);
  XFlush(display);
}

void QBrowserWindow::setCefBrowser(const CefRefPtr<CefBrowser> &browser) {
  this->browser_ = browser;
}

void QBrowserWindow::closeEvent(QCloseEvent *ev) {
  qDebug("closing");
  if (!is_closing_) {
    browser_->GetHost()->TryCloseBrowser();
    ev->ignore();
  } else {
    browser_ = nullptr;
    ev->accept();
  }
}
void QBrowserWindow::setBrowserUrl(const QString &url) {
  this->browser_url_ = url;
  qDebug() << browser_url_;
}
void QBrowserWindow::setLoadingState(bool isLoading, bool canGoBack, bool canGoForward) {
  this->is_loading_ = isLoading;
  this->can_go_back_ = canGoBack;
  this->can_go_forward_ = canGoForward;
  qDebug() << isLoading << ' ' << canGoBack << ' ' << canGoForward;
}
void QBrowserWindow::setClosingState(bool isClosing) {
  this->is_closing_ = isClosing;
}
void QBrowserWindow::attachBrowser(const CefString &url) {

}


