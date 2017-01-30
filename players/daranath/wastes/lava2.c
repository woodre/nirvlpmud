#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/wastes/"
inherit "room/room";

reset(int arg){
if(!present("lavamon")) {
  int a, b; a = 0; b = (random(4)+2);
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
"You seem to have reached the northern edge of the pool of superheated lava. The\n"+
"rocks floating in the area go no further north, although you can seem to head\n"+
"west from here. Nothing else about the area seems to be out of the ordinary.\n";

items=({
"pool","The lava pool extends all around you, several large rocks floating upon it",
"lava","The lava pool extends all around you, several large rocks floating upon it",
"rocks","Large rocks float about on the lava flow, making a pathway you could walk on",
"rock","Large rocks float about on the lava flow, making a pathway you could walk on",
    });

    dest_dir=({
  ROOT+"lava1.c","south",
  ROOT+"lava3.c","west",
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
