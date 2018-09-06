#include "model.h"

int DrawModel::m_counter = 0;

Model::~Model()
{}

void Model::notify()
{
    for(const auto& view: m_listeners)
        view(this);
}

void DrawModel::drawGliph(Glyph* gliph, int x, int y)
{
    m_counter++;
    std::cout << "New glyph " << gliph->getDescription() << " with number " << m_counter
              << " and coordinates: " << x << ", " << y << " created" << std::endl;

    InternalData data = { data.x = x, data.y = y, data.number = m_counter };
    m_gliphStore.emplace(gliph, data);
    notify();
}

void DrawModel::deleteGliph(Glyph* gliph)
{
    m_counter--;
    auto result = m_gliphStore.find(gliph);
    if(result == m_gliphStore.end())
        return;    
    std::cout << "Glyph " << gliph->getDescription() << " with number " << result->second.number
              << " and coordinates: " << result->second.x << ", " << result->second.y << " deleted" << std::endl;
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
        strRepresentation.append("glyph name: ");
        strRepresentation.append(pair.first->getDescription());
        strRepresentation.append(", number: ");
        strRepresentation.append(std::to_string(pair.second.number));
        strRepresentation.append(" and coordinates: ");
        strRepresentation.append(std::to_string(pair.second.x));
        strRepresentation.append(", ");
        strRepresentation.append(std::to_string(pair.second.y));
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

void MenuModel::exportDocument(std::string& asFile)
{    
    std::cout << "Manipulation for exporting project as document " << asFile << std::endl;
    m_state = MenuModelState::DOC_EXPORTED;
    notify();
}

Glyph *MenuModel::createGlyph(GlyphType glyph, std::string description)
{
    std::cout << "Choosing glyph type from menu collection" << std::endl;
    switch(static_cast<int>(glyph)){
        case static_cast<int>(GlyphType::SIMPLE_GLYPH):
            return new SimpleGlyph(description);
        default:
            return nullptr;
    }
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
