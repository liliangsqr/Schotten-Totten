#ifndef JEU_EXPERTS_H
#define JEU_EXPERTS_H

#include "JeuClassique.h"

class JeuClassiqueExperts : public JeuClassique
{
public:
    static JeuClassiqueExperts& getInstance()
    {
        static JeuClassiqueExperts instance;
        return instance;
    }

    void jouerTour(shared_ptr<Joueur>& joueur);

protected:
    JeuClassiqueExperts() = default;
    JeuClassiqueExperts(const JeuClassiqueExperts&) = delete;
    JeuClassiqueExperts& operator=(const JeuClassiqueExperts&) = delete;
};

#endif // JEU_EXPERTS_H
