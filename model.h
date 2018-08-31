#pragma once
#include <functional>
#include <list>
#include <iostream>

class Model;
using Listener = std::function<void(Model*)>;

class Model {    
public:
    virtual ~Model();

    void connect(Listener view) { m_listeners.emplace_back(view); }
    virtual void printNameOfCurrentDocument() = 0;
private:
    void notify();
private:
    std::list<Listener> m_listeners;
};

class MenuModel: public Model {
public:
    MenuModel() = default;

    void createDocument(std::string& docName) { std::cout << "You see a new document with name " << docName << std::endl; }
    void importDocument(std::string& docName) { std::cout << "Document " << docName << " has been imported " << std::endl; }
    std::string exportDocument() { std::cout << "Current document " << m_docName << " has been exported " << std::endl; }

    void printNameOfCurrentDocument() { std::cout << m_docName << std::endl; }
private:
    std::string m_docName;
};

class DrawModel: public MenuModel {
public:
    DrawModel() = default;

    void drawGliph(std::string gliphName) { std::cout << "You see a new gliph " << gliphName << std::endl; m_counter++; }
    void deleteGliph(std::string gliphName) { std::cout << "You see a new gliph " << gliphName << "with number: " << m_counter << std::endl; m_counter++; }
private:
    std::map<int, std::string> gliphStore;
};
