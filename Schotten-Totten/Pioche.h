#pragma once
#include "TasDeCartes.h"
class Pioche :public TasDeCartes<Carte>
{
private:
	//Capacite 
	// tas
public:
	 unique_ptr<Carte> getOnTop();
};

