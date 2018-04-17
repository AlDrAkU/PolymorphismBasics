#pragma once
#include <string>
class CombatUnit
{
public:
	CombatUnit( );
	virtual ~CombatUnit( );
	// Rule of 5 remark:
	// - Destructor defined to do some tracing, no resources are freed
	// - So the default copy/move constructor and operator= are ok
	virtual std::string GetReport() const =0;
protected:
	int m_MyNumber;

private: 
};



