#ifndef SPELLBOOK_HPP

# define SPELLBOOK_HPP

# include <iostream>
# include <map>

# include "ASpell.hpp"
# include "ATarget.hpp"

class SpellBook {
    private:
        std::map<std::string, ASpell *> _spells;

        SpellBook( const SpellBook &other );
        SpellBook & operator=( const SpellBook &other );

    public:
        SpellBook( void );
        ~SpellBook( void);

        void    learnSpell( ASpell *spell );
        void    forgetSpell( const std::string &name );
        ASpell  *createSpell( const std::string &name );
};

#endif