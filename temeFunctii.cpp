#include "temeFunctii.h"

//Bucla for: 
//Ex.1 
void numaratoareInversaPtLansare()
{
	std::cout << "Incepem numaratoarea inversa! Atentie..." << std::endl;
	for (size_t i{ 10 }; i > 0; i--)
	{
		std::cout << i << std::endl;
	}
	std::cout << "Lansare!" << std::endl;
}

//Ex.2
void sumaPrimNNumNaturale()
{
	//Citim de la utilizator numarul N
	std::cout << "Introdu numarul N: ";
	unsigned int N{};
	std::cin >> N;

	//Calculam suma primelor N numere naturale
	unsigned int suma{};
	for (size_t i{ N }; i > 0; i--)
	{
		suma += i;
	}

	//Afisam rezultatul
	std::cout << "Suma primelor " << N << " numere naturale este " << suma << std::endl;
}

//Ex.3
void afisareaPattern()
{
	std::cout << "Introdu numarul de randuri ale piramider: ";
	short n{};
	std::cin >> n;

	for (size_t i{ 0 }; i < n; i++)
	{
		//Numarul de spatii pentru fiecare linie este n - i - 1, unde i este indexul liniei
		//De exemplu pentru linia cu indexul 0, voi avea n - 1 spatii pana la prima steluta
		for (size_t j{ n - i - 1 }; j > 0; j--)
		{
			std::cout << " ";
		}

		//Numarul de stelute este i+1, unde i este indexul liniei respective
		//De exemplu pentru linia cu indexul 0, voi avea 0 + 1 = 1 stelute
		for (size_t k{}; k < i + 1; k++)
		{
			std::cout << "* ";
		}

		std::cout << std::endl;
	}
}


/*	    *
	   * *
	  * * *
	 * * * *
	* * * * *
	 * * * *
	  * * *
	   * *
		*       */

//Functie care afiseaza un romb - adaugator
void afisareRomb()
{
	//n este numarul total de randuri din care este construit rombul
	std::cout << "Introdu numarul de randuri ale rombului: ";
	short n{};
	std::cin >> n;

	//Am utilizat operatorul ternar pentru a face mai scurta verificarea 
	//daca numarul introdus este impar sau par
	bool numarImpar = ((n % 2) != 0) ? true : false;

	for (size_t i{ 0 }; i < n; i++)
	{
		//Cat suntem mai sus de jamatatea rombuliu, folosim algoritmul pentru piramida
		if (i < n / 2)
		{
			for (size_t j{ n / 2 - i }; j > 0; j--)
			{
				std::cout << " ";
			}

			for (size_t k{}; k < i + 1; k++)
			{
				std::cout << "* ";
			}

			std::cout << std::endl;
		}
		//Cand ajungem la jumatate, verificam daca numarul total de randuri este par sau impar
		//Daca numarul este impar, includem o linie cu un element mai mult decat in precedenta
		else if (numarImpar && i == n / 2)
		{
			for (size_t aux{}; aux < i + 1; aux++)
			{
				std::cout << "* ";
			}
			std::cout << std::endl;
		}
		//Daca numarul este par, includem inca o linie identica cu precedenta.
		else if (!numarImpar && i == n / 2)
		{
			std::cout << " "; //Includ un spatiu pentru aliniere
			for (size_t aux{}; aux < i; aux++)
			{
				std::cout << "* ";
			}
			std::cout << std::endl;
		}
		//Dupa ce am trecut de jumatate, mergem in descrestere pentru afisare
		//Numarul spatiilor se mareste, fiindca se mareste (i - n/2), iar numarul stelutelor se micsoreaza 
		//fiindca se micosreaza valoarea (n - i)
		else if (i > n / 2)
		{
			if (!numarImpar) {
				std::cout << " ";
			} //Includ un spatiu pentru aliniere
			  //In acest mod functia lucreaza si pt numere pare si pentru impare
			for (size_t j{}; j < i - n / 2; j++)
			{
				std::cout << " ";
			}

			for (size_t k{}; k < n - i; k++)
			{
				std::cout << "* ";
			}

			std::cout << std::endl;
		}
	}
}


//Bucla while
//Ex.1 
void celMaiMareDivizorCom()
{
	//Citim numerele de la utilizator
	int num1{}, num2{};
	std::cout << "Introdu primul numar: ";
	std::cin >> num1;
	std::cout << "Introdu al doilea numar: ";
	std::cin >> num2;

	std::cout << "Cel mai mare divizor comun pentru numerele " << num1 << " si " << num2 << " este ";

	while (num2 != 0)
	{
		int rest = num1 % num2;
		num1 = num2;
		num2 = rest;
	}
	std::cout << num1 << std::endl;
}

