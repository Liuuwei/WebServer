//
// Created by Liuwei on 2023/8/6.
//

#ifndef WEBSERVER_HTTP_H
#define WEBSERVER_HTTP_H

#include <string>
#include <fstream>


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
#include <my/Log.h>

struct request {
    std::string method;
    std::string resource;
};

class HTTP {
public:
    HTTP();
    ~HTTP();
    static request parse(const std::string& url) {
        std::smatch result;
        std::regex_match(url, result, httpRegex_);
        request ret;
        if (result.size() != 3) {
            Log::Instance()->DEBUG("HTTP::parse failed: %s", url.c_str());
            ret.method = std::string("GET");
            ret.resource = std::string("index.html");
        }
        ret.method = result[1].str();
        ret.resource = result[2].str();
        return ret;
    }
    static std::string generate(request& request) {
        std::string ret = "HTTP/1.1 200 OK\r\nConnection: keep-alive\r\nContent-Type: text/html\r\nContent-Length: ";

        std::string path = "../www";
        if (request.resource != "/") {
            path += request.resource;
        } else {
            path += "/index.html";
        }
        Log::Instance()->LOG("path: %s", path.c_str());
        FILE* fp = fopen(path.c_str(), "r");
        std::string body;
        if (fp == nullptr) {
            path = "log/" + request.resource;
            fp = fopen(path.c_str(), "r");
            if (fp == nullptr) {
                body = "404 Not Found";
            } else { // 打开本地普通文件
                std::ifstream file(path);
                std::string line;
                while (std::getline(file, line)) {
                    body += line + "<br>";
                }
                file.close();
            }
        }  else { // 打开本地的html文件
            std::ifstream file(path);
            std::string line;
            while (std::getline(file, line)) {
                body += line + '\n';
            }
            file.close();
        }

        ret += std::to_string(body.size());
        ret += "\r\n\r\n";
        ret += body;
        return ret;
    }
    static std::string generate(const std::string& msg) {
        std::string ret = "HTTP/1.1 200 OK\r\nConnection: keep-alive\r\nContent-Type: text/html\r\nContent-Length: "
                          +std::to_string(msg.size());
        ret += "\r\n\r\n";
        ret += msg;
        return ret;
    }
    static std::string generateHtml(const std::string& msg) {
        std::string body = "<!DOCTYPE html>\n"
                           "<html lang=\"en\">\n"
                           "<head>\n"
                           "    <meta charset=\"UTF-8\">\n"
                           "    <title>liuwei</title>\n" + msg +
                           "</head>\n"
                           "<body>\n"
                           "\n"
                           "</body>\n"
                           "</html>";
        return body;
    }
private:
    static std::regex httpRegex_;
};

std::regex HTTP::httpRegex_("([A-Z]+) (/.*) HTTP[\\s\\S]*");

#endif //WEBSERVER_HTTP_H
