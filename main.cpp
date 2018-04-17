#include <iostream>
#include "Tank.h"
#include "Helicopter.h"
#include "Soldier.h"
#include <vector>

std::vector< Tank * > g_pTanks;
std::vector< Helicopter * > g_pHelicopters;
std::vector< Soldier * > g_pSoldiers;
std::vector<CombatUnit *> g_CombatUnits;
enum class MenuChoice
{
	tank,
	helicopter,
	soldier,
	report,
	quit,
	invalid
};

MenuChoice GetValidChoice( );
void ShowMenu( );
void HandleChoice( MenuChoice choice );
void ReportAll( );
void CleanUp( );

int main( )
{
	MenuChoice choice;
	while ( ( choice = GetValidChoice( ) ) != MenuChoice::quit )
	{
		HandleChoice( choice );
	}
	CleanUp( );

	std::cout << "Push ENTER to continue";
	std::cin.get( );
}

MenuChoice GetValidChoice( )
{
	MenuChoice menuChoice;
	do
	{
		ShowMenu( );

		char enteredChoice;
		std::cin >> enteredChoice;
		std::cin.ignore( std::cin.rdbuf( )->in_avail( ) );

		switch ( enteredChoice )
		{
		case 't':
			menuChoice = MenuChoice::tank;
			break;
		case 's':
			menuChoice = MenuChoice::soldier;
			break;
		case 'h':
			menuChoice = MenuChoice::helicopter;
			break;
		case 'r':
			menuChoice = MenuChoice::report;
			break;
		case 'q':
			menuChoice = MenuChoice::quit;
			break;
		default:
			std::cout << enteredChoice << " is an invalid choice\n";
			menuChoice = MenuChoice::invalid;
			break;
		}
	}
	while ( menuChoice == MenuChoice::invalid );
	
	return menuChoice;
}

void ShowMenu( )
{
	std::cout << "Make your choice\n";
	std::cout << "t: add tank\n";
	std::cout << "s: add soldier\n";
	std::cout << "h: add helicopter\n";
	std::cout << "r: report\n";
	std::cout << "q: quit\n";
}

void HandleChoice( MenuChoice choice )
{
	switch ( choice )
	{
	case MenuChoice::helicopter:
		g_CombatUnits.push_back( new Helicopter( ) );
		break;
	case MenuChoice::tank:
		g_CombatUnits.push_back( new Tank( ) );
		break;
	case MenuChoice::soldier:
		g_CombatUnits.push_back( new Soldier( ) );
		break;
	case MenuChoice::report:
		ReportAll( );
		break;

		
	}
}

void ReportAll( )
{
	int seqNr{ 0 };




	for (CombatUnit* ptr : g_CombatUnits)
	{
		++seqNr;
		std::cout << seqNr << ": " << ptr->GetReport( ) << "\n";
	}
	//for ( Soldier* ptr : g_CombatUnits)
	//{
	//	++seqNr;
	//	std::cout << seqNr << ": " << ptr->GetReport( ) << "\n";
	//}
	//for ( Tank* ptr : g_pTanks )
	//{
	//	++seqNr;
	//	std::cout << seqNr << ": " << ptr->GetReport( ) << "\n";
	//}

}


void CleanUp( )
{
	for (CombatUnit* ptr : g_CombatUnits)
	{
		delete ptr;
	}
	g_CombatUnits.clear( );

//	for (CombatUnit* ptr : g_pSoldiers )
//	{
//		delete ptr;
//	}
//	g_pSoldiers.clear( );
//
//	for (CombatUnit* ptr : g_pTanks )
//	{
//		delete ptr;
//	}
//	g_pTanks.clear( );
}
