#pragma once
#include "Joueur.h"
#include "Combinaison.h"
#include "TotalClassique.h"
#include "TasDeCartes.h"
#include "Jeu.h"

class JeuClassique : public Jeu
{
private:
	TotalClassique total;
	vector<unique_ptr<Joueur>> totalJoueurs;
	//Frontiere bornes;
public:
	
	void Initialiser();
	bool Terminer();
	void JouerTours(const Joueur& joueur);
	//Combinaison EvaluerCombinaisonJoueur();

	TasDeCartes<CarteClan> getTotalCarteClassique() { return totalCarteClassique; }

};