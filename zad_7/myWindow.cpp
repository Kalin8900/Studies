//
// Created by Kalin on 06.05.2020.
//
#include <Graph.h>
#include <memory>
#include "myWindow.h"

using namespace Graph_lib;

//actionDescriptor

actionDescriptor::actionDescriptor(myWindow *pWnd, menuHeader *pMenu, actionDescriptor::action act,
                                   Graph_lib::Color col)
        : pMyWnd(pWnd),
          pMenuHeader(pMenu),
          currAction(act),
          selectedColor(col) {}

//menuItem

menuItem::menuItem(Graph_lib::Point xy, int w, int h, const string &label)
        : Graph_lib::Button(xy, w, h, label, nullptr) {}

void menuItem::attach(myWindow *pWnd, menuHeader *pMenu, Graph_lib::Color color,
                      Graph_lib::Callback cbSetColor)
{
    btnDesc.pMyWnd = pWnd;
    btnDesc.pMenuHeader = pMenu;
    btnDesc.selectedColor = color;

    pWnd->attach(*this);
    pw->box(_FL_SHADOW_BOX);
    pw->callback(reinterpret_cast<Fl_Callback *>(cbSetColor),
                 &btnDesc); //connecting callback with actionDescrpitor
}

//menu

menuHeader::menuHeader(Point xy, int w, int h, const string &label)
        : Button(xy, w, h, label, nullptr),
          pos(xy),
          width(w),
          height(h),
          wholeHeight(h),
          isOpen(false),
          menDesc() {}

bool menuHeader::getIsOpen() const
{
    return isOpen;
}

void menuHeader::attach(myWindow *pWnd, const vector<colorSpec> &btns)
{
    menDesc.pMyWnd = pWnd;
    menDesc.pMenuHeader = this;

    for(int currY = pos.y + height; const auto &elem : btns) //every next menu's button will be lower
    {
        menuButtons.push_back(std::make_unique<menuItem>(Point(pos.x, currY),
                                                         width, height, elem.colorName));
        menuButtons.back()->attach(pWnd, this, elem.color, cbSetColor);
        currY += height;
    }

    pWnd->attach(*this);

    hideMenu(); //only menus visible
    pw->color(FL_RED); //cosmetic
    pw->box(_FL_SHADOW_BOX); //cosmetic
    pw->callback(reinterpret_cast<Fl_Callback *>(cbOpenClose),
                 &menDesc); //connecting callback with actionDescriptor
}

void menuHeader::showMenu()
{
    for(const auto &elem : menuButtons)
        elem->show();

    wholeHeight = countWholeMenuHeight(); //wholeHeight is now equal to all buttons
    isOpen = true;
}

void menuHeader::hideMenu()
{
    for(const auto &elem : menuButtons)
        elem->hide();

    wholeHeight = height; //wholeHeight is now equal to only menu height
    isOpen = false;
}

void menuHeader::cbOpenClose(Graph_lib::Address, Graph_lib::Address pActDesc) //closing when opend, opening when closed
{
    auto *ptr = reinterpret_cast<actionDescriptor *>(pActDesc);
    if(ptr->pMenuHeader->isOpen)
        ptr->currAction = actionDescriptor::menuClose;
    else
        ptr->currAction = actionDescriptor::menuOpen;
    myWindow::menuAction(ptr); //actionDescrpitor handle the callbacks
}

void menuHeader::cbSetColor(Graph_lib::Address, Graph_lib::Address pBtnDesc)
{
    auto *ptr = reinterpret_cast<actionDescriptor *>(pBtnDesc);
    ptr->currAction = actionDescriptor::menuSelect; //color and action selected
    myWindow::menuAction(ptr); //passing action to handle
}

void menuHeader::moveMenuButtonsDown()
{
    for(auto &elem : menuButtons)
        elem->move(0, countWholeMenuHeight());
}

void menuHeader::moveMenuButtonsUp()
{
    for(auto &elem : menuButtons)
        elem->move(0, -countWholeMenuHeight());
}

Graph_lib::Point menuHeader::getPos() const
{
    return pos;
}

void menuHeader::updatePos(const int &changeHeight)
{
    pos.y += changeHeight;
}

int menuHeader::getHeight() const
{
    return height;
}

int menuHeader::countWholeMenuHeight() const
{
    return static_cast<int>(menuButtons.size()) * height;
}

int menuHeader::getWholeMenuHeight() const
{
    return wholeHeight;
}

//here are available colors, Its no the best way to initialise them due to possible uncaught exception
std::vector<colorSpec> myWindow::fillColors
        {
                {"No Color", Color::invisible},
                {"Red",      Color::red},
                {"Blue",     Color::blue},
//                {"Green",    Color::green},
//                {"Magenta",  Color::magenta}
        };

//here are menuButtons, the same issue
std::vector<menuSpec> myWindow::btnNames
        {
                {"Fill",        80, 20},
                {"Outline",     80, 20},
                {"Test menu",   80, 20},
                {"Test menu 2", 80, 20},
                {"Test menu 3", 80, 20},
                {"Test menu 3", 80, 20}
        };

//window

bool moveError(const string &mes, int &value) //quick utility for open/close cb
{
    if(value == -1)
    {
        cerr << "Error in " + mes + " moveVal = -1" << endl;
        return true;
    }
    return false;
}

