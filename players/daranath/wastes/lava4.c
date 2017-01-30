#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/wastes/"
inherit "room/room";

reset(int arg){
if(!present("lavamon")) {
  int a, b; a = 0; b = (random(4)+2);
while(a<b){
  int c; c = random(14);
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
"here well above normal. A series of rocks floating upon the lava flow create\n"+
"a walkway around the area, allowing you to travel across the lava itself, \n"+
"heading both north and south.\n";

items=({
"lava","The lava pool extends all around you, several large rocks floating upon it",
"rock","Large rocks float about on the lava flow, making a pathway you could walk on",
"rocks","Large rocks float about on the lava flow, making a pathway you could walk on",
"pool","The lava pool extends all around you, several large rocks floating upon it",
    });

    dest_dir=({
  ROOT+"lava3.c","north",
  ROOT+"lava5.c","south",
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
