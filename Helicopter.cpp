#include "Helicopter.h"
#include <iostream>


int Helicopter::m_InstanceCounter = 0;

Helicopter::Helicopter( )
{
	std::cout << ">Helicopter constructor<\n";
	++m_InstanceCounter;
	m_MyNumber = m_InstanceCounter;
}

Helicopter::~Helicopter()
{
	std::cout << ">Helicopter destructor<\n";
}

std::string Helicopter::GetReport( ) const
{
	return std::string("Viper ")  + std::to_string(m_MyNumber) +  " has taken to the air." ;
}
