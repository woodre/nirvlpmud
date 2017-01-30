#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";
int a;

reset(int arg){
a = random(2);
if(a == 0){
  if(!present("drifter")) {
move_object(clone_object("/players/daranath/qualtor/mon/drifter.c"),this_object());
  }
}
  if(!arg){

    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"("+WHT+"Crystalline Tower"+NORM+")");
    long_desc=
     "An extended hallway runs east and west below the remains of the\n"+
     "crystal tower. All along this hall, a series of private rooms\n"+
     "for the origonal Avatars were faced along the northern wall.\n"+
     "A huge mosaic runs along the opposite side of the passage,\n"+
     "extending the entire length of the hallway.\n";

    items=({
     "hallway","The dark stone hallway is covered on the southern wall\n"+
               "by a great mosaic. The mosaic seems to be made of tiny\n"+
               "pieces of crystal cut into tiles",
     "darkness","Who knows what the darkness may hold???",
     "mosaic","A huge tile mosaic made from crystals lines the southern wall.\n"+
              "It spans the length of the hallway, obsucring your view of its\n"+
              "completion. The scene depicts Sagan, founder of the Circle, coming\n"+
              "forth and battling against several giants and an evil\n"+
              "warlord with a wicked spear",
     "room","The private rooms of the Avatars are lined against the north wall",
    });

    dest_dir=({
      "/players/daranath/qualtor/cryst8.c","north",
      "/players/daranath/qualtor/cryst9.c","east",
      "/players/daranath/qualtor/cryst5.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("You find nothing of interest with the ruins of the crystal tower.\n");
    say(tp +" searches the area.\n");
     return 1;
    }


