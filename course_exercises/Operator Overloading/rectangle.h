#ifndef RECTANGLE_H
#define RECTANGLE_H

class rectangle
{
    public:
        rectangle();
        rectangle(int w, int h);
        int getArea() const;
        int getPerimeter() const;
        int getWidth() const;
        int getHeight() const;
        bool operator==(const rectangle& other) const;
        bool operator!=(const rectangle& other) const;
        rectangle operator+(const rectangle& other) const;
        void operator=(const rectangle& other);
    private:
        int width;
        int height;
}; // end class

#endif