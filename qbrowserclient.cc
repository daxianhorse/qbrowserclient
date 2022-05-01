//
// Created by liang on 22-4-20.
//

#include "qbrowserclient.h"
#include "qbrowserwindow.h"
#include "cef_app.h"

#include <iostream>

#include <mutex>

QBrowserClient::QBrowserClient(const std::string &url) {
  handler_ = new ClientHandler(this);

  auto *target_window = new QBrowserWindow;

  CreateBrowserByWindow(target_window, "bilibili.com");
}

void QBrowserClient::OnBrowserCreated(CefRefPtr<CefBrowser> browser) {
  // Add to the list of existing browsers.

  curr_window->setCefBrowser(browser);
  browser_list_[browser->GetIdentifier()] = curr_window;
  curr_window->show();
  window_lock.unlock();
}

void QBrowserClient::OnBeforeBrowserPopup(CefWindowInfo &window_info) {
  window_lock.lock();

  auto *w = new QBrowserWindow;
  curr_window = w;

  window_info.SetAsChild(w->winId(), {0, 0, 0, 0});
}

void QBrowserClient::OnSetTitle(CefRefPtr<CefBrowser> browser, const CefString &title) {
  browser_list_[browser->GetIdentifier()]->setTitle(QString::fromStdString(title.ToString()));
}

void QBrowserClient::OnBrowserClosed(CefRefPtr<CefBrowser> browser) {
  browser_list_[browser->GetIdentifier()]->setClosingState(true);
  browser_list_[browser->GetIdentifier()]->close();
  browser_list_.erase(browser->GetIdentifier());

  if (browser_list_.empty()) CefQuitMessageLoop();
}

void QBrowserClient::OnSetAddress(CefRefPtr<CefBrowser> browser, const CefString &url) {
  browser_list_[browser->GetIdentifier()]->setBrowserUrl(QString::fromStdString(url.ToString()));
}
void QBrowserClient::OnSetLoadingState(CefRefPtr<CefBrowser> browser, bool isLoading, bool canGoBack, bool canGoForward) {
  browser_list_[browser->GetIdentifier()]->setLoadingState(isLoading, canGoBack, canGoForward);
}
void QBrowserClient::CreateBrowserByWindow(QBrowserWindow *target_window, const CefString &url) {
  window_lock.lock();
  CefWindowInfo window_info;
  window_info.SetAsChild(target_window->winId(), {0, 0, 0, 0});
  curr_window = target_window;

  CefBrowserSettings browser_settings;

  CefBrowserHost::CreateBrowser(window_info,
                                handler_,
                                url,
                                browser_settings,
                                nullptr,
                                nullptr);
}
