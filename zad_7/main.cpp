#include <Graph.h>
#include <Window.h>
#include "myWindow.h"

int main()
{
    myWindow wnd(Graph_lib::Point(100,100), 600, 400, "304541");

    Graph_lib::gui_main();
    return 0;
}
