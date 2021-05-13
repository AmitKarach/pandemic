#pragma once
#include "City.hpp"
namespace pandemic
{
	enum Color
	{
		Yellow,
		Red,
		Blue,
		Black
	};

	inline std::string color_to_string(Color c)
	{

		if (c == Yellow)
		{
			return "Yellow";
		}
		if (c == Red)
		{
			return "Red";
		}
		if (c == Blue)
		{
			return "Blue";
		}
		else
		{
			return "Black";
		}
	}
}