#include<conio.h>
#include<stdio.h>
#include<string.h>

#define MAXSIZE 100
#define fNameIn_DSSV "input_DSSV.txt"
#define fNameOut_DSSV "output_DSSV.txt"
typedef struct SinhVien
{
	char mssv[11];
	char ho[8], hoLot[20], ten[8];
	double diemTB;
}SV;
typedef SV itemType;