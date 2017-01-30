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
 * tokenize
 */

string tokenize(string str)
{
  string *tokens;
  string *values;
  string *t;
  int i, siz, code;
  object ob;

  ob = tp;
  if(!ob) ob = en;

  /* array of tokens we will replace */
  tokens = ({ "NAME" });

  /* values that we replace them with */
  values = ({ ob->query_real_name() });

  siz = sizeof(t = explode(str, "%"));

  for (i = 0; i < siz; i++)
  {
	if (i > 0 && t[(i - 1)] == "\\") /* Escape char */
		t[i] = "%";
	else
	{
		code = member_array(t[i], tokens);
		if (code > -1)
			t[i] = capitalize(values[code]);
	}
  }

  return (implode(t, ""));

}

/*
 * for backwards compatibility...
 */

string colorize(string str)
{
  return (string)COLOR_PARSER->parse_pcodes(str);
}

