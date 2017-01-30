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
"The first open area up on the Gundar plateau, this clearing seems to lead in several\n"+
"directions. A large nest can be seen nestled inbetween a couple of boulders to\n"+
"the east, while trails lead north and south from here.\n";

items=({
"nest","A massive, giant sized nest can be seen to the east",
"trails","Well worn pathways leads all across the plateau",
"boulders","Several boulders are all about the top of the plateau",
"plateau","You are standing on top the Gundar plateau",
    });

    dest_dir=({
  ROOT+"plateau3.c","north",
  ROOT+"plateau7.c","south",
  ROOT+"plateau2.c","east",
  ROOT+"plateau_entry.c","west",
    });

    }
  }

init(){
  ::init();
add_action("search","search");
}

search(){
write("It is much too hot to take the time to search the area.\n");
  say(tp +" tries to search the area.\n");
 return 1;
}

realm() {return "NT"; }
