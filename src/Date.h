/*
 * Date.h
 *      Author: charlie
 */

#ifndef CLASSES_DATE_H_
#define CLASSES_DATE_H_
#include <vector>

	class Date {
	public:
		Date();
		Date(int jour, int mois, int annee);
		virtual ~Date();
		bool dateValide(int j, int m, int a);
		void afficheDate() const;
		void afficheDateRecente(std::vector<Date> dates);
		int getJour() const;
		int getMois() const;
		int getAnnee() const;
		int NombreJoursEcoules (Date date1,Date date2);
		Date retourneDateRecente(std::vector<Date> dates);

	private:
		int _jour;
		int _mois;
		int _annee;
	};
#endif /* CLASSES_DATE_H_ */
