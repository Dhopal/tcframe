#pragma once

#include "GraderConfig.hpp"
#include "Verdict.hpp"
#include "tcframe/util.hpp"

namespace tcframe {

class Evaluator {
public:
    virtual ~Evaluator() {}

    virtual optional<Verdict> evaluate(const TestCase& testCase, const GraderConfig& config) = 0;
};

}