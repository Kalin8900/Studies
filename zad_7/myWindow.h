//
// Created by Kalin on 06.05.2020.
//

#ifndef ZAD_7_MYWINDOW_H
#define ZAD_7_MYWINDOW_H

#include <Graph.h>
#include <Window.h>
#include <GUI.h>
#include <vector>

struct colorSpec //linking color with their name
{
    std::string colorName;
    Graph_lib::Color color;
};

struct menuSpec //for easier menu allocation
{
    std::string btnName;
    const int width;
    const int height;
};

class myWindow; //predeclaration needed for actionDescriptor
struct menuHeader; //predeclaration needed for actionDescriptor

struct actionDescriptor //this class handle multiple callbacks and buttons
{
    enum action
    {
        noAction, menuOpen, menuClose, menuSelect
    };
    //menuOpen expand buttons, menuClose hide them, menuSelect handle the callback of button from menu

    myWindow *pMyWnd;
    menuHeader *pMenuHeader;
    action currAction;
    Graph_lib::Color selectedColor; //color selected from the expanded button

    explicit actionDescriptor(myWindow *pWnd = nullptr, menuHeader *pMenu = nullptr,
                              action act = noAction, Graph_lib::Color col = Graph_lib::Color::invisible);

    ~actionDescriptor() = default;
};

class menuItem : public Graph_lib::Button //menus buttons while expanded
{
public:
    menuItem(Graph_lib::Point xy, int w, int h, const std::string &label);

    void attach(myWindow *pWnd, menuHeader *pMenu, Graph_lib::Color color,
                Graph_lib::Callback cbSetColor); //connects with menu and window

private:
    actionDescriptor btnDesc; //actions for btns
};

class menuHeader : public Graph_lib::Button //"menu" while clicked expands buttons
{
public:
    menuHeader(Graph_lib::Point xy, int w, int h, const std::string &label);

    void attach(myWindow *pWnd, const std::vector<colorSpec> &btns); //attach whole menu to window

    void showMenu(); //shows menu buttons

    void hideMenu(); //hides menu buttons

    [[nodiscard]] bool getIsOpen() const; //returns isOpen

    [[nodiscard]] int getHeight() const; //return height of menu buttons

    [[nodiscard]] int countWholeMenuHeight() const; //return height of menu buttons

    [[nodiscard]] int getWholeMenuHeight() const; //return whole height

    [[nodiscard]] Graph_lib::Point getPos() const; //return pos

    void moveMenuButtonsDown(); //moves buttons up to align with their parent

    void moveMenuButtonsUp(); //moves buttons down to align with their parent

    void updatePos(const int &heightChange); //changes pos.y by heightChange

private:
    Graph_lib::Point pos;
    int width, height, wholeHeight;
    bool isOpen;

    std::vector<unique_ptr<menuItem>> menuButtons; //buttons which appears after cbOpenClose

    actionDescriptor menDesc; //conected to the window by actionDescriptor

    static void cbOpenClose(Graph_lib::Address, Graph_lib::Address pActDesc); //shows/hides menu

    static void cbSetColor(Graph_lib::Address, Graph_lib::Address pBtnDesc); //menu's button clicked
};

class myWindow : public Graph_lib::Window
{
public:
    myWindow(Graph_lib::Point pos, int w, int h, const std::string &title);

    static void menuAction(actionDescriptor *desc); //action handling

private:
    Graph_lib::Button btnClose; //closing button with separate callback
    Graph_lib::Rectangle rect; //rectangle which changes after menus callbacks
    std::vector<unique_ptr<menuHeader>> menus; //all menus here
    static std::vector<colorSpec> fillColors; //colors for menu buttons
    static std::vector<menuSpec> btnNames; //names for menus

    void fillRectangle(actionDescriptor *desc);

    void outlineRectangle(actionDescriptor *desc);

    void selectedAction(actionDescriptor *desc);

    int findIndx(menuHeader *menu); //returns the index in vector of clicked menu

    static void open(actionDescriptor *descriptor); //open callback

    static void close(actionDescriptor *descriptor); //close callback

    static void wndClose(Graph_lib::Address, Graph_lib::Address pWnd); //window close callback
};


#endif //ZAD_7_MYWINDOW_H
