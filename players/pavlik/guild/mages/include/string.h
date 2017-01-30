#include "/players/pavlik/guild/mages/defs.h"

/*
 * returns a string padded to specified lenght with specified char
 */
string strpad(mixed str, string padchar, int padlength)
{
  int x;

  if(stringp(str))
	x = strlen(str);
  else if(intp(str))
  {
	if(str > 999) x = 4;
	else if(str > 99) x = 3;
	else if(str > 9) x = 2;
	else if(str < -999) x = 5;
	else if(str < -99) x = 4;
	else if(str < -9) x = 3;
	else if(str < 0) x = 2;
	else x = 1;
  }
  else
	return "";

  if(padlength > 0)
	x = padlength - x;
  else if(padlength < 0)
	x = (padlength * -1) - x;

  if(x > 120)	x = 120;
  if(x <= 0)	return str;

  while(x--)
  {
	if(padlength > 0)
		str = str + padchar;
	else
		str = padchar + str;
  }

  return str;
}


/*
 * string alignment
 */
align_str(str, num)
{
  int len, x;
  string msg;
  sscanf(str, "%s", msg);
  len = num - strlen(str);
  if(len < 1) return msg+" ";
  for(x=0;x<len;x++) msg = msg+" ";
  return msg;
}


rancol(str)
{
  string msg, letr;
  int i, x;

  msg = "";
  for(i=0;i<strlen(str);i++){
    letr = extract(str,i,i);
    x = random(7);
    if(x == 0) letr = HIR+letr; else
    if(x == 1) letr = HIG+letr; else
    if(x == 2) letr = HIY+letr; else
    if(x == 3) letr = HIB+letr; else
    if(x == 4) letr = HIM+letr; else
    if(x == 5) letr = HIC+letr; else
    letr = HIW+letr;
    msg = msg + letr;
  }
  msg = msg+NORM;
  return msg;
}


rancol2(str)
{
  string msg;
  int x;
  x = random(7);
  if(x == 0) msg = HIR+str+NORM; else
  if(x == 1) msg = HIG+str+NORM; else
  if(x == 2) msg = HIY+str+NORM; else
  if(x == 3) msg = HIB+str+NORM; else
  if(x == 4) msg = HIM+str+NORM; else
  if(x == 5) msg = HIC+str+NORM; else
  msg = HIW+str+NORM;
  return msg;
}


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

