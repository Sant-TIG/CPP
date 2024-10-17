#ifndef WARLOCK_HPP

# define WARLOCK_HPP

# include <iostream>
# include <map>

# include "ASpell.hpp"
# include "ATarget.hpp"
# include "SpellBook.hpp"

class Warlock {
    private:
        std::string _name;
        std::string _title;
        SpellBook   _spells;

        Warlock( void );
        Warlock( const Warlock &other );
        Warlock & operator=( const Warlock &other );

    public:
        Warlock( const std::string &name, const std::string &title );
        ~Warlock( void);

        const std::string   &getName( void ) const;
        const std::string   &getTitle( void ) const;

        void    setTitle( const std::string &title );

        void    introduce( void ) const;
        void    learnSpell( ASpell *spell );
        void    forgetSpell( const std::string &name );
        void    launchSpell( const std::string &name, const ATarget &target );
};

#endif