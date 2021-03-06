

#include "pch.h"
#include <iostream>
#include<algorithm>
#include<iomanip>
#include<typeinfo>
#include<string> 

using namespace std;

class Macros
{
private:
	string description;
	double proteinGrams;
	double fatGrams;
	double carbGrams;

public:
	void setDescription(string);
	void setProteins(double);
	void setFats(double);
	void setCarbs(double);
	string getDescription() const;
	double getProteins() const;
	double getFats() const;
	double getCarbs() const;
};

void Macros::setDescription(string d)
{
	description = d;
}

void Macros::setProteins(double grams)
{
	proteinGrams = grams;
}

void Macros::setFats(double grams)
{
	fatGrams = grams;
}

void Macros::setCarbs(double grams)
{
	carbGrams = grams;
}

string Macros::getDescription() const
{
	return description;
}

double Macros::getProteins() const
{
	return proteinGrams;
}

double Macros::getFats() const
{
	return fatGrams;
}

double Macros::getCarbs() const
{
	return carbGrams;
}


double lbs_to_kg(int pounds);

double inches_to_cm(int inches);

double tdee_calc(double bmr);

int bmr_calc_men(int weight, int height, int age);

int weight_goals(int tdee);

void display_proteins();

void display_fats();

void display_carbs();



int main()
{
	cout << "Please answer the following questions to determine your macros " << endl;
	int weight,
		kilos,
		height,
		centimeters,
		age;

	cout << "How much do you weigh? \n";
	cin >> weight;
	kilos = lbs_to_kg(weight);
	cout << "How tall are you? \n";
	cin >> height;
	centimeters = inches_to_cm(height);
	cout << "How old are you? \n";
	cin >> age;

	double bmr = bmr_calc_men(kilos, centimeters, age);
	cout << bmr << endl;
	double calories = tdee_calc(bmr);
	cout << calories << endl;

	int protein,
		fat,
		carbs,
		calGoal;
	calGoal = weight_goals(calories);

	protein = 1 * weight;
	fat = (0.25 * calGoal) / 9;
	carbs = (calGoal - ((protein*4) + (fat*9)))/4;

	cout << "Youre expected Macros are: \n";
	cout << "Protein: " << protein << endl;
	cout << "Fat: " << fat << endl;
	cout << "Carbohydrates: " << carbs << endl;
	
	cout << "\n What Macros source would you like to see? \n";

	cout << "1. Proteins" << endl;
	cout << "2. Fats" << endl;
	cout << "3. Carbohydrates" << endl;


	int choice;
	cin >> choice;

	switch (choice)
	{
	case 1: display_proteins();
		break;
	case 2: display_fats();
		break;
	case 3: display_carbs();
		break;
	default: "please choose 1-3 \n";
	}

	

	return 0;
}

double lbs_to_kg(int pounds)
{
	double kg = pounds * 0.45359237;
	return kg;
}

double inches_to_cm(int inches)
{
	double centimeters = inches * 2.54;
	return centimeters;
}

double tdee_calc(double bmr)
{
	int choice,
		tdee;
	cout << "Please choose your activity level: " << endl;
	cout << "1: Sendentary(little to no exercise)" << endl;
	cout << "2: Light Activity(light exercise)" << endl;
	cout << "3. Moderately Active(moderate exercise)" << endl;
	cout << "4. Very Active(heavy exercise)" << endl;
	cout << "5. Extremely Active(very head exercise)" << endl;
	cin >> choice;
	if (choice == 1)
		tdee = bmr * 1.2;
	else if (choice == 2)
		tdee = bmr * 1.375;
	else if (choice == 3)
		tdee = bmr * 1.55;
	else if (choice == 4)
		tdee = bmr * 1.725;
	else if (choice == 5)
		tdee = bmr * 1.9;
	return tdee;

}

int bmr_calc_men(int weight, int height, int age)
{

	int bmr = 88.362 + (13.397 * weight) + (4.799 * height) - (5.677 * age);
	return bmr;

}

int bmr_calc_women(int weight, int height, int age)
{
	int bmr_women = 447.593 + (9.247 * weight) + (3.098 * height) - (4.330 * age);
	return bmr_women;
}

