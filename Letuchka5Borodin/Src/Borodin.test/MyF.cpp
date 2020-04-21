#pragma pack(1)
#include "stdafx.h"
#include "MyF.h"

/*bool WriteTextAuthor(const char *fileName, const Author& author)
{
		FILE *fp = nullptr;
		fopen_s(&fp, fileName, "w");
		
		fprintf(fp, "%s\n%d\n%s\n", author.Title, author.Publishyear, author.Autor);
		fclose(fp);
		return true;
}*/
bool WriteTextAuthor(const char *fileName, const Author& author)
{
	ofstream FileOut(fileName);
	if (!FileOut)
		return 0;
	FileOut << author.Title << "\t" << author.Publishyear << "\t" << author.Autor << "\t" << endl;
	FileOut.close();
	return 1;
}
bool ReadTextAuthor(const char* fileName, Author& author)
{
	ifstream FileInt(fileName);
	if (!FileInt)
		return 0;
	FileInt >> author.Title >> author.Publishyear >> author.Autor;
	FileInt.close();
	return 1;
}


bool WriteBinaryAuthor(const char* fileName, const Author& author)
{
	ofstream FileOut(fileName, ios::binary);
	if (!FileOut)
		return 0;
	/*FileOut.write((char*)&author.Title, sizeof(author.Title));
	FileOut.write((char*)&author.Publishyear, sizeof(author.Publishyear));
	FileOut.write((char*)&author.Autor, sizeof(author.Autor));*/
	FileOut.write((char*)&author, sizeof(Author));
	FileOut.close();
	return 1;
}

bool ReadBinaryAuthor(const char* fileName, Author& author)
{
	ifstream FileInt(fileName, ios::binary);
	if (!FileInt)
		return 0;
	FileInt.read((char*)&author, sizeof(Author));
	/*FileInt.read((char*)&author.Title, sizeof(author.Title));
	FileInt.read((char*)&author.Publishyear, sizeof(author.Publishyear));
	FileInt.read((char*)&author.Autor, sizeof(author.Autor));*/
	FileInt.close();
	return 1;
}