myWindow::myWindow(Point pos, int w, int h, const string &title)
        : Window(pos, w, h, title),
          btnClose(Point(x_max() - 80, y_max() - 20), 80, 20,
                   "Close", wndClose),
          rect(Point(100, 100), 300, 200)
{
    attach(btnClose);

    //creating and attaching menus
    for(int currY = 0; const auto &elem : btnNames) //every next button will be lower
    {
        menus.push_back(std::make_unique<menuHeader>(Point(x_max() - elem.width, currY),
                                                     elem.width, elem.height, elem.btnName));
        currY += elem.height;
    }
    for(auto &elem : menus)
        elem->attach(this, fillColors);

    attach(rect);
}

void myWindow::fillRectangle(actionDescriptor *desc)
{
    rect.set_fill_color(desc->selectedColor); //changing fill of the rectangle
    menus.at(0)->hideMenu(); //closing menu button after action
    close(desc); //moving menus for proper display
    redraw();
}

void myWindow::outlineRectangle(actionDescriptor *desc)
{
    rect.set_color(desc->selectedColor); //changing outline of the rectangle
    menus.at(1)->hideMenu(); //closing menu button after action
    close(desc); //moving menus for proper display
    redraw();
}

void myWindow::wndClose(Address, Address pWnd) //closing window
{
    reinterpret_cast<myWindow *>(pWnd)->hide();
}

//utilities for open/close cbs

//searching for new clicked menu, saving the index in menus vector
//return pair where bool means if clicked menu is before or after the last one
//returned int is a index of clicked item in menus vector

int myWindow::findIndx(menuHeader *menu)
{
    for(int i = 0; i < static_cast<int>(menus.size()); ++i)
    {
        if(menus.at(i)->label == menu->label)
            return i;
    }
    return -1; //if element was not found
}

//height difference between two menus
//could be unsigned
//but distance between this two menus wont be so big to consider unsigned value and casting it further

int buttonsHeightDif(menuHeader &menuDown, menuHeader &menuAbove)
{
    return abs(menuDown.getPos().y - menuAbove.getPos().y);
}

//helper function for Down/Up

void menuMove(menuHeader &menu, const int &val)
{
    menu.move(0, val);
    menu.updatePos(val);
}

//menu transition needed for proper menu opening

void menuMoveDown(menuHeader &menuDown, int &val)
{
    menuMove(menuDown, val);
    menuDown.moveMenuButtonsDown();
    if(!menuDown.getIsOpen()) //move function in FLTK do show on widget so if the menuDown was closed
        menuDown.hideMenu();  //it should be hided to maintain this state
}

//menu transition needed for proper menu closing

void menuMoveUp(menuHeader &menuDown, int &val)
{
    menuMove(menuDown, -val);
    menuDown.moveMenuButtonsUp();
    if(!menuDown.getIsOpen()) //move function in FLTK do show on widget so if the menuDown was closed
        menuDown.hideMenu();  //it should be hided to maintain this state
}

//callbacks handling

void myWindow::open(actionDescriptor *descriptor)
{
    descriptor->pMenuHeader->showMenu();
    auto pW = descriptor->pMyWnd;
    auto menuIdx = pW->findIndx(descriptor->pMenuHeader); //index in menus vector

    //neded for task
    //if somehow menu will be colliding with rectangle, the menu will be displayed above the rectangle
    int yPos = descriptor->pMenuHeader->getWholeMenuHeight() + descriptor->pMenuHeader->getPos().y;
    int xPos = descriptor->pMenuHeader->getPos().x;
    if(xPos < pW->rect.point(0).x + pW->rect.width() && yPos > pW->rect.point(0).y)
        pW->detach(pW->rect);

    int moveVal = pW->menus.at(menuIdx)->getWholeMenuHeight();

    if(moveError("open (before)", moveVal)) //check if menu was found in vector and throws ex if not
        throw runtime_error("");

    for(int i = menuIdx + 1; i < static_cast<int>(pW->menus.size()); ++i)
        menuMoveDown(*(pW->menus.at(i)), moveVal);
}

void myWindow::close(actionDescriptor *descriptor)
{
    descriptor->pMenuHeader->hideMenu();
    auto pW = descriptor->pMyWnd;
    auto menuIdx = pW->findIndx(descriptor->pMenuHeader); //index in menus vector

    pW->attach(pW->rect);

    int allDistance = 0; //the height of visible elements above transforming menu
    for(int i = menuIdx + 1; i < static_cast<int>(pW->menus.size()); ++i)
    {
        int moveVal = buttonsHeightDif(*(pW->menus.at(i)),
                                       *(pW->menus.at(menuIdx))) - (i - menuIdx) * pW->menus.at(i)->getHeight();

        if(moveError("open", moveVal))
            throw runtime_error("");

        if(i > menuIdx + 1) //every next menu can be opend
        {
            if(pW->menus.at(i - 1)->getIsOpen())
                allDistance += pW->menus.at(i - 1)->getWholeMenuHeight();
            moveVal -= allDistance;
        }

        menuMoveUp(*(pW->menus.at(i)), moveVal);
    }
}

void myWindow::selectedAction(actionDescriptor *desc) //only two working menus for this task
{
    if(desc->pMenuHeader->label == menus.at(0)->label)
        fillRectangle(desc);
    else if(desc->pMenuHeader->label == menus.at(1)->label)
        outlineRectangle(desc);
}

void myWindow::menuAction(actionDescriptor *desc) //actions handler
{
    switch (desc->currAction)
    {
        case actionDescriptor::menuOpen:
            desc->pMyWnd->open(desc);
            break;
        case actionDescriptor::menuClose:
            desc->pMyWnd->close(desc);
            break;
        case actionDescriptor::menuSelect:
            desc->pMyWnd->selectedAction(desc);
            break;
        case actionDescriptor::noAction:
            break;
    }
}
