/*
 * Usage of CDK Matrix
 *
 * File:   example1.cc
 * Author: Stephen Perkins
 * Email:  stephen.perkins@utdallas.edu
 */

#include <iostream>
#include "cdk.h"
#include <fstream>
#include <iomanip>
using namespace std;

const	int maxRecordStringLength = 25;

class BinaryFileRecord{

public:
	int	strLength;
	char	stringBuffer[maxRecordStringLength];

};

#define MATRIX_WIDTH 5
#define MATRIX_HEIGHT 3
#define BOX_WIDTH 30
#define MATRIX_NAME_STRING "Binary File Contents"


int main()
{

//BinaryFileRecord *myRecord1 = new BinaryFileRecord();
//myRecord1->myVal = 123.4567

//ofstream binOutfile ("binaryfile.bin", ios::out | ios::binary);

//binOutfile.write((char *) myRecord1, sizeof(BinaryFileRecord));
//binOutfile.close();


BinaryFileRecord *myRecord = new BinaryFileRecord();

ifstream binInfile ("cs3377.bin", ios::in | ios::binary);

binInfile.read((char *) myRecord, sizeof(BinaryFileRecord));

cout<<"Value was: " << setprecision(10) << myRecord->stringBuffer[maxRecordStringLength] << endl;


  WINDOW	*window;
  CDKSCREEN	*cdkscreen;
  CDKMATRIX     *myMatrix;           // CDK Screen Matrix

  const char 		*rowTitles[MATRIX_HEIGHT+1] = {"R0", "a", "b", "c"};
  const char 		*columnTitles[MATRIX_WIDTH+1] = {"C0", "a", "b", "c","d", "e"};
  int		boxWidths[MATRIX_WIDTH+1] = {BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH};
  int		boxTypes[MATRIX_WIDTH+1] = {vMIXED, vMIXED, vMIXED, vMIXED};

  /*
   * Initialize the Cdk screen.
   *
   * Make sure the putty terminal is large enough
   */
  window = initscr();
  cdkscreen = initCDKScreen(window);

  /* Start CDK Colors */
  initCDKColor();

  /*
   * Create the matrix.  Need to manually cast (const char**) to (char **)
  */
  myMatrix = newCDKMatrix(cdkscreen, CENTER, CENTER, MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_WIDTH, MATRIX_HEIGHT,
			  MATRIX_NAME_STRING, (char **) columnTitles, (char **) rowTitles, boxWidths,
				     boxTypes, 1, 1, ' ', ROW, true, true, false);

  if (myMatrix ==NULL)
    {
      printf("Error creating Matrix\n");
      _exit(1);
    }

  /* Display the Matrix */
  drawCDKMatrix(myMatrix, true);

  /*
   * Dipslay a message
   */
  setCDKMatrixCell(myMatrix, 2, 2, "Test Message");
  drawCDKMatrix(myMatrix, true);    /* required  */

  setCDKMatrixCell(myMatrix, 1,1, "hello there");
drawCDKMatrix(myMatrix, true);

  /* so we can see results */
  sleep (10);


  // Cleanup screen
  endCDK();
}