int weight_goals(int tdee)
{
	cout << "What is your weight goal?: " << endl;
	cout << "1. lose weight \n";
	cout << "2. gain muscle \n";

	int weightGoal,
		cal;
	cin >> weightGoal;

	if (weightGoal == 1)
		cal = tdee - (tdee * 0.3);
	else if (weightGoal == 2)
		cal = tdee + (tdee * 0.15);
	return cal;
}

void display_proteins()
{
	
	//Proteins
	Macros chicken; //Macros for chicken per 4 oz
	chicken.setDescription("chicken");
	chicken.setProteins(31);
	chicken.setFats(3.6);
	chicken.setCarbs(0);

	Macros salmon; // Macros for salmon per 4 oz
	salmon.setDescription("salmon");
	salmon.setProteins(25);
	salmon.setFats(14);
	salmon.setCarbs(0);

	Macros pork; // Macros for pork per 4 oz
	pork.setDescription("pork");
	pork.setProteins(29.3);
	pork.setFats(16);
	pork.setCarbs(0);

	Macros beef; // Macros for beef per 4 oz
	beef.setDescription("beef");
	beef.setProteins(29.3);
	beef.setFats(22.7);
	beef.setCarbs(0);
	
	Macros protein_sources[4] = { chicken, salmon, pork, beef };
	
	cout << "Here is a list of Protein sources: " << endl;

	for (int i = 0; i < 4; i++)
	{
		cout << "\n";
		cout << protein_sources[i].getDescription() << endl;
		cout << "protein: " << protein_sources[i].getProteins() << endl;
		cout << "fats: " << protein_sources[i].getFats() << endl;
		cout << "carbs: " << protein_sources[i].getCarbs() << endl;

	}
}

void display_fats()
{
	Macros avocado; // Macros for one avocado
	avocado.setDescription("avocado");
	avocado.setProteins(2.7);
	avocado.setFats(21);
	avocado.setCarbs(12);

	Macros nuts; // Macros per oz of nuts
	nuts.setDescription("nuts");
	nuts.setProteins(5.7);
	nuts.setFats(15);
	nuts.setCarbs(6);

	Macros oliveOil; // Macros per tbsp of Olive oil
	oliveOil.setDescription("Olive Oil");
	oliveOil.setProteins(0);
	oliveOil.setFats(14);
	oliveOil.setCarbs(0);

	Macros fat_sources[3] = { avocado, nuts, oliveOil };

	cout << "Here is a list of Fat sources: " << endl;

	for (int i = 0; i < 4; i++)
	{
		cout << "\n";
		cout << fat_sources[i].getDescription() << endl;
		cout << "protein: " << fat_sources[i].getProteins() << endl;
		cout << "fats: " << fat_sources[i].getFats() << endl;
		cout << "carbs: " << fat_sources[i].getCarbs() << endl;

	}


}

void display_carbs()
{
	Macros  brownRice; // Macros per 4 oz of Brown Rice
	brownRice.setDescription("Brown Rice");
	brownRice.setProteins(2.7);
	brownRice.setFats(.8);
	brownRice.setCarbs(23);

	Macros oatmeal; // Macros per 8 oz of oatmeal
	oatmeal.setDescription("oatmeal");
	oatmeal.setProteins(5.9);
	oatmeal.setFats(3.6);
	oatmeal.setCarbs(28);

	Macros sweetPotato; // Macros per Sweet Potato
	sweetPotato.setDescription("Sweet Potato");
	sweetPotato.setProteins(2.1);
	sweetPotato.setFats(.2);
	sweetPotato.setCarbs(27);

	Macros quinoa; // Macros per 4 oz of quinoa
	quinoa.setDescription("quinoa");
	quinoa.setProteins(4.1);
	quinoa.setFats(1.8);
	quinoa.setCarbs(20);
	
	Macros carb_sources[4] = { brownRice, oatmeal, sweetPotato, quinoa };

	cout << "Here is a list of Carbohydrate sources: " << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << "\n";
		cout << carb_sources[i].getDescription() << endl;
		cout << "protein: " << carb_sources[i].getProteins() << endl;
		cout << "fats: " << carb_sources[i].getFats() << endl;
		cout << "carbs: " << carb_sources[i].getCarbs() << endl;

	}

}