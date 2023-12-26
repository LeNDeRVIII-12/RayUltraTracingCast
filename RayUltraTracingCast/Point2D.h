#pragma once

struct Point2D
{
	double x;
	double y;

	Point2D() = default;
	Point2D(double x, double y) : x(x), y(y) {}

	Point2D operator+(const Point2D& point2D) const;
	Point2D operator-(const Point2D& point2D) const;

	Point2D operator*(double number) const;
	Point2D operator/(double number) const;

	Point2D& operator=(Point2D& point2D);

	Point2D& operator+=(const Point2D& point2D);
	Point2D& operator-=(const Point2D& point2D);
	Point2D& operator*=(double number);
	Point2D& operator/=(double number);

	bool operator==(const Point2D& point2D);
	bool operator!=(const Point2D& point2D);
	bool operator<(const Point2D& point2D) const;

	double operator*(const Point2D& point2D);
	double cross(const Point2D& point2D) const;
	static double dot(const Point2D& a, const Point2D& b);
	static double cross(const Point2D& a, const Point2D& b);

	Point2D normalize() const;
	double sqrAbs() const;
	double abs() const;
	double getAngle(const Point2D& b) const;
};