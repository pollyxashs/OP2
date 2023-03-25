
class Subset {

private:

    int set[10] = { 0 };

public:

    Subset() = default;
    Subset(const int arr[10]);

    Subset operator+(const Subset& other) const;

    bool operator==(const Subset& other) const;

    bool operator!=(const Subset& other) const;

    Subset& operator+=(int num);

    Subset& operator-=(int num);

    void print() const;
};
