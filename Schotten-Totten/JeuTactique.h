#ifndef JEUTACTIQUE
#define JEUTACTIQUE

#include "Joueur.h"
#include "TotalTactique.h"
#include "TasDeCartes.h"
#include "Jeu.h"
#include "Combinaison.h"

// Variante tactique du jeu, gère tout le fonctionnement interne des mécaniques de jeu et y donne accès pour l'utiliser dans Application
class JeuTactique : public Jeu
{

private:
	TotalTactique total;
	// vector<shared_ptr<Joueur>> totalJoueurs;
	// Frontiere frontiere;
	// Pioche pioche

	// PiocheTactique piocheTactique
	// Defausse defausse


	// Empêche toute instatiation en dehors de la classe
	JeuTactique() : Jeu() { initialiser(); }

	// Méthodes d'initialisation
	void creerJoueurs(unsigned int nbJoueurs) { }
	void distribuerCartes(unsigned int nbCartesMain) { }
	void initialiser() { }
	void finDePartie() { }


public: // Partie publique, sert à accéder à l'instance unique
	static JeuTactique& getInstance() {
		static JeuTactique instance;
		return instance;
	}

	// On empêche toute copie ou assignation
	JeuTactique(const JeuTactique&) = delete;
	JeuTactique& operator=(const JeuTactique&) = delete;

	


	// Méthodes

	const std::shared_ptr<Joueur> getGagnant() const { std::shared_ptr<Joueur> a; return a; }
	bool terminer() { return true; }
	bool borneEstRevendicableParJoueur(unsigned int index, const shared_ptr<Joueur> joueur) const { return true; }
	void revendiquerBorne(unsigned int index, const shared_ptr<Joueur>& joueur) { }
	void piocher(shared_ptr<Joueur>& joueur) { }
	void poserCarte(unsigned int indexBorne, unsigned int indexCarte, shared_ptr<Joueur>& joueur) { }
	void jouerTour(shared_ptr<Joueur>& joueur) { }

	const vector<shared_ptr<Joueur>>& getJoueurs() { return totalJoueurs; }
	virtual const Frontiere& getFrontiere() { return frontiere; }
};

#endif