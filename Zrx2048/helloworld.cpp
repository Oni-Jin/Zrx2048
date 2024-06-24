#include "pch.h"

void helloworld()
{
	acutPrintf(_T("\nHello world!"));
}


int showhello(struct resbuf *rb)
{
	ads_printf(_T("hello"));
	ads_retvoid();
	return RTNORM;
}

int showhellocmd(struct resbuf *rb)
{
	ads_printf(_T("hello"));
	ads_retvoid();
	return RTNORM;
}

void game() {
	auto pDb = acdbHostApplicationServices()->workingDatabase();
	AcDbBlockTable* pBT = nullptr;
	if (pDb->getBlockTable(pBT, AcDb::kForWrite) != Acad::eOk) {
		acutPrintf(_T("get pBT: false"));
	}

	auto pBtr = new AcDbBlockTableRecord();

	AcDbObjectId btrId;
	pBT->add(btrId, pBtr);

	if (pBT->getAt(ZCDB_MODEL_SPACE, pBtr, AcDb::kForWrite) != Acad::eOk) {
		acutPrintf(_T("get pBtr: false"));
	}
	pBT->close();

	GameDrawer* gameDrawer = new GameDrawer();

	AcDbObjectId enID;
	pBtr->appendAcDbEntity(enID, gameDrawer);
	gameDrawer->close();

	gameDrawer = nullptr;
	acdbOpenAcDbEntity((AcDbEntity*&)gameDrawer, enID, AcDb::kForWrite);

	std::array<std::array<int, ROW>, COLUMN> dataArray;
	int num = 0;
	for (int row = 0; row < ROW; ++row) {
		for (int col = 0; col < COLUMN; ++col) {
			dataArray[row][col] = num;
			num = num + 1;
		}
	}
	gameDrawer->updataArray(dataArray);
	
	gameDrawer->close();
	pBtr->close();

}

void gameJig() {
	GameDrawer* myent = new GameDrawer();
	Gamejig* myjig = new Gamejig();
	myjig->startJig(myent);
}