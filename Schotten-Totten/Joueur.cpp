#include "Joueur.h"

void Joueur::PoserCarte(unsigned int positionCarte,TasDeCartes<Carte>& tas)
{
	if (pMain.GetSizeTas() == 0) {
		throw runtime_error("pas de carte dans la main");
	}	
	else{
		tas.Ajouter(move(pMain.Retirer(positionCarte)));
	}
}

void Joueur::Piocher(Pioche& pioche)
{
	if(pMain.GetSizeTas() < 7) 
		pMain.Ajouter(move(pioche.getOnTop()));
}
