#include "Application.h"

void Application::jouerTour(Jeu& jeu, shared_ptr<Joueur>& joueur)
{
	jeu.jouerTour(joueur);
}


void Application::demarrerJeu(Jeu& jeu)
{
	// Affichage::demarrerJeu() (tu peux dire : distribution aléatoire du paquet, tout ça tout ça)


	// L'initialisation du jeu a déjà eu lieu lors de l'appel à l'instance dans Application

	// TODO : choisir qui joue en premier
}

void Application::jouerPartie(Jeu& jeu)
{
	// Tant que le jeu n'est pas fini
	while (!jeu.terminer()) {

		// On fait jouer chaque joueur dans l'ordre
		for (auto& joueur : jeu.getJoueurs()) {
			// Cette assignation permet de modifier l'objet pointé par joueur mais pas le pointeur en lui-même
			shared_ptr<Joueur> J = joueur;
			jouerTour(jeu, J);
		}
	}

	// Une fois le jeu fini on annonce le gagnant

	
	// Affichage::victoire(jeu.getGagnant());
	cout << jeu.getGagnant().get()->getNom() << endl;
}

void Application::terminerJeu(Jeu& jeu)
{
	// Affichage::terminerJeu(jeu.getGagnant());
}




// Méthode principale, appelle les méthodes de déroulement en fonction du mode de jeu
void Application::lancerApplication()
{
	unsigned int mode = Interaction::demanderModeJeu();
	switch (mode) {
		// Mode classique
		case 1: {
			JeuClassique& jeu = JeuClassique::getInstance();
			demarrerJeu(jeu);
			jouerPartie(jeu);
			terminerJeu(jeu);
			break;
		}

		// Mode tactique
		case 2: {
			JeuTactique& jeu = JeuTactique::getInstance();
			demarrerJeu(jeu);
			jouerPartie(jeu);
			terminerJeu(jeu);
			break;
		}

		default: {
			throw runtime_error("Choix de mode de jeu invalide, vérifier Interaction::demanderModeJeu()");
			break;
		}
	}
}