#ifndef COMPLEXTYPE_COMPLEX_H
#define COMPLEXTYPE_COMPLEX_H

class figure {

private:

    double x;
    double y;
    double side;

public:

    figure(double x, double y, double side);

    double area() const;

    void scale(double scale);

    void move(double dx, double dy);

    void koord();

    bool operator==(const figure &other) const;

    bool operator!=(const figure &other) const;

    bool operator<(const figure &other) const;

    bool operator>(const figure &other) const;
};

#endif