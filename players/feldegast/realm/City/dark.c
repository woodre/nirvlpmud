/*
File: dark.c
Author: Feldegast
Date: 04/09/02
Description:
  The dark cathedral
*/

#include "defs.h"

inherit ROOM;

int flag;
int block;

reset(arg) 
{

  if (arg) return;
  no_clean=1;
  set_light(1);
  short_desc=BOLD+BLK+"Dark Cathedral"+NORM;
/********************************************************************/
  long_desc=
"  This cathedral has been abandoned for many decades.  It's many\n\
furnishings have become moth-eaten and tarnished.  Strangely, it has\n\
not been looted by impious thieves.  This place has an unholy feel\n\
to it that restrains casual ingress.  In the middle of the cathedral\n\
is an altar.\n";
  items=({
    "cathedral", "reflexive",
    "furnishings", "The furnishings have been ravaged by time and are now worthless",
    "thieves", "They are not here",
    "altar", "There is an altar in the middle of the cathedral.  There is a clear\n"+
             "space on it, as though it were waiting for somebody to place something\n"+
             "on it",
  });
  dest_dir=({
    PATH+"amber2.c", "out",
  });
}   

void init()
{
  ::init();
  add_action("cmd_place", "place");
  add_action("cmd_out", "out");
}

int cmd_place(string str)
{
  object symbol;
  string junk;
  if(sscanf(str, "%s on altar",junk) != 1)
  {
    notify_fail("Place what on altar?\n");
    return 0;
  }

  symbol = present("holy symbol of the maiden", TP);

  if(!symbol)
  {
    write("You cannot place that on the altar.\n");
    return 1;
  }

  if(!flag)
  {
    write(BOLD+"As you step towards the altar, a dark figure steps out of the shadows!\n"+NORM);
    say(BOLD+"A dark figure steps out of the shadow!\n"+NORM);
    move_object(clone_object(MON_PATH+"darkangel.c"), this_object());
    flag = 1;
    return 1;
  }

  if(present("dark angel"))
  {
    write("You cannot approach the altar while the dark figure guards it.\n");
    return 1;
  }

  write("You place the "+(string)symbol->short()+" on the altar.\n");
  say(TPN+" places the "+(string)symbol->short()+" on the altar.\n");
  write("You have restored the Maiden's Cathedral.\n"+
        "Congratulations!  You have completed this quest.\n");
  TP->add_weight(-((int)symbol->query_weight()));
  destruct(symbol);
  /* Maybe put a reward in here somewhere?  Sfx?  Something interesting?
  TP->set_quest("maiden_cathedral");
  */
  long_desc=
    "  This cathedral appears pristine.  Its white marble shines as though it\n"+
    "had just been cleaned just a moment before you laid eyes upon it.  In the\n"+
    "center of the cathedral is an altar with a golden symbol on it, shining\n"+
    "in the mid-morning light streaking through the stained glass windows.\n";
  return 1;
}

int cmd_out(string str)
{
  if(block)
  {
    write(BOLD+BLK+"A wall of darkfire blocks the way out.\n"+NORM);
    return 1;
  }
}

realm() { if(block) return "NT"; }

long(str) 
{
  ::long(str);
  if(block)
    write(BOLD+BLK+"A darkfire field prevents all escape.\n"+NORM);
}  

void set_field(int x)
{
  if(x && !block)
    tell_room(this_object(), BOLD+BLK+"A darkfire field rises up around the cathedral.\n"+NORM);
  block = x;
  if(block)
  {
    remove_call_out("set_field");
    call_out("set_field", 10+random(20), 0);
  }
  else
    tell_room(this_object(), "The darkfire field fades.\n");
}
