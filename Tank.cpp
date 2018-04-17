#include "Tank.h"
#include <iostream>

int Tank::m_InstanceCounter = 0;

Tank::Tank()
{
	std::cout << ">Tank constructor<\n";
	++m_InstanceCounter;
	m_MyNumber = m_InstanceCounter;
}

Tank::~Tank()
{
	std::cout << ">Tank destructor<\n";
}


std::string Tank::GetReport( ) const
{
	return std::string( "Tank " ) + std::to_string( m_MyNumber ) + " ready to roll out!";
}