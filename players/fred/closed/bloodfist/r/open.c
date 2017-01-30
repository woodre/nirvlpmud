inherit "room/room";
#include "/players/zeus/closed/ansi.h"
#include "/players/fred/closed/bloodfist/defs.h"
int torch;
object merch;
#include "/players/fred/closed/bloodfist/r/torches.h"

reset(arg){
	if(arg) return;

  if(!present("merchant"))
  {
    merch = clone_object(DIR+"NPC/merchant.c");
    move_object(merch, this_object());
  }

  torch = 1;
  set_light(1);
  set_no_clean(1);

  add_property("no_teleport");

  items =({
    "rock",
      "The flat rock face of the mountain is punctuated by small grooves\n"+
      "which lead up into the darkness",
    "grooves",
      "The grooves act as a sort of ladder that leads up into the darkness.\n"+
      "There is no way to tell what they lead to.  It looks dangerous in\n"+
      "part due to the strong winds that are blowing over the encampment",
    "torches",
      "The torches are mounted on the stone walls of the arena",
    "sky",
      "The sky is a shroud of darkness and swirling sand",
    "ground",
      "The ground is destolate, cracked and broken",
    "sand",
      "The ground is caked with a layer of dry sand",
    "mountain",
      "The encampment is built around some mountains of rock that jut\n"+
      "out of the earth at almost as sharp an angle as the walls of the\n"+
      "encampment itself",
    "mountains",
      "The encampment is built around some mountains of rock that jut\n"+
      "out of the earth at almost as sharp an angle as the walls of the\n"+
      "encampment itself",
    "tables",
      "Tables are visible to the south",
    "chairs",
      "Chairs are visible to the south",
    "horizon",
      "The mountains make up the horizon, which is constantly shrouded\n"+
      "by the sands whipping through the air",
  });

  dest_dir=({
    DIR + "r/meeting.c",        "north",
    DIR + "r/hall.c",           "south",
    DIR + "r/armory.c",         "west",
  });
}

short(){ return "An encampment in the desert"; }

long(str){
  if(torch)
    long_desc =
"  This area of the encampment is generally open.  To the north an opening\n"+
"leads into the base of the rock.  The mountain climbs high into the sky,\n"+
"and wraps around the outside of the encampment to the east.  To the south\n"+
"a few chairs and tables are visible, scattered across the sand.  Pieces\n"+
"of equipment from the armory are visible to the west.  There are some\n"+
"lit torches mounted on the exterior of the encampment.  Overhead the sky\n"+
"is a mass of darkness.\n";
  else
    long_desc = 
"  This area of the encampment is generally open.  To the north an opening\n"+
"leads into the base of the rock.  The mountain climbs high into the sky,\n"+
"and wraps around the outside of the encampment to the east.  To the south\n"+
"a few chairs and tables are visible, scattered across the sand.  Pieces\n"+
"of equipment from the armory are visible to the west.  There are some\n"+
"extinguished torches mounted on the exterior of the encampment.  Overhead\n"+
"the sky is a mass of darkness.\n";
  ::long(str);
}

void init(){
  ::init();
  add_action("extinguish", "extinguish");
  add_action("light", "light");
  add_action("climb", "up");
}

status climb()
{
  this_player()->move_player("up#"+DIR+"r/mountain1.c");
  return 1;
}
