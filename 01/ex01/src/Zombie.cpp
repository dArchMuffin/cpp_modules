#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {}

Zombie::~Zombie()
{
  std::cout << this->_name << ": destroyed" << std::endl;
}

void Zombie::setName(std::string name)
{
  this->_name = name;
}

void Zombie::announce(void) const
{
  std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
