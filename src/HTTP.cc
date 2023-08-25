//
// Created by Liuwei on 2023/8/6.
//
#include "HTTP.h"
#include "Log.h"

#include <unistd.h>
#include <fstream>
#include <algorithm>

HTTP::HTTP() {

}

HTTP::~HTTP() {

}

request HTTP::parse(const std::string& url) {
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

std::string HTTP::generate(request& request) {
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
            body += line;
        }
        file.close();
    }

    ret += std::to_string(body.size());
    ret += "\r\n\r\n";
    ret += body;
    return ret;
}

std::string HTTP::generate(const std::string& msg) {
    std::string ret = "HTTP/1.1 200 OK\r\nConnection: keep-alive\r\nContent-Type: text/html\r\nContent-Length: "
            +std::to_string(msg.size());
    ret += "\r\n\r\n";
    ret += msg;
    return ret;
}

std::string HTTP::generateHtml(const std::string &msg) {
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

std::regex HTTP::httpRegex_("([A-Z]+) (/.*) HTTP[\\s\\S]*");