#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "Conversion.h"
#include "Date.h"
#include "Ferie.h"

using namespace std;

int main(){

	int choixUtilisateur;
	int nombreDeJoursEcoules;
	int jour,mois,annee,liste,i;
	bool continuer = true;
	char reponse;
	std::string chaine = " ";
	std::vector<Date> listeDate;
	char tableauTemporaire[256];
	Date d;
	cout << "======================================== Menu ===================================" << endl << endl;

	cout << "\t1- Créé une date du jour et l'affiché" << endl;
	cout << "\t2- Listes des jours fériés d'une année N" << endl;
	cout << "\t3- Affiche la date récente parmi une série de date en chiffre et en lettre" << endl;
	cout << "\t4- Nombre de jours séparant deux dates" << endl;
	cout << "\t5- Afficher une date en lettre" << endl << endl;

	while(continuer)
	{
		cout << "Quelle est votre choix : ";
		cin >> choixUtilisateur;
		switch(choixUtilisateur)
		{
			case 1:{
				cout << "Entrer le jour: ";
				cin >> jour;
				cout << "Entrer le mois: ";
				cin >> mois;
				cout << "Entrer l'annéé: ";
				cin >> annee;
				Date date(jour,mois,annee);
				if(date.dateValide(jour,mois,annee))
				{
					cout << "La date saisie est valide." << endl << endl;
					date.afficheDate();
				}
			}
			break;
			case 2:{
				cout << "Entrer l'année: ";
				cin >> annee;
				Ferie f;
				f.listeJoursFerie(annee);
			}break;
			case 3:{
				cout << "Combien de date voulez-vous saisis ? ";
				cin >> liste;
				for(i=0;i<liste;i++){
					cout << "Entrer le jour " << i+1 << " : ";
					cin >> jour;
					cout << "Entrer le mois " << i+1 << " : ";
					cin >> mois;
					cout << "Entrer l'annéé " << i+1 << " : ";
					cin >> annee;
					Date date(jour,mois,annee);
					listeDate.push_back(date);
				}
				d.afficheDateRecente(listeDate);
				d = d.retourneDateRecente(listeDate);
				Conversion::convertirValeurEnLettre(d.getJour(),tableauTemporaire);
				chaine = chaine + tableauTemporaire + "/ ";
				Conversion::convertirMoisEnLettre(d.getMois(),tableauTemporaire);
				chaine = chaine + tableauTemporaire +"/ ";
				Conversion::convertirValeurEnLettre(d.getAnnee(),tableauTemporaire);
				chaine = chaine + tableauTemporaire;
				cout << "La date récente en lettre est : " << chaine << endl << endl;
				chaine = " ";
			}break;
			case 4:{
				for(i=0;i<2;i++){
					cout << "Entrer le jour " << i+1 << " : ";
					cin >> jour;
					cout << "Entrer le mois " << i+1 << " : ";
					cin >> mois;
					cout << "Entrer l'annéé " << i+1 << " : ";
					cin >> annee;
					Date date(jour,mois,annee);
					listeDate.push_back(date);
				}
				nombreDeJoursEcoules = d.NombreJoursEcoules(listeDate[0],listeDate[1]);
				cout << "Le nombre de jour écoulé(s) entre ("
						<< listeDate[0].getJour()<<"/"<<listeDate[0].getMois()<<"/"<<listeDate[0].getAnnee()
						<<") et ("<< listeDate[1].getJour()<<"/"<<listeDate[1].getMois()<<"/"<<listeDate[1].getAnnee()<<") est: "
						<< nombreDeJoursEcoules << " jour(s)" <<  endl << endl;
			}break;
			case 5:{
				cout << "Entrer le jour: ";
				cin >> jour;
				cout << "Entrer le mois: ";
				cin >> mois;
				cout << "Entrer l'annéé: ";
				cin >> annee;
				//Date date(jour,mois,annee);
				if(d.dateValide(jour,mois,annee)){
					Conversion::convertirValeurEnLettre(jour,tableauTemporaire);
					chaine = chaine + tableauTemporaire + "/ ";
					Conversion::convertirMoisEnLettre(mois,tableauTemporaire);
					chaine = chaine + tableauTemporaire +"/ ";
					Conversion::convertirValeurEnLettre(annee,tableauTemporaire);
					chaine = chaine + tableauTemporaire;
					cout << "La date "<< jour << "/" << mois << "/" << annee << " en lettre est : " << chaine << endl << endl;
					chaine = " ";
				}
			}break;
			default:
				cout << "Ouups ! Erreur, merci de consulter le menu." << endl << endl;
				break;
		}
		cout << "Voulez-vous continuer (O,N) ? ";
		cin >> reponse;
		if(reponse =='O' || reponse=='o')
			continuer = true;
		else
			continuer = false;
	}
	return 0;
}
