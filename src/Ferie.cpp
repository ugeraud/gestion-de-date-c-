/*
 * Ferie.cpp
 *      Author: Ulrich Geraud
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "Ferie.h"
#include "Conversion.h"

using namespace std;


void Ferie::listeJoursFerie(int annee){
	int n,u,c,s,t,p,q,e,b,d,l,h,m,j;
	char resultat[256];
	std::string chaine = "";

	//calcul date pâques
	n = annee % 19;
	u = annee % 100;
	c = annee / 100;
	s = c / 4;
	t = c % 4;
	p = (c+8) / 25;
	q = (c-p+1) / 3;
	e = (19*n+c-s-q+15) % 30;
	b = u / 4;
	d = u % 4;
	l = (2*t+2*b-e-d+32) % 7;
	h = (n+11*e+22*l) / 451;
	m = (e+l-7*h+114) / 31;
	j = (e+l-7*h+114) % 31;

	cout << "\n\tListes des jours fériés en "<< annee << endl << endl << endl;

	//fete du nouvel an
	int nouvelAnJ = 1;
	int nouvelAnM = 1;
	//convertion du mois en lettre
	Conversion::convertirMoisEnLettre(nouvelAnM,resultat);
	//fabrication de la chaine jour mois annnee
	chaine = chaine + resultat;
	cout << "Nouvel An "<<" : " << nouvelAnJ << " " << chaine << " " << annee << endl << endl;
	//réinitialise la chaine
	chaine = " ";
	//vide le tableau contenant le mois
	strcpy(resultat,"");

	//fete du Vodoun
	int feteVodounJ = 10;
	int feteVodounM = 1;
	Conversion::convertirMoisEnLettre(feteVodounM,resultat);
	chaine = chaine + resultat;
	cout << "Fête de Vodoun "<<" : " << feteVodounJ << " " << chaine << " " << annee << endl << endl;
	chaine = " ";
	strcpy(resultat,"");

	//gestion et affichage de la pâques
	Conversion::convertirMoisEnLettre(m,resultat);
	chaine = chaine + resultat;
	cout << "Pâques "<<" : " << j+1 << " " << chaine << " " << annee << endl << endl;
	chaine = " ";
	strcpy(resultat,"");

	//fête de travail
	int feteTravailJ = 1;
	int feteTravailM = 5;
	Conversion::convertirMoisEnLettre(feteTravailM,resultat);
	chaine = chaine + resultat;
	cout << "Fête du travail "<<" : " << feteTravailJ << " " << chaine << " " << annee << endl << endl;
	chaine = " ";
	strcpy(resultat,"");

	//calcul de l'ascencion
	int ascensionJ = (j+1+39)%30==0 ? 30 : (j+1+39)%30 ;
	int ascensionM = (j+1+39)%30==0 || (j+1+39)%31!=0  ?  m+1 : m+2;
	Conversion::convertirMoisEnLettre(ascensionM,resultat);
	chaine = chaine + resultat;
	cout << "Ascension "<<" : " << ascensionJ << " " << chaine << " " << annee << endl << endl;
	chaine = " ";
	strcpy(resultat,"");

	//calcul de la pentecôte
	int pentecoteJ = (ascensionJ + 10)%31==0 ? 31 : (ascensionJ + 10)%31;
	int pentecoteM =  (ascensionJ+10)%30==0 || (ascensionJ+10)%31==0  ? ascensionM  : ascensionM + 1;
	Conversion::convertirMoisEnLettre(pentecoteM,resultat);
	chaine = chaine + resultat;
	cout << "Pentécôte "<<" : " << pentecoteJ << " " << chaine << " " << annee << endl << endl;
	chaine = " ";
	strcpy(resultat,"");

	//calcul assomption
	int assomptionj = 15;
	int assomptionM = 8;
	Conversion::convertirMoisEnLettre(assomptionM,resultat);
	chaine = chaine + resultat;
	cout << "Assomption "<<" : " << assomptionj << " " << chaine << " " << annee << endl << endl;
	chaine = " ";
	strcpy(resultat,"");

	//calcul toussaint
	int toussaintJ = 1;
	int toussaintM = 11;
	Conversion::convertirMoisEnLettre(toussaintM,resultat);
	chaine = chaine + resultat;
	cout << "Toussaint "<<"  : " << toussaintJ << " " << chaine << " " << annee << endl << endl;
	chaine = " ";
	strcpy(resultat,"");

	//fete de noël
	int noelJ = 25;
	int noelM = 12;
	//convertion du mois en lettre
	Conversion::convertirMoisEnLettre(noelM,resultat);
	//fabrication de la (chaîne jour mois annee)
	chaine = chaine + resultat;
	cout << "Noël "<<" : " << noelJ << " " << chaine << " " << annee << endl << endl;
	//réinitialisation de la chaine
	chaine = " ";
	//vide le tableau contenant le mois
	strcpy(resultat,"");
}

//constructeur par défaut
Ferie::Ferie()
{}

//destructeur d'objet de type Ferie
Ferie::~Ferie()
{}

