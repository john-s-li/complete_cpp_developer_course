#ifndef CIRCLE_H
#define CIRCLE_H

class circle
{
    public:
        circle(int r);
        double getCircumference() const;
        double getArea() const;

    private:
        int radius;
        const double PI;
        
}; // end class

#endif