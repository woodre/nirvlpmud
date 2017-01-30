#define tp this_player()->query_name()
#include <ansi.h>
inherit "obj/treasure";
reset(arg)
{   if (arg) return;

   set_id("portal");
   set_alias("boneportal");
   set_short("A bone portal with a dark, swirling mist inside");
   set_long("The portal's mist swirls about inside it, beckoning anyone to enter.\n"+
            "This is a doorway to the Necromancer's guild...\n"+
            "enter it to learn more about the guild...\n");
   set_weight(6000);
   set_value(0);
}

init()  {
  ::init();
  add_action("enter_portal","enter");
        }

enter_portal(str)  {
  if(str == "portal")  {
/* INSERTED SNOW 3/00 */
write("Sorry, this portal does not function at this time.\n"); return 1;
  write("You feel the energy of the dark portal flow into your body\n"+
        "as you enter the bone portal and move to a new location.\n");
  this_player()->move_player("through the bone portal#players/daranath/guild/room/newbie.c");
return 1;
        }
  write("What do you want to enter?\n");
return 1;
        }

get()  { return 0; }
