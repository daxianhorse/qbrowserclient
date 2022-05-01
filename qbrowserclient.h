//
// Created by liang on 22-4-20.
//

#ifndef QBROWSERCLIENT__QBROWSERCLIENT_H_
#define QBROWSERCLIENT__QBROWSERCLIENT_H_

#include "clienthandler.h"
#include "qbrowserwindow.h"

class QBrowserClient : public ClientHandler::Delegate {
 public:
  explicit QBrowserClient(const std::string &url);

//  impl the SimpleHandler::Delegate
  void OnBrowserCreated(CefRefPtr<CefBrowser> browser) override;

  void OnBeforeBrowserCreate(CefWindowInfo &windowInfo) override;

  void OnBrowserClosed(CefRefPtr<CefBrowser> browser) override;

  void OnSetTitle(CefRefPtr<CefBrowser> browser, const CefString &title) override;

 private:
  ClientHandler *handler_;

  std::map<int, QBrowserWindow *> browser_list_;

  std::mutex window_lock;
  QBrowserWindow *curr_window;
};

#endif //QBROWSERCLIENT__QBROWSERCLIENT_H_
