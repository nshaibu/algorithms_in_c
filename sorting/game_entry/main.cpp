#include <iostream>
#include "game_entry.hpp"
#include "score.hpp"
#include "../../exceptions/index_out_of_range.hpp"



int main(void) {
    GameEntry e1("nafiu", 3434);
    GameEntry e2("shaibu", 434);
    GameEntry e3("nshaibu", 432);

    Score s(3);
    s.add(e1);
    s.add(e2);
    s.add(e3);

    s.printElements();

    std::cout << "\nRemove middle entry: "  << std::endl;
    GameEntry e = s.remove(1);
    std::cout << "Removed entry: " << e.getName() << "->" << e.getScore() << std::endl;
    s.printElements();

    std::cout << "\nHandling Exceptions" << std::endl;
    try {
        s.remove(20);
    } catch(IndexOutOfRangeError &exc) {
        std::cout << "Captured the exceptin: " << exc.getMessage() << std::endl;
    }

    return 0;
}