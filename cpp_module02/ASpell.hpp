#ifndef ASPELL_HPP

# define ASPELL_HPP

# include <iostream>

# include "ATarget.hpp"

class ATarget;

class ASpell {
    protected:
        std::string _name;
        std::string _effects;

    public:
        ASpell( void );
        ASpell( const std::string &name, const std::string &effects );
        ASpell( const ASpell &other );
        virtual ~ASpell( void);

        ASpell & operator=( const ASpell &other );

        const std::string   &getName( void ) const;
        const std::string   &getEffects( void ) const;

        virtual ASpell  *clone( void ) const = 0;

        void    launch( const ATarget &target ) const;
};

#endif