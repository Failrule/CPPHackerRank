#include <iostream>
using namespace std;

/*
 * Create classes Rectangle and RectangleArea
 */
class Rectangle
{
    public:
    int m_int_ancho;
    int m_int_alto;
    int m_int_area;

    void display()
    {
        cout << m_int_ancho << " " <<m_int_alto << endl;
    }

};

/* 
 * Clase RectangleArea que hereda de Rectangle
 */
class RectangleArea:public Rectangle
{
    public:

    void read_input()
    {
        cin >> m_int_ancho >> m_int_alto;
    }
    void display()
    {
        m_int_area = m_int_ancho * m_int_alto;
        cout << m_int_area << endl;
    }

};

int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;
    
    /*
     * Read the width and height
     */
    r_area.read_input();
    
    /*
     * Print the width and height
     */
    r_area.Rectangle::display();
    
    /*
     * Print the area
     */
    r_area.display();
    
    return 0;
}


