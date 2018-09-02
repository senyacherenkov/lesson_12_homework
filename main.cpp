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

    MenuView menuView {};
    DrawView drawView {};

    menuModel.connect([&](Model* m) {
        menuView->printNameOfCurrentDocument(m);
    });

    drawModel.connect([&](Model* m) {
        drawView->printNameOfCurrentDocument(m);
    });

    menuController.createNewDocument("picture_1.jpg");


    return 0;
}
