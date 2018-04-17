#pragma once
#include "CombatUnit.h"
#include <string>

class Soldier : public CombatUnit
{
public:
	Soldier( );
	~Soldier( );

	virtual std::string GetReport( ) const override;

private:
	static int m_InstanceCounter;
};
