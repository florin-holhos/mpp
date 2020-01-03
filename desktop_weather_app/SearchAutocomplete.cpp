#include "pch.h"
#include "curl-7.67.0-win64-mingw/include/curl/curl.h"
#include <string>

using namespace std;

auto getSuggestions(string input_value) {
	const string url = "https://devru-latitude-longitude-find-v1.p.rapidapi.com/latlon.php?location=" + input_value;
	
	CURL *curl;
	CURLcode res;

	curl = curl_easy_init();
    struct curl_slist *headers = NULL;

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        headers = curl_slist_append(headers, "Content-Type: application/json");
        headers = curl_slist_append(headers, "x-rapidapi-host: devru-latitude-longitude-find-v1.p.rapidapi.com");
        headers = curl_slist_append(headers, "x-rapidapi-key: f52d47d0a9msh399976bf74e6564p198b56jsnd57700a39a5a");
        
        // set headers
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        
        // fetch
        res = curl_easy_perform(curl);
        
        /* Check for errors */
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
            /* cleanup */
            curl_easy_cleanup(curl);
            curl_slist_free_all(headers);
            return NULL;
        }
        
        
        /* cleanup */
        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
    }
	
}
