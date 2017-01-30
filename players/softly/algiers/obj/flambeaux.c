#include "/players/softly/closed/define.h"
#include "/players/softly/closed/ansi.h"
inherit "obj/treasure";

int lit;

reset(arg)
{
  if (arg) return;

  set_id("flambeaux");
  set_short("Flambeaux, a magical flame");
  set_alias("flame");
  set_long("\nA tall enchanted torch atop a wooden standard.\n\
You can light or douse the flame.\n");
  set_weight(1);
  set_value(250);
  set_light(0);
}

init()
{  
  add_action("cmd_light", "light");
  add_action("cmd_douse","douse");  
}

cmd_light(str)  
{
  if(!str) return 0;
  if(!str == "flame") 
    {
      notify_fail("\
What do you want to light?\n");
      return 0;
    }
  {
    if(lit == 1)
      {
      write("The flambeaux already lights your way.\n"); return;
      }
    write("\nThe flambeaux blazes brightly.\n");
    say(this_player()->query_name() + " lights the flambeaux.\n");
    set_light(1);
    lit = 1;
    return 1;   
  }
}

cmd_douse(str) 
{
  if(!str) return 0;
  if(!str == "flame") 
    {
      notify_fail("\
What do you want to douse?\n");
      return 0;
    }
  {
    if(lit == 0) 
      {
	write("You must light the flambeaux first.\n"); 
	return 1; 
      }
    write("The flambeax is doused.  You are bathed in darkness.\n");
    say(this_player()->query_name()+ " douses the flambeaux.\n");
    set_light(-1);
    lit = 0;
    return 1;
  }
}

