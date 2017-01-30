/*
 *      File:                   filename.c
 *      Function:               
 *      Author(s):              YourName@Nirvana
 *      Copyright:              Copyright (c) 2004 YourName
 *                                      All Rights Reserved.
 *      Source:                 05/24/2004
 *      Notes:                  
 *      Change History:
 */

#include "../defs.h"

inherit "/room/room.c";

/* Global Variables */
status Flag_Searched;

void reset(status arg)
{
  ::reset(arg);
  Flag_Searched = 0;
  
  if (arg)
  {
    return;
  }
    
  short_desc = YEL + "The Bottom of a Moat" + NORM;
  long_desc = "\
This is the bottom of a moat.  The water is murky but clear enough that one\n\
can see a fair distance.  To the east and west the waters are teaming with \n\
life - large shark-like forms dart here and there, and swarms of vicious-\n\
looking smaller fish meander about.  Here, however, there is nothing but the\n\
sparse vegetation - mostly weeds - dispersed about the rocky moat-bottom.\n\
Something is definitely out of place however.\n";
  dest_dir = ({ RPATH + "fields5", "surface" });
  items = ({
    "moat", "You're in it",
    "water", "It's murky but clear enough to see a ways in each direction",
    "east", "There's signs of life there",
    "life", "It abounds everywhere in the moat but here.  How strange",
    "forms", "They are off to the east and west but not here",
    "vegetation", "The vegetation is mainly just weeds and some brush",
    "brush", "Little bushes that live on the bottom of the moat",
    "weeds", "Real weeds, not the kind some might smoke",
    "fish", "Everywhere but here there seem to be fish",
    "bottom", "It definitely looks a bit odd",
    "moat-bottom", "Something is very strange about it...",
  });
  add_property("NT");
  add_property("no_teleport");
}

void init()
{
  ::init();
  add_action("on_search", "search");
  add_action("exit_surface", "surface");
  add_action("exit_enter", "enter");
}

status on_search(string arg)
{
  if (arg && arg != "bottom" && arg != "moat-bottom")
  {
    write("Perhaps you'd best search the bottom of the moat, or just do a general search.\n");
    return 1;
  }
  
  if ((int)this_player()->query_level() < 19)
  {
    write("Earwax's voice sounds inside your head, he says: \n");
    write("Perhaps you should wait until you're a little more experienced.\n");
    return 1;
  }
  
  if (Flag_Searched)
  {
    write("There is a tunnel here leading deeper into the moat.  You may 'enter' it.\n");
    return 1;
  }
  
  Flag_Searched = 1;
  write("As you move toward a particularly intriguing rock formation you sense movement...\n");
  call_out("attack_them", 2, this_player());
  return 1;
}
    
void attack_them(object ob)
{
  object squid;
  
  if (!ob) 
    return;
 
  while(remove_call_out("attack_them") != -1); 
  say(HIK+"Suddenly something bolts up from underneath the moat-bottom!\n"+NORM);  
  squid = clone_object(MPATH+"squid");
  move_object(squid, this_object());
  ob->attacked_by(squid);
  squid->attacked_by(ob);
  return;
}
  
status exit_surface(string arg)
{
  if (!present("moat-monster", this_object()))
    return 0;
    
  write(HIK+"The hideous giant squid would annihilate you if you turned your back!\n"+NORM);
  return 1;
}

status exit_enter(string arg)
{
  if(!Flag_Searched)
  {
    write("You don't see anything to enter here.\n");
    return 1;
  }
  
  if (present("moat_monster", this_object()))
  {
    write("The hideous giant squid is blocking the tunnel entrance.\n");
    return 1;
  }
  
  this_player()->move_player("into the tunnel#"+RPATH+"moat_cave");
  return 1;
}
  
/* This isn't working properly.
int query_property(string arg)
{
  if (arg != "no_teleport")
    return ::query_property(arg);

  write("For some reason you can't teleport from here.\n");
  write("Perhaps it has something to do with the fact that you're underwater.\n");
  return 1;
}
*/

















/* 
 * Function name:
 * Description:
 * Arguments:
 * Returns:
 */

 