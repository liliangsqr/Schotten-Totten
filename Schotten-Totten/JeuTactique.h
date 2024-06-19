#ifndef JEUTACTIQUE
#define JEUTACTIQUE

#include "Joueur.h"
#include "TotalTactique.h"
#include "TasDeCartes.h"
#include "Jeu.h"
#include "Combinaison.h"
#include "Defausse.h"
#include "PiocheTactique.h"

// Variante tactique du jeu, g�re tout le fonctionnement interne des m�caniques de jeu et y donne acc�s pour l'utiliser dans Application
class JeuTactique : public Jeu
{

private:
	TotalTactique total;
	// vector<shared_ptr<Joueur>> totalJoueurs;
	// Frontiere frontiere;
	// Pioche pioche

	PiocheTactique piocheTactique;
	Defausse defausse;


	// Emp�che toute instatiation en dehors de la classe
	JeuTactique() : Jeu() { initialiser(); }

	// Methodes d'initialisation
	void creerJoueurs(unsigned int nbJoueurs);
	void distribuerCartes(unsigned int nbCartesMain);
	void initialiser();
	void finDePartie();


public: // Partie publique, sert � acc�der � l'instance unique
	static JeuTactique& getInstance() {
		static JeuTactique instance;
		return instance;
	}

	// On emp�che toute copie ou assignation
	JeuTactique(const JeuTactique&) = delete;
	JeuTactique& operator=(const JeuTactique&) = delete;

	


	// M�thodes

	const std::shared_ptr<Joueur> getGagnant() const { std::shared_ptr<Joueur> a; return a; }
	bool terminer() { return true; }
	bool borneEstRevendicableParJoueur(unsigned int index, const shared_ptr<Joueur> joueur) const;
	void revendiquerBorne(unsigned int index, const shared_ptr<Joueur>& joueur);
	void piocher(shared_ptr<Joueur>& joueur);
	void poserCarte(unsigned int indexBorne, unsigned int indexCarte, shared_ptr<Joueur>& joueur);
	void jouerTour(shared_ptr<Joueur>& joueur);

	const vector<shared_ptr<Joueur>>& getJoueurs() { return totalJoueurs; }
	virtual const Frontiere& getFrontiere() const { return frontiere; }
};

#endif