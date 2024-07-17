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
typedef SV ItemType;

void docTTSV(FILE *fi, ItemType &x)
{
	fscanf(fi, "%[^#]%*c%[^#]%*c%[^#]%*c%[^#]%*c%lf\n", &x.mssv, &x.ho, &x.hoLot, &x.ten, &x.diemTB);
}

void xuatTTSV(ItemType x)
{
	printf("%-15s%-10s%-20s%-10s%5.2lf\n", x.mssv, x.ho, x.hoLot, x.ten, x.diemTB);
}