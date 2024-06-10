#include "JeuClassique.h"

void JeuClassique::Initialiser( )// initialisation des cartes création des joueurs.
{
	unique_ptr<Joueur> joueur1 = make_unique<Joueur>("lilian");
	unique_ptr<Joueur> joueur2 = make_unique<Joueur>("Alex");
}
