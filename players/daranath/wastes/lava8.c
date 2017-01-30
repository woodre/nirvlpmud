#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/wastes/"
inherit "room/room";

reset(int arg){
if(!present("lavamon")) {
  int a, b; a = 0; b = (random(5)+1);
while(a<b){
  int c; c = random(16);
if(c == 0) move_object(clone_object(ROOT+"mon/sal_priest.c"),this_object());
if(c == 1) move_object(clone_object(ROOT+"mon/creeper.c"),this_object());
if(c == 2) move_object(clone_object(ROOT+"mon/choaker.c"),this_object());
if(c == 3) move_object(clone_object(ROOT+"mon/sal_assassin.c"),this_object());
if(c == 4) move_object(clone_object(ROOT+"mon/lbeast.c"),this_object());
if(c == 5) move_object(clone_object(ROOT+"mon/lbeast.c"),this_object());
if(c == 6) move_object(clone_object(ROOT+"mon/sal_war.c"),this_object());
if(c == 7) move_object(clone_object(ROOT+"mon/sal_war.c"),this_object());
if(c > 7) move_object(clone_object(ROOT+"mon/firenewt.c"),this_object());
  a++; }
}
  if(!arg){
    
set_light(1);
short_desc= (BLK+BOLD+"Gundar "+HIR+"Lava Pits"+NORM);
long_desc=
"The large, stagnant pool of lava is all around this area, keeping the temperature\n"+
"in this area well above normal. A series of rocks floating upon the lava flow \n"+
"create a walkway around the area, allowing you to travel across the area \n"+
"both north and south.\n";

items=({
"rock","The rocks head across the lava, making a pathway you can walk upon",
"rocks","The rocks head across the lava, making a pathway you can walk upon",
"pool","The pool of lava seems to extend all around you",
"lava","The lava keeps the temperature in the area above normal",
    });

    dest_dir=({
  ROOT+"lava1.c","north",
  ROOT+"lava7.c","south",
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
