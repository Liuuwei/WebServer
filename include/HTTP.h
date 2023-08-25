//
// Created by Liuwei on 2023/8/6.
//

#ifndef WEBSERVER_HTTP_H
#define WEBSERVER_HTTP_H

#include <string>

//GET / HTTP/1.1
//Host: 10.211.55.3:9999
//Connection: keep-alive
//Upgrade-Insecure-Requests: 1
//User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/115.0.0.0 Safari/537.36
//Sec-Purpose: prefetch;prerender
//Purpose: prefetch
//Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7
//Accept-Encoding: gzip, deflate
//Accept-Language: zh-CN,zh;q=0.9

#include <regex>

struct request {
    std::string method;
    std::string resource;
};

class HTTP {
public:
    HTTP();
    ~HTTP();
    static request parse(const std::string& url);
    static std::string generate(request& msg);
    static std::string generate(const std::string& msg);
    static std::string generateHtml(const std::string& msg);
private:
    static std::regex httpRegex_;
};

#endif //WEBSERVER_HTTP_H
