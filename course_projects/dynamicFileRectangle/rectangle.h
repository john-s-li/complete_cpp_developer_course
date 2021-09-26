#ifndef RECTANGLE_H
#define RECTANGLE_H

class rectangle
{
    public:
        rectangle(int w, int h);
        int getArea() const;
        int getPerimeter() const;

    private:
        int width;
        int height;
}; // end class

#endif