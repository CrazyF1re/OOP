#pragma once
#include <iostream>
struct Point
{
	float x;
	float y;
};
class Straight
{
	float a, b, c;
	double eps = 0.0000005;
public:
		/*1*/Straight(float ax = 1, float by = 1, float C = 1);
		/*2*/void Print();
		/*2*/void Input();
		/*3*/bool check_start_cords();
		/*4*/void check_parallelism_axis();
		/*5*/void segments();
		/*6*/float coefficient();
		/*7*/bool check_similarity(Straight line2);
		/*8*/bool check_parallelism_two_lines(Straight line2);
		/*9*/bool check_perpendicularity(Straight line2);
		/*10*/float distance();
		/*11*/bool check_point(Point p);
		/*12*/float distance_to_point(Point p);
		/*13*/bool check_cross_two_lines(Straight line2);
		/*14*/Point cross_point(Straight line2);
		/*15*/double injection_between_lines(Straight line2);
		/*16*/void which_line_is_closer(Straight line2);
		/*17*/float distance_between_paralel_lines(Straight line2);
		/*18*/bool is_line_between_others(Straight line1, Straight line2);
};