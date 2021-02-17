#ifndef SCORE_H
#define SCORE_H

#include "game_entry.hpp"
#include "../../exceptions/index_out_of_range.hpp"

class Score {
    public:
        Score(unsigned max_entries);
        ~Score() { delete [] entries; }
        unsigned getMaxNumEntries() const { return maxEntries; }
        unsigned getNumEntries() const { return numEntries; }
        void add(const GameEntry& e);
        GameEntry remove(unsigned i) throw(IndexOutOfRangeError);
        void printElements();
    private:
        unsigned int maxEntries;
        unsigned int numEntries;
        GameEntry *entries;
};

#endif
