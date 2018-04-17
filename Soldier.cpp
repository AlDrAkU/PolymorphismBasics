#include "Soldier.h"
#include <iostream>


int Soldier::m_InstanceCounter = 0;

Soldier::Soldier()
{
	std::cout << ">Soldier constructor<\n";
	++m_InstanceCounter;
	m_MyNumber = m_InstanceCounter;
}

Soldier::~Soldier()
{
	std::cout << ">Soldier destructor<\n";
}

std::string Soldier::GetReport( ) const
{
	return std::string( "Private " ) + std::to_string( m_MyNumber ) + " reporting for duty SIR!";
}


