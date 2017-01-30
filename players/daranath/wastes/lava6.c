#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/wastes/"
inherit "room/room";

reset(int arg){
if(!present("lavamon")) {
  int a, b; a = 0; b = (random(6)+2);
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
"You seem to have reached the southern edge of the pool of superheated lava. The\n"+
"rocks floating in the area go no further south, although you can seem to head\n"+
"east from here. Nothing else about the area seems to be out of the ordinary.\n";

items=({
"pool","The pool of lava seems to extend all around you",
"lava","The lava keeps the temperature in the area above normal",
"rocks","The rocks head across the lava, making a pathway you can walk upon",
"rock","The rocks head across the lava, making a pathway you can walk upon",
});

    dest_dir=({
  ROOT+"lava5.c","north",
  ROOT+"lava7.c","east",
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
