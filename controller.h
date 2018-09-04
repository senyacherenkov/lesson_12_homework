#pragma once
#include "model.h"
#include "gliph.h"

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

    void drawGliph(Gliph* gliph) {m_model.drawGliph(gliph);}
    void deleteGliph(Gliph* gliph) {m_model.deleteGliph(gliph);}
private:
    DrawModel& m_model;
};
