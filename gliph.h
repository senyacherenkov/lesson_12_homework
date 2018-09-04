#pragma once
#include <string>

class Gliph {
public:
    Gliph(std::string description):
        m_description(description)
    {}
    std::string getDescription() { return m_description;}
private:
    std::string m_description;
};

class SimpleGliph: public Gliph {
public:
    SimpleGliph(std::string description):
        Gliph(description)
    {}
};
