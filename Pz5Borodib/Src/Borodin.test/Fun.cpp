#include "stdafx.h"
char* FileToString(const char* fileName, size_t &LengthFile)
{
	FILE *fptr;
	fopen_s(&fptr, fileName, "r");


	if (fptr == nullptr)
		return nullptr;

	fseek(fptr, 0, SEEK_END);
	long filesize = ftell(fptr);
	rewind(fptr);

	char *charFile = new char[filesize];

	auto countChar = fread(charFile, 1, filesize, fptr);
	LengthFile = countChar;
	charFile[countChar] = '\0';
	fclose(fptr);

	return charFile;
}

int SizeStuctMass(char* FileChar, size_t LengthFile)
{
	int rezult = 0;
	for (size_t i = 0; i < LengthFile; ++i)
		if (FileChar[i] == '{')
			rezult++;
	return rezult;
}

size_t getFirstDoublePoint(wchar_t* string)
{
	int indexOfColon = 0;

	for (indexOfColon = 0; string[indexOfColon] != L':' && string[indexOfColon] != L'\0'; ++indexOfColon);

	return indexOfColon;

}

wchar_t *StrToWideStr(char *str, size_t length)
{
	size_t converted = 0;

	wchar_t *wstr = new wchar_t[length];

	mbstowcs_s(&converted, wstr, length, str, _TRUNCATE);

	if (converted != length)
		return nullptr;

	return wstr;
}


Entrant* ReadStructOfFile(const char* fileName, int &coll)
{
	size_t lengthFile;
	char* file = nullptr;
	wchar_t* filewch = nullptr;

	file = FileToString(fileName, lengthFile);
	if (file == nullptr)
		return nullptr;

	filewch = StrToWideStr(file, lengthFile);
	int countStruct = SizeStuctMass(file, lengthFile);
	delete[] file;

	coll = countStruct;
	Entrant* rezultMass = new Entrant[countStruct]{};
	//resultMass = nullptr;
	size_t pointRead = 0;

	for (int i = 0; i < countStruct; ++i)
	{
		
		pointRead += getFirstDoublePoint(filewch + pointRead)+2 ;
		if (*(filewch+ pointRead-2)=='\0')
			return rezultMass;
		swscanf_s(filewch + pointRead, L"%[^\"]", rezultMass[i].Name, 30);
		pointRead += getFirstDoublePoint(filewch + pointRead) +1;

		swscanf_s(filewch + pointRead, L"%[^,]", rezultMass[i].Phone, 10);
		pointRead += getFirstDoublePoint(filewch + pointRead) + 2;

		for (int j = 0; j<4; ++j)
			swscanf_s(filewch + pointRead + j * 2, L"%d", &rezultMass[i].Estimates[j]);

	}
	delete[] filewch;
	return rezultMass;
}


double middleBallEntarnt(Entrant ent)
{
	return (double)(ent.Estimates[0] + ent.Estimates[1] + ent.Estimates[2] + ent.Estimates[3]) / 4.;
}

Entrant* getEntrantMiddleBall(Entrant* entMass, int &collEntrant, double middleBall)
{
	int coll = 0;

	for (int i = 0; i < collEntrant; i++)
		if (middleBallEntarnt(entMass[i]) > middleBall)
			++coll;

	if (coll == 0)
		return nullptr;

	Entrant* rezult = new Entrant[coll];

	for (int i = 0, j = 0; i < collEntrant; i++)
		if (middleBallEntarnt(entMass[i]) > middleBall)
		{
			rezult[j] = entMass[i];
			++j;
		}
	collEntrant = coll;
	return rezult;
}

bool PrintToFile(const char* fileName, Entrant* structEnt, int coll)
{
	FILE*filePtr = nullptr;
	fopen_s(&filePtr, fileName, "w");
	if (filePtr == nullptr || structEnt == nullptr)
		return false;
	fwprintf_s(filePtr,L"%ws",
		L"+---+-------------------+-----------------------+--------------------------+\n"
		L"| ¹ |       Name        |         Phone         |        Estimates         |\n"
		L"+---+-------------------+-----------------------+--------------------------+\n");
	for (int i = 0; i < coll; ++i)
	{
		fwprintf_s(filePtr, L"%ws %d %ws %ws %ws %ws %ws %d %c %d %c %d %c %d %ws",
			L"|", i + 1, L"|\t", structEnt[i].Name, L"\t|\t", structEnt[i].Phone, L"\t|\t",
			structEnt[i].Estimates[0], L'\\', structEnt[i].Estimates[1], L'\\',
			structEnt[i].Estimates[2], L'\\', structEnt[i].Estimates[3], L"\t |\n");
			fwprintf_s(filePtr, L"%ws", L"+---+-------------------+-----------------------+--------------------------+\n");
	}
	return true;
}

void copy(wchar_t* str1, wchar_t* str2)
{
	for (int i = 0; i < 10; ++i)
		str1[i] = str2[i];
}

void PickingStruct(Entrant* entstr, int coll)
{
	Entrant buffer = { L"",L"",{ 0,0,0,0 } };
	for (int i = 0; i<coll; ++i)
		for (int j = 0; j < coll; j++)
		{
			if (entstr[i].Name[0] < entstr[j].Name[0])
			{
				copy(buffer.Name, entstr[i].Name);
				copy(entstr[i].Name, entstr[j].Name);
				copy(entstr[j].Name, buffer.Name);

			}
		}
}