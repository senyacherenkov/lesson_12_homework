#include "model.h"

int DrawModel::m_counter = 0;

void Model::notify()
{
    for(const auto& view: m_listeners)
        view(this);
}

void DrawModel::drawGliph(std::string gliphName)
{
    m_counter++;
    std::cout << "New gliph" << gliphName << " with number " << m_counter << "created" << std::endl;

    m_gliphStore.emplace(gliphName, m_counter);
}

void DrawModel::deleteGliph(std::string gliphName)
{
    m_counter--;
    auto result = m_gliphStore.find(gliphName);
    if(result == m_gliphStore.end())
        return;
    std::cout << "Gliph " << gliphName << " with number " << result->second << "deleted" << std::endl;
}

void MenuModel::createDocument(std::string &docName)
{
    std::cout << "Manipulation for creating new document with name " << docName << std::endl;
    m_docName = docName;
    m_state = MenuModelState::DOC_CREATED;
    notify();
}

void MenuModel::importDocument(std::string &docName)
{
    std::cout << "Manipulation for importing document " << docName << std::endl;
    m_docName = docName;
    m_state = MenuModelState::DOC_IMPORTED;
    notify();
}

std::string MenuModel::exportDocument()
{
     std::cout << "Manipulation for exportong current document " << m_docName << std::endl;
     m_state = MenuModelState::DOC_EXPORTED;
     notify();
     return m_docName;
}

std::string MenuModel::printState()
{
    std::string strRepresentation;
    strRepresentation.append("Current document: ");
    strRepresentation.append(m_docName);
    switch(static_cast<int>(m_state)){
        case MenuModelState::DOC_CREATED:
            strRepresentation.append(". It wa")
    }
}
