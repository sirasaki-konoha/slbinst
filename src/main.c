#include <stdio.h>
#include "download_src.h"


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
	}
}
