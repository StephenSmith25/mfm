#pragma once
#include "domain.h"


namespace mfm{


template <unsigned TDim>
class Maxent {
public:
    Maxent() {};

private:
    std::shared_ptr<Domain<Tdim>> domain;

    void doSomething();

};
}