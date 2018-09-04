#include "model.h"

int DrawModel::m_counter = 0;

Model::~Model()
{}

void Model::notify()
{
    for(const auto& view: m_listeners)
        view(this);
}

void DrawModel::drawGliph(Gliph* gliph)
{
    m_counter++;
    std::cout << "New gliph " << gliph->getDescription() << " with number " << m_counter << " created" << std::endl;

    m_gliphStore.emplace(gliph, m_counter);
    notify();
}

void DrawModel::deleteGliph(Gliph* gliph)
{
    m_counter--;
    auto result = m_gliphStore.find(gliph);
    if(result == m_gliphStore.end())
        return;    
    std::cout << "Gliph " << gliph->getDescription() << " with number " << result->second << " deleted" << std::endl;
    m_gliphStore.erase(result);
    notify();
}

std::string DrawModel::printState()
{
    std::string strRepresentation;
    strRepresentation.append("Drawing current document: ");
    strRepresentation.append(m_docName);
    strRepresentation.append("\n");
    for(const auto& pair: m_gliphStore)
    {
        strRepresentation.append("gliph name: ");
        strRepresentation.append(pair.first->getDescription());
        strRepresentation.append(", number: ");
        strRepresentation.append(std::to_string(pair.second));
        strRepresentation.append("\n");
    }

    return strRepresentation;
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
     std::cout << "Manipulation for exporting current document " << m_docName << std::endl;
     m_state = MenuModelState::DOC_EXPORTED;
     notify();
     return m_docName;
}

std::string MenuModel::printState()
{
    std::string strRepresentation;
    strRepresentation.append("Current document: ");
    strRepresentation.append(m_docName);
    strRepresentation.append("\n");
    switch(static_cast<int>(m_state)){
        case static_cast<int>(MenuModelState::DOC_CREATED):
            strRepresentation.append("It was created here");
            break;
        case static_cast<int>(MenuModelState::DOC_IMPORTED):
            strRepresentation.append("It was imported");
            break;
        case static_cast<int>(MenuModelState::DOC_EXPORTED):
            strRepresentation.append("It was succesfully exported");
            break;
    }
    strRepresentation.append("\n");
    return strRepresentation;
}
