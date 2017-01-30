#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */

string
colourcode(string arg)
{
  switch (arg)
  {
    case "black"  : return BLACK;
    case "red"    : return RED;
    case "green"  : return GREEN;
    case "yellow" : return YELLOW;
    case "blue"   : return BLUE;
    case "magenta": return MAGENTA;
    case "cyan"   : return CYAN;
    case "white"  : return WHITE;
  }
}

string
modifiercode(string arg)
{
  switch (arg)
  {
    case "bold": return BOLD;
  }
}
    
string
makeansi(string arg)
{
  string tmp, rest, mod;
  string modifier, colour;
  
  if (sscanf(arg, "%s %s", mod, rest) < 2)
  {
    if (!(colour = colourcode(arg)) &&
      !(modifier = modifiercode(arg)))
    {
      write("Unrecognized token '" + arg + "'.\n");
    }
  }
  else
  {
    if (!(modifier = modifiercode(mod)))
    {
      write("Unrecognized token '" + arg + "'.\n");
    }
    if (!(colour = colourcode(rest)))
    {
      write("Unrecognized colour '" + arg + "'.\n");
    }
  }
  if (modifier)
  {
    tmp = ESC + modifier;
    if (colour)
    {
      tmp += ";" + FOREGROUND + colour;
    }
  }
  else tmp = ESC + FOREGROUND + colour;
  if (tmp) tmp += "m";
  return tmp;
}
