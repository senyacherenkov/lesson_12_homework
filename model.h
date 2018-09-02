#pragma once
#include <functional>
#include <list>
#include <iostream>
#include <map>

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

    void createDocument(std::string& docName);
    void importDocument(std::string& docName);
    std::string exportDocument();

    virtual std::string printState();
private:
    MenuModelState m_state;
};

class DrawModel: public MenuModel {
public:
    DrawModel() = default;

    void drawGliph(std::string gliphName);
    void deleteGliph(std::string gliphName);

    virtual std::string printState();
private:
    std::map<std::string, int> m_gliphStore;
    static int m_counter;
};
