#include <iostream>
#include "controller.h"
#include "model.h"
#include "view.h"

int main()
{
    Model* menuModel = new MenuModel();
    Controller* menuController = new MenuController(menuModel);

    ViewBase* menuView = new MenuView("menuView");

    menuModel->connect([&](Model* m) {
        menuView->printNameOfCurrentDocument(m);
    });


    return 0;
}
