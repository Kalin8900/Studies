#include "figure.h"
#include <cmath>

#define PI 3.14159265359


//FPoint

FPoint max(const FPoint &l, const FPoint &r)
{
    return {std::max(l.x, r.x), std::max(l.y, r.y)};
}

FPoint min(const FPoint &l, const FPoint &r)
{
    return {std::min(l.x, r.x), std::min(l.y, r.y)};
}

FPoint::operator Graph_lib::Point() const //conversion from FPoint to Graph_lib::Point
{
    return {static_cast<int>(x), static_cast<int>(y)};
}

std::ostream &operator<<(std::ostream &os, const FPoint &pt)
{
    os << '(' << pt.x << ',' << pt.y << ')';
    return os;
}

std::istream &operator>>(std::istream &is, FPoint &pt)
{
    char l, c, r;
    is >> l >> pt.x >> c >> pt.y >> r;
    if(l != '(' || c != ',' || r != ')')
        throw std::runtime_error("Its not a point");
    return is;
}

bool operator==(const FPoint &ls, const int &to_check) //comparing FPoint with single int
{
    return ls.x == static_cast<float>(to_check) && ls.y == static_cast<float>(to_check);
}

FPoint operator*(const FPoint &ls, const FPoint &rs)
{
    return {ls.x * rs.x, ls.y * rs.y};
}

FPoint operator+(const FPoint &ls, const FPoint &rs)
{
    return {ls.x + rs.x, ls.y + rs.y};
}

FPoint operator-(const FPoint &ls, const FPoint &rs)
{
    return {ls.x - rs.x, ls.y - rs.y};
}

std::pair<FPoint, FPoint> operator*(const std::pair<FPoint, FPoint> &pr, FPoint &pt)
{
    return std::make_pair(pr.first * pt, pr.second * pt);
}


//Figure

std::pair<FPoint, FPoint> figure::bbox() const
{
    FPoint pmin = fdef[0], pmax = fdef[0];
    for(const auto &elem : fdef)
    {
        pmin = min(pmin, elem);
        pmax = max(pmax, elem);
    }
    return std::make_pair(pmin, pmax);
}

std::ostream &operator<<(std::ostream &os, const figure &fig)
{
    os << fig.getId() << '(';
    for(const auto &elem : fig.fdef)
        os << elem;
    os << ')';
    return os;
}

//Rect

Graph_lib::Shape *Rect::getShape(
        const FPoint &scale,
        const FPoint &trans) const
{
    if(scale == 0)
        throw runtime_error("Scale must be different from 0");
    const FPoint one = fdef[0] * scale + trans;
    const FPoint two = fdef[1] * scale + trans;
    return new Graph_lib::Rectangle(min(one, two), max(one, two));

}

std::vector<FPoint> Rect::getPoints() const
{
    std::vector<FPoint> vec;

    vec.push_back(min(fdef.at(0), fdef.at(1)));
    vec.emplace_back(min(fdef.at(0).x, fdef.at(1).x),
            max(fdef.at(0).y, fdef.at(1).y));
    vec.push_back(max(fdef.at(0), fdef.at(1)));
    vec.emplace_back(max(fdef.at(0).x, fdef.at(1).x),
            min(fdef.at(0).y, fdef.at(1).y));
    vec.push_back(min(fdef.at(0), fdef.at(1)));

    return vec;
}

figure *Rect::create(const vector<FPoint> &points)
{
    return new Rect(points);
}

//Circ

Graph_lib::Shape *Circ::getShape(
        const FPoint &scale,
        const FPoint &trans) const
{
    const FPoint cPt = fdef[1] * scale + trans;
    const FPoint mid = fdef[0] * scale + trans;
    float rad = radius(mid, cPt);
    return new Graph_lib::Circle(mid, static_cast<int>(rad));
}

std::pair<FPoint, FPoint> Circ::bbox() const
{
    FPoint pmin = fdef[0], pmax = fdef[0];
    float rad = radius(fdef[0], fdef[1]);
    pmin = FPoint(pmin.x - rad, pmin.y - rad);
    pmax = FPoint(pmin.x + rad * 2, pmin.y + rad * 2);
    return std::make_pair(pmin, pmax);
}

std::vector<FPoint> Circ::getPoints() const
{
    //Parametric equation
    float rad = radius(fdef.at(0), fdef.at(1));
    std::vector<FPoint> vec;
    for(float i = 0; i < 2 * PI; i += 0.25)
        vec.emplace_back(fdef.at(0).x + rad * cos(i),
                fdef.at(0).y + rad * sin(i));
    return vec;
}

