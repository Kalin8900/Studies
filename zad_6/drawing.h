//
// Created by Kalin on 22.04.2020.
//

#ifndef ZAD_6_DRAWING_H
#define ZAD_6_DRAWING_H

#include <iostream>
#include <fstream>
#include <Graph.h>
#include <Window.h>
#include <GUI.h>
#include "figure.h"

class myButton : public Graph_lib::Button //made for changing callback func
{
public:
    myButton(Graph_lib::Point xy, int w, int h, const string &label,
             Graph_lib::Callback cb)
            : Button(xy, w, h, label, cb) {}

    [[nodiscard]] Fl_Widget *get_pw() const { return pw; } //inherited from Graph_lib::Button protected
};


class myWindow : public Graph_lib::Window
{
public:
    myWindow(Graph_lib::Point loc, int width, int height, const string &title, const string &filename);

    ~myWindow() override;

    FPoint get_center() const; //gets center of a drawing area
    bool is_in_animation() const { return animation; }

private:
    int w, h;
    myButton btnClose, btnStartStop;
    bool animation;
    float rotationAngle;
    std::vector<Graph_lib::Shape *> shapes;
    std::vector<figure *> figs;

    void activate_anim() { animation = true; }

    void deactivate_anim() { animation = false; }

    void load(const string &file); //loads figures from the txt file
    void clear_wnd(); //clears shapes vector and window
    void refreshMap(); //moves shapes
    static void cb_close(Graph_lib::Address, Graph_lib::Address pWnd); //closing callback
    static void cb_start(Graph_lib::Address, Graph_lib::Address pWnd); //animation start callback
    static void cb_stop(Graph_lib::Address, Graph_lib::Address pWnd); //animation stop callback
    static void timer_callback(Graph_lib::Address pWnd); //rerunning animation if stop is not clicked
    void start(Graph_lib::Address pWnd); //helping function for start callback
    void stop(Graph_lib::Address pWnd); //helping function for stop callback
    void clearAllMem(); //clearing all allocated memory
};


#endif //ZAD_6_DRAWING_H
