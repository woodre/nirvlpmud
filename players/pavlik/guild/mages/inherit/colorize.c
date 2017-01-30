#include "/players/pavlik/guild/mages/defs.h"

/*
 * return a colorized string
 *  tokens wth $$<C> are replaced with the ansi color code
 */

string colorize(string str)
{
  int i;
  string c, n, t;
  string newStr;

  newStr = "";

  i = 0;
  while(i < strlen(str))
  {
	n = "";

	if(str[i..i] == "$" && str[(i+1)..(i+1)] == "$")
	{
		c = str[(i+2)..(i+2)];
		switch(c)
		{
			case "r" : n = RED; break;	/* red */
			case "R" : n = HIR; break;	/* hi-Red */
			case "g" : n = GRN; break;	/* green */
			case "G" : n = HIG; break;	/* hi-Green */
			case "y" : n = YEL; break;	/* yellow */
			case "Y" : n = HIY; break;	/* hi-Yellow */
			case "b" : n = BLU; break;	/* blue */
			case "B" : n = HIB; break;	/* hi-Blue */
			case "m" : n = MAG; break;	/* magenta */
			case "M" : n = HIM; break;	/* hi-Magenta */
			case "c" : n = CYN; break;	/* cyn */
			case "C" : n = HIC; break;	/* hi-Cyan */
			case "W" : n = HIW; break;	/* hi-White */
			case "K" : n = HIK; break;	/* hi-Black */
			case "N" : n = NORM; break;	/* normal */
		}

	}

	if(n != "")
	{
		newStr += n;
		i += 3;
	}
	else
	{
		newStr += str[i..i];
		i++;
	}
  }

  if(newStr != str)
	newStr += NORM;

  return newStr;

}

