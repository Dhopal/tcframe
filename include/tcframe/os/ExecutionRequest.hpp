#pragma once

#include <string>
#include <tuple>
#include <utility>

#include "tcframe/util.hpp"

using std::move;
using std::string;
using std::tie;

namespace tcframe {

struct ExecutionRequest {
    friend class ExecutionRequestBuilder;

private:
    string command_;
    optional<string> inputFilename_;
    optional<string> outputFilename_;
    optional<string> errorFilename_;
    optional<int> timeLimit_;
    optional<int> memoryLimit_;

public:
    const string& command() const {
        return command_;
    }

    const optional<string>& inputFilename() const {
        return inputFilename_;
    }

    const optional<string>& outputFilename() const {
        return outputFilename_;
    }

    const optional<string>& errorFilename() const {
        return errorFilename_;
    }

    const optional<int>& timeLimit() const {
        return timeLimit_;
    }

    const optional<int>& memoryLimit() const {
        return memoryLimit_;
    }

    bool operator==(const ExecutionRequest& o) const {
        return tie(command_, inputFilename_, outputFilename_, errorFilename_, timeLimit_, memoryLimit_)
                == tie(o.command_, o.inputFilename_, o.outputFilename_, o.errorFilename_, o.timeLimit_, o.memoryLimit_);
    }
};

class ExecutionRequestBuilder {
private:
    ExecutionRequest subject_;

public:
    ExecutionRequestBuilder& setCommand(string command) {
        subject_.command_ = command;
        return *this;
    }

    ExecutionRequestBuilder& setInputFilename(string inputFilename) {
        subject_.inputFilename_ = optional<string>(inputFilename);
        return *this;
    }

    ExecutionRequestBuilder& setOutputFilename(string outputFilename) {
        subject_.outputFilename_ = optional<string>(outputFilename);
        return *this;
    }

    ExecutionRequestBuilder& setErrorFilename(string errorFilename) {
        subject_.errorFilename_ = optional<string>(errorFilename);
        return *this;
    }

    ExecutionRequestBuilder& setTimeLimit(int timeLimit) {
        subject_.timeLimit_ = optional<int>(timeLimit);
        return *this;
    }

    ExecutionRequestBuilder& setMemoryLimit(int memoryLimit) {
        subject_.memoryLimit_ = optional<int>(memoryLimit);
        return *this;
    }

    ExecutionRequest build() {
        return move(subject_);
    }
};

}
