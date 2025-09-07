#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "download_src.h"
#include "fetch_url.h"
#include "search_pkg.h"


void help(const char* call_name) {
	printf(
			"slbinst version %s\n"
			"Usage:\n"
			"\t%s install [PACKAGE]\n"
			"\t%s update [PACKAGE]\n"
			"\t%s search [PACKAGE]\n"
	      , PACKAGE_VERSION, call_name, call_name, call_name);
	return;
}


int main(int argc, char* argv[]) {
	if (argc < 2) {
		help(argv[0]);
		exit(EXIT_FAILURE);
	}
	curl_global_init(CURL_GLOBAL_DEFAULT);

	printf("search: argc: %d\n", argc);
	if (strcmp(argv[1], "search") == 0) {
		if (argc == 3) {
			char *package_location = search_pkg(argv[2]);
			if (package_location != NULL) {
				printf("Package found: %s\n", package_location);
				free(package_location);
			}else {
				printf("Package not found\n");
			}
		}else {
			printf("Known user\n");
		}
	}

	curl_global_cleanup();
}
