/*
Matrix3X3 is a friend of Vector. Thus it's method 'multiply' is able 
to access the private member variable 'coord' of Vector.
Just debug to see outputs
*/

class Vector {
    public:
        Vector(){};
        Vector(double x, double y, double z);
    private:
        double coord[3];
        friend class Matrix3X3;
};


class Matrix3X3 {
    public:
        Matrix3X3(double a00, double a01, double  a02,
                double a10, double a11, double a12,
                double a20, double a21,  double a22);
        Vector multiply(const Vector &vec);
    private:
        double a[3][3];
};

Vector::Vector(double x, double y, double z) {
    coord[0] = x;
    coord[1] = y;
    coord[2] = z;
}

Matrix3X3::Matrix3X3(double a00, double a01, double  a02,
                double a10, double a11, double a12,
                double a20, double a21,  double a22) {
    a[0][0] = a00;
    a[0][1] = a01;
    a[0][2] = a02;

    a[1][0] = a10;
    a[1][1] = a11;
    a[1][2] = a12;

    a[2][0] = a20;
    a[2][1] = a21;
    a[2][2] = a22;
}

Vector Matrix3X3::multiply(const Vector &vec) {
    Vector v;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            v.coord[i] += a[i][j] * vec.coord[j];
    return v;
}


int main(int argc, char **argv) {
    Vector vec(1, 2, 3);
    Matrix3X3 mat(1, 3, 6, 2, 12, 8, 4, 5, 7);
    Vector v = mat.multiply(vec);
    return 0;
}
