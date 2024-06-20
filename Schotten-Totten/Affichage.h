#ifndef AFFICHAGE_H
#define AFFICHAGE_H
#include "CarteClan.h"
#include "CarteTactique.h"
#include "Regles.h"
#include "Jeu.h"
#include "Joueur.h"
#include <cstdlib> // pour clear
// Définitions des séquences d'échappement ANSI pour différentes couleurs

#define RESET "\033[0m";
#define NOIRE "\033[30m";
#define ROUGE "\033[31m";
#define VERT "\033[32m";
#define JAUNE "\033[33m";
#define BLEU "\033[34m";
#define MAGENTA "\033[35m";
#define CYAN "\033[36m";
#define BLANC "\033[37m";
#define MARRON "\033[33m";
#define VIOLET "\033[35m";


// Gère complètement l'affichage console du projet
class Affichage
{
public:
	
	// On rend la classe statique
	Affichage() = delete;
	~Affichage() = delete;

	void static ChoixMode();

	void static demarrerJeu() { cout << "Distribution al\202atoire du paquet" << endl; }

	void static Toursjoueur(const shared_ptr<Joueur>& Joueur);

	void static carteClan(const unique_ptr<Carte>& CC){ cout << Couleurs(CC.get()->getCouleur()) << "[" << CC.get()->getValeur() << "]" << RESET;}

	void static carteTactique(const CarteTactique& CT){ cout << "[" << CT.getNom() << "]"; }

	void static board(Jeu& jeux);

	string static Couleurs(unsigned int CarteCouelurs);

	void static victoire(Jeu& jeu){ cout << "Victoire de : " + jeu.getGagnant().get()->getNom() + " !!!!!" << endl; }

	void static demanderBorne(){ cout << "Choisir la borne : ";}

	void static bornePleine(){ cout << "La borne est pleine, autre choix : "; }

	void static demanderCarte() {cout << "Poser la carte : ";};

	void static demanderPhaseRevendication(){cout << "Voulez-vous revendiquer une borne ? (1) Oui (2) Non:" ;}

	void static demanderBorneARevendiquer() {cout << "Revendiquer la borne : "; }

	void static demanderArretRevendication(){ cout << "Voulez-vous faire une autre revendication ? (1)Non (2)Oui :";}

	void static staticclearConsole() {
		#ifdef _WIN32
				std::system("cls");
		#elif defined(__linux__) || defined(__APPLE__)
				std::system("clear");
		#else
				// Si vous avez d'autres OS à gérer, ajoutez ici
		#endif
	}


};

#endif // AFFICHAGE_H



