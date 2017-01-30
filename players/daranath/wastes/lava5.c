#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/wastes/"
inherit "room/room";

reset(int arg){
move_object(clone_object(ROOT+"mon/sal_war.c"),this_object());
move_object(clone_object(ROOT+"mon/sal_war.c"),this_object());
move_object(clone_object(ROOT+"mon/sal_war.c"),this_object());
if(!present("priest")) {
  int a, b; a = 0; b = (random(3)+1);
while(a<b){
  int c; c = random(12);
if(c == 0) move_object(clone_object(ROOT+"mon/sal_priest.c"),this_object());
if(c == 1) move_object(clone_object(ROOT+"mon/creeper.c"),this_object());
if(c == 2) move_object(clone_object(ROOT+"mon/choaker.c"),this_object());
if(c == 3) move_object(clone_object(ROOT+"mon/sal_assassin.c"),this_object());
if(c == 4) move_object(clone_object(ROOT+"mon/lbeast.c"),this_object());
if(c == 5) move_object(clone_object(ROOT+"mon/lbeast.c"),this_object());
if(c > 5) move_object(clone_object(ROOT+"mon/firenewt.c"),this_object());
  a++; }
}

  if(!arg){
    
set_light(1);
short_desc= (BLK+BOLD+"Gundar "+HIR+"Lava Pits"+NORM);
long_desc=
"The rocks floating upon the large pool of lava seem to come together here, \n"+
"creating a large floating platform of stone. To the west, the platform creates a\n"+
"an open area that just begs to be explored. The floating pathway of stone \n"+
"continues north and south as well.\n";

items=({
"rocks","Large rocks float about on the lava flow, making a pathway you could walk on",
"rock","Large rocks float about on the lava flow, making a pathway you could walk on",
"pool","The lava pool extends all around you, several large rocks floating upon it",
"lava","The lava pool extends all around you, several large rocks floating upon it",
"platform","Several of the larger rocks come together here, making a platform that\n"+
           "extends to the west",
"stone","The rocks making the platform are a charred black stone",
    });

    dest_dir=({
  ROOT+"lava4.c","north",
  ROOT+"lava6.c","south",
  ROOT+"lava_boss.c","west",
    });

    }
  }

init(){
  ::init();
add_action("search","search");
add_action("dar_west","west");
}

search(){
write("It is much too hot to take the time to search the area.\n");
  say(tp +" tries to search the area.\n");
 return 1;
}

dar_west(){
if(present("salamander")){
write("The salamander blocks your way from proceeding westwards.\n");
return 1; }
return 0;
}

realm() {return "NT"; }
