/*    Statis field 
      The statis field blocks exits in a room it is in.
*/
#pragma strict_types

#include "/players/llew/closed/ansi.h"

inherit "obj/clean";


int id(string str) 
{
   return str == "field" || str == "stasis field" || str == "BC_stasisfield";
}

string short()
{
   return HIC + "Statis " + HIG + "Field" + NORM;   
}

void long()
{
   write("A pulsating field that seems to block all exit from the room.\n");
}

int get() { return 0; }

void init()
{
   add_action("prevent","north");
   add_action("prevent","south");
   add_action("prevent","east");
   add_action("prevent","west");
   add_action("prevent","northeast");
   add_action("prevent","northwest");
   add_action("prevent","southeast");
   add_action("prevent","southwest");      
}

int prevent()
{
   if (this_player() && this_player()->query_level() < 21
       && member_array(query_verb(), (string *)environment()->query_dest_dir()) > -1)
   {
      int check;
      int check2;

      /* They may be able to push past if they make a int/wil check. */
      check = (int)(this_player()->query_attrib("int") + this_player()->query_attrib("wil")) / 2;
      check2 = random(50) + 1;
      if (check < check2)
      {  
         write ("You're unable to push through the " + short() + "!\n");
         write ("The " + short() + " hits you with mental backlash!\n");
         this_player()->hit_player(check2 - check, "other|mental");
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

string query_name() { return short(); }