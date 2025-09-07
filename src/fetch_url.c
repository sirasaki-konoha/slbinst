#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <curl/curl.h>

#include "fetch_url.h"


int fetch_url(const char* url) {
	CURL *curl;
	CURLcode res;
	
	if (url == NULL) {
		fprintf(stderr, "fetch: url is NULL!");
		exit(EXIT_FAILURE);
	}

	curl = curl_easy_init();

	if (curl) {
		FILE *fp = fopen("/dev/null", "rw+");
		if (fp == NULL) {
			printf("Failed to open /dev/null: %s\n", strerror(errno));
			exit(EXIT_FAILURE);
		}

		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_VERBOSE, 0);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
		curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);

		printf("Fetching %s...\n", url);
		res = curl_easy_perform(curl);
		fclose(fp);

		return (res != CURLE_HTTP_RETURNED_ERROR);
	}
	
}


