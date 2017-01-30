#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/wastes/"
inherit "room/room";

reset(int arg){
if(!present("platmon")) {
  int a, b; a = 0; b = (random(4)+1);
while(a<b){
  int c; c = random(12);
if(c == 0) move_object(clone_object(ROOT+"mon/croaker.c"),this_object());
if(c == 1) move_object(clone_object(ROOT+"mon/faerl_hunt.c"),this_object());
if(c == 2) move_object(clone_object(ROOT+"mon/carver.c"),this_object());
if(c == 3) move_object(clone_object(ROOT+"mon/faerl_wiz.c"),this_object());
if(c == 4) move_object(clone_object(ROOT+"mon/rock_hound.c"),this_object());
if(c == 5) move_object(clone_object(ROOT+"mon/faerl_war.c"),this_object());
if(c == 6) move_object(clone_object(ROOT+"mon/faerl_war.c"),this_object());
if(c == 7) move_object(clone_object(ROOT+"mon/eagle.c"),this_object());
if(c == 8) move_object(clone_object(ROOT+"mon/eagle.c"),this_object());
if(c > 8) move_object(clone_object(ROOT+"mon/centipede.c"),this_object());
  a++; }
}
  if(!arg){
    
set_light(1);
short_desc= (BLK+BOLD+"Gundar Plateau"+NORM);
long_desc=
"A small dead end on the pathways of the Gundar plateau, this area seems\n"+
"devoid of life. Nothing has grown or lived here for a number of years, although\n"+
"critters do wander in from time to time. The only way out seems to be back\n"+
"how you came in.\n";

items=({
"plateau","You are on top of the Gundar plateau",
"end","The pathways end here, forming a small dead end on the plateau",
"pathways","The pathways snake themselves around the boulders here",
    });

    dest_dir=({
  ROOT+"plateau4.c","south",
    });

    }
  }

init(){
  ::init();
add_action("search","search");
}

search(){
write("There are no exits from this dead end except back the way you came in.\n");
  say(tp +" searches the area.\n");
 return 1;
}

realm() {return "NT"; }
