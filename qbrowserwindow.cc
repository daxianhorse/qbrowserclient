//
// Created by liang on 22-4-20.
//

#include <iostream>
#include "qbrowserwindow.h"

#ifdef __linux__
#include <X11/Xlib.h>
#endif

QBrowserWindow::~QBrowserWindow() {
}

void QBrowserWindow::keyPressEvent(QKeyEvent *event) {
  std::cout << event->key() << std::endl;
}

void QBrowserWindow::resizeEvent(QResizeEvent *ev) {
  std::cout << 324234 << std::endl;

  ::Display *display = cef_get_xdisplay();
  DCHECK(display);
  ::Window window = browser_->GetHost()->GetWindowHandle();

  XResizeWindow(display, window, this->geometry().width() * 1.25, this->geometry().height() * 1.25);
  XFlush(display);
}

void QBrowserWindow::setCefBrowser(const CefRefPtr<CefBrowser> &browser) {
//  this->browser_->Release();
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

