#include "rect.h"

Rect::Rect() {
	Clear();
}

Rect::Rect(int x, int y, int w, int h) {
	SetRect(x, y, w, h);
}

void Rect::Clear() {
	SetRect(0, 0, 0, 0);
}

std::string Rect::ToString() {
	std::string res = "(";
	res += std::to_string(x);
	res += ", ";
	res += std::to_string(y);
	res += ", ";
	res += std::to_string(w);
	res += ", ";
	res += std::to_string(h);
	res += ")";
	return res;
}

bool Rect::Intersects(Rect* rect) {
	int leftA = x;
	int rightA = x + w;
	int topA = y;
	int bottomA = y + h;

	int leftB = rect->x;
	int rightB = rect->x + rect->w;
	int topB = rect->y;
	int bottomB = rect->y + rect->h;

	if (bottomA <= topB) return false;
	if (topA >= bottomB) return false;
	if (rightA <= leftB) return false;
	if (leftA >= rightB) return false;

	return true;
}

// bool Rect::Intersects(int x, int y, int w, int h) {
// 	return Intersects(&CreateRect(x, y, w, h));
// }

bool Rect::Contains(Rect* rect) {
	return (rect->x >= x && rect->Right() <= (x + w) && rect->y >= y && rect->Bottom() <= (y + h));
}

bool Rect::Contains(Vec2<int>* point) {
	return (point->x >= x && point->x <= (x + w) && point->y >= y && point->y <= (y + h));
}

bool Rect::Contains(int x, int y, int w, int h) {
	Rect tempRect(x, y, w, h);
	return Contains(&tempRect);
}

Vec2<int>* Rect::Position() {
	Vec2<int>* res = new Vec2<int>(x, y);
	return res;
}

Vec2<int>* Rect::Center() {
	Vec2<int>* res = new Vec2<int>(x + (w / 2), y + (h / 2));
	return res;
}

int Rect::CenterX() {
	return (x + (w / 2));
}

int Rect::CenterY() {
	return (y + (h / 2));
}

int Rect::Left() {
	return x;
}

int Rect::Right() {
	return (x + w);
}

int Rect::Top() {
	return y;
}

int Rect::Bottom() {
	return y + h;
}

int Rect::Perimiter() {
	return (w + w + h + h);
}

int Rect::Area() {
	return (w + h);
}

int Rect::GetX() {
	return x;
}

int Rect::GetY() {
	return y;
}

int Rect::GetW() {
	return w;
}

int Rect::GetH() {
	return h;
}

void Rect::SetRect(int x, int y, int w, int h) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}

void Rect::SetSize(Vec2<int>* size) {
	this->x = size->x;
	this->y = size->y;
}

void Rect::SetPos(Vec2<int>* pos) {
	this->w = pos->x;
	this->h = pos->y;
}

void Rect::Translate(Vec2<int>* offset) {
	this->x += offset->x;
	this->y += offset->y;
}

void Rect::TranslateX(int x) {
	this->x += x;
}

void Rect::TranslateY(int y) {
	this->y += y;
}

Rect::~Rect() {
}
