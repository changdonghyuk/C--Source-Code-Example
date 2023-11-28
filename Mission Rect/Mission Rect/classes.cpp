#include "classes.h"
#define MIN(x,y) (((x)<(y))? (x):(y))
#define MAX(x,y) (((x)>(y))? (x):(y))
#define	ABS(x)	(((x)<0)?(-(x)):(x))

double Point::Dist(Point p)
{
	int w = x - p.x;
	int h = y - p.y;
	return sqrt(w * w + h * h);
}
void Point::Show(const char* s)
{
	printf("%s(%d,%d)\n", s, x, y);
}
void Point::ShowEx(const char* s)
{
	std::cout << s << "(" << x << "," << y << ")";
}
Point& Point::operator+(Point p)  // 두점 CurP와 p의 + 연산결과를 (새로운 Point로) 반환
{
	p1 = (new Point(x + p.x, y + p.y));
	return *p1;
}

Rect &Rect::Show(const char* s)  // RECT(P1(x1,y1), P2(x2,y2))
{
	printf("%s(", s);
	LL.ShowEx("LL");
	UR.ShowEx("UR");
	printf(")\n");
	return *this;
}

double Rect::Area()
{
	return (double)(ABS(p1.x - p2.x) * (p1.x - p2.y));

}
Rect& Rect :: operator+(Rect r)
{
	int xx1 = MIN(MIN(this->x1, this->x2), MIN(r.x1, r.x2));  // this ( 왼쪽) , LL (오른쪽)
	int xx2 = MAX(MAX(this->x1, this->x2), MAX(r.x1, r.x2));

	int yy1 = MIN(MIN(this->y1, this->y2), MIN(r.y1, r.y2));
	int yy2 = MAX(MAX(this->y1, this->y2), MAX(r.y1, r.y2));
	
	return *(new Rect(xx1, xx1, yy2, yy2));
}

Rect& Rect::operator-(Rect r)
{
	int x1, x2, x3, x4;
	int y1, y2, y3, y4;
	Rect& rr = *this;

	// == 겹치지 않기 위한 조건식 , 겹치지않는 경우 0  Rect 반환
	if (rr.LR.x<r.LL.x || rr.LR.x>r.LL.x ||rr.UL.y<r.LL.y || rr.LL.y>r.UL.y)
	return *(new Rect(0, 0, 0, 0)); // if  를 하면 왜 0 0 0 0 ?
	x1 = MIN(MIN(rr.x1, r.x2), MIN(r.x1, r.x2));
	x2 = MAX(rr.LL.x, r.LL.x);
	x3 = MIN(rr.LR.x, r.LR.x);
	x4 = MAX(MAX(rr.x1, rr.x2), MAX(r.x1, r.x2));

	y2 = MIN(rr.UL.y, r.UL.y);
	y3 = MAX(rr.LL.y, r.LL.y);
	y4 = MAX(MAX(rr.y1, rr.y2), MAX(r.y1, r.y2));
	
	return *(new Rect(x2, y2, x3, y3));
	y1 = MIN(MIN(rr.y1, r.y2), MIN(r.y1, r.y2));
}

double Rect :: operator*(Rect r)
{
	double d1 = Area();
	double d2 = r.Area();
	double d3 = (*(this) - r).Area();
	return d1 + d2 - d3;
}


