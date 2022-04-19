//
// Created by liang on 22-4-19.
//

#ifndef QBROWSERCLIENT__CLIENTHANDLER_H_
#define QBROWSERCLIENT__CLIENTHANDLER_H_

#include "include/cef_client.h"

class ClientHandler :
    public CefClient,
    public CefDisplayHandler,
    public CefKeyboardHandler,
    public CefContextMenuHandler,
    public CefLifeSpanHandler,
    public CefLoadHandler {
 public:
  class Delegate {
   public:
    // Called when the browser has been created.
    virtual void OnBrowserCreated(CefRefPtr<CefBrowser> browser) = 0;

    virtual void OnBeforeBrowserCreate(CefWindowInfo &windowInfo) = 0;

    virtual void OnSetTitle(CefRefPtr<CefBrowser> browser, const CefString &title) = 0;

//    // Called when the browser is closing.
//    virtual void OnBrowserClosing(CefRefPtr<CefBrowser> browser) = 0;
//
//    // Called when the browser has been closed.
    virtual void OnBrowserClosed(CefRefPtr<CefBrowser> browser) = 0;

//    // Set the window URL address.
//    virtual void OnSetAddress(const std::string& url) = 0;
//
//    // Set the window title.
//    virtual void OnSetTitle(const std::string& title) = 0;
//
//    // Set fullscreen mode.
//    virtual void OnSetFullscreen(bool fullscreen) = 0;
//
//    // Auto-resize contents.
//    virtual void OnAutoResize(const CefSize& new_size) = 0;
//
//    // Set the loading state.
//    virtual void OnSetLoadingState(bool isLoading,
//                                   bool canGoBack,
//                                   bool canGoForward) = 0;

   protected:
    virtual ~Delegate() = default;
  };

  explicit ClientHandler(Delegate *delegate) {
    this->delegate_ = delegate;
  }

  // CefClient methods:
  CefRefPtr<CefDisplayHandler> GetDisplayHandler() override {
    return this;
  }

  CefRefPtr<CefLifeSpanHandler> GetLifeSpanHandler() override {
    return this;
  }

  CefRefPtr<CefContextMenuHandler> GetContextMenuHandler() override {
    return this;
  }

  CefRefPtr<CefLoadHandler> GetLoadHandler() override {
    return this;
  }

  CefRefPtr<CefKeyboardHandler> GetKeyboardHandler() override {
    return this;
  }

  // LifeSpanHandler
  bool OnBeforePopup(CefRefPtr<CefBrowser> browser,
                     CefRefPtr<CefFrame> frame,
                     const CefString &target_url,
                     const CefString &target_frame_name,
                     WindowOpenDisposition target_disposition,
                     bool user_gesture,
                     const CefPopupFeatures &popupFeatures,
                     CefWindowInfo &windowInfo,
                     CefRefPtr<CefClient> &client,
                     CefBrowserSettings &settings,
                     CefRefPtr<CefDictionaryValue> &extra_info,
                     bool *no_javascript_access) override;
  void OnAfterCreated(CefRefPtr<CefBrowser> browser) override;
  bool DoClose(CefRefPtr<CefBrowser> browser) override;
  void OnBeforeClose(CefRefPtr<CefBrowser> browser) override;

  // CefContextMenuHandler methods
  void OnBeforeContextMenu(CefRefPtr<CefBrowser> browser,
                           CefRefPtr<CefFrame> frame,
                           CefRefPtr<CefContextMenuParams> params,
                           CefRefPtr<CefMenuModel> model) override;
  bool OnContextMenuCommand(CefRefPtr<CefBrowser> browser,
                            CefRefPtr<CefFrame> frame,
                            CefRefPtr<CefContextMenuParams> params,
                            int command_id,
                            EventFlags event_flags) override;

  // CefLoadHandler methods:
  void OnLoadError(CefRefPtr<CefBrowser> browser,
                           CefRefPtr<CefFrame> frame,
                           ErrorCode errorCode,
                           const CefString &errorText,
                           const CefString &failedUrl) override;

  void OnTitleChange(CefRefPtr<CefBrowser> browser, const CefString &title) override;

  // CefKeyboardHandler:
  bool OnPreKeyEvent(CefRefPtr<CefBrowser> browser,
                     const CefKeyEvent &event,
                     XEvent *os_event,
                     bool *is_keyboard_shortcut) override;

  void OnShowDevTools(CefRefPtr<CefBrowser> browser, const CefPoint &inspect_element_at);

  Delegate *delegate_;

// Include the default reference counting implementation.
 IMPLEMENT_REFCOUNTING(ClientHandler);
};

#endif //QBROWSERCLIENT__CLIENTHANDLER_H_