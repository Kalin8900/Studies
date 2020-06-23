//
// Created by Kalin on 22.04.2020.
//

#include "drawing.h"
#include "Matrix.h"

using namespace Graph_lib;

myWindow::myWindow(Graph_lib::Point loc, int width, int height, const string &title, const string &filename)
        : Graph_lib::Window(loc, width, height, title),
          w(width),
          h(height),
          btnClose(Graph_lib::Point(x_max() - 80, y_max() - 20),
                   80, 20,
                   "Close", cb_close),
          btnStartStop(Graph_lib::Point(x_max() - 80, y_max() - 50),
                       80, 20,
                       "Start", cb_start),
          animation(false),
          rotationAngle(0.0f)
{
    attach(btnClose);
    attach(btnStartStop);

    load(filename);

    refreshMap(); //first display
}

void myWindow::load(const string &file) //loading data from file
{
    ifstream ifs(file);
    figure* fig;
    if(!ifs.good())
        throw runtime_error("Cant load points"); //application cant run without objects
    while((fig = getFigure(ifs)) != nullptr)
    {
        figs.push_back(fig);
    }
}

FPoint myWindow::get_center() const //center of the display area
{
    return {static_cast<float>(w - btnStartStop.width) / 2,
            static_cast<float>(h - btnStartStop.height) / 2};
}

void myWindow::clear_wnd()
{
    if(is_in_animation()) //clear old elements before next step of animation
    {
        for(const auto& elem : shapes)
        {
            detach(*elem);
            delete elem;
        }
    }
    shapes.clear();
}

void myWindow::refreshMap() //display
{
    if(is_in_animation())
    {
        rotationAngle += 0.05f;
        clear_wnd(); //cleaning from prev display
    }

    Matrix<float> transMx;
    FPoint center = get_center();

    //getting transformation matrix
    transMx = Matrix<float>::translateMx(-center.x, -center.y) *
            Matrix<float>::rotateMx(rotationAngle) * Matrix<float>::translateMx(center.x, center.y);

    //changing figures to points for easier transform
    for(const auto& elem : figs)
    {
        auto* poly = new Open_polyline;
        vector<FPoint> points = elem->getPoints();
        for(const auto& elem : points)
        {
            poly->add(transMx.transform(elem));
        }
        shapes.push_back(poly);
        attach(*poly);
    }
    redraw();
}

void myWindow::cb_start(Graph_lib::Address, Graph_lib::Address pWnd)
{
    reinterpret_cast<myWindow*>(pWnd)->start(pWnd);
}

void myWindow::cb_close(Graph_lib::Address, Graph_lib::Address pWnd)
{
    auto* p = reinterpret_cast<myWindow*>(pWnd);
    p->hide(); //hiding window destructor is not called as I thought
    p->clearAllMem(); //clearing data
}

void myWindow::cb_stop(Graph_lib::Address, Graph_lib::Address pWnd)
{
    reinterpret_cast<myWindow*>(pWnd)->stop(pWnd);
}

void myWindow::timer_callback(Graph_lib::Address pWnd)
{
    const auto p = reinterpret_cast<myWindow*>(pWnd);
    p->rotationAngle += 0.05f;
    p->refreshMap(); //next display
    if (p->animation)
        Fl::repeat_timeout(0.1, timer_callback, p); //waiting for next step of animation
}

void myWindow::start(Address pWnd)
{
    btnStartStop.label = "Stop";
    btnStartStop.get_pw()->callback(reinterpret_cast<Fl_Callback*>(cb_stop), pWnd); //changing callback fc to stop
    activate_anim();
    timer_callback(pWnd);
}

void myWindow::stop(Graph_lib::Address pWnd)
{
    btnStartStop.label = "Start";
    btnStartStop.get_pw()->callback(reinterpret_cast<Fl_Callback*>(cb_start), pWnd); //changing callback fc to start
    clear_wnd();
    deactivate_anim();
}

void myWindow::clearAllMem()
{
    for(const auto& elem : figs) //removing all data from figs
        delete elem;
    figs.clear();

    clear_wnd(); //removing data from shapes
}

myWindow::~myWindow()
{
    clearAllMem(); //In case of closing window in other way than with close btn
}
