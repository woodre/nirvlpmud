#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/wastes/"
inherit "room/room";

reset(int arg){
if(!present("platmon")) {
  int a, b; a = 0; b = (random(4)+1);
while(a<b){
  int c; c = random(10);
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
"The open area at the top of the plateau ends here, the pathway almost running\n"+
"off the end of a large cliff. The area itself seems battle scarred, with\n"+
"numerous scorch marks and small burns all over the surrounding rock\n"+
"surface. The only way to go is back to the north.\n";

items=({
"area","A strong breeze blows about the area, being on top of the plateau",
"cliff","The cliff extends over the edge of the plateau's lip",
"plateau","You are on top of the Gundar plateau",
"scorch","Scorch marks seem to be the result of a magical battle",
"marks","Scorch marks seem to be the result of a magical battle",
"burns","The small burns might be the result of a magical battle that took place",
"rock","The surrounding rock surface is heavily scarred and pitted",
"scars","The various scars are all over the dark grey rock surface",
"cave","A small cave can be seen below the large cliff up here.\n"+
       "You might be able to "+HIR+"climb"+NORM+" down there",
    });

    dest_dir=({
  ROOT+"plateau8.c","north",
    });

    }
  }

init(){
  ::init();
add_action("search","search");
add_action("climb_down","climb");
}

search(){
write("During your search, you find a small cave down the side of the plateau.\n");
  say(tp +" searches the area.\n");
 return 1;
}

climb_down(){
write("\nYou slowly make your way down to the small cave.\n\n");
this_player()->move_player("down the rocky surface of the plateau#/players/daranath/wastes/plateau_cave.c");
return 1; 
}

realm() {return "NT"; }