//Ex.2
void numarPrim()
{
	std::cout << "Introdu un numar pozitiv (numerele negative nu pot fi numere prime): "; 
	unsigned int numar{};
	std::cin >> numar;

	std::cout << "Numarul " << numar;

	unsigned int impartitor = numar/2; 
	//Un numar nu poate fi divizibil cu un alt numar care este mai mare decat jumatatea sa.
	while (impartitor != 1) 
	{
		if (numar % impartitor == 0)
		{	
			//Daca restul impartirii va fi 0, numarul nu este prim
			std::cout << " nu este numar prim." << std::endl;
			std::cout << "Este divizibil cu " << impartitor << std::endl;
			return;
		}
		impartitor--; 
	}
	std::cout << " este un numar prim." << std::endl;
}

//Ex.3
void convertDecToBin()
{
	std::cout << "Introdu un numar in baza 10: "; 
	int num{};
	std::cin >> num; 

	if (num == 0)
	{
		std::cout << "Forma binara a numarului introdus este " << 0 << std::endl;
	}

	std::string result{}; 
	while (num != 0)
	{
		//Fiecare cifra calculata trebuie sa fie pusa inaintea celor anterioare
		result = (char)((num % 2) + '0') + result; //Daca ar fi result += (char)((num%2)+'0') cifrele ar fi
												   //inversate cu locul	
		num /= 2;
	}
	std::cout << "Forma binara a numarului introdus este " << result << std::endl;
}



//Bucla do...while
//Ex.1
void citireaPanaLaNumMagic()
{
	const int numarMagic = 999; 
	int inputUser{}, numarIncercari{};

	do {
		std::cout << "Care este numarul magic (este intre 0 si 1000)? "; 
		std::cin >> inputUser;
		if (inputUser == numarMagic) {
			std::cout << "Ai ghicit. Numarul magic este " << numarMagic << " !" << std::endl;
		}
		else {
			std::cout << "Incorect. Mai incearca odata!" << std::endl;
		}
		numarIncercari++; 

	} while (inputUser != numarMagic); 

	std::cout << "Numarul de incercari: " << numarIncercari << std::endl;
}

//Ex.2
void calculatorSimplu()
{
	std::cout << "CALCULATOR SIMPLU" << std::endl;

	double operand_1{}, operand_2{}, rezultat{};;
	char operatia{};
	bool sfarsit{ false }; //Cand sfarsit este true, bucla se opreste din executare 

	while (!sfarsit) {
		//Citim operatia de la utilizator
		std::cout << "Introduceti numerele si operatia sub forma \"operand_1 operatia operand_2\": " << std::endl;
		/*std::cin >> operand_1 >> operatia >> operand_2;*/

		//Verificam daca fluxul cin a reusit sa introduca valorile din consola in variabile
		if (!(std::cin >> operand_1 >> operatia >> operand_2))
		{	
			//Daca sunt introduse alte caracter care nu se potrivesc pentru variabilele de intrare, fluxul cin 
			//cade in stare de eroare.
			std::cin.clear(); //Curata starea de eroare
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Toate caracterele din buffer sunt sterse pana la 
																				//ultimul newline
			std::cout << "Ai introdus caractere gresite! Incerca din nou!" << std::endl;
			continue;
		}

		switch (operatia)
		{
			case '+': rezultat = operand_1 + operand_2;
				break;
			case '-': rezultat = operand_1 - operand_2;
				break;
			case '*':rezultat = operand_1 * operand_2;
				break;
			case '/': rezultat = operand_1 / operand_2;
				break;
			case '^': rezultat = pow(operand_1, operand_2);
				break;
			case 'q': rezultat = pow(operand_1, 1.0/operand_2); //operatia radical
				break;
			default: std::cout << "Ai introdus operatia gresita!" << std::endl;
				continue;
		}		

		std::cout << "Rezultat: " << rezultat << std::endl;
		std::cout << std::endl;

		//Utilizatorul este interogat daca doreste sa efectueze alta operatie
		std::cout << "Doriti sa efectuati o noua operatie? " <<
	    "Raspunde cu \"DA\" pentru confirmare, orice alt raspuns va fi considerat ca refuz!" << std::endl;
		std::string raspuns{}; 
		std::cin >> raspuns;

		//Daca intre paranteze avem true, este intors false, in caz contrar este intors true
		sfarsit = (raspuns == "DA") ? false : true; 
	}

	std::cout << "O zi buna in continuare!" << std::endl;
}


//Ex.3
void validareaInceptului()
{
	int numarIntrodus{}; 

	do {
		//Citim numarul de la utilizator
		std::cout << "Introduce un numar intre 1 si 100: "; 
		std::cin >> numarIntrodus; 
		
		if (numarIntrodus > 0 && numarIntrodus < 101) {
			std::cout << "Inceptul este validat!" << std::endl;
		}
		else {
			std::cout << "Incearca din nou!" << std::endl;
		}
		//Conditia buclei 
	} while (numarIntrodus < 1 || numarIntrodus > 100); 

	//Bucla este incheiata cand numarul introdus este corect si este afisat mesajul de mai jos
	std::cout << "Felicitari! Ai reusit sa introduci un numar intre 1 si 100." << std::endl;
}