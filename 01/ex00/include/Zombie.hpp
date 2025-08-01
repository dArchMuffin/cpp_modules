#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie 
{
  public :
    Zombie(std::string name);
    ~Zombie();
    void _announce(void) const;
  private :
    std::string _name;

};

#endif
