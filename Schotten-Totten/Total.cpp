#include "Total.h"

Total::Total()
{
	for (auto& itVal : ENUMVAL) {
		for (auto& itCoul : ENUMCOUL) {
			tas.push_back(make_unique<Carte(itVal, itCoul)>);
		}
	}
}