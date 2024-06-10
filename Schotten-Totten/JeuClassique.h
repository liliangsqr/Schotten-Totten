#pragma once
#include "Joueur.h"
#include "Combinaison.h"include
#include "TotalClassique.h"
#include "TasDeCartes.h"

class JeuClassique : public Jeu
{
private:
	TasDeCartes<CarteClan> totalCarteClassique;
	vector<Joueur> totalJoueurs;
	//Frontiere bornes;
public:
	
	void Initialiser();
	bool Terminer();
	void JouerTours(const Joueur& joueur);
	//Combinaison EvaluerCombinaisonJoueur();

	TasDeCartes<CarteClan> getTotalCarteClassique() { return totalCarteClassique; }

};