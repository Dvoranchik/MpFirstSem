using namespace std;
struct Author
{
	char Title[32]{};
	int Publishyear;
	char Autor[32]{};
};

bool WriteTextAuthor(const char*, const Author& author);
bool ReadTextAuthor(const char*, Author& author);
bool WriteBinaryAuthor(const char*, const Author& author);
bool ReadBinaryAuthor(const char*, Author& author);