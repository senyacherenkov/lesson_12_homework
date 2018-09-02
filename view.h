#pragma once
#include <string>
#include "model.h"


class MenuView {
public:
    MenuView() = default;
    void printStateOfMainDocument(Model* model) { std::cout << "Main view: current document is " << m_name << std::endl; }
};

class DrawView : public ViewBase {
public:
    DrawView(std::string name):
        ViewBase(name)
    {}

    virtual void printNameOfCurrentDocument(Model* model) { std::cout << "Draw view: current document is " << m_name << std::endl; }
};
