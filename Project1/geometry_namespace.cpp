// Класс Square
Square::Square(double s) {
    if (s < 0) throw std::invalid_argument("Сторона не может быть отрицательной");
    side = s;
}

double Square::area() const {
    return side * side;
}

double Square::perimeter() const {
    return 4 * side;
}


// Класс Circle
Circle::Circle(double r) {
    if (r < 0) throw std::invalid_argument("Радиус не может быть отрицательным");
    radius = r;
}

double Circle::area() const {
    return M_PI * radius * radius;
}

double Circle::perimeter() const {
    return 2 * M_PI * radius;
}


// Класс Triangle
Triangle::Triangle(double side1, double side2, double side3) {
    if (side1 <= 0 || side2 <= 0 || side3 <= 0)
        throw std::invalid_argument("Стороны должны быть положительными");
    a = side1;
    b = side2;
    c = side3;
}

double Triangle::area() const {
    double s = (a + b + c) / 2;
    return std::sqrt(s * (s - a) * (s - b) * (s - c));
}

double Triangle::perimeter() const {
    return a + b + c;
}


// Новый класс Sphere для вычисления объёма шара
Sphere::Sphere(double r) {
    if (r < 0) throw std::invalid_argument("Радиус не может быть отрицательным");
    radius = r;
}

double Sphere::volume() const {
    // Формула объёма шара: 4/3 * π * r^3
    return (4.0 / 3.0) * M_PI * std::pow(radius, 3);
}


// Функция, возвращающая список доступных фигур
std::vector<std::string> listShapes() {
    return { "Square", "Circle", "Triangle", "Sphere" };
}