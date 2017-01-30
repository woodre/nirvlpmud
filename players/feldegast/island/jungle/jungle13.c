#include "/players/feldegast/defines.h"
inherit ROOM;
reset(arg) {
  object panther;
  if(!random(4)) {
    panther=clone_object("/players/feldegast/island/npc/panther");
    move_object(panther,this_object());
  }
  if (arg) return;
  set_light(0);
  short_desc=GRN+"The Deep Jungle"+NORM;
  long_desc=
"     You are surrounded by a tangled growth of tropical vines\n"+
"and bushes.  Movement through here is slow and difficult.  You\n"+
"have a feeling that you're being watched, that something is\n"+
"nearby, that something brushes against your skin, yet nothing\n"+
"is there.  This is the jungle.\n";
  items=({
    "vines","It seems to slither and squirm, moving slowly towards\n"+
            "you.  Or maybe it's just your imagination?  You hope so",
    "bushes","You examine the bushes carefully and can make out tiny\n"+
             "eyes watching you in the shadows",
    "shadows","Glowing green eyes stare back at you",
    "eyes","Glowing green eyes stare back at you"
  });
  dest_dir=({
    "/players/feldegast/island/jungle/jungle4","west",
    "/players/feldegast/island/jungle/jungle14","east"
  });
}

