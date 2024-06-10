#pragma once
#include "Joueur.h"
#include "Combinaison.h"
class JeuClassique : public Jeu
{
private:
	//TasCarte<Carte> totalCarte;
	//vector<Borne> bornes;
public:
	void Initialiser();
	bool Terminer();
	void JouerTours(const Joueur& joueur);
	Combinaison DuelRevendication();

};