inherit "room/room";
#include "/players/zeus/closed/ansi.h"
#include "/players/fred/closed/bloodfist/defs.h"
int torch;
object elder, mboard;
#include "/players/fred/closed/bloodfist/r/torches.h"


reset(arg){

  if(!present("elder"))
  {
    elder = clone_object(DIR+"NPC/elder.c");
    move_object(elder, this_object());
  }
  if(!present("bulletin board"))
  {
    mboard = clone_object(DIR+"obj/mboard.c");
    move_object(mboard, this_object());
  }
	if(arg) return;

  torch = 1;
  set_light(1);
  set_no_clean(1);

  add_property("no_teleport");

  items =({
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
    DIR + "r/portal.c",         "east",
    DIR + "r/open.c",           "south",
    DIR + "r/lockers.c",        "west",
  });
}

short(){ return "An encampment in the desert"; }

long(str){
  if(torch)
    long_desc =
"  This is a large room that has been carved out of the rock in the side\n"+
"of the mountain.  It is hotter here than outside, however there is\n"+
"almost no wind or blowing sand.  There is a large table here with a\n"+
"number of chairs around it.  A few torches are on the walls casting\n"+
"shadows across the room.  The ground is still loose sand and shifts\n"+
"below your feet as you walk.  To the south an open area can be seen\n"+
"outside of the room.\n";
  else
    long_desc = 
"  This is a large room that has been carved out of the rock in the side\n"+
"of the mountain.  It is hotter here than outside, however there is\n"+
"almost no wind or blowing sand.  There is a large table here with a\n"+
"number of chairs around it.  A few unlit torches are mounted on the\n"+
"walls.  The ground is still loose sand and shifts below your feet as\n"+
"you walk.  To the south an open area can be seen outside of the room.\n";
  ::long(str);
}

void init(){
  ::init();
  add_action("extinguish", "extinguish");
  add_action("light", "light");
}

