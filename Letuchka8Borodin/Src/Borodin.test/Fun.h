
class Matrix
{
	public:
		Matrix(int str, int colom);
		Matrix(Matrix &matrix);
		~Matrix();

		const Matrix& operator= (const Matrix &right);
		Matrix operator+ (Matrix &right);
		int* operator [] (int index) const;
		
		bool setMatrix(const char *fileName);

		friend bool operator== (Matrix &left, Matrix &right);
		friend Matrix operator* (Matrix &left, Matrix &right);

	private:
		int **_matrix;
		int str;
		int colom;

};