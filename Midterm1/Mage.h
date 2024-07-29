#ifndef Mage_h
#define Mage_h

/* Mage */

class Mage : public Entity{
  public :
    Mage( std::string name = "", int attackpower = 0 ):
      Entity( "Rogue", name, attackpower, 0, 0, 100) {
      };
    virtual int attack( Entity * other=0 ) {
      return magicAttack(other);
        //return defaultAttack(other);
    };
};

#endif
