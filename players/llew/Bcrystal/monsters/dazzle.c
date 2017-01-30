/* Dazzle object
   This stops actions in a room based on character will power.
*/

#pragma strict_types

#include "/players/llew/closed/ansi.h"

inherit "obj/clean";


int id(string str) 
{
   return str == "BC_dazzle" || str == "lights";
}

string short()
{
   return 0;   
}

void long()
{
   write("A display of dazzling lights.\n");
}

int get() { return 0; }

void init()
{
#ifndef __LDMUD__
   add_action("prevent"); add_xverb("");     
#else
   add_action("prevent", "", 3);     
#endif
}

int prevent()
{
   if (this_player() && this_player()->query_level() < 21)
   {
      int check;
      int check2;

      /* They may be able to push past if they make a int/wil check. */
      check = (int)(this_player()->query_attrib("cha") + this_player()->query_attrib("wil")) / 2;
      check2 = random(50) + 1;
      if (check < check2)
      {  
         write (BOLD + "\nThe lights blind and confuse you!\n\n" + NORM);
         return 1;
      }
   }
}

void set_length(int seconds)
{
  call_out("dest", ((seconds > 0) ? seconds : 1));
}

void dest()
{
   destruct(this_object());
}
