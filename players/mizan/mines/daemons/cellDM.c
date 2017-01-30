#include "../definitions.h"
#include "/obj/ansi.h"

string *numbers;

int get() { return 0; }
short() { return "A server named (cell)"; }
id(string str) { return str == "cell" || str == "server"; }

void reset(int arg)
{
	move_object(this_object(), DAEMON_HOME);
	if(arg) return;

}

string *get_test_array()
{
	return ({ "one", "two", "three", });
}


string convert_dir(string str) 
{
	switch(str) 
	{
		case "n": return "north";
		case "e": return "east";
		case "s": return "south";
		case "w": return "west";
		case "sw": return "southwest";
		case "se": return "southeast";
		case "nw": return "northwest";
		case "ne": return "northeast";
		case "d": return "down";
		case "u": return "up";
	}
	return str;
}

string translate_exit(string fullDirection)
{
	switch(fullDirection)
	{
		case "north":     return "n";
		case "south":     return "s";
		case "east":      return "e";
		case "west":      return "w";
		case "northeast": return "ne";
		case "northwest": return "nw";
		case "southeast": return "se";
		case "southwest": return "sw";
		case "up":        return "u";
		case "down":      return "d";
		default:          return fullDirection;
	}
}


string convert_number(int inputNum)
{
	if(!pointerp(numbers))
		numbers = (string*)this_object()->query_numbers();
	if (inputNum > 9)
		return "lot of";
	return numbers[inputNum];
}


string *query_numbers()
{
	if(!numbers)
		numbers = ({"no", "one", "two", "three", "four", "five",
			    "six", "seven", "eight", "nine" });
	return numbers;
}


