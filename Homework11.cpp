#include "temeFunctii.h"

int main()
{
	std::cout << "Tema pe acasa:" << std::endl;
	const std::string optiuni_intrare{ R"(
			1.Tema numaratoare inversa pentru lansare
			2.Tema suma primelor N numere naturale
			3.Tema afisare pattern
			4.Tema afisare pattern (romb)
			5.Tema cel mai mare divizor comun
			6.Tema verificarea unui numar prim
			7.Tema convertirea unui numar din baza 10 in baza 2
			8.Tema citirea pana la numarul magic
			9.Tema calculator simplu 
			10.Tema validarea inceputului
	)" };

	//Afisam optiunile posibile
	std::cout << "Optiuni:" << std::endl << optiuni_intrare << std::endl;

	//Citim optiunea necesara de la tastatura
	std::cout << "Introduce numarul din dreptul optiunii necesare: ";
	short optiune{};
	std::cin >> optiune;
	std::cout << std::endl;

	//Executam functia ce corespunde optiunei introduse
	switch (optiune)
	{
	case 1: numaratoareInversaPtLansare();
		break;
	case 2: sumaPrimNNumNaturale();
		break;
	case 3: afisareaPattern();
		break;
	case 4: afisareRomb();
		break;
	case 5: celMaiMareDivizorCom();
		break;
	case 6: numarPrim();
		break;
	case 7: convertDecToBin();
		break;
	case 8: citireaPanaLaNumMagic();
		break;
	case 9: calculatorSimplu();
		break;
	case 10: validareaInceptului();
		break;
	default: std::cout << "Optiune incorecta!" << std::endl;
	}

}

