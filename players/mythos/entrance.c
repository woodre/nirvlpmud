#include "/players/mythos/closed/guild/def.h"

inherit "room/room";

reset(arg)
{
  if(!arg)
  {
    set_no_clean(1);
    move_object(clone_object("/players/mythos/prac/vending"), this_object());
    set_light(1);
    short_desc = "Chamber of Realms";
    long_desc =
"  You have entered the Chamber of Realms where different lands\n\
converge.  The Chamber is softly lit by the wall of mist behind\n\
you.  The realms you may go to can be entered through glittering \n\
man-size gems.  You can 'look' into the gems to see where they lead.\n\n";
    items = ({
      "healing","The Mythical Chamber of Healing....",
      "healer", "Great Hall of Healing....",
	  "warp","A tear in time.... to multiple realms of Eurale",
/*
    "desert","A realm of heat and pain....",
*/
      "wall","A Great Wall of Mist.  It seems to pulse and a light streams \
from \nit.  You can 'pass' through it",
      "mist","The mist seems to swirl and 'glow'.\nYou peer beyond it, but \
you cannot see anything",
      "gems","Each gem is brilliantly cut and leads to another place.  \
Look at \nthe destinations",
      "gem","A beautiful gem.  Try looking at the destinations",
      "ancient","You peer into the gem and see a realm of the ancient orient",
      "library","You peer into the gem and see the hallway to The Great \n\
Library-where all knowledge is kept",
      "tokyo","You peer into the gem and you see a large airport teaming with \
people",
      "portal","Beyond you see a Black Chamber- Saber's portal to other realms",
      "detroit","The image of the city Detroit (Pathfinder's) appears within \
the gem. \nBeware it is not for the feint of heart",
      "snow","You see a realm of ice and cold- Snow's area",
      "crystal","You see a dark crystal- Arrina's area",
      "glow","Something swirls about...\nYou may want to reach out...",
      "forbin","The realms of Forbin await the bold adventurer",
  });

  dest_dir = ({
  "/players/guilds/healers/room/hall.c","healer",
    "/players/mythos/portal.c", "pass",
    "/players/mythos/reg.c","healing",
    "/players/mythos/aroom/path1.c", "ancient",
    "/players/mythos/lroom/hall.c","library",
    "/players/mythos/mroom/narita.c","tokyo",
    "/players/snow/gate.c","snow",
    "/players/saber/ryllian/portal.c","portal",
    "/room/south/sforst4", "forbin",
    "/players/pathfinder/detroit/rooms/entrance.c","detroit",
    "/room/plane3.c","crystal",
	 "/players/eurale/RMS/warp.c","warp",
/*
    "/players/mythos/droom/desert.c","desert",
*/

  });
} }

init() {
  ::init();
  add_action("keats","keats");
  add_action("portal","portal");
  add_action("naga","naga");
  add_action("hills","hills");
  add_action("test","test");
  add_action("reach","reach");
}

keats()
{
    write("The portal to the realm of Keats is currently closed.\n It will \
soon be back in it's new and improved version. Stay tuned.\n");
    return 1;
}

hills() {
this_player()->move_player("hills#players/mythos/closed/guild/task/hill/hills.c");
return 1;}

portal() {
  if(this_player()->query_spell_point() < 20)
     return (write("You don't have enough magical energy to enter the portal.\n"), 1); /* verte */
  call_other(this_player(), "add_spell_point", -20);
  call_other(this_player(),"move_player","portal#players/saber/ryllian/portal.c");
return 1; }

naga() {
  if(this_player()->query_real_name() == "servant") {
    move_object(clone_object("/players/mythos/prac/servant2.c"),this_player());
  write("done\n");
  return 1;
}
  if(this_player()->query_real_name() == "meshitsukai") {
    move_object(clone_object("/players/mythos/prac/servant2.c"),this_player());
  write("done");
  write("\n");
  return 1;}
  if(this_player()->query_real_name() == "priest") {
    move_object(clone_object("/players/mythos/closed/play/tells.c"), this_player());
  write("hehe..\n");
return 1;}
return 1; }


test() {
  if(this_player()->query_real_name() == "servant" ||
     this_player()->query_real_name() == "mythos" ||
     this_player()->query_real_name() == "meshitsukai" ||
     this_player()->query_real_name() == "priest") {
     move_object(this_player(),"/players/mythos/prac/test.c");
     return 1;}
}

reach(str) {
  if(!str) return 0;
  if(str != "out") return 0;
  if(!pp) { write("Something flashes and you feel a bit of pain.\n");
             tp->heal_self(-5);
           return 1;}
    write("You reach out and something flares!\n");
     pp->set_shatter(1);
     pp->save_dark();
     command("uu",tp);
     write("To use type <shatter>\n");
     write_file("/players/mythos/closed/guild/task_spell",
    ctime(time())+" "+(this_player())->query_real_name()+
    "  shatter\n");
return 1;}

/* removed
query_no_fight() { return 1; }
*/
