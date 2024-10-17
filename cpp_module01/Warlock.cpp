#include "Warlock.hpp"

Warlock::Warlock( void ) : _name(""), _title("") {

}

Warlock::Warlock( const std::string &name, const std::string &title ) : _name(name), _title(title) {
    std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock( const Warlock &other ) {
    *this = other;
}

Warlock::~Warlock( void) {
    std::cout << _name << ": My job here is done!" << std::endl;
}


Warlock &Warlock::operator=( const Warlock &other ) {
    if (this != &other) {
        _name = other._name;
        _title = other._title;
    }
    return *this;
}

const std::string   &Warlock::getName( void ) const {
    return _name;
}

const std::string   &Warlock::getTitle( void ) const {
    return _title;
}

void    Warlock::setTitle( const std::string &title ) {
    _title = title;
}

void    Warlock::introduce( void ) const {
    std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void    Warlock::learnSpell( ASpell *spell ) {
    if (spell) {
        if (_spells.find(spell->getName()) == _spells.end()) {
                _spells[spell->getName()] = spell->clone();
        }
    }
}

void    Warlock::forgetSpell( const std::string &name ) {
    if (_spells.find(name) != _spells.end()) {
        delete _spells[name];
        _spells.erase(_spells.find(name));
    }
}

void    Warlock::launchSpell( const std::string &name, const ATarget &target ) {
    if (_spells.find(name) != _spells.end()) {
        _spells[name]->launch(target);
    }
}

