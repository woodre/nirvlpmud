/*  RUSTKEY.C - Key carried by monster TRAINER.C in room PANTRY.C of
    Delnoch Keep.  This key will be used to open the door to the 
    halfling pens.  The door will be in room COURTYD2.C of Delnoch
    keep.  Door and halfling pens not yet coded.
    Changes as of 5-31-96:
    Color added
*/
#include "/players/traff/closed/ansi.h"
#define tp this_player()->qury_name()
inherit "obj/treasure";
reset(arg) {   
  if (arg) return;
  set_id("key");
  set_alias("rusty key");
  set_short("A small "+YEL+"rusty"+NORM+" key");
  set_long(HIY+
    "A small rusty key .\n"+
    "You can "+WHT+BOLD+"<unlock>"+HIY+" something with it.\n"+NORM);
  set_weight(0);
  set_value(1);
}

init()  {
  ::init();
  add_action("unlock_door","unlock");
        }

unlock_door(str)  {
  if(str == "door")  {
  if(!present("iron door",environment(this_player())))  {
  write("Your key doesn't seem to work on this door.\n");
  say(tp+" tries to unlock the door but fails...\n");
  return 1;
        }
        }
        }
