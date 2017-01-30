#define tp this_player()->query_name()
inherit "room/room";

#include <ansi.h>

reset(int arg){
move_object(clone_object("/players/daranath/mons/demonling2.c"),this_object());
move_object(clone_object("/players/daranath/mons/demonling2.c"),this_object());
move_object(clone_object("/players/daranath/mons/demonling1.c"),this_object());
move_object(clone_object("/players/daranath/mons/demonling1.c"),this_object());
 if(!arg){

  set_light(-1);
  short_desc="Tunnel within the UnderDark";
  long_desc=
 "The twisting tunnels of the UnderDark continue here, but your attention\n"+
 "is taken from them by the large pool of dark liquid resting on the\n"+
 "floor here. Slightly boiling and bubbling over, the dark red liquid\n"+
 "makes you wonder just what put it here, and what purpose it has. The\n"+
 "tunnels run to the north, south and west.\n";

items=({
 "paths", "The paths lead further into the darkness",
 "tunnels", "The tunnels are naturally formed by forces long since gone from\n"+
            "this area. They lead off different paths into the darkness",
 "walls", "The rough hewn walls surround you, encasing you within the\n"+
          "darkness all about",
 "blood", "The dark red liquid is commonly found amongst the tunnels of\n"+
          "the UnderDark",
 "pool", "The boiling pool is filled with dark blood",
 "liquid", "The liquid makes you think something is wrong here",
 });

  dest_dir=({
  "/players/daranath/underdark/level1/d,4.c","north",
  "players/daranath/underdark/level1/f,4.c","south",
  "/players/daranath/underdark/level1/e,3.c","west",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
}

search() {
write("You find nothing amongst the dirt.\n");
say (tp +" searches the area\n");
 return 1;  }

arate() { return "YES"; }
