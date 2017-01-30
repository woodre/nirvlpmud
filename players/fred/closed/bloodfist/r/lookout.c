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
    "wood",
      "The thick boards of wood that make up the platform jut out\n"+
      "from the side of the mountain.  They feel very secure",
    "guard rail",
      "The guard rail is made of the same wood as the platform.  It\n"+
      "looks very worn from the blowing sands",
    "torch",
      "There is one torch here mounted against the back edge of "+
      "the guard rail",
    "walls",
      "The stone walls of the encampment are visible in all directions\n"+
      "from the courtyward.  The walls of the arena are also visible\n"+
      "through the sandy wind to the north",
    "sky",
      "The sky is a shroud of darkness and swirling sand",
    "ground",
      "The ground can not be seen from here, only a few spots of light\n"+
      "coming from the encampment below",
    "sand",
      "A layer of sand coats the lookout fort",
    "mountains",
      "Even this high up it is difficult to truly see the mountains\n"+
      "because of the darkness and the wind",
    "horizon",
      "The mountains make up the horizon, which is constantly shrouded\n"+
      "by the sands whipping through the air",
    "platform",
      "The platform is made up of thick boards that jut out from the\n"+
      "side of the mountain.  It is very secure",
  });

  dest_dir=({
    DIR + "r/mountain3.c",       "down",
  });
}

short(){ return "An encampment in the desert"; }

long(str){
  if(torch)
    long_desc =
"  You are standing within a small lookout fort that has been built into\n"+
"the side of the mountains.  The wood beneath you juts out into the sky a\n"+
"few feet and looks much less stable than it actually is.  A guard rail\n"+
"goes around the edge of the platform so that the wind doesn't knock\n"+
"people out.  It is impossible to see very far through the thick darkness\n"+
"and blowing sands that make of the sky.  Looking down only small spots\n"+
"of light can be seen from the torches below.  One dim torch burns here.\n"+
"Grooves cut out of the side of the mountain lead down to the encampment.\n";
  else
    long_desc = 
"  You are standing within a small lookout fort that has been built into\n"+
"the side of the mountains.  The wood beneath you juts out into the sky a\n"+
"few feet and looks much less stable than it actually is.  A guard rail\n"+
"goes around the edge of the platform so that the wind doesn't knock\n"+
"people out.  It is impossible to see very far through the thick darkness\n"+
"and blowing sands that make of the sky.  Looking down only small spots\n"+
"of light can be seen from the torches below.  There is one torch here,\n"+
"however it is not lit.  Grooves cut out of the side of the mountain\n"+
"lead down to the encampment.\n";
  ::long(str);
}

void init(){
  ::init();
  add_action("extinguish", "extinguish");
  add_action("light", "light");
}

