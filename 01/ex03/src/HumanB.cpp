
#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB (std::string name)  : _name(name) {}

void HumanB::setWeapon(Weapon& weapon)
{
  _weapon = &weapon;
}

void HumanB::attack()
{
  if (_weapon)
    std::cout << _name << " attacks with " << _weapon->getType() << std::endl;
  else
    std::cout << _name << " has no weapon to attack with!" << std::endl;
}

