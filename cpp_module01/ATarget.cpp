#include "ATarget.hpp"

ATarget::ATarget( void ) : _type("") {

}

ATarget::ATarget( const std::string &type ) : _type(type) {
}

ATarget::ATarget( const ATarget &other ) {
    *this = other;
}

ATarget::~ATarget( void) {
}

ATarget &ATarget::operator=( const ATarget &other ) {
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

const std::string   &ATarget::getType( void ) const {
    return _type;
}

void    ATarget::getHitBySpell( const ASpell &spell ) const {
    std::cout << _type << " has been " << spell.getEffects() << "!" << std::endl;
}
