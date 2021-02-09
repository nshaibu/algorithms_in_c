#include <string>

enum MealType {BIG, SMALL};

class Passenger {
    public:
        Passenger();
        Passenger(const std::string& nm, MealType mp, const std::string& ffn="NONE");
        Passenger(const Passenger& pass);

        bool isFrequentFlyer() const { return isFreqFlyer; };
        void makeFrequentFlyer(const std::string& newFreqFlyerNo);
    private:
        std::string name;
        MealType mealPref;
        bool isFreqFlyer; 
        std::string freqFlyerNo;
};

Passenger::Passenger() {
    name = "--NO NAME--";
    mealPref = BIG;
    isFreqFlyer = false;
    freqFlyerNo = "NONE";
}

Passenger::Passenger(const std::string& nm, MealType mp, const std::string& ffn) 
: name(nm), mealPref(mp), isFreqFlyer(ffn != "NONE")
{
    freqFlyerNo = ffn;
}

Passenger::Passenger(const Passenger& pass) {
    name = pass.name;
    mealPref = pass.mealPref;
    isFreqFlyer = pass.isFreqFlyer;
    freqFlyerNo = pass.freqFlyerNo;
}

void Passenger::makeFrequentFlyer(const std::string& newFreqFlyerNo) {
    isFreqFlyer = true;
    freqFlyerNo = newFreqFlyerNo;
}


class Vect {
    public:
        Vect(int n);
        Vect(const Vect &other);
        ~Vect();
        Vect& operator=(const Vect& other);
    private:
        int *data;
        int  size;
};

Vect::Vect(int n) {
    data = new int[n];
    size = n;
}

Vect::~Vect() {
    delete [] data;
}

Vect::Vect(const Vect &other) {
    size = other.size;
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = other.data[i];
}

Vect& Vect::operator=(const Vect& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size;  i++)
            data[i] = other.data[i];
    }
    return *this;
}


int main(void) {
    Passenger p1;
    Passenger p2("JS", BIG, "323232");
    Passenger p3("PJ", SMALL);
    Passenger p4(p3);
    Passenger p5 = p2;
    Passenger *pp1 = new Passenger;
    Passenger *pp2 = new Passenger("Jello", BIG);
    Passenger pa[20];

    Vect a(10);
    Vect b(a);
    Vect c = b;

    delete pp1;
    delete pp2;
    return 0;
}