/*************************************************************************
 * File:        c5.c
 * Function:		Room file for Black Willow forest area
 * Author(s):		Sparrow@Nirvana
 * Copyright:		Copyright (c) 2013 Sparrow
 *              All Rights Reserved
 * Source:			3/20/2013
 * Notes:			  
 *                                   
 * Change History:
 *
 ************************************************************************/
#include <ansi.h>
#include "/players/sparrow/areas/bwo/include/defs.h"
#define terrain "forest"
#define environment "outdoor"

inherit "room/room";
  reset(arg){
  if(!arg){
    set_light(-1);
    short_desc = HIW+"B"+HIK+"lack "+HIW+"W"+HIK+"illow "+HIW+"F"+HIK+"orest"+NORM;
    long_desc = make_long();
    items=({
      "trees", 		"The trees are Black Willows of enormous size. Perpetually in the\n"+
                  "budding stage, the buds glow white like twinkling stars",
      "tree", 	  "The trees are Black Willows of enormous size. Perpetually in the\n"+
                  "budding stage, the buds glow white like twinkling stars",
      "shadows", 	"The shadows are so dark that they seem to have depth, almost like a tunnel",
      "shadow",   "The shadows are so dark that they seem to have depth, almost like a tunnel",
    });
    dest_dir=({
      BWO+"forest/b5.c","west",
      BWO+"forest/d5.c","east",
      BWO+"forest/c6.c","south",
      BWO+"forest/b6.c","southwest",
    });
  }   
}

make_long() {
  string foo;
  switch(random(5)) {
    case 0:
      foo = "It is unnaturaly dark in these woods. The black willow trees grow\n"+
            "to heights unseen anywhere else in the world. The bark itself seems\n"+
            "to suck in all of the surrounding light leaving the only the buds\n"+
            "visible, appearing like the sky on a clear moonless night. If the\n"+
            "Nightlord and his Order does truly exist, this would be his home.\n";
    break;
    case 1:
      foo = "Large shadows are cast in every directions from the faint light of\n"+
            "of the glowing canopy. The forest seems to go on forever in every\n"+
            "direction. The whisper of wind that occasionally blows seems to \n"+
            "always come from behind. The darkness is unsettling.\n";
    break;
    case 2:
      foo = "The forest is deadly silent here. The darkness seems to mute all\n"+
            "other senses as much as sight. No natural beasts call this magical\n"+
            "forest home, they seem to fear these woods. One could get lost within\n"+
            "the shadows for days without any progress at all.\n";
    break;
    case 3:
      foo = "The darkness seems to press in from all sides almost as if it had\n"+
            "substance. Large black willows dominate this stand of trees, choking\n"+
            "out even a single blade of grass. The canopy above in impermiable to\n"+
            "any outside light. Only the twinkling of the magical buds break the\n"+
            "darkness from above.\n";
    break;
    case 4:
      foo = "Tiny pinpoints of light twinkle down from above looking like an\n"+
            "alien night sky. The shadows they cast feel like deep pits of nothing.\n"+
            "The Black Willow Order is rumored to dwell somewhere in this forest,\n"+
            "providing the magical darkness that fills this forest. The trees seem\n"+
            "to change and move when not viewed directly.\n";
    break;
    default:
      foo = "It is unnaturaly dark in these woods. The black willow trees grow\n"+
            "to heights unseen anywhere else in the world. The bark itself seems\n"+
            "to suck in all of the surrounding light leaving the only the buds\n"+
            "visible, appearing like the sky on a clear moonless night. If the\n"+
            "Nightlord and his Order does truly exist, this would be his home.\n";
  }
  return foo;
}


init()  {
 ::init();
  add_action("search_room","search");
  add_action("enter_shadows","enter");
}

search_room() {
  write("You find nothing of interest in the general area.\n");
  say (this_player()->query_name() +" searches the general area.\n");
  return 1;  
}



enter_shadows(string wha) {
  if(!wha) {
    write("What are you trying to enter?\n");
    return 1;
  }
  if(!wha == "shadows") {
    write("You try as hard as you can but you just cannot squeeze into the "+wha+"!\n");
    return 1;
  }
  write("You walk into the shadows behind one tree and come out from behind another.\n");
  this_player()->move_player("suddenly disappearing into the shadows#players/sparrow/areas/bwo/rms/forest/c5.c");
  return 1;
}
