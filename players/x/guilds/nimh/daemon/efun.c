#include "../x.h"

status is_vowel(string letter)
{
 return (member_array(letter, ({"a","e","i","o","u"})) > -1);
}

string a_or_an(string word)
{
 return (is_vowel(word[0..0]) ? "an" : "a");
}

string gen_lo_color()
{
 switch(random(6))
 {
  case 0:
   return RED;
  case 1:
   return GRN;
  case 2:
   return YEL;
  case 3:
   return BLU;
  case 4:
   return MAG;
  case 5:
   return CYN;
 }
}

string gen_hi_color()
{
 switch(random(6))
 {
  case 0:
   return HIR;
  case 1:
   return HIG;
  case 2:
   return HIY;
  case 3:
   return HIB;
  case 4:
   return HIM;
  case 5:
   return HIC;
 }
}

string ansi_to_str(string str)
{
 switch(str)
 {
  case BLK: return "black";
  case RED: return "red";
  case GRN: return "green";
  case YEL: return "yellow";
  case BLU: return "blue";
  case MAG: return "magenta";
  case CYN: return "cyan";
  case WHT: return "white";
  case HIK: return "intense black";
  case HIR: return "intense red";
  case HIG: return "intense green";
  case HIY: return "intense yellow";
  case HIB: return "intense blue";
  case HIM: return "intense magenta";
  case HIC: return "intense cyan";
  case HIW: return "intense white";
  default:  return 0;
 }
}

string str_to_ansi(string str)
{
 switch(str)
 {
  case "black":     return BLK;
  case "red":       return RED;
  case "green":     return GRN;
  case "yellow":    return YEL;
  case "blue":      return BLU;
  case "magenta":   return MAG;
  case "cyan":      return CYN;
  case "white":     return WHT;
  case "intense black":  return HIK;
  case "intense red":    return HIR;
  case "intense green":  return HIG;
  case "intense yellow": return HIY;
  case "intense blue":   return HIB;
  case "intense magenta":return HIM;
  case "intense cyan":   return HIC;
  case "intense white":  return HIW;
  default: return 0;
 }
}

status is_hi_ansi(string str)
{
 return sscanf(str, ESC+"[1;%s");
}

string reverse_exit(string str)
{
 str = (string)TO->shorten_exit(str);
 switch(str)
 {
  case "n":
   return "s";
  case "e":
   return "w";
  case "s":
   return "n";
  case "w":
   return "e";
  case "ne":
   return "sw";
  case "nw":
   return "se";
  case "se":
   return "nw";
  case "sw":
   return "ne";
  case "u":
   return "d";
  case "d":
   return "u";
  default:
   return 0;
 }
}

string shorten_exit(string str)
{
 switch(str)
 {
  case "east":
   return "e";
  case "west":
   return "w";
  case "north":
   return "n";
  case "south":
   return "s";
  case "northeast":
   return "ne";
  case "northwest":
   return "nw";
  case "southeast":
   return "se";
  case "southwest":
   return "sw";
  case "up":
   return "u";
  case "down":
   return "d";
  default:
   return str;
 }
}

string elongate_exit(string str)
{
 switch(str)
 {
  case "e":
   return "east";
  case "w":
   return "west";
  case "n":
   return "north";
  case "s":
   return "south";
  case "ne":
   return "northeast";
  case "nw":
   return "northwest";
  case "se":
   return "southeast";
  case "sw":
   return "southwest";
  case "u":
   return "up";
  case "d":
   return "down";
  default:
   return str;
 }
}
