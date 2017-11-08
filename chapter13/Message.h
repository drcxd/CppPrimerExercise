#pragma once
#include <string>
#include <set>

class Folder;

class Message {
    friend class Folder;
public:
    // folders is implicitly initialized to the empty set
    explicit Message(const std::string &str = "")
        : contents(str) { }
    // copy control to manage pointers to this Message
    Message(const Message &);
    Message(Message &&);
    Message &operator=(const Message &);
    Message &operator=(Message &&);
    ~Message();
    // add/remove this Message from the specified Folder's set of messages
    void save(Folder &);
    void remove(Folder &);
    void addFolder(Folder &);
    void remFolder(Folder &);
    void swap(Message &lhs, Message &rhs);
private:
    std::string contents;    // actual message text
    std::set<Folder *> folders;    // Folders that have this Message
    // utility functions used by copy constructor, assignment, and destructor
    // add this Message to the Folders that point to the parameter
    void add_to_Folders(const Message&);
    // remove this Message from every Folder in folders
    void remove_from_Folders();
    void move_Folders(Message *m);
};
