// The Http class (BlockOut/Http.h) without a network, for AmigaOS: it is
// built in place of BlockOut/Http.cpp. BlockOut II's online hall of fame
// was on blockout.net, which is gone; every request fails with the reason,
// and the game shows it as it shows any network error.
// The AmiCradle Team. GPL 2 or later, like BlockOut II.
#include "GLApp/GLApp.h"
#include "Http.h"
#include <string.h>

static const char *no_network = "No network in this build (the online hall of fame is gone)";

Http::Http() {
  strcpy(err_str, no_network);
  useProxy = FALSE;
  strcpy(proxyName, "");
  proxyPort = 0;
}

void Http::SetProxy(BOOL enable) { useProxy = enable; }
void Http::SetProxyName(char *name) { strncpy(proxyName, name, sizeof(proxyName) - 1); proxyName[sizeof(proxyName) - 1] = 0; }
void Http::SetProxyPort(int port) { proxyPort = port; }

char *Http::Get(char *link, DWORD timeout, DWORD *outLength) {
  (void)link; (void)timeout;
  if (outLength)
    *outLength = 0;
  strcpy(err_str, no_network);
  return NULL;
}

char *Http::UploadFile(char *url, char *remotePHP, BYTE *buffer, DWORD length, DWORD timeout) {
  (void)url; (void)remotePHP; (void)buffer; (void)length; (void)timeout;
  strcpy(err_str, no_network);
  return NULL;
}

char *Http::GetError() { return err_str; }

BOOL Http::CheckProxy() { return FALSE; }
int Http::WaitFor(int, DWORD, int) { return -1; }
int Http::Write(int, char *, int, DWORD) { return -1; }
int Http::Read(int, char *, int, DWORD) { return -1; }
int Http::Connect(char *, int) { return -1; }
int Http::GetHttpCode() { return 0; }
