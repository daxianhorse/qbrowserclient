#include <QApplication>
#include "browserclient.h"
#include "clienthandler.h"
#include "qbrowserwindow.h"
#include "cef_app.h"

int main(int argc, char **argv) {
  // Provide CEF with command-line arguments.
  CefMainArgs main_args(argc, argv);

  // CEF applications have multiple sub-processes (render, GPU, etc) that share
  // the same executable. This function checks the command-line and, if this is
  // a sub-process, executes the appropriate logic.
  int exit_code = CefExecuteProcess(main_args, nullptr, nullptr);
  if (exit_code >= 0) {
    // The sub-process has completed so return here.
    return exit_code;
  }

  // Parse command-line arguments for use in this method.
  CefRefPtr<CefCommandLine> command_line = CefCommandLine::CreateCommandLine();
  command_line->InitFromArgv(argc, argv);

  // Specify CEF global settings here.
  CefSettings settings;

  CefString(&settings.locale).FromString("zh-CN");
  CefString(&settings.accept_language_list).FromString("zh-CN");

  CefRefPtr<CefApp> app;

  CefInitialize(main_args, settings, app.get(), nullptr);
  QApplication a(argc, argv);

  QBrowserWindow w("https://mirrors.ustc.edu.cn/ubuntu-releases/22.04/");

  CefRunMessageLoop();

  CefShutdown();
}
