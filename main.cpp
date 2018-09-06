#include <iostream>
#include "controller.h"
#include "model.h"
#include "view.h"
#include "gliph.h"

//1. Adding new gliphs is just creating new classes inheritable from Gliph
//2. Database interconnection is a new functions in MenuModel
//3. Modification of gliphs needs adding an access to their properties. Gliphstore in DrawModel allows to find elements and call appropriates methods for changing their properties
//4. Gliphstore in DrawModel allows to iterate through gliphs and work with them (replace, modification, etc)

int main()
{
    MenuModel menuModel{};
    DrawModel drawModel{};
    MenuController menuController(menuModel);
    DrawController drawController(drawModel);

    View menuView {};
    View drawView {};

    menuModel.connect([&](Model* m) {
        menuView.printStateOfDocument(m);
    });

    drawModel.connect([&](Model* m) {
        drawView.printStateOfDocument(m);
    });

    menuController.createNewDocument("picture.jpg");
    menuController.exportDocument("awesome_drawing.pdf");
    menuController.importDocument("other_picture.jpg");

    auto glyph = menuController.createGlyph(GlyphType::SIMPLE_GLYPH, "simple glyph");

    drawController.drawGlyph(glyph, 0, 0);
    drawController.deleteGlyph(glyph);

    return 0;
}
