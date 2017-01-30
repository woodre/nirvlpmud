#include "../x.h"

inherit N_EFUN;

int cmd_vision(string str)
{
 string ansi_str;
 if(!str)
 {
  string x;
  if(x = (string)PO->query_glowing_eyes())
  {
   write("Your eyes stop glowing "+(ansi_str=str_to_ansi(x))+x+NORM+".\n");
   say((string)TP->QN+
    "'s glowing "+ansi_str+x+NORM+" eyes flicker and fade.\n");
   PO->set_glowing_eyes(0);
   return 1;
  }
  else
  {
   notify_fail("Usage: 'vision <color>'\n"+
               "Type 'nhelp vision' for a list of colors.\n");
   return 0;
  }
 }
 if(str == "off" || str == "normal")
  return cmd_vision(0);
 if(!(ansi_str = str_to_ansi(str)))
 {
  write("That is not a valid color.\n"+
        "Type 'nhelp vision' for a list of colors.\n");
  return 1;
 }
 else
 {
  string y;
  write("Your eyes flicker and glow "+(y=a_or_an(str))+" "+ansi_str+str+NORM+" color.\n");
  say((string)TP->QN+"'s eyes begin to glow "+y+" "+ansi_str+str+NORM+" color.\n");
  PO->set_glowing_eyes(str);
  return 1;
 }
}
