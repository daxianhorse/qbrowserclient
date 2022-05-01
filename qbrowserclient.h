//
// Created by liang on 22-4-20.
//

#ifndef QBROWSERCLIENT__QBROWSERCLIENT_H_
#define QBROWSERCLIENT__QBROWSERCLIENT_H_

#include "clienthandler.h"
#include "qbrowserwindow.h"

class QBrowserClient : public ClientHandler::Delegate {
 public:
  explicit QBrowserClient();

//  impl the SimpleHandler::Delegate
  void OnBrowserCreated(CefRefPtr<CefBrowser> browser) override;

  void OnBeforeBrowserPopup(CefWindowInfo &windowInfo) override;

  void OnBrowserClosed(CefRefPtr<CefBrowser> browser) override;

  void OnSetAddress(CefRefPtr<CefBrowser> browser, const CefString &url) override;

  void OnSetTitle(CefRefPtr<CefBrowser> browser, const CefString &title) override;

  void OnCreateBrowserByUrl(const CefString &url) override;

  void OnSetLoadingState(CefRefPtr<CefBrowser> browser, bool isLoading, bool canGoBack, bool canGoForward) override;

  void CreateBrowserByWindow(QBrowserWindow *target_window, const CefString &url);

  static QBrowserClient* GetInstance();

  QBrowserClient(const QBrowserClient &) = delete;
  const QBrowserClient &operator=(const QBrowserClient &) = delete;

 private:
  ClientHandler *handler_;

  std::unordered_map<int, QBrowserWindow *> browser_list_;
};

#endif //QBROWSERCLIENT__QBROWSERCLIENT_H_
