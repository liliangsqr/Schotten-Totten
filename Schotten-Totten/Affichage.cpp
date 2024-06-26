#include "Affichage.h"

void Affichage::ChoixMode()
{
	for (unsigned int numero = 1; numero< Regles::getInstance().getModesJeu().size(); numero++)
	{
		for (string mode : Regles::getInstance().getModesJeu())
		{
			cout << numero << ". " << mode <<endl;
			numero++;
		}
	}
	cout << endl << " Veuillez choisir un mode de jeu :";
}

void Affichage::Toursjoueur(const shared_ptr<Joueur>& Joueur)
{
	//afficher le plateau 
	// board();
	cout << "Tour de " << Joueur.get()->getNom() << endl;
	for (const auto& carte: Joueur.get()->getMain().getCartes()) {
		Affichage::carteClan(carte);
	}
	cout << endl;
	
	
}

void Affichage::board(Jeu& jeux)
{
	Affichage::staticclearConsole();
	cout << "+--------------------PLATEAU--------------------+" << endl;

	// Boucle sur le nombre de bornes
	for (unsigned int i = 0; i < Regles::getInstance().getNbBornes(); i++)
	{
		unsigned int position =1; // servant a faire l'affichage en ligne
		for (const auto& joueur : jeux.getJoueurs())
		{
			if (position == 1)
			{
				if (jeux.getFrontiere().getBorne(i).getProprietaire() == joueur) {
					cout << "|Borne " << i + 1 << "|";
				}
				cout <<"	"<< joueur.get()->getNom() << " ->";
				for (const auto& carte : jeux.getFrontiere().getBorne(i).getTasBorne(joueur).getCartes())
				{
					Affichage::carteClan(carte);

				}
				if (jeux.getFrontiere().getBorne(i).getProprietaire() == joueur) {
					cout <<"|";
				}
				if (jeux.getFrontiere().getBorne(i).getProprietaire() == nullptr) {
					cout << "|Borne " << i + 1 << "|";
				}
			}
			if (position == 2) {

				for (const auto& carte : jeux.getFrontiere().getBorne(i).getTasBorne(joueur).getCartes())
				{
					Affichage::carteClan(carte);
				}

				if (jeux.getFrontiere().getBorne(i).getProprietaire() == joueur) {
					cout << "|Borne " << i + 1 << "|" << endl;
				}
				else {
					cout << "<- " << joueur.get()->getNom() << endl;

				}

			}
			position++;
		}	

	}
	cout << "+--------------------PLATEAU--------------------+" << endl;

}


string Affichage::Couleurs(unsigned int carteCouleurs)
{

	switch (carteCouleurs+1) //!\\ Les cartes ont une couleur en unsigned int. la classe Ennum.h nous permet de savoir quel ui correspond a quelle couleur;
	{
	case 0: return ""; break; //carte tactique en blanc
	case 1:return VERT; break;
	case 2:return BLEU; break;
	case 3:return ROUGE; break;
	case 4:return JAUNE; break;
	case 5:return MARRON; break;
	case 6:return VIOLET; break;

	default:
		return string("");
		break;
	}
}
