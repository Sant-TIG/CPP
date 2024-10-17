#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator( void ) : _targets() {

}

TargetGenerator::TargetGenerator( const TargetGenerator &other ) {
    *this = other;
}

TargetGenerator::~TargetGenerator( void) {
}


TargetGenerator &TargetGenerator::operator=( const TargetGenerator &other ) {
    if (this != &other) {
        _targets = other._targets;
    }
    return *this;
}


void    TargetGenerator::learnTargetType( ATarget *target ) {
    if (target) {
        if (_targets.find(target->getType()) == _targets.end()) {
                _targets[target->getType()] = target->clone();
        }
    }
}

void    TargetGenerator::forgetTargetType( const std::string &type ) {
    if (_targets.find(type) != _targets.end()) {
        delete _targets[type];
        _targets.erase(_targets.find(type));
    }
}


ATarget    *TargetGenerator::createTarget( const std::string &type ) {
    ATarget  *tmp = NULL;
    if (_targets.find(type) != _targets.end()) {
        tmp = _targets[type];
    }
    return tmp;
}