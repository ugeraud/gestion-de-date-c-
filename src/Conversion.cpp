/*
 * Conversion.cpp
 *      Author: charlie
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "Conversion.h"
#include "Date.h"

using namespace std;

void Conversion::convertirValeurEnLettre(unsigned int valeur, char * tableauChaineCaractere)
{
	unsigned int centaine, dizaine, unite, reste, y;
    bool dix = false;
    strcpy(tableauChaineCaractere, "");
    reste = valeur;
    for(int i=1000000000; i>=1; i/=1000)
    {
        y = reste/i;
        if(y!=0)
        {
            centaine = y/100;
            dizaine  = (y - centaine*100)/10;
            unite = y-(centaine*100)-(dizaine*10);
            switch(centaine)
            {
                case 0:
                    break;
                case 1:
                    strcat(tableauChaineCaractere,"cent ");
                    break;
                case 2:
                    if((dizaine == 0)&&(unite == 0)) strcat(tableauChaineCaractere,"deux cents ");
                    else strcat(tableauChaineCaractere,"deux cent ");
                    break;
                case 3:
                    if((dizaine == 0)&&(unite == 0)) strcat(tableauChaineCaractere,"trois cents ");
                    else strcat(tableauChaineCaractere,"trois cent ");
                    break;
                case 4:
                    if((dizaine == 0)&&(unite == 0)) strcat(tableauChaineCaractere,"quatre cents ");
                    else strcat(tableauChaineCaractere,"quatre cent ");
                    break;
                case 5:
                    if((dizaine == 0)&&(unite == 0)) strcat(tableauChaineCaractere,"cinq cents ");
                    else strcat(tableauChaineCaractere,"cinq cent ");
                    break;
                case 6:
                    if((dizaine == 0)&&(unite == 0)) strcat(tableauChaineCaractere,"six cents ");
                    else strcat(tableauChaineCaractere,"six cent ");
                    break;
                case 7:
                    if((dizaine == 0)&&(unite == 0)) strcat(tableauChaineCaractere,"sept cents ");
                    else strcat(tableauChaineCaractere,"sept cent ");
                    break;
                case 8:
                    if((dizaine == 0)&&(unite == 0)) strcat(tableauChaineCaractere,"huit cents ");
                    else strcat(tableauChaineCaractere,"huit cent ");
                    break;
                case 9:
                    if((dizaine == 0)&&(unite == 0)) strcat(tableauChaineCaractere,"neuf cents ");
                    else strcat(tableauChaineCaractere,"neuf cent ");
            }// endSwitch(centaine)

            switch(dizaine)
            {
                case 0:
                    break;
                case 1:
                    dix = true;
                    break;
                case 2:
                    strcat(tableauChaineCaractere,"vingt ");
                    break;
                case 3:
                    strcat(tableauChaineCaractere,"trente ");
                    break;
                case 4:
                    strcat(tableauChaineCaractere,"quarante ");
                    break;
                case 5:
                    strcat(tableauChaineCaractere,"cinquante ");
                    break;
                case 6:
                    strcat(tableauChaineCaractere,"soixante ");
                    break;
                case 7:
                    dix = true;
                    strcat(tableauChaineCaractere,"soixante ");
                    break;
                case 8:
                    strcat(tableauChaineCaractere,"quatre-vingt ");
                    break;
                case 9:
                    dix = true;
                    strcat(tableauChaineCaractere,"quatre-vingt ");
            } // endSwitch(dizaine)

            switch(unite)
            {
                case 0:
                    if(dix) strcat(tableauChaineCaractere,"dix ");
                    break;
                case 1:
                    if(dix) strcat(tableauChaineCaractere,"onze ");
                   // else    strcat(tableauChaineCaractere,"un ");
                    break;
                case 2:
                    if(dix) strcat(tableauChaineCaractere,"douze ");
                    else    strcat(tableauChaineCaractere,"deux ");
                    break;
                case 3:
                    if(dix) strcat(tableauChaineCaractere,"treize ");
                    else    strcat(tableauChaineCaractere,"trois ");
                    break;
                case 4:
                    if(dix) strcat(tableauChaineCaractere,"quatorze ");
                    else    strcat(tableauChaineCaractere,"quatre ");
                    break;
                case 5:
                    if(dix) strcat(tableauChaineCaractere,"quinze ");
                    else    strcat(tableauChaineCaractere,"cinq ");
                    break;
                case 6:
                    if(dix) strcat(tableauChaineCaractere,"seize ");
                    else    strcat(tableauChaineCaractere,"six ");
                    break;
                case 7:
                    if(dix) strcat(tableauChaineCaractere,"dix-sept ");
                    else    strcat(tableauChaineCaractere,"sept ");
                    break;
                case 8:
                    if(dix) strcat(tableauChaineCaractere,"dix-huit ");
                    else    strcat(tableauChaineCaractere,"huit ");
                    break;
                case 9:
                    if(dix) strcat(tableauChaineCaractere,"dix-neuf ");
                    else    strcat(tableauChaineCaractere,"neuf ");
            } // endSwitch(unite)

            switch (i)
            {
                case 1000000000:
                    if(y>1) strcat(tableauChaineCaractere,"milliards ");
                    else strcat(tableauChaineCaractere,"milliard ");
                    break;
                case 1000000:
                    if(y>1) strcat(tableauChaineCaractere,"millions ");
                    else strcat(tableauChaineCaractere,"million ");
                    break;
                case 1000:
                    strcat(tableauChaineCaractere,"mille ");
            }

        } // end if(y!=0)
        reste = reste - y*i;
        dix = false;
    } // end for
    if(strlen(tableauChaineCaractere)==0)
    	strcpy(tableauChaineCaractere,"premier ");
}

void Conversion::convertirMoisEnLettre(unsigned int mois,char * tableauChaineCaractere){
	strcpy(tableauChaineCaractere, "");
	switch(mois){
		case 1: strcat(tableauChaineCaractere,"Janvier ");
        		break;
		case 2: strcat(tableauChaineCaractere,"Février ");
		        break;
		case 3: strcat(tableauChaineCaractere,"Mars ");
		        		break;
		case 4: strcat(tableauChaineCaractere,"Avril ");
		        		break;
		case 5: strcat(tableauChaineCaractere,"Mai ");
		        		break;
		case 6: strcat(tableauChaineCaractere,"Juin ");
		        		break;
		case 7: strcat(tableauChaineCaractere,"Juillet ");
		        		break;
		case 8: strcat(tableauChaineCaractere,"Août ");
		        		break;
		case 9: strcat(tableauChaineCaractere,"Septembre ");
		        		break;
		case 10: strcat(tableauChaineCaractere,"Octobre ");
		        		break;
		case 11: strcat(tableauChaineCaractere,"Novembre ");
		        		break;
		case 12: strcat(tableauChaineCaractere,"Décembre ");
		        		break;
		default: strcat(tableauChaineCaractere,"\n>> Oups ! Erreur La valeur doit être comprise entre [1 .. 12].\n");
				 break;
	}
}

