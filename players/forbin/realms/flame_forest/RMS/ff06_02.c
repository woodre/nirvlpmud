/*
 *  Created:      Forbin@Nirvana
 *  Copyright:    Copyright (c) 2004 Forbin
 *                  All Rights Reserved.
 *  Realm:        Flame Forest
 *  Function:     Room
 *  Create Date:  2004.06.03
 *  Last Edit:    2004.06.08 -Forbin
 *  Notable Changes:
 */

#pragma combine_strings

#include "/players/forbin/realms/flame_forest/ffdefine.h"
inherit "/players/forbin/closed/std/room.c"; 

reset(arg) {
  if(!present("keats_pgk")) add_object("/players/forbin/realms/keats/NPC/pg_gateguard.c");
  if(!present("keats_pgk 2")) add_object("/players/forbin/realms/keats/NPC/pg_gateguard.c");
  if(arg) return;
  short_desc = HIC+"City of "+HIW+"Keats "+HIC+"(["+NORM+"City Gates"+HIC+"])"+NORM;
  long_desc = 
    "  The scorched forest gives way to a lush green grassland.  A paved\n"+
    "roadway takes up at the edge of the forest and continues toward a\n"+
    "large stone gate to the south.  Beyond the gate, a wondrously built\n"+ 
    "suspension bridge spans a great chasm, disappearing into a fog of\n"+
    "mist and haze.\n";
  add_item("forest",
           "Everywhere save to the south, the thick blackened forest towers high,\n"+
           "yet it casts not a single shadow over the grassland southward");
  add_item(({"grassland","grass","green grassland"}),
           "Verdant grasses grow almost thigh-high, waving rhythmically in the\n"+
           "strong breeze");
  add_item(({"road","roadway"}),
           "Paved with small oval stones, each a perfect copy.  It runs from the\n"+
           "forest to the gateway and chasm");
  add_item(({"gate","stone gate"}),
           "A large stone gateway towers over the southern grassland.  Perched\n"+
           "directly on the edge of a unfathomable chasm, it opens directly onto\n"+
           "a masterfully built suspension bridge.  Stretching over eight men\n"+
           "high and at least 30 men wide, it seems to have been carved from a\n"+
           "single piece of stone.  A pair of large doors are closed, barring\n"+
           "entrance; a small wooden sign hangs near the center");
  add_item(({"bridge","suspension bridge"}),
           "Built of bamboo and woven rope, the magnificent bridge looks able to\n"+
           "carry tremendous weight for such fragile materials.  The far end\n"+
           "disappears into the fog far south, leaving the other side of the\n"+
           "chasm unseen");
  add_item(({"door","doors"}),
    "Each pair of doors is made of a dark, weathered wood.  Several iron\n"+
    "bands run horizontally across each door.  Currently, they are closed");
  add_item("stone",
    "Each gateway is made of a dark gray stone that is marbled with light\n"+
    "streaks of bright blue");           
  add_item("chasm",
           "The chasm ends unseen in the mist and fog far below");
  add_item(({"mist","haze","fog"}),
           "A thick fog of pale mist and haze keep both the bottom of and the far\n"+
           "side of it well hidden from view");
  add_item("sign",
           "A small handwritten sign that one could read");
  add_listen("main", 
             "Far into the depths of the chasm, you hear the rush of water.\n");
  set_light(1);
  add_property("NT");
  add_exit(RMS+"ff05_02","north");
  add_exit(RMS+"ff06_03","east");
  add_exit(RMS+"ff06_01","west");
}

short() { return HIC+"City of "+HIW+"Keats "+HIC+"(["+NORM+"City Gates"+HIC+"])"+NORM; }

init() {
  ::init();
  add_action("cmd_read","read");
  add_action("cmd_enter","enter");
}

okay_follow() { return 1; }

cmd_read(string str) {
  if(!str || str != "sign") { 
    notify_fail("Read what?\n"); 
      return 0; 
  }
  write("The sign reads:\n\n"+
        "     "+HIC+"-=-=-=- "+HIW+"By the order of the Magistrate "+HIC+"-=-=-=-"+NORM+"\n"+
        "                                                  \n"+
        "               The high gateway to the City     \n"+
        "               of Keats and its surrounding       \n"+
        "               prefectures has been closed        \n"+
        "               until further notice.       \n"+
        "                                                  \n"+
        "     "+HIC+"-=-=-=-  "+NORM+CYN+"-=-=-=--=-=-=---=-=-=--=-=-=-  "+HIC+"-=-=-=-"+NORM+"\n");
    return 1; 
}

cmd_enter(string str) {
  if(!str || (str != "gate" && str != "gateway")) { 
    notify_fail("Enter what?\n"); 
      return 0; 
  }
  write("The gateway is closed indefinitely.\n");
    return 1; 
}


