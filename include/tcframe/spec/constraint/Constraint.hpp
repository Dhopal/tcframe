#pragma once

#include <functional>
#include <string>
#include <tuple>

using std::function;
using std::string;
using std::tie;

namespace tcframe {

struct Constraint {
private:
    function<bool()> predicate_;
    string description_;

public:
    Constraint(const function<bool()>& predicate, const string& description)
            : predicate_(predicate)
            , description_(description) {}

    const function<bool()>& predicate() const {
        return predicate_;
    }

    const string& description() const {
        return description_;
    }

    bool operator==(const Constraint& o) const {
        return tie(description_) == tie(o.description_);
    }
};

}
