//
// Created by yakir on 5/24/20.
//

#ifndef LINEARPSETGENERATOR_INVALIDDIMENSIONEXCEPTION_H
#define LINEARPSETGENERATOR_INVALIDDIMENSIONEXCEPTION_H

#include <stdexcept>

class InvalidDimensionException : public std::runtime_error {
public:
    InvalidDimensionException() : std::runtime_error("The dimensions of a nonsingular must be nonzero and equal") {
    }
};

#endif //LINEARPSETGENERATOR_INVALIDDIMENSIONEXCEPTION_H
