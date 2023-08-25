//
// Created by Liuwei on 2023/8/19.
//
#include "EventLoop.h"
#include "Log.h"
#include "TcpServer.h"
#include "HTTP.h"

#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

std::string path_to_directory = "/clion/bin/log"; // 替换为你要遍历的目录路径

void fun(std::shared_ptr<TcpConnection> conn, Buffer* buffer) {
    std::vector<std::string> names;
    if (buffer->FindEnd()) {
        std::string url = buffer->retriveSome(buffer->FindEnd() - buffer->readIndex() + 1);
        request request_ = HTTP::parse(url);
        if (request_.resource == "/") {
            std::string body;
            try {
                for (const auto& entry : fs::directory_iterator(path_to_directory)) {
                    if (fs::is_regular_file(entry.status())) {
                        names.emplace_back(entry.path().filename());
                    }
                }
            } catch (const fs::filesystem_error& ex) {
                std::cerr << "Error accessing directory: " << ex.what() << std::endl;
            }
            std::sort(names.begin(), names.end());
            for (auto& name : names) {
                std::string tmp = "<a href=\"";
                tmp += name;
                tmp += "\">";
                tmp += name;
                tmp += "</a><br>";
                body.append(tmp);
            }
            body = HTTP::generateHtml(body);
            std::string ret = HTTP::generate(body);
            conn->send(ret);
        } else {
            std::string ret = HTTP::generate(request_);
            conn->send(ret);
        }
    }
}

int main() {
    EventLoop loop;
    InetAddr addr("192.168.0.165", 9999);
    TcpServer server(&loop, addr);
    server.setOnMessageCallback(fun);
    server.setThreadNums(0);
    server.start();
    Log::Instance()->close();
    loop.loop();
}
