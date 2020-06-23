//Michal Kalinowski 304541
#ifndef FIGURE_H_INCLUDED
#define FIGURE_H_INCLUDED

#include <iostream>
#include <utility>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <Graph.h>

//added object factory

//figure.h and figure.cpp needs some refactoring
//because they dont keep up with my new code standards
//cleaning code


class FPoint
{
public:
    float x, y;

    FPoint(float cx = 0.0f, float cy = 0.0f)
            : x{cx}, y{cy} {};

    friend std::ostream &operator<<(std::ostream &os, const FPoint &pt);

    friend std::istream &operator>>(std::istream &is, FPoint &pt);

    friend FPoint max(const FPoint &l, const FPoint &r);

    friend FPoint min(const FPoint &l, const FPoint &r);

    operator Graph_lib::Point() const;
};

bool operator==(const FPoint &ls, const int &to_check);

FPoint operator*(const FPoint &ls, const FPoint &rs);

FPoint operator+(const FPoint &ls, const FPoint &rs);

FPoint operator-(const FPoint &ls, const FPoint &rs);

std::pair<FPoint, FPoint> operator*(const std::pair<FPoint, FPoint> &pr, FPoint &pt);

class figure
{
public:
    explicit figure(const std::vector<FPoint> &vec)
            : fdef(vec) {};

    virtual ~figure() = default;

    static std::string classId() { return "Unknown"; }

    virtual std::string getId() const = 0;

    virtual Graph_lib::Shape *getShape(
            const FPoint &scale = {1.0f, 1.0f},
            const FPoint &trans = {0.0f, 0.0f}) const = 0; //it was used in previous project
    virtual std::pair<FPoint, FPoint> bbox() const; //border box
    friend std::ostream &operator<<(std::ostream &os, const figure &fig);

    virtual std::vector<FPoint> getPoints() const = 0; //change from figure to polyline for animation purpose

protected:
    std::vector<FPoint> fdef;
};

class Rect : public figure
{
public:
    Rect(const std::vector<FPoint> &vec)
            : figure(vec)
    {
        if(fdef.size() != 2)
            throw std::runtime_error("Rect points != 2");
    }

    static std::string classId() { return "Rect"; }

    std::string getId() const override { return Rect::classId(); }

    static figure *create(const std::vector<FPoint> &points);

    Graph_lib::Shape *getShape(
            const FPoint &scale = {1.0f, 1.0f},
            const FPoint &trans = {0.0f, 0.0f}) const override;

    std::vector<FPoint> getPoints() const override;
};

float radius(const FPoint &mid, const FPoint &pt);

class Circ : public figure
{
public:
    explicit Circ(const std::vector<FPoint> &vec)
            : figure(vec)
    {
        if(fdef.size() != 2)
            throw std::runtime_error("Circ points != 2");
    }

    static std::string classId() { return "Circ"; }

    std::string getId() const override { return Circ::classId(); }

    static figure *create(const std::vector<FPoint> &points);

    Graph_lib::Shape *getShape(
            const FPoint &scale = {1.0f, 1.0f},
            const FPoint &trans = {0.0f, 0.0f}) const override;

    std::pair<FPoint, FPoint> bbox() const override;

    std::vector<FPoint> getPoints() const override;
};

class Line : public figure
{
public:
    explicit Line(const std::vector<FPoint> &vec)
            : figure(vec) {};

    static std::string classId() { return "Line"; }

    std::string getId() const override { return Line::classId(); }

    static figure *create(const std::vector<FPoint> &points);

    Graph_lib::Shape *getShape(
            const FPoint &scale = {1.0f, 1.0f},
            const FPoint &trans = {0.0f, 0.0f}) const override;

    std::vector<FPoint> getPoints() const override;
};

std::ostream &operator<<(std::ostream &os, const std::pair<FPoint, FPoint> &p);

std::string getId(std::istream &is);

std::vector<FPoint> getPoints(std::istream &is);

figure *getFigure(std::istream &is);

std::pair<FPoint, FPoint> mapBbox(
        const std::vector<figure *> &figures); //it was used in previous project
std::pair<FPoint, FPoint> getTransformation(
        const std::pair<FPoint, FPoint> &objBbox,
        const std::pair<FPoint, FPoint> &dispBbox); //it was used in previous project
std::string windowTitle();

class figFactory
{
public:
    typedef figure *(*createFig)(const std::vector<FPoint> &fdef);

    static figFactory &getFactory();

    void registerFigure(const std::string &id, figure *(*createFunc)(const std::vector<FPoint> &fdef));

    figure *create(const std::string &id, const std::vector<FPoint> &fdef);

private:
    typedef std::map<std::string, createFig> creators;
    creators creatorsMap;

    figFactory() = default;

    figFactory(const figFactory &) = delete;

    figFactory &operator=(const figFactory &) = delete;
};

#endif // FIGURE_H_INCLUDED