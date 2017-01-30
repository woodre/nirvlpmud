#include "/players/vertebraker/ansi.h"

mixed replace_ansi(string str)
{
   string x;
   if(str == "H") x = BOLD;
   if(str == "K") x = BLK;
   if(str == "R") x = RED;
   if(str == "Y") x = YEL;
   if(str == "B") x = BLU;
   if(str == "G") x = GRN;
   if(str == "C") x = CYN;
   if(str == "W") x = WHT;
   if(str == "M") x = MAG;
   if(str == "N") x = NORM;
   return x;
}

mixed filter_msg(string str)
{
   int x; string *words; string tmp;
   words = explode(str,"$");
   for(x=0;x<sizeof(words);x++)
   if(replace_ansi(words[x])) words[x] = replace_ansi(words[x]);
   str = (implode(words,""))+NORM;
   return str;
}
