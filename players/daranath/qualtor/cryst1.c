#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/"
#include <ansi.h>
inherit "room/room";
int a;

reset(int arg){
move_object(clone_object(ROOT+"newstuff/mon/doomdrifter.c"),this_object());
a = random(2);
if(a == 0) {
if(!present("drifter")) {
move_object(clone_object("/players/daranath/qualtor/mon/drifter.c"),this_object());
   }
}
  if(!arg){

    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"("+WHT+"Crystalline Tower"+NORM+")");
    long_desc=
     "A grey stone hall runs to the north from here, while a pair of\n"+
     "smaller hallways exit east and west. The most striking feature\n"+
     "of the room, however, is the crystal lined passage extending\n"+
     "southbound.\n";

    items=({
     "hall","The grey stone hall leads back to the stairs",
     "hallway","The twin hallways run east and west from here, both are\n"+
               "a bit smaller then the main hallway in the ruins",
     "passage","The crystal lines passage was rumored of have led the Circle\n"+
               "members to their greatest tests. Tests of sorcery and strength\n"+
               "were preformed down that passage. In better times, a pair\n"+
               "of well armed guards would be here to stop you",
     "crystal","Crystalline lines the passage leading south",
    });

    dest_dir=({
      "/players/daranath/qualtor/cryst_land.c","north",
/*
      "/players/daranath/qualtor/cryst_test_ent.c","south",
*/
      "/players/daranath/qualtor/cryst2.c","west",
      "/players/daranath/qualtor/cryst5.c","east",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("You search the area to no avail.\n");
    say(tp +" searches the area.\n");
     return 1;
    }


