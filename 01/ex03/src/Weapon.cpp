
#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : _type(type) {}

const std::string& Weapon::getType() const
{
  return this->_type;
}

void Weapon::setType(std::string type)
{
  this->_type = type;
}
