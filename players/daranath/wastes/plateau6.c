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
"The pathway around the boulders on the Gundar plateau ends here. A rocky ledge\n"+
"overlooks a steep drop down the side of the plateau, not a good area to be\n"+
"backed into.\n";

items=({
"pathway","The pathway snakes itself around the boulders here",
"boulders","Large boulders sit atop the plateau, blocking the pathway from going further",
"ledge","The ledge extends its out farther from any other point up on the plateau\n"+
     "Looking down, you can see quite a drop to the base of the plateau",
"side","The side of the plateau is rocky and unforgiving",
"plateau","You are on top of the plateau itself",
    });

    dest_dir=({
  ROOT+"plateau4.c","west",
    });

    }
  }

init(){
  ::init();
add_action("search","search");
}

search(){
write("Nothing of interest is found about the top of the plateau.\n");
  say(tp +" searches the area.\n");
 return 1;
}

realm() {return "NT"; }
