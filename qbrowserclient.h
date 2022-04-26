//
// Created by liang on 22-4-20.
//

#ifndef QBROWSERCLIENT__QBROWSERCLIENT_H_
#define QBROWSERCLIENT__QBROWSERCLIENT_H_

#include "clienthandler.h"
#include "qbrowserwindow.h"

 class QBrowserClient : public ClientHandler::Delegate {
 public:
  QBrowserClient(const std::string &url);

//  impl the SimpleHandler::Delegate
  void OnBrowserCreated(CefRefPtr<CefBrowser> browser) override;

  void OnBeforeBrowserCreate(CefWindowInfo &windowInfo) override;

  void OnBrowserClosed(CefRefPtr<CefBrowser> browser) override;

  void OnSetTitle(CefRefPtr<CefBrowser> browser, const CefString &title) override;

 private:
  CefRefPtr<ClientHandler> handler_;

  std::map<int, QBrowserWindow*> browser_list_;
};

#endif //QBROWSERCLIENT__QBROWSERCLIENT_H_
