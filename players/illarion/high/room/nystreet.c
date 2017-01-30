inherit "room/room";
#include "/players/illarion/dfns.h"

reset(arg) {
  if(!present("mugger",this_object()))
    move_object(clone_object(HMON+"mugger"),this_object());
  if(arg) return;

  set_light(1);
  short_desc="A New York City street";
  long_desc=
"You have located a street through the City of New York, and a\n"+
"none too good street at that.  A look at the boarded windows and the\n"+
"garbage makes you imagine any number of reasons you might want to know\n"+
"how to protect yourself just a little bit better.  The building directly\n"+
"south of you makes you think you might be in luck, as the sign on the\n"+
"front reads: \"DeSalvo's Dojo\".  A stoop in front of the building allows\n"+
"access into the dojo.  Out in front of the dojo stands an oddly familiar\n"+
"telephone booth.\n";

  items= ({
  "street","Asphault, trash, and despair.  It's not a pretty sight",
  "city","The Big Apple is pretty rotten in this part of town",
  "windows","Boarded up against theft and because glass is always broken",
  "garbage","Waste, generally smelly, and usally not that interesting",
  "building","It looks delapidated, but still solid.  Maybe its\n"+
             "condition is a front",
  "sign","The sign is old, but still easily readable",
  "dojo","Nothing on the outside indicates this place has anything to do\n"+
         "with martial arts",
  "stoop","Concrete, with an iron railing, and stairs down one side",
  "booth","A metal and glass phone booth, probably quite dirty on the\n"+
          "inside, matching the appearance of the rest of the street.  The\n"+
          "door is ajar, making a simple matter to "+BLD("enter")+" the booth",
  });
  dest_dir= ({
    HROOM2+"nystreet","east",
    HROOM+"nystreet2","west",
    HROOM+"halle","dojo",
  });
}
void init() {
  ::init();
  add_action("cmd_enter","enter");
  add_action("stop_dir","east");
}
cmd_enter(str) {
  if(!str || str != "booth")
    { notify_fail("Enter what?\n"); return 0;}
  write("You enter the phone booth.\n");
  TP->move_player("into the phone booth#"+HROOM+"nybooth");
  return 1;
}
stop_dir() {
  if(TP->query_level()>20) {
    write(
"As you walk down the street to the east, an odd rippling effect spreads\n"+
"across your vision, as if you were looking at a pool of water someone just\n"+
"threw a stone into.  When the rippling subsides, you find yourself on a\n"+
"different street.\n");
    return 0;
  }
  write("You start down the street, but something tells you there's\n"+
        "nothing to see down there.\n");
  return 1;
}
