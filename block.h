#ifndef TETRIS_BLOCK_INCLUDED
#define TETRIS_BLOCK_INCLUDED

#include "Common.h"

class CTetrisBlock
{

public:
	void Create();
	void Draw();
	void Destroy();

	CTetrisBlock();
	virtual ~CTetrisBlock();

	int GetPosX();
	int GetPosY();

	void SetPosX(int x);
	void SetPosY(int y);

private:
	int m_iPosX
	int m_iPosY;

};

#endif
