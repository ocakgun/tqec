#ifndef PLUMBINGPIECES_H_
#define PLUMBINGPIECES_H_

#include "numberandcoordinate.h"
#include "geometry.h"

#include <vector>
#include <string>
#include <map>

class plumbingpiece
{
public:
	convertcoordinate position;
	//BIT interpretation: EXIST, XAXIS, YAXIS, ZAXIS
	//0000, 1100, 1010, 1001,
	unsigned int primal;
	unsigned int dual;

	plumbingpiece();

	std::string toString();

	void setMask(bool isPrimal, unsigned int mask);
};


class plumbingpiecesgenerator
{
public:
	/**
	 * The map uses a serialised version of the segments as key for
	 * retrieving their index from the segments collection.
	 */
	std::map<std::string, long> plumbMap;

	std::vector<plumbingpiece> pieces;

	void generateFromGeometry(geometry& geom);

	int getPlumbingPieceIndex(convertcoordinate& coord);
};


#endif /* PLUMBINGPIECES_H_ */
