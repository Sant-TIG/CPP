#include "SpellBook.hpp"

SpellBook::SpellBook( void ) : _spells() {

}

SpellBook::SpellBook( const SpellBook &other ) {
    *this = other;
}

SpellBook::~SpellBook( void) {
}


SpellBook &SpellBook::operator=( const SpellBook &other ) {
    if (this != &other) {
        _spells = other._spells;
    }
    return *this;
}


void    SpellBook::learnSpell( ASpell *spell ) {
    if (spell) {
        if (_spells.find(spell->getName()) == _spells.end()) {
                _spells[spell->getName()] = spell->clone();
        }
    }
}

void    SpellBook::forgetSpell( const std::string &name ) {
    if (_spells.find(name) != _spells.end()) {
        delete _spells[name];
        _spells.erase(_spells.find(name));
    }
}


ASpell    *SpellBook::createSpell( const std::string &name ) {
    ASpell  *tmp = NULL;
    if (_spells.find(name) != _spells.end()) {
        tmp = _spells[name];
    }
    return tmp;
}