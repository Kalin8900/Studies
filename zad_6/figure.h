//Michal Kalinowski 304541
#ifndef FIGURE_H_INCLUDED
#define FIGURE_H_INCLUDED
#include <iostream>
#include <utility>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <Graph.h>

class FPoint
{
public:
    float x,y;
    FPoint(float cx = 0.0f, float cy = 0.0f)
            : x{cx}, y{cy} {};
    friend std::ostream& operator<<(std::ostream& os, const FPoint& pt);
    friend std::istream& operator>>(std::istream& is, FPoint& pt);
    friend FPoint max(const FPoint& l, const FPoint& r);
    friend FPoint min(const FPoint& l, const FPoint& r);
    operator Graph_lib::Point() const;
};
bool operator==(const FPoint& ls, const int& to_check);
FPoint operator*(const FPoint& ls, const FPoint& rs);
FPoint operator+(const FPoint& ls, const  FPoint& rs);
FPoint operator-(const FPoint& ls, const FPoint& rs);
std::pair<FPoint, FPoint> operator*(const std::pair<FPoint, FPoint>& pr, FPoint& pt);

class figure
{
public:
    explicit figure(std::vector<FPoint> vec)
            : fdef(std::move(vec)) {};
    virtual ~figure() = default;
    static std::string class_id() { return "Unknown"; }
    virtual std::string get_id() const = 0;
    virtual Graph_lib::Shape* get_shape(
            const FPoint& scale = {1.0f, 1.0f},
            const FPoint& trans = {0.0f, 0.0f}) const = 0; //it was used in previous project
    virtual std::pair<FPoint, FPoint> bbox() const; //border box
    friend std::ostream& operator<<(std::ostream& os, const figure& fig);
    virtual std::vector<FPoint> get_points() const = 0; //change from figure to polyline for animation purpose

protected:
    std::vector<FPoint> fdef;
};

class Rect : public figure
{
public:
    explicit Rect(std::vector<FPoint>& vec)
            : figure(vec)
    {
        if(fdef.size() != 2)
            throw std::runtime_error("Rect points != 2");
    }
    static std::string class_id() { return "Rect"; }
    std::string get_id() const override { return Rect::class_id(); }
    Graph_lib::Shape* get_shape(
            const FPoint& scale = {1.0f, 1.0f},
            const FPoint& trans = {0.0f, 0.0f}) const override;
    std::vector<FPoint> get_points() const override;
};

float radius(const FPoint& mid, const FPoint& pt);

class Circ : public figure
{
public:
    explicit Circ(std::vector<FPoint>& vec)
            : figure(vec)
    {
        if(fdef.size() != 2)
            throw std::runtime_error("Circ points != 2");
    }
    static std::string class_id() { return "Circ"; }
    std::string get_id() const override { return Circ::class_id(); }
    Graph_lib::Shape* get_shape(
            const FPoint& scale = {1.0f, 1.0f},
            const FPoint& trans = {0.0f, 0.0f}) const override;
    std::pair<FPoint, FPoint> bbox() const override;
    std::vector<FPoint> get_points() const override;
};

class Line : public figure
{
public:
    explicit Line(std::vector<FPoint>& vec)
            : figure(vec) {};
    static std::string class_id() { return "Line"; }
    std::string get_id() const override { return Line::class_id(); }
    Graph_lib::Shape* get_shape(
            const FPoint& scale = {1.0f, 1.0f},
            const FPoint& trans = {0.0f, 0.0f}) const override;
    std::vector<FPoint> get_points() const override;
};

std::ostream& operator<<(std::ostream& os, const std::pair<FPoint, FPoint>& p);
std::string get_id(std::istream& is);
std::vector<FPoint> get_points(std::istream& is);
figure* get_figure(std::istream& is);
std::pair<FPoint, FPoint> map_bbox(
        const std::vector<figure*>& figures); //it was used in previous project
std::pair<FPoint, FPoint> get_transformation(
        const std::pair<FPoint, FPoint>& obj_bbox,
        const std::pair<FPoint, FPoint>& disp_bbox); //it was used in previous project
std::string window_title();
#endif // FIGURE_H_INCLUDED