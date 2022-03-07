#pragma once

#ifndef _POINT_H
#define _POINT_H
typedef struct _point {
	int no;
	char name[10];
	double score;
}Point;
void SetPoint(Point* ppos, int no, char* name, double score);
void ShowPoint(Point* ppos);
#endif