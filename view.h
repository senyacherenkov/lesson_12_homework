#pragma once
#include <string>
#include "model.h"


class View {
public:
    View() = default;
    void printStateOfDocument(Model* model) { std::cout << model->printState() << std::endl; }
};

