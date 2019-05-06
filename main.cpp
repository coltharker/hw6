#include <iostream>
#include <fstream>
#include "cdk.h"

using namespace std;

class BinaryFileHeader
{
public:
uint32_t magicNumber; /* Should be 0xFEEDFACE */
uint32_t versionNumber;
uint64_t numRecords;
};

const int maxRecordStringLength = 25;
class BinaryFileRecord
{
public:
uint8_t strLength;
char stringBuffer[maxRecordStringLength];
};

int main (int argc, char* argv[]) {
    WINDOW *window;
    CDKSCREEN *cdkscreen;
    CDKMATRIX *myMatrix;

    ifstream myFile("cs3377.bin");
    BinaryFileHeader *bfh;
    myFile.read((char*) bfh, sizeof(BinaryFileHeader));
    int n = (int) (bfh -> numRecords);
    BinaryFileRecord *bfr = new BinaryFileRecord[n];
    myFile.read((char*) bfr, sizeof(BinaryFileRecord) * n);

    myFile.close();

    const char *rowTitles[6] = {"", "", "", ""};
    const char *columnTitles[4] = {"", "", "", ""};
    int boxWidths[4] = {25, 25, 25, 25};
    int boxTypes[4] = {vMIXED, vMIXED, vMIXED, vMIXED};

    window = initscr();
    cdkscreen = initCDKScreen(window);
    initCDKColor();

    myMatrix = newCDKMatrix(cdkscreen, CENTER, CENTER, 3, 5, 3, 5, "Binary File Contents", 
                            (char **) columnTitles, (char **) rowTitles, boxWidths,
				            boxTypes, 1, 1, ' ', ROW, true, true, false);

    if (myMatrix ==NULL)
    {
        printf("Error creating Matrix\n");
        _exit(1);
    }

    drawCDKMatrix(myMatrix, true);

    setCDKMatrixCell(myMatrix, 2, 2, "Test Message");
    drawCDKMatrix(myMatrix, true);    /* required  */

    sleep (10);

    endCDK();

    return 0;
}