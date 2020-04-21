#include "stdafx.h"
#include "Fstream.h"

inline std::istream& operator>>( std::istream& stream, IPair& ob)
{
	return ob.Input(stream);
}

inline std::ostream& operator<<( std::ostream& stream, IPair& ob)
{
	return ob.Output(stream);
}