figure *Circ::create(const vector<FPoint> &points)
{
    return new Circ(points);
}

//Line

Graph_lib::Shape *Line::getShape(
        const FPoint &scale,
        const FPoint &trans) const
{
    auto *line = new Graph_lib::Open_polyline;
    for(const auto &elem : fdef)
    {
        line->add(elem * scale + trans);
    }
    return line;
}

std::vector<FPoint> Line::getPoints() const
{
    return fdef;
}

figure *Line::create(const vector<FPoint> &points)
{
    return new Line(points);
}

//Additional

float radius(const FPoint &mid, const FPoint &pt)
{
    return static_cast<float>(sqrt(pow(mid.x - pt.x, 2.0) + pow(mid.y - pt.y, 2.0)));
}

std::ostream &operator<<(std::ostream &os, const std::pair<FPoint, FPoint> p)
{
    os << p.first << ' ' << p.second;
    return os;
}

std::string getId(std::istream &is)
{
    std::string res;
    char br;
    while(is >> br)
    {
        if(isalpha(br))
            res.push_back(br);
        else
        {
            is.unget();
            break;
        }
    }
    if(res.empty() && !is.eof())
        throw std::runtime_error("There is no prefix");
    return res;
}

std::vector<FPoint> getPoints(std::istream &is)
{
    std::vector<FPoint> res;
    char br;
    is >> br;
    if(br != '(')
        throw std::runtime_error("Couldnt load points");
    FPoint pt;
    while(is >> pt)
    {
        res.push_back(pt);
        is >> br;
        if(br == ')')
            break;
        else if(br == '(')
            is.unget();
    }
    return res;
}

figure *getFigure(std::istream &is)
{
    std::string id = getId(is);
    if(id.length() == 0)
        return nullptr;

    std::vector<FPoint> pts = getPoints(is);

    figFactory::getFactory().registerFigure(Rect::classId(), Rect::create);
    figFactory::getFactory().registerFigure(Circ::classId(), Circ::create);
    figFactory::getFactory().registerFigure(Line::classId(), Line::create);

    return figFactory::getFactory().create(id, pts);
}

std::pair<FPoint, FPoint> mapBbox(
        const std::vector<figure *> &figures)
{
    std::pair<FPoint, FPoint> cur_bbox = (*figures[0]).bbox();
    for(const auto &elem : figures)
    {
        cur_bbox.first = min(cur_bbox.first, (*elem).bbox().first);
        cur_bbox.second = max(cur_bbox.second, (*elem).bbox().second);
    }
    return cur_bbox;
}

float bbox_height(const std::pair<FPoint, FPoint> &bbox)
{
    return bbox.second.y - bbox.first.y;
}

float bbox_width(const std::pair<FPoint, FPoint> &bbox)
{
    return bbox.second.x - bbox.first.x;
}

FPoint bbox_mid(const std::pair<FPoint, FPoint> &bbox)
{

    return {(bbox.second.x + bbox.first.x) / 2, (bbox.second.y + bbox.first.y) / 2};
}

std::pair<FPoint, FPoint> getTransformation(
        const std::pair<FPoint, FPoint> &objBbox,
        const std::pair<FPoint, FPoint> &dispBbox)
{
    FPoint scale;
    const float h_scale = bbox_height(dispBbox) / bbox_height(objBbox);
    const float w_scale = bbox_width(dispBbox) / bbox_width(objBbox);
    scale.x = (h_scale < w_scale) ? h_scale : w_scale;
    scale.y = -scale.x;
    const FPoint disp_mid = bbox_mid(dispBbox);
    const FPoint obj_mid = bbox_mid(objBbox * scale);
    return std::make_pair(scale, disp_mid - obj_mid);
}

std::string windowTitle()
{
    return "Animation box";
}

//figFactory

figFactory &figFactory::getFactory()
{
    static figFactory factory;
    return factory;
}

figure *figFactory::create(const string &id, const vector<FPoint> &fdef)
{
    const auto it = creatorsMap.find(id);
    if(it != creatorsMap.end())
        return it->second(fdef);
    throw std::runtime_error("Unknown fig id passed to factory");
}

void figFactory::registerFigure(const string &id, figFactory::createFig pCreate)
{
    creatorsMap.insert({id, pCreate});
}
