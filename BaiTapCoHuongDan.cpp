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
void docDSSV(char fNameIn[], ItemType ds[], int &n)
{
	FILE *fi = fopen(fNameIn, "rt");
	if (fi == NULL)
	{
		printf("Loi: mo file de doc du lieu.");
		getch();
		return;
	}
	fscanf(fi, "%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		SV x;
		docTTSV(fi, x);
		ds[i] = x;
	}
	fclose(fi);
}
void ghiTTSV(FILE *fo, ItemType x)
{
	fprintf(fo, "%-15s%-10s%-20s%-10s%5.2lf\n", x.mssv, x.ho, x.hoLot, x.ten, x.diemTB);
}
void ghiDSSV(char fNameOut[], ItemType ds[], int n)
{
	FILE *fo = fopen(fNameOut, "wt");
	if (fo == NULL)
	{
		printf("Loi: mo file de ghi du lieu.");
		getch();
		return;
	}
	fprintf(fo, "%-5s%-15s%-40s%-10s\n", "STT", "MSSV", "HO VA TEN SINH VIEN", "DIEM TB");
	for (int i = 0; i < n; i++)
	{
		fprintf(fo, "%-5d", i + 1);
		ghiTTSV(fo, ds[i]);
	}
	fclose(fo);
}
void xuatDSSV(ItemType ds[], int &n)
{
	printf("%-5s%-15s%-40s%-10s\n", "STT", "MSSV", "HO VA TEN SINH VIEN", "DIEM TB");
	for (int i = 0; i < n; i++)
	{
		printf("%-5d", i + 1);
		xuatTTSV(ds[i]);
	}
}