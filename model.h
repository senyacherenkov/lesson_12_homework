#pragma once
#include <functional>
#include <list>
#include <iostream>
#include <map>
#include "gliph.h"

enum class MenuModelState {
    DOC_CREATED,
    DOC_IMPORTED,
    DOC_EXPORTED
};

class Model;
using Listener = std::function<void(Model*)>;

class Model {    
public:
    virtual ~Model();

    void connect(Listener view) { m_listeners.emplace_back(view); }
    virtual std::string printState() = 0;
protected:
    void notify();
private:
    std::list<Listener> m_listeners;
protected:
    std::string m_docName;
};

class MenuModel: public Model {
public:
    MenuModel() = default;
    ~MenuModel() {}
    void createDocument(std::string& docName);
    void importDocument(std::string& docName);
    void exportDocument(std::string& docName);

    Glyph* createGlyph(GlyphType glyph, std::string description);
    virtual std::string printState();
private:
    MenuModelState m_state;
};

class DrawModel: public Model {
public:
    DrawModel() = default;
    ~DrawModel() {}
    void drawGliph(Glyph* gliphName, int x, int y);
    void deleteGliph(Glyph* gliphName);

    virtual std::string printState();

private:
    struct InternalData {
      int x, y, number;
    };

private:
    std::map<Glyph*, InternalData> m_gliphStore;
    static int m_counter;
};
