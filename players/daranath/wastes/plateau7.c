#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/wastes/"
inherit "room/room";

reset(int arg){
if(!present("platmon")) {
  int a, b; a = 0; b = (random(4)+2);
while(a<b){
  int c; c = random(18);
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
"The trails up upon the Gundar Plateau continue here, travelling both north and\n"+
"east from here. Large rocks and boulder line the pathway, giving the area a \n"+
"dungeon-like feel, with the exception of the open air above.\n";

items=({
"rocks","Large rocks line the pathway",
"boulders","Large boulders like the pathway up upon the plateau",
"trails","The trails upon the Gundar Plateau line the mountaintop",
"plateau","You are on top of the Gundar plateau",
    });

    dest_dir=({
  ROOT+"plateau1.c","north",
  ROOT+"plateau8.c","east",
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
