#pragma once

#include "c17e11.h"

#include <bitset>
#include <string>

template <unsigned N>
class QuizCAnswer {
public:
    QuizCAnswer() = default;
    QuizCAnswer(const std::string &s) : correct(s) { }
    int grades(const Quiz<N> &q) {
        int result = 0;
        for (unsigned i = 0; i < N; ++i) {
            if (correct[i] == q[i]) {
                ++result;
            }
        }
        return result;
    }
private:
    std::bitset<N> correct;
};
