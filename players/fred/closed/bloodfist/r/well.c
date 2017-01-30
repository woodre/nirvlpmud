inherit "room/room";
#include "/players/zeus/closed/ansi.h"
#include "/players/fred/closed/bloodfist/defs.h"
int torch;
#include "/players/fred/closed/bloodfist/r/torches.h"

reset(arg){
	if(arg) return;

  torch = 1;
  set_light(1);
  set_no_clean(1);

  add_property("no_teleport");

  items =({
    "torches",
      "The torches are mounted on the stone walls of the arena",
    "walls",
      "The stone walls of the encampment are visible in all directions\n"+
      "from here.  The walls of the arena are also visible to the north\n"+
      "Directly to the south is the exterior wall which is built up against\n"+
      "the mountains",
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
      "The well that is here is constructed of old gray stones which extend\n"+
      "above the desolate ground 3 or 4 feet.  There is no bucket or any\n"+
      "way to get anything out of the well or enter it.  Looking down it\n"+
      "all that can be seen is darkness",
    "horizon",
      "The mountains make up the horizon, which is constantly shrouded\n"+
      "by the sands whipping through the air",
    "pathway",
      "The pathway leads into a carved out section of the mountain.  It\n"+
      "looks as though there are a few gravestones protruding from the\n"+
      "otherwise barren earth to the west",
    "arena",
      "The arena walls are visible to the north",
  });

  dest_dir=({
    DIR + "r/arena.c",         "north",
    DIR + "r/courtyard.c",     "east",
    DIR + "r/graveyard.c",     "west",
  });
}

short(){ return "An encampment in the desert"; }

long(str){
  if(torch)
    long_desc =
"  This open area is to the west of the primary courtyard of the encampment.\n"+
"To the south the outer wall of the encampment is visible, which is built\n"+
"up against the mighty rock mountains of the desert.  In the center of\n"+
"the room is an old well which is no longer functional.  A pathway to the\n"+
"west leads to a dug out area within the rock.  There are torches lining\n"+
"the wall of the encampment.  To the north the arena is visible, and beyond\n"+
"that the mountains continue on.  The area here is very warm and the sky\n"+
"overhead is a blanket of darkness.\n";
  else
    long_desc = 
"  This open area is to the west of the primary courtyard of the encampment.\n"+
"To the south the outer wall of the encampment is visible, which is built\n"+
"up against the mighty rock mountains of the desert.  In the center of\n"+
"the room is an old well which is no longer functional.  A pathway to the\n"+
"west leads to a dug out area within the rock.  There are torches lining\n"+
"the wall of the encampment, none of which are lit.  To the north the\n"+
"arena is visible, and beyond that the mountains continue on.  The area\n"+
"here is very warm and the sky overhead is a blanket of darkness.\n";
  ::long(str);
}

void init(){
  ::init();
  add_action("extinguish", "extinguish");
  add_action("light", "light");
  add_action("down_dir", "down");
  add_action("enter_dir", "enter");
}

down_dir(){
  write("There is no way to descend into the well...\n\n");
  return 1;
}

enter_dir(str){
  if(str != "well") return 0;
  write("There is no way to descend into the well...\n\n");
  return 1;
}

