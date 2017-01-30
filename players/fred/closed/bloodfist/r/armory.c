inherit "room/room";
#include "/players/zeus/closed/ansi.h"
#include "/players/fred/closed/bloodfist/defs.h"
int torch;
object master, chest, obit;
#include "/players/fred/closed/bloodfist/r/torches.h"

reset(arg){
	if(arg) return;

  if(!present("draelok"))
  {
    master = clone_object("/players/fred/closed/bloodfist/NPC/blacksmith.c");
    move_object(master, this_object());
  }
  if(!present("zeus_bf_Tchest"))
  {
    chest = clone_object("/players/fred/closed/bloodfist/obj/chest.c");
    move_object(chest, this_object());
  }
  if(!present("pk_obit"))
  {
    obit = clone_object(DIR+"obj/pk_obit.c");
    move_object(obit, this_object());
  }

  torch = 1;
  set_light(1);
  set_no_clean(1);

  add_property("no_teleport");

  items =({
    "torches",
      "The torches are mounted on the stone walls of the arena",
    "walls",
      "The stone walls of the encampment are visible beyond the arena\n"+
      "to the north.  They protrude from the ground at a sharp angle.\n"+
      "The outer walls of the arena curve along the edge of the armory",
    "sky",
      "The sky is a shroud of darkness and swirling sand",
    "ground",
      "The ground is destolate, cracked and broken",
    "sand",
      "The ground is caked with a layer of dry sand",
    "racks",
      "There are many racks of equipment containing all types of armors\n"+
      "and weapons here in varrying stages of completion",
    "equipment",
      "There is much equipment in this armory for the blacksmith to use",
    "forge",
      "The forge is glowing hot, ready for the blacksmith to use",
    "mountain",
      "The encampment is built around some mountains of rock that jut\n"+
      "out of the earth at almost as sharp an angle as the walls of the\n"+
      "encampment itself",
  });

  dest_dir=({
    DIR + "r/bsroom.c",       "north",
    DIR + "r/open.c",        "east",
    DIR + "r/courtyard.c",    "south",
    DIR + "r/arena.c",        "west",
  });
}

short(){ return "An encampment in the desert"; }

long(str){
  if(torch)
    long_desc =
"  This is the armory of the encampment.  To the northwest the walls of the\n"+
"arena are clearly visible.  Equipment is hanging all along the outer wall\n"+
"of the arena.  Numerous racks of equipment are set up out in the sand.\n"+
"There is a forge here which is ready to be used by the blacksmith to\n"+
"create new equipment.  The sky above is dark and consuming.  An occasional\n"+
"wind blows through the area kicking up sand.  To the northeast a mountain\n"+
"of rock seems to protrude from the ground.  A few torches are lit which\n"+
"provide the only light.\n"; 
  else
    long_desc = 
"  This is the armory of the encampment.  To the northwest the walls of the\n"+
"arena are clearly visible.  Equipment is hanging all along the outer wall\n"+
"of the arena.  Numerous racks of equipment are set up out in the sand.\n"+
"There is a forge here which is ready to be used by the blacksmith to\n"+
"create new equipment.  The sky above is dark and consuming.  An occasional\n"+
"wind blows through the area kicking up sand.  To the northeast a mountain\n"+
"of rock seems to protrude from the ground.  None of the torches that are\n"+
"mounted on the walls here are lit.\n";
  ::long(str);
}

void init(){
  ::init();
  add_action("extinguish", "extinguish");
  add_action("light", "light");
  add_action("north", "north");
  add_action("unlock", "unlock");
}

north()
{
  if(present("draelok"))
  {
    tell_room(this_object(),
      "Draelok says, \"I'd prefer you didn't go in there, "+
      this_player()->query_name()+".\"\n");
    return 1;
  }
  else {
    write("The door is locked.\n");
    return 1;
  }
}

unlock(str)
{
  if(str != "door") return 0;
  if(present("draelok"))
  {
    tell_room(this_object(),
      "Draelok says, \"I'd prefer you didn't go in there, "+
      this_player()->query_name()+".\"\n");
    return 1;
  }
  else {
    write("You don't have the key.\n");
    return 1;
  }
}

