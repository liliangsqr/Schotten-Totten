#pragma once
#include "TasDeCartes.h"
#include "CarteClan.h"
#include <vector>
#include <memory>

class TasBorne : public TasDeCartes<CarteClan> {
public:
    TasBorne() = default;
    unsigned int GetSize() const {
        return tas.size();
    }
};

