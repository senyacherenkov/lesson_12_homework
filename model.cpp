#include "model.h"

void Model::notify()
{
    for(const auto& view: m_listeners)
        view(this);
}
