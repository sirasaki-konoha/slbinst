#include <stdio.h>
#include <stdlib.h>

#include "fetch_url.h"
#include "kutil.h"

char* search_pkg(const char* pkg) {
	const char* words[] = {
		"academic",
		"business",
		"games",
		"ham",
		"misc",
		"office",
		"ruby",
		"accessibility",
		"desktop",
		"gis",
		"haskell",
		"multimedia",
		"perl",
		"system",
		"audio",
		"development",
		"graphics",
		"libraries",
		"network",
		"python",
		NULL};

	int array_len = get_array_len(words);

	for(int p=0;p<array_len;p+=1) {
		int state = fetch_url(format_string("http://slackbuilds.org/slackbuilds/15.0/%s/%s.tar.gz", words[p], pkg));

		if (state != 1) {
			continue;
		}else {
			return format_string("%s/%s", words[p], pkg);
		}
	}

	return NULL;
}

