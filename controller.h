#pragma once
#include "model.h"

class MenuController {
public:
    MenuController(MenuModel& model):
       m_model(model)
    {}

    void createNewDocument(std::string docName) { m_model.createDocument(docName); }
    void importDocument(std::string docName) {m_model.importDocument(docName); }
    std::string exportDocument() { return m_model.exportDocument(); }
private:
    MenuModel& m_model;
};

class DrawController {
public:
    DrawController(DrawModel& model):
        m_model(model)
    {}

    void drawGliph(std::string docName) {m_model.drawGliph(docName);}
    void deleteGliph(std::string docName) {m_model.deleteGliph(docName);}
private:
    DrawModel& m_model;
};
