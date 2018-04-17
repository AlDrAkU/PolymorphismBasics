#pragma once
#include "CombatUnit.h"
#include <string>

class Helicopter : public CombatUnit
{
public:
	Helicopter( );
	~Helicopter( );

	virtual std::string GetReport( ) const override;

private:
	static int m_InstanceCounter;
};


 
