#pragma once
#include <string>
#include "model.h"


class ViewBase {
public:
    ViewBase(std::string name);

    virtual void printNameOfCurrentDocument(Model* model) = 0;
private:
    std::string m_name;
};

class MenuView : public ViewBase {
public:
    MenuView(std::string name):
        ViewBase(name)
    {}

    void printNameOfCurrentDocument(Model* model) {}
};
