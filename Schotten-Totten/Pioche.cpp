#include "Pioche.h"

unique_ptr<Carte> Pioche::getOnTop()
{
	if (tas.empty()) throw runtime_error("la pioche est vide");
	
	unique_ptr<Carte> HautPioche = move(tas.back());
	tas.pop_back();
	return HautPioche;
}
