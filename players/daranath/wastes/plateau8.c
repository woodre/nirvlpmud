#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/wastes/"
inherit "room/room";

reset(int arg){
if(!present("platmon")) {
  int a, b; a = 0; b = (random(4)+1);
while(a<b){
  int c; c = random(16);
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
"Another large open area up upon the Gundar plateau, the clearing itself allows\n"+
"you to see the majority of the surrounding lands from Gundar. Smaller areas \n"+
"are east and south from the main area, while you can travel back west along\n"+
"the trail you came in.\n";

items=({
"clearing","Another large clearing sits amongst the boulders here",
"lands","The lands of Gundar are blackened and torn, but there is another spot\n"+
     "atop the plateau that would give a better vantage point",
"trail","The trail leads back west",
"plateau","You are up upon the Gundar plateau",
    });

    dest_dir=({
  ROOT+"plateau9.c","south",
  ROOT+"plateau7.c","west",
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
