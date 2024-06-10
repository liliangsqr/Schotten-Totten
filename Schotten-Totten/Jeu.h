#ifndef JEU_H
#define JEU_H

// Jeu est un Singleton, pour y acc�der : Jeu& jeuObj = Jeu::getInstance();
class Jeu
{
	// Partie publique, pour acc�der � l'instance unique
public :

	static Jeu& getInstance() {
		static Jeu instanceJeu;
		return instanceJeu;
	}

	// On "supprime" les m�thodes qui copient
	Jeu(const Jeu&) = delete;
	Jeu& operator=(const Jeu&) = delete;



	// Partie priv�e, on met le constructeur et le destructeur pour s'assurer qu'une seule instance existe
private :
	Jeu() {

	}

	~Jeu() {

	}
};


#endif