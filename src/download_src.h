#ifndef _DOWNLOAD_SRC_H
#define _DOWNLOAD_SRC_H
#include <curl/curl.h>

int progress_callback(void *p, curl_off_t dltotal, curl_off_t dlnow, curl_off_t ultotal, curl_off_t ulnow);

int download_file(const char* url, const char* out_file);

#endif 
