/*
 * Conversion.h
 *      Author: Ulrich Geraud
 */
#include "Date.h"
#ifndef CONVERSION_H_
#define CONVERSION_H_

class Conversion {
	public:
		static void convertirValeurEnLettre(unsigned int valeur,char * tableauChaineCaractere);
		static void convertirMoisEnLettre(unsigned int mois,char * tableauChaineCaractere);
};

#endif /* CONVERSION_H_ */
