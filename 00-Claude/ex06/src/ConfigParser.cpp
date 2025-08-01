#include "ConfigParser.hpp"
#include "Setting.hpp"
#include <iostream>
#include <fstream>
#include <string>

ConfigParser::ConfigParser(std::string file)
{
    _file = file;
}


ConfigParser::ConfigParser(const ConfigParser& other)
    : _settings(other._settings), _file(other._file)
{
    // std::cout << "ConfigParser Copy constructor called" << std::endl;
}

ConfigParser& ConfigParser::operator=(const ConfigParser& other)
{

    // std::cout << "ConfigParser Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        _file = other._file;
        _settings = other._settings;
    }
    return *this;
}

ConfigParser::~ConfigParser()
{
    // std::cout << "ConfigParser Destructor called" << std::endl;
}

bool ConfigParser::load()
{
    std::ifstream file(_file.c_str());  // Ouvre le fichier

    if (!file.is_open())
    {
        std::cerr << "Error : impossible to open " << _file << "." << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line))
    {
        if (line.empty() || line[0] == '#')
            continue;

        size_t sep = line.find("=");
        if (sep != std::string::npos)
        {
            std::string key = line.substr(0, sep);
            std::string value = line.substr(sep + 1);
            Setting setting(key, value);
            _settings[key] = setting;
        }
    }
    file.close(); 
    return true;
}

std::string ConfigParser::getString(std::string key)
{
    if (_settings.find(key) == _settings.end())
        throw std::runtime_error("Key not found: " + key);
    return _settings[key].asString();
}

int ConfigParser::getInt(std::string key)
{
    if (_settings.find(key) == _settings.end())
        throw std::runtime_error("Key not found: " + key);
    return _settings[key].asInt();
}

bool ConfigParser::getBool(std::string key)
{
    if (_settings.find(key) == _settings.end())
        throw std::runtime_error("Key not found: " + key);
    return _settings[key].asBool();
}

double ConfigParser::getDouble(std::string key)
{
    if (_settings.find(key) == _settings.end())
        throw std::runtime_error("Key not found: " + key);
    return _settings[key].asDouble();
}
