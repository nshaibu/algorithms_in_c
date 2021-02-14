#include "score.hpp"


Score::Score(unsigned max_entries) {
    maxEntries = max_entries;
    numEntries = 0;
    entries = new GameEntry[maxEntries];
}

void Score::add(const GameEntry& e)  {

}

GameEntry& Score::remove(unsigned i) throw(IndexOutOfRangeError) {

}
