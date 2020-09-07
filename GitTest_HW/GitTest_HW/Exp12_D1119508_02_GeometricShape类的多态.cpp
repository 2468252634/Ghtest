/* 
 习题8.6，以几何图形类为基类派生出矩形类、圆类和圆柱类等，并完成各操作。
几何形体的派生关系如下：
几何图形(geometric_shape) <--- 矩形(rectangle) <--- 长方体(box)
几何图形(geometric_shape) <--- 圆(circle) <--- 圆柱(cylinder)
几何图形(geometric_shape) <--- 圆(circle) <--- 圆锥(cone)
几何图形(geometric_shape) <--- 三角形(triangle) <--- 三棱锥(t_pyramid)
几何图形(geometric_shape) <--- 三角形(triangle) <--- 三棱柱(t_prism)

编程计算平面形体的周长和面积，
编程计算立体图形的表面积和体积，
请编程，并测试。

注：
本题随着学习进度，还会要求扩展。
*/
#include<iostream>
#include<cmath>
using namespace std;
#define PI 3.14159 
class geometric
{
public:
    virtual double Perimetre() { return 0; }
    virtual double Area() { return 0; };
    virtual double Volume() { return 0; };
    virtual void Show() { return; }
};
class Circle : public geometric
{
private:
    double radius;
public:
    Circle(double r = 0) { this->radius = r; cout << "建立一个圆对象" << endl; }
    double Perimetre() { return 2 * PI * radius; }
    double Area() { return PI * radius * radius; }
    double getR() { return radius; }
    double Volume() { return 0; }
    void Show() { cout << "半径是" << radius <<'\t'<< "周长是" << Perimetre() <<'\t'<< "面积是" << Area() << endl; }
};
class Cylinder : public Circle
{
private:
    double height;
public:
    Cylinder(double r = 0, double h = 0) :Circle(r), height(h) { cout << "建立一个圆柱对象" << endl; }
    double Perimetre() { return 0; }
    double Area() { return 2 * Circle::Area() + 2 * PI * getR() * height; }
    double Volume() { return Circle::Area() * height; }
    double getR() { return Circle::getR(); }
    double getH() { return height; }
    void Show() { cout << "半径是" << getR() << '\t' <<"高是"<<height<<'\t'<< "表面积是" << Area() << '\t' << "体积是" << Volume() << endl; }

};
class Cone :public Circle
{
private:
    double height, length;
public:
    Cone(double r = 0, double h = 0) :Circle(r), height(h) { length = sqrt(r * r + h * h); cout << "建立一个圆锥对象" << endl;}
    double Perimetre() { return 0; }
    double Area() { return Circle::Area() + PI * getR() * length; }
    double Volume() { return 1 / 3.0 * Circle::Area() * height; }
    double getR() { return Circle::getR(); }
    double getH() { return height; }
    double getL() { return length; }
    void Show() { cout << "半径是" << getR() << '\t' << "高是" << height << '\t' << "母线是" << length << '\t' << "表面积是" << Area() << '\t' << "体积是" << Volume() << endl; }

};
class Rectangle :public geometric
{
private:
    double length, width;
public:
    Rectangle(double l = 0, double w = 0) :length(l), width(w) { cout << "建立一个矩形对象" << endl; };
    double Perimetre() { return 2 * (length + width); }
    double Area() { return length * width; }
    double Volume() { return 0; }
    double getLength() { return length; }
    double getWidth() { return width; }
    void Show() { cout << "长是" << length << '\t' << "宽是" << width << '\t' << "周长是" << Perimetre() << '\t' << "面积是" << Area() << endl; }
};
class Box:public Rectangle
{
private:
    double height;
public:
    Box(double l = 0, double w = 0, double h = 0) :Rectangle(l, w), height(h) { cout << "建立一个长方体对象" << endl; }
    double Perimetre() { return 0; }
    double Area() { return 2 * (getLength() * getWidth() + height * getLength() + height * getWidth()); }
    double Volume() { return Rectangle::Area() * height; }
    double getLength() { return Rectangle::getLength(); }
    double getWidth() { return Rectangle::getWidth(); }
    double getHeight() { return height; }
    void Show() { cout << "长是" << getLength() << '\t' << "宽是" << getWidth() << '\t' << "高是" << height << '\t' << "表面积是" << Area() << '\t' << "体积是" << Volume() << endl; }
};
class Triangle :public geometric
{
private:
    double first, second, third;
public:
    Triangle(double f=0, double s=0, double t=0) :first(f), second(s), third(t) { cout << "建立一个三角形对象" << endl;}
    double Perimetre() { return first + second + third; }
    double Area()
    {
        double p = (first + second + third) / 2;
        return sqrt(p * (p - first)*(p - second)*(p - third));
    }
    double Volume() { return 0; }
    double getF() { return first; }
    double getS() { return second; }
    double getT() { return third; }
    void Show() { cout << "三边长分别是" << first << '\t' << second << '\t' << third << '\t' << "周长是" << Perimetre()<<'\t' << "面积是" << Area() << endl; }
};
class t_pyrimid :public Triangle
{
private:
    double height, mu1, mu2, mu3;
public:
    t_pyrimid(double f = 0, double s = 0, double t = 0, double h = 0,double m1=0,double m2=0,double m3=0) :Triangle(f, s, t), height(h),mu1(m1),mu2(m2),mu3(m3) { cout << "建立一个三棱锥对象" << endl; }
    double Perimetre() { return 0; }
    double Area();
    double Volume() { return Triangle::Area() * height / 3; }
    void Show() { cout << "三棱锥的表面积是" << Area() << '\t' << "体积是" << Volume() << endl; }
};
class t_prism :public Triangle
{
private:
    double height;
public:
    t_prism(double f = 0, double s = 0, double t = 0, double h = 0) :Triangle(f, s, t), height(h) { cout << "建立一个三棱柱对象" << endl; }
    double Perimetre() { return 0; }
    double Area() { return 2*Triangle::Area() + (getF() + getS() + getT()) * height; }
    double Volume() { return Triangle::Area() * height; }
    double getH() { return height; }
    void Show() { cout << "三棱柱的表面积是" << Area() << '\t' << "体积是" << Volume() << endl; }
};
double t_pyrimid::Area()
{
    Triangle tr1(getF(), getS(), getT());
    Triangle tr2(mu1, mu2, getF());
    Triangle tr3(mu1, mu3, getT());
    Triangle tr4(mu2, mu3, getS());
    return tr1.Area() + tr2.Area() + tr3.Area() + tr4.Area();
}
int main()
{
    
    Circle c1(2);
    geometric* geo;
    geo = &c1;
    geo->Show();
//    c1.Show();

    Cylinder cy1(2, 3);
    geo = &cy1;
    geo->Show();
//    cy1.Show();

    Cone co1(2, 3);
    geo = &co1;
    geo->Show();
//    co1.Show();

    Rectangle Rect(3, 4);
    geo = &Rect;
    geo->Show();
//    Rect.Show();

    Box b1(2, 3, 4);
    geo = &b1;
    geo->Show();
//    b1.Show();

    Triangle tri(3, 4, 5);
    geo = &tri;
    geo->Show();
//   tri.Show();

    t_pyrimid py_1(3, 4, 5, 1, 2, 3,4);
    geo = &py_1;
    geo->Show();
//    py_1.Show();

    t_prism pris1(3, 4, 5, 2);
    geo = &pris1;
    geo->Show();
//    pris1.Show();

    return 0;
}