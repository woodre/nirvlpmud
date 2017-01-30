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
"A clearing within the pathways atop the Gundar plateau allows you some breathing\n"+
"room from the boulders that loom overhead. You can see clearly from this\n"+
"vantage point, overlooking the majority of the blasted and rotting \n"+
"countryside. Gundar was a beautiful place to live, but that was a long \n"+
"time ago.\n";

items=({
"plateau","You are on top of the Gundar plateau",
"clearing","A large clearing exsists here amongst the rocks and boulders",
"rocks","A variety of large chunks of rock and stone were left here during the last\n"+
     "volcanic explosion in Gundar",
"rock","A variety of large chunks of rock and stone were left here during the last\n"+
     "volcanic explosion in Gundar",
"boulders","Large boulders loom everywhere on the top of the plateau",
"pathways","The pathways snake themselves around the boulders here",
"countryside","The Gundar countryside was once a beautiful place to live. Now, many\n"+
     "years after Gundar was laid to waste, the country is still blackened\n"+
     "and torn, unable to support any type of civilized life",
    });

    dest_dir=({
  ROOT+"plateau5.c","north",
  ROOT+"plateau6.c","east",
  ROOT+"plateau3.c","southwest",
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
