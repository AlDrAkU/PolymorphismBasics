#pragma once
#include "CombatUnit.h"
#include <string>

class Tank : public CombatUnit
{
public:
	Tank( );
	~Tank( ); 

	virtual std::string GetReport( ) const override;
private:
	static int m_InstanceCounter;
};

 
