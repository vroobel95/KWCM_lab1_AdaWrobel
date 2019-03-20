#include "LaborkaConfig.h"
#include <iostream>

#ifdef USE_TRIGONOMETRY_DEGREE
	#include "trygonometria.h"
#endif

int main()
{
	#ifdef USE_TRIGONOMETRY_DEGREE
		double sinus = degreemath::sin(15.0);
		double cosinus = degreemath::cos(15.0);
		double tangens = degreemath::tg(15.0);
		double cotangens = degreemath::ctg(15.0);
	#else
		double sinus = sin(15.0);
		double cosinus = cos(15.0);
		double tangens = tan(15.0);
		double cotangens = 1/tan(15.0);
	#endif

	std::cout << sinus << std::endl;
	std::cout << cosinus << std::endl;
	std::cout << tangens << std::endl;
	std::cout << cotangens << std::endl;
}