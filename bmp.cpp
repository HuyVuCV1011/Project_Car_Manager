#include <stdio.h>
#include <Windows.h>
#include "bmp.h"


bool isBmpFile(FILE *f)
{
	if (f == NULL)
		return false;

	BmpSignature signature;
	fseek(f, 0, SEEK_SET);
	fread(&signature, sizeof(BmpSignature), 1, f);

	return signature.data[0] == 'B' && signature.data[1] == 'M';
}

void readBmpHeader(FILE *f, BmpFile &bmp)
{
	if (f == NULL)
		return;

	fseek(f, 0, SEEK_SET);
	fread(&bmp.header, sizeof(BmpHeader), 1, f);
}

void readBmpDib(FILE *f, BmpFile &bmp)
{
	if (f == NULL)
		return;

	fseek(f, sizeof(BmpHeader), SEEK_SET);
	fread(&bmp.dib, sizeof(BmpDib), 1, f);
}


void readBmpPixelArray(FILE *f, BmpFile &bmp)
{
	if (f == NULL)
		return;

	int widthSize = bmp.dib.imageWidth * (bmp.dib.pixelSize / 8);
	bmp.pixelArray.paddingSize = (4 - (widthSize % 4)) % 4;
	bmp.pixelArray.lineSize = widthSize + bmp.pixelArray.paddingSize;
	bmp.pixelArray.rawByteSize = bmp.pixelArray.lineSize * bmp.dib.imageHeight;
	bmp.pixelArray.rawBytes = new unsigned char[bmp.pixelArray.rawByteSize];

	fseek(f, bmp.header.dataOffset, SEEK_SET);
	fread(bmp.pixelArray.rawBytes, bmp.pixelArray.rawByteSize, 1, f);

	initPixels(bmp.pixelArray, bmp.dib.imageWidth, bmp.dib.imageHeight);
}

void initPixels(PixelArray &pa, int width, int height)
{
	pa.rowCount = height;
	pa.columnCount = width;

	pa.pixels = new Color *[pa.rowCount];
	for (int i = 0; i < pa.rowCount; i++)
		pa.pixels[pa.rowCount - 1 - i] = (Color *)(pa.rawBytes + pa.lineSize * i);
}

void drawBmp(BmpFile bmp)
{
	HWND console = GetConsoleWindow();
	HDC hdc = GetDC(console);
	for (int i = 0; i < bmp.dib.imageHeight; i++)
		for (int j = 0; j < bmp.dib.imageWidth; j++)
		{
			Color pixel = bmp.pixelArray.pixels[i][j];
			SetPixel(hdc, j, i, RGB(pixel.red, pixel.green, pixel.blue));
		}
	ReleaseDC(console, hdc);
}

void releaseBmpPixelArray(BmpFile &bmp)
{
	delete[]bmp.pixelArray.rawBytes;
	delete[]bmp.pixelArray.pixels;
}

void readBmpFile(const char *filename, BmpFile &bmp)
{
	FILE *f;
	fopen_s(&f, filename, "rb");

	if (f == NULL || !isBmpFile(f))
	{
		printf("Error or Invalid Bmp File.\n");
		return;
	}

	readBmpHeader(f, bmp);
	readBmpDib(f, bmp);
	readBmpPixelArray(f, bmp);

	fclose(f);
}

