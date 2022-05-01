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

  CefBrowserSettings browser_settings;

  CefWindowInfo window_info;

  OnBeforeBrowserCreate(window_info);

//  settings.multi_threaded_message_loop=true;
  CefBrowserHost::CreateBrowser(window_info,
                                handler_,
                                url,
                                browser_settings,
                                nullptr,
                                nullptr);
}

void QBrowserClient::OnBrowserCreated(CefRefPtr<CefBrowser> browser) {
  // Add to the list of existing browsers.

  curr_window->setCefBrowser(browser);
  browser_list_[browser->GetIdentifier()] = curr_window;
  curr_window->show();
  window_lock.unlock();
}

void QBrowserClient::OnBeforeBrowserCreate(CefWindowInfo &window_info) {
  window_lock.lock();

  auto *w = new QBrowserWindow;
  curr_window = w;

  window_info.SetAsChild(w->winId(), {0, 0, 0, 0});
}

void QBrowserClient::OnSetTitle(CefRefPtr<CefBrowser> browser, const CefString &title) {
  browser_list_[browser->GetIdentifier()]->setTitle(QString::fromStdString(title.ToString()));
}

void QBrowserClient::OnBrowserClosed(CefRefPtr<CefBrowser> browser) {
  browser_list_[browser->GetIdentifier()]->is_closing_ =true;
  browser_list_[browser->GetIdentifier()]->close();
  browser_list_.erase(browser->GetIdentifier());

  if (browser_list_.empty()) CefQuitMessageLoop();
}
