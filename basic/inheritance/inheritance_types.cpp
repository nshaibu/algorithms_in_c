#include<iostream>
#include<string>
using namespace std;

class Base {
    public:
        Base(int user_id, const string& nm):id(user_id), name(nm) {}
        string getName() const { return name; }
        int getID() const { return id; }
    protected:
        string name;
    private:
        int id;
};


class DerivedPublicBase: public Base {
    public:
        DerivedPublicBase(int id, const string& name, const string& mj, const string& room)
        :Base(id, name), major(mj), classRoom(room){}
        string getClassRoom() const { return classRoom; }
        string getMajor() const { return major; }
    private:
        string classRoom;
        string major;
};


class DerivedProtectedBase: protected Base {
    public:
    private:
};


class DerivedPrivateBase: private Base {
    public:
    private:
};


int main(void) {
    cout << "Public derived base: " << endl;
    DerivedPublicBase pb(1, "nafiu", "CS", "TL34");
    return 0;
}
