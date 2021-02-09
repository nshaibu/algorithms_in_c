#include <string>
#include <iostream>
using namespace std;


int main(int argc, char **argv) {
    string str = "Hello world";
    cout << "The string: " << str << endl;
    cout << "size: " << str.size() << endl;
    cout << "find: " << str.find("world") << endl;
    cout << "indexing with 'at': " << str.at(3) << endl;
    cout << "Indexing with []: " << str[6] << endl;
    str.replace(6, 5,  "nshaibu");
    cout << "Replaced world: "  << str << endl;
    str.erase(6, 7);
    cout << "Removed 'nshaibu': " << str << endl;
    str.insert(5, " world");
    cout << "Inserted 'world': " << str << endl;
    return 0;
}
