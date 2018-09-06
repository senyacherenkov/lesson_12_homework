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
    void exportDocument(std::string asFile) { m_model.exportDocument(asFile); }

    Glyph* createGlyph(GlyphType glyph, std::string description) { return m_model.createGlyph(glyph, description); }
private:
    MenuModel& m_model;
};

class DrawController {
public:
    DrawController(DrawModel& model):
        m_model(model)
    {}

    void drawGlyph(Glyph* gliph, int x, int y) {m_model.drawGliph(gliph, x, y);}
    void deleteGlyph(Glyph* gliph) {m_model.deleteGliph(gliph);}
private:
    DrawModel& m_model;
};
