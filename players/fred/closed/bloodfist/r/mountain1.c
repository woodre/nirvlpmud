inherit "room/room";
#include "/players/fred/closed/bloodfist/defs.h"

reset(arg){
	if(arg) return;

  set_light(0);
  set_no_clean(1);

  add_property("no_teleport");

  long_desc =
"  You are in a precarious place right now as you stand in small\n"+
"grooves cut out of the mountainside.  The wind is blowing against\n"+
"your body, making it hard for you to keep your grip.  Below the\n"+
"lights of the encampment can be seen.  You can climb up or down\n"+
"from here.\n";

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
      "The platform can barely be seen from here",
  });

  dest_dir=({
    DIR + "r/mountain2.c",       "up",
    DIR + "r/open.c",            "down",
  });
}

short(){ return "An encampment in the desert"; }

