#pragma once

#include <bitset>
#include <string>

template <unsigned N>
class Quiz {
public:
    Quiz() = default;
    Quiz(const std::string &ans) : answer(ans) { }
    void update(unsigned qnum, bool ans) {
        if (qnum >= N) {
            return;
        }
        answer.set(qnum, ans);
    }
private:
    std::bitset<N> answer;
};
