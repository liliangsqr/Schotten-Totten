#include "Application.h"

void Application::jouerTour(Jeu& jeu, shared_ptr<Joueur>& joueur)
{
	Affichage::board(jeu);
	Affichage::Toursjoueur(joueur); //ajout
	jeu.jouerTour(joueur);
}


void Application::demarrerJeu(Jeu& jeu)
{
	// L'initialisation du jeu a d�j� eu lieu lors de l'appel � l'instance dans Application
	Affichage::demarrerJeu();
	

	// TODO : choisir qui joue en premier
}

void Application::jouerPartie(Jeu& jeu)
{
	// Tant que le jeu n'est pas fini
	while (!jeu.terminer()) {

		// On fait jouer chaque joueur dans l'ordre
		for (auto& joueur : jeu.getJoueurs()) {

			// On rev�rifie pour que la victoire soit effective d�s la fin du tour du joueur gagnant
			if (!jeu.terminer()) {
				// Cette assignation permet de modifier l'objet point� par joueur mais pas le pointeur en lui-m�me
				// On pourrait aussi juste faire joueur.get() et faire que jouerTour prenne un Joueur en param
				shared_ptr<Joueur> J = joueur;
				jouerTour(jeu, J);
				//afficher Board(jeu)
			}
		}
	}

	// Une fois le jeu fini on annonce le gagnant
	Affichage::victoire(jeu); //ajout
}

void Application::terminerJeu(Jeu& jeu)
{
	// Affichage::terminerJeu(jeu.getGagnant());
}




// M�thode principale, appelle les m�thodes de d�roulement en fonction du mode de jeu
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

		case 3: {
			JeuClassiqueExperts& jeu = JeuClassiqueExperts::getInstance();
			demarrerJeu(jeu);
			jouerPartie(jeu);
			terminerJeu(jeu);
			break;
		}

		default: {
			throw runtime_error("Choix de mode de jeu invalide, v�rifier Interaction::demanderModeJeu()");
			break;
		}
	}
}