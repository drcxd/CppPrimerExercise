#include "Folder.h"

Folder::Folder(const Folder &f) {
    for (auto &i : f.messages) {
        i->save(*this);
    }
}

Folder &Folder::operator=(const Folder &f) {
    for (auto &i : messages) {
        i->remove(*this);
    }
    for (auto &i : f.messages) {
        i->save(*this);
    }
}

Folder::~Folder() {
    for (auto &i : messages) {
        i->remove(*this);
    }
}

void Folder::addMsg(Message &m) {
    messages.insert(&m);
} 

void Folder::remMsg(Message &m) {
    messages.erase(&m);
}

void Folder::swap(Folder &lhs, Folder &rhs) {
    std::set<Message *> common;
    for (auto &i : lhs.messages) {
        if (rhs.messages.find(i) != rhs.messages.end()) {
            common.insert(i);
        }
    }
    
    for (auto &i : lhs.messages) {
        if (common.find(i) == common.end()) {
            i->remove(&lhs);
            i->add(&rhs);
        }
    }
    for (auto &i : rhs.messages) {
        if (common.find(i) == common.end()) {
            i->remove(&lhs);
            i->add(&rhs);
        }
    }
}
