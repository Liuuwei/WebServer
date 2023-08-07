//
// Created by Liuwei on 2023/8/6.
//
#include "HTTP.h"
#include "Util.h"

#include <unistd.h>

HTTP::HTTP() {

}

HTTP::~HTTP() {

}

request HTTP::parse(const std::string& url) {
    std::smatch result;
    std::regex_match(url, result, httpRegex_);
    if (result.size() != 3) {
        DEBUG("HTTP::parse failed: %s", url.c_str());
    }
    request ret;
    ret.method = result[1].str();
    ret.resource = result[2].str();
    return ret;
}

std::string HTTP::generate(const request& request) {
    std::string ret = "HTTP/1.1 200 OK\r\nConnection: keep-alive\r\nContent-Type: text/html\r\nContent-Length: ";

    std::string path = "../www";
    if (request.resource != "/") {
        path += request.resource;
    } else {
        path += "/index.html";
    }
    LOG("path: %s", path.c_str());
    FILE* fp = fopen(path.c_str(), "r");
    std::string body;
    if (fp == nullptr) {
        body = "404 Not Found";
    } else {
        char buf[65536]{};
        ssize_t n = 0;
        while ((n = fread(buf, 1, sizeof(buf), fp)) > 0) {
            body += std::string(buf, n);
        }
    }
    ret += std::to_string(body.size());
    ret += "\r\n\r\n";
    ret += body;
    return ret;
}

std::regex HTTP::httpRegex_("([A-Z]+) (/.*) HTTP[\\s\\S]*");