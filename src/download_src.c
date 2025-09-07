#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>


int progress_callback(void *p, curl_off_t dltotal, curl_off_t dlnow, curl_off_t ultotal, curl_off_t ulnow) {
	(void)p; (void)ulnow; (void)ultotal;

	if(dltotal > 0) {
		int percent = (int)((dlnow * 100) / dltotal);
		printf("\rDownloading: %d%%", percent);
		fflush(stdout);
	}
	return 0;
}

int download_file(const char* url, const char* out_file) {
	CURL *curl;
	CURLcode res;
	FILE *fp;

	if (url == NULL || out_file == NULL) {
		fprintf(stderr, "download_file: %s is NULL!\n", url == NULL ? "url" : "out_file");
		return 1;
	}
	
	curl = curl_easy_init();
	if (curl) {
		fp = fopen(out_file, "wb");
		if (!fp) {
			perror("Failed to out_file");
			return 1;
		}
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

		curl_easy_setopt(curl, CURLOPT_XFERINFOFUNCTION, progress_callback);
		curl_easy_setopt(curl, CURLOPT_XFERINFODATA, NULL);
		curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);
		
		res = curl_easy_perform(curl);
		printf("\n");
		if (res != CURLE_OK) {
			perror("curl_easy_perform() failed");
			return 1;
		}

		fclose(fp);
		curl_easy_cleanup(curl);
	}
	return 0;

}




