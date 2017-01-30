inherit "room/room";
#include "/players/fred/closed/bloodfist/defs.h"

reset(arg){
	if(arg) return;

  set_light(0);
  set_no_clean(1);

  add_property("no_teleport");

  long_desc =
"  You are quite high up on the mountain.  Your feet are in small grooves\n"+
"which have been cut out of the mountain as a means to ascend it.  It is\n"+
"difficult to see, but above you there appears to be a wooden platform\n"+
"sticking out from the mountain.  Down below you can make out a few tiny\n"+
"spots of light from the encampment.  You can climb up or down from here.\n";

  items =({
    "light",
      "Spots of light are visible below you from the torches that are lit\n"+
      "in the encampment.  There isn't enough light to see around here\n"+
      "however",
    "sky",
      "The sky is a shroud of darkness and swirling sand",
    "ground",
      "The ground can not be seen from here, only the light of the encampment",
    "sand",
      "Sand is constantly blowing up against you",
    "mountains",
      "Even this high up it is difficult to truly see the mountains\n"+
      "because of the darkness and the wind",
    "horizon",
      "The mountains make up the horizon, which is constantly shrouded\n"+
      "by the sands whipping through the air",
    "platform",
      "A wooden platform has been built into the side of the mountain.  If\n"+
      "you climb up from here then you will reach it",
  });

  dest_dir=({
    DIR + "r/lookout.c",       "up",
    DIR + "r/mountain2.c",       "down",
  });
}

short(){ return "An encampment in the desert"; }

