/*
 * Date.cpp
 *      Author: charlie
 */



#include <iostream>
#include <algorithm>
#include "Date.h"

using namespace std;


//les accesseurs pour récupérer la valeurs des attributs privés
int Date::getJour() const{
	return _jour;
}
int Date::getMois() const{
	return _mois;
}
int Date::getAnnee() const{
	return _annee;
}

//fonction pour vérifier si l'année est bissextile
bool bissextile(int a){
	return (a % 4 == 0 && !(a % 100 == 0)) || (a % 400 == 0);
}

//fonction pour calculer le nombre de jour dans un mois
int nombreJoursDansMois(int m, int a){
	int resultat = 0;
	switch(m){
		case 4: case 6: case 9: case 11:
			resultat = 30;
			break;
		case 2:
			resultat = (bissextile(a) ? 29 : 28);
			break;
		default:
			resultat = 31;
	}
	return resultat;
}

//methode de la classe Date pour vérifier si la date est valide
bool Date::dateValide(int j, int m, int a){
	return (a >=0) && (m >=1 && m<=12) && (j >=1 && j<= nombreJoursDansMois(m,a));
}

//methode de la classe Date pour afficher la date
void Date::afficheDate() const{
	cout << "La date (j/m/a) saisie est : " << this->getJour()<< "/" << this->getMois() << "/" << this->getAnnee() << endl;
}


/*nombre de jours ecoulés depuis le debut de l'annee donnee*/
int Nb_Jours (int J, int M, int A)
{
  int i, TotalJours = 0;
  const int Mois[12]= {31,28,31,30,31,30,31,31,30,31,30,31};

  if (M == 1)
  {
	 TotalJours = J;
  }
  else
  {
    for (i = 0; i < (M-1); i++)
    {
      TotalJours = TotalJours + Mois[i];
    }
    TotalJours = TotalJours + J;
  }
  if ((M = 2) && (bissextile(A)))
  {
	 TotalJours++;
  }
  return TotalJours;
}

/*la méthode qui calcule le nombre de jours entre deux dates*/
int Date::NombreJoursEcoules (Date date1, Date date2)
{
  int NJ = 0, NJ1, NJ2, i;

  NJ1 = Nb_Jours (date1.getJour(), date1.getMois(), date1.getAnnee());
  NJ2 = Nb_Jours (date2.getJour(), date2.getMois(), date2.getAnnee());
  if (date2.getAnnee() == date1.getAnnee())
  {
    NJ = NJ2 - NJ1;
  }
  else
  {
    for (i = 0; i < (date2.getAnnee() - date1.getAnnee()); i++)
    {
      NJ = NJ + 364;
      if (bissextile (date1.getAnnee() + i))
      {
        NJ++;
      }
    }
    NJ = NJ - NJ1;
    NJ = NJ + NJ2 + 1;
  }
  return NJ;
}

//fonction pour comparer deux objets Date
bool compare (const Date &d1, const Date &d2){
	    if (d1.getAnnee() < d2.getAnnee())
	        return true;
	    if (d1.getAnnee() == d2.getAnnee() && d1.getMois() < d2.getMois())
	        return true;
	    if (d1.getAnnee() == d2.getAnnee() && d1.getMois() == d2.getMois() && d1.getJour() < d2.getJour())
	        return true;

	    return false;
}

//methode pour afficher la date la plus récente
void Date::afficheDateRecente(std::vector<Date> dates){
	std::sort(dates.begin(),dates.end(),compare);
	cout << "La date la plus récente est : ";
	cout << dates[dates.size() - 1].getJour() << "/" << dates[dates.size() - 1].getMois() << "/" << dates[dates.size() - 1].getAnnee() << endl;
}


//methode pour retourner la date la plus récente
Date Date::retourneDateRecente(std::vector<Date> dates){
	std::sort(dates.begin(),dates.end(),compare);
	return dates[dates.size() - 1];
}


//constructeur par défaut
Date::Date(){
	//valeur par défaut d'un objet Date
	_jour = 02;
	_mois = 10;
	_annee = 1998;

}


//constructeur pour initialiser l'objet
Date::Date(int jour, int mois, int annee) {
	if(dateValide(jour,mois,annee))
	{
		_jour = jour;
		_mois = mois;
		_annee = annee;
	}
	else
	{
		cout << "Oups ! Erreur, la date que vous avez saisi n'est pas valide." << endl;
		//valeur par défaut d'un objet Date
		_jour = 02;
		_mois = 10;
		_annee = 1998;
	}

}

//constructeur pour détruire l'objet à la fin du programme
Date::~Date()
{}

