#pragma once
#include <string>

enum class GlyphType {
    SIMPLE_GLYPH,
    OTHER_GLYPH
};

class Glyph {
public:
    Glyph(std::string description):
        m_description(description)
    {}
    std::string getDescription() { return m_description;}
private:
    std::string m_description;
};

class SimpleGlyph: public Glyph {
public:
    SimpleGlyph(std::string description):
        Glyph(description)
    {}
};
