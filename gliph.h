#pragma once

enum class GliphType {
    DOT,
    ROUND,
    RECTANGULAR,
    TRIANGLE,
    ELLIPSE
};

class Gliph {
public:
    Gliph(GliphType type):
        m_type(type)
    {}
private:
    GliphType m_type;
};
