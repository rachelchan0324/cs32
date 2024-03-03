#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "Level.h"
#include "Actor.h"

#include <list>
#include <string>

using namespace std;

class Actor;
class Agent;
class Player;

// Note:  A convention used in a number of interfaces is to represent a
// direction with the adjustments to x and y needed to move one step in
// that direction:
// left:   dx is -1, dy is  0
// right:  dx is  1, dy is  0
// up:     dx is  0, dy is  1
// down:   dx is  0, dy is -1

class StudentWorld : public GameWorld {
public:
    StudentWorld(std::string assetDir);
    virtual ~StudentWorld();
    
    virtual int init();
    virtual int move();
    virtual void cleanUp();
    
    bool canAgentMoveTo(Agent* agent, int x, int y, int dx, int dy) const;
    bool canMarbleMoveTo(int x, int y) const;
    bool isPlayerColocatedWith(int x, int y) const;
    
    bool damageSomething(Actor* a, int damageAmt);
    bool swallowSwallowable(Actor* a);
    
    bool existsClearShotToPlayer(int x, int y, int dx, int dy) const;
    bool doFactoryCensus(int x, int y, int distance, int& count) const;
    
    Actor* getColocatedStealable(int x, int y) const;
    
    void restorePlayerHealth() {m_player->restoreHealth();}
    
    void increaseAmmo() {m_player->increaseAmmo();}
    bool anyCrystals() const {return crystals > 0;}
    void decCrystals() {crystals--;}
    
    void setLevelFinished() {levelFinished = true;}
    void addActor(Actor* a);
    
private:
    list <Actor*> actors;
    Player* m_player;
    
    int bonus;
    int crystals;
    bool levelFinished;
};

#endif // STUDENTWORLD_H_
