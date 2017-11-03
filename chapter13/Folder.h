#pragma once
#include <set>

class Message;
class Folder {
pubic:
    Folder() { }
    Folder(const Folder &);
    Folder &operator=(const Folder &);
    ~Folder();
    void addMsg(Message &);
    void remMsg(Message &);
    static void swap(Folder &lhs, Folder &rhs);
private:
    std::set<Message *> messages;
};
