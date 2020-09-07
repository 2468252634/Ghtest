/* 
 ϰ��8.6���Լ���ͼ����Ϊ���������������ࡢԲ���Բ����ȣ�����ɸ�������
���������������ϵ���£�
����ͼ��(geometric_shape) <--- ����(rectangle) <--- ������(box)
����ͼ��(geometric_shape) <--- Բ(circle) <--- Բ��(cylinder)
����ͼ��(geometric_shape) <--- Բ(circle) <--- Բ׶(cone)
����ͼ��(geometric_shape) <--- ������(triangle) <--- ����׶(t_pyramid)
����ͼ��(geometric_shape) <--- ������(triangle) <--- ������(t_prism)

��̼���ƽ��������ܳ��������
��̼�������ͼ�εı�����������
���̣������ԡ�

ע��
��������ѧϰ���ȣ�����Ҫ����չ��
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
    Circle(double r = 0) { this->radius = r; cout << "����һ��Բ����" << endl; }
    double Perimetre() { return 2 * PI * radius; }
    double Area() { return PI * radius * radius; }
    double getR() { return radius; }
    double Volume() { return 0; }
    void Show() { cout << "�뾶��" << radius <<'\t'<< "�ܳ���" << Perimetre() <<'\t'<< "�����" << Area() << endl; }
};
class Cylinder : public Circle
{
private:
    double height;
public:
    Cylinder(double r = 0, double h = 0) :Circle(r), height(h) { cout << "����һ��Բ������" << endl; }
    double Perimetre() { return 0; }
    double Area() { return 2 * Circle::Area() + 2 * PI * getR() * height; }
    double Volume() { return Circle::Area() * height; }
    double getR() { return Circle::getR(); }
    double getH() { return height; }
    void Show() { cout << "�뾶��" << getR() << '\t' <<"����"<<height<<'\t'<< "�������" << Area() << '\t' << "�����" << Volume() << endl; }

};
class Cone :public Circle
{
private:
    double height, length;
public:
    Cone(double r = 0, double h = 0) :Circle(r), height(h) { length = sqrt(r * r + h * h); cout << "����һ��Բ׶����" << endl;}
    double Perimetre() { return 0; }
    double Area() { return Circle::Area() + PI * getR() * length; }
    double Volume() { return 1 / 3.0 * Circle::Area() * height; }
    double getR() { return Circle::getR(); }
    double getH() { return height; }
    double getL() { return length; }
    void Show() { cout << "�뾶��" << getR() << '\t' << "����" << height << '\t' << "ĸ����" << length << '\t' << "�������" << Area() << '\t' << "�����" << Volume() << endl; }

};
class Rectangle :public geometric
{
private:
    double length, width;
public:
    Rectangle(double l = 0, double w = 0) :length(l), width(w) { cout << "����һ�����ζ���" << endl; };
    double Perimetre() { return 2 * (length + width); }
    double Area() { return length * width; }
    double Volume() { return 0; }
    double getLength() { return length; }
    double getWidth() { return width; }
    void Show() { cout << "����" << length << '\t' << "����" << width << '\t' << "�ܳ���" << Perimetre() << '\t' << "�����" << Area() << endl; }
};
class Box:public Rectangle
{
private:
    double height;
public:
    Box(double l = 0, double w = 0, double h = 0) :Rectangle(l, w), height(h) { cout << "����һ�����������" << endl; }
    double Perimetre() { return 0; }
    double Area() { return 2 * (getLength() * getWidth() + height * getLength() + height * getWidth()); }
    double Volume() { return Rectangle::Area() * height; }
    double getLength() { return Rectangle::getLength(); }
    double getWidth() { return Rectangle::getWidth(); }
    double getHeight() { return height; }
    void Show() { cout << "����" << getLength() << '\t' << "����" << getWidth() << '\t' << "����" << height << '\t' << "�������" << Area() << '\t' << "�����" << Volume() << endl; }
};
class Triangle :public geometric
{
private:
    double first, second, third;
public:
    Triangle(double f=0, double s=0, double t=0) :first(f), second(s), third(t) { cout << "����һ�������ζ���" << endl;}
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
    void Show() { cout << "���߳��ֱ���" << first << '\t' << second << '\t' << third << '\t' << "�ܳ���" << Perimetre()<<'\t' << "�����" << Area() << endl; }
};
class t_pyrimid :public Triangle
{
private:
    double height, mu1, mu2, mu3;
public:
    t_pyrimid(double f = 0, double s = 0, double t = 0, double h = 0,double m1=0,double m2=0,double m3=0) :Triangle(f, s, t), height(h),mu1(m1),mu2(m2),mu3(m3) { cout << "����һ������׶����" << endl; }
    double Perimetre() { return 0; }
    double Area();
    double Volume() { return Triangle::Area() * height / 3; }
    void Show() { cout << "����׶�ı������" << Area() << '\t' << "�����" << Volume() << endl; }
};
class t_prism :public Triangle
{
private:
    double height;
public:
    t_prism(double f = 0, double s = 0, double t = 0, double h = 0) :Triangle(f, s, t), height(h) { cout << "����һ������������" << endl; }
    double Perimetre() { return 0; }
    double Area() { return 2*Triangle::Area() + (getF() + getS() + getT()) * height; }
    double Volume() { return Triangle::Area() * height; }
    double getH() { return height; }
    void Show() { cout << "�������ı������" << Area() << '\t' << "�����" << Volume() << endl; }
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