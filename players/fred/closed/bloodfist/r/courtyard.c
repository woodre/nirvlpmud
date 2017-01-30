inherit "room/room";
#include "/players/zeus/closed/ansi.h"
#include "/players/fred/closed/bloodfist/defs.h"
int torch, num;
object ob, obj;
#include "/players/fred/closed/bloodfist/r/torches.h"

reset(arg){
	if(arg) return;

  if(!present("bloodfist guard"))
  {
    obj = clone_object("/players/fred/closed/bloodfist/NPC/guard1.c");
    move_object(obj, this_object());
  }

  torch = 1;
  set_light(1);
  set_no_clean(1);
  num = 2;
  call_out("check", 30+random(60));

  add_property("no_teleport");

  items =({
    "torches",
      "The torches are mounted on the stone walls of the arena",
    "walls",
      "The stone walls of the encampment are visible in all directions\n"+
      "from the courtyward.  The walls of the arena are also visible\n"+
      "through the sandy wind to the north",
    "sky",
      "The sky is a shroud of darkness and swirling sand",
    "ground",
      "The ground is destolate, cracked and broken",
    "sand",
      "The ground is caked with a layer of dry sand",
    "mountains",
      "The encampment is built around some mountains of rock that jut\n"+
      "out of the earth at almost as sharp an angle as the walls of the\n"+
      "encampment itself",
    "well",
      "A well is visible to the west",
    "tables",
      "Tables are visible to the east",
    "chairs",
      "Chairs are visible to the east",
    "horizon",
      "The mountains make up the horizon, which is constantly shrouded\n"+
      "by the sands whipping through the air",
    "arch",
      "To the south two large doors can be seen below an arch which\n"+
      "the outer wall of the encampment",
    "doors",
      "The door are at least fifteen feet tall and lead out of the encampment",
  });

  dest_dir=({
    DIR + "r/armory.c",       "north",
    DIR + "r/hall.c",         "east",
    DIR + "r/entrance_in.c",  "south",
    DIR + "r/well.c",         "west",
  });
}

short(){ return "An encampment in the desert"; }

long(str){
  if(torch)
    long_desc =
"  This open expanse of dirt within the encampment is the primary courtyard.\n"+
"To the north the walls of the arena are visible.  Beyond the arena a vast\n"+
"expanse of mountains make up the what is visible of the horizon through\n"+
"the whipping winds.  The sky above is a haze of darkness.  The light in\n"+
"the encampment is coming from torches that are scattered about the area.\n"+
"To the west an old well is visible, and to the east numerous tables and\n"+
"chairs are scatted about.  To the south the arch of the entrance of the\n"+
"encampment can be seen.\n";
  else
    long_desc = 
"  This open expanse of dirt within the encampment is the primary courtyard.\n"+
"To the north the walls of the arena are visible.  Beyond the arena a vast\n"+
"expanse of mountains make up the what is visible of the horizon through the\n"+
"whipping winds.  The sky above is a haze of darkness.  The light in the\n"+
"encampment would coming from torches that are scattered about the area,\n"+
"however none of them are lit.  To the west an old well is visible, and to\n"+
"the east numerous tables and chairs are scatted about.  To the south the\n"+
"arch of the main entrance of the encampment can be seen.\n";
  ::long(str);
}

void init(){
  ::init();
  add_action("extinguish", "extinguish");
  add_action("light", "light");
}

