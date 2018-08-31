#pragma once
#include "model.h"

class Controller {
public:
    Controller(Model* model):
        m_model(model)
    {}
private:
    Model* m_model;
};

class MenuController: public Controller {
public:
    MenuController(Model* model):
        Controller(model)
    {}

    void createNewDocument(std::string& docName) { m_model->}
    void importDocument(std::string& docName);
    void exportDocument();
};

class DrawController: public Controller {
public:
    DrawController(Model* model):
        Controller(model)
    {}

    void drawGliph(std::string& docName);
    void deleteGliph(std::string& docName);
};
