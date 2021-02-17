#include <iostream>
#include "score.hpp"


Score::Score(unsigned max_entries) {
    maxEntries = max_entries;
    numEntries = 0;
    entries = new GameEntry[maxEntries];
}

void Score::printElements() {
    for (int i = 0; i <= numEntries-1; i++)
        std::cout << entries[i].getName() << ": " << entries[i].getScore() <<  std::endl;
}

void Score::add(const GameEntry& e)  {
    int newScore = e.getScore();
    if (maxEntries == numEntries) {
        if (newScore == entries[maxEntries-1].getScore())
            return;
    }
    else
    {
        numEntries++;
    }

    int i = maxEntries-2;
    while(i >= 0 && newScore > entries[i].getScore()) {
        entries[i+1] = entries[i];
        i--;
    }
    entries[i+1] = e;
}

GameEntry Score::remove(unsigned i) throw(IndexOutOfRangeError) {
    if (i < 0 || i > maxEntries-1)
        throw IndexOutOfRangeError("Index Out of range");
    
    GameEntry e = entries[i];
    for (int j = i + 1; j < numEntries; j++)
        entries[j-1] = entries[j];
    numEntries--;
    return e;
}
