#ifndef GAME_ENTRY_H
#define GAME_ENTRY_H
#include <string>

class GameEntry {
    public:
        GameEntry(const std::string& n, unsigned int s);
        std::string getName() const { return name; }
        int getScore() const { return score; }
    private:
        std::string name;
        unsigned int score;
}

#endif