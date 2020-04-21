#include "stdafx.h"
bool PrintToFile(const char* fileName, Entrant* structEnt, int coll);
void copy(wchar_t* str1, wchar_t* str2);
void PickingStruct(Entrant* entstr, int coll);
char* FileToString(const char* fileName, size_t &LengthFile);
Entrant* ReadStructOfFile(const char* fileName, int &coll);
Entrant* getEntrantMiddleBall(Entrant* entMass, int &collEntrant, double middleBall);
