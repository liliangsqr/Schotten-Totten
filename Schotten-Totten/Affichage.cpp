#include "Affichage.h"

void Affichage::carteClan(const CarteClan& CC)
{	
	cout << Couleurs(CC.getCouleur()) << "[" << CC.getValeur() << "]";
}

string Affichage::Couleurs(unsigned int carteCouleurs)
{

	switch (carteCouleurs) //!\\ Les cartes ont une couleur en unsigned int. la classe Ennum.h nous permet de savoir quel ui correspond a quelle couleur;
	{
	case 0: return NOIRE; break;
	case 1:return VERT; break;
	case 2:return BLEU; break;
	case 3:return ROUGE; break;
	case 4:return JAUNE; break;
	case 5:return MARRON; break;
	case 6:return VIOLET; break;

	default:
		break;
	}
}
