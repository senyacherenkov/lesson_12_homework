#include <iostream>
#include "controller.h"
#include "model.h"
#include "view.h"

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
    menuController.exportDocument();
    menuController.importDocument("other_picture.jpg");

    drawController.drawGliph("rectangular");
    drawController.drawGliph("triangle");
    drawController.drawGliph("line");

    drawController.deleteGliph("triangle");

    return 0;
}
