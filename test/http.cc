//
// Created by Liuwei on 2023/8/6.
//

#include <iostream>
#include <string>
#include <regex>

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

#include "HTTP.h"

int main() {
    std::string request = "GET /favicon.ico HTTP/1.1\n"
                          "Host: 10.211.55.3:9999\n"
                          "Connection: keep-alive\n"
                          "User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/115.0.0.0 Safari/537.36\n"
                          "Accept: image/avif,image/webp,image/apng,image/svg+xml,image/*,*/*;q=0.8\n"
                          "Referer: http://10.211.55.3:9999/\n"
                          "Accept-Encoding: gzip, deflate\n"
                          "Accept-Language: zh-CN,zh;q=0.9\n"
                          "";
    HTTP http_;
    auto ret = HTTP::parse(request);
    std::cout << ret.method << std::endl << ret.resource << std::endl;
}