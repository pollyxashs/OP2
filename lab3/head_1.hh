#ifndef OP_3_HEAD_1_HH
#define OP_3_HEAD_1_HH

class Square {

private:

    double x_;
    double y_;
    double side_;

public:

    Square(double x, double y, double side);

    double area() const;

    void scale(double scale);

    void move(double dx, double dy);

    void kordi();

    bool operator==(const Square &other) const;

    bool operator!=(const Square &other) const;

    bool operator<(const Square &other) const;

    bool operator>(const Square &other) const;
};

#endif
