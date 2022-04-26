#include <iostream>
#include <QApplication>
#include "qbrowserclient.h"
#include "clienthandler.h"
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

  // Specify CEF global settings here.
  CefSettings settings;

  CefRefPtr<CefApp> app;

  CefInitialize(main_args, settings, app.get(), nullptr);
//  return 0;
  QApplication a(argc, argv);

  QBrowserClient qw("bilibili.com");

  CefRunMessageLoop();

  CefShutdown();

//  a.exec();
}
