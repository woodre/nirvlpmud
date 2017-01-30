#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
move_object(clone_object("/players/daranath/qualtor/mon/keeper.c"),this_object());
  if(!arg){
    
    set_light(1);
short_desc= (BOLD+BLK+"City of Qual'tor "+NORM+"("+RED+"RedTower"+NORM+")");
    long_desc=
     "Exotic tapestries covering the walls and a warm fire burning with a\n"+
     "stone hearth make this room seem more hospitable then the rest of\n"+
     "the tower. A large rug supports the weight of several comfy chairs\n"+
     "and a four poster bed rests in the far corner of the room. The only\n"+
     "exit is back out the way you came.\n";

    items=({
     "chair","RUN!!!!!  Its the comfy chair....",
     "bed","A large four poster bed looks irristable to <lie> upon",
     "rug","A dark red rug makes the room match the rest of the tower",
     "hearth","Personal items of conquest line the stone of the hearth",
     "tapestry","The many tapestries completly cover the walls",
     "wall","The walls are covered in exotic tapestries",
     "walls","The walls are covered in exotic tapestries",
     "fire","Fire...  flame....  burn.....     warm....  ummm....",
    });

    dest_dir=({
      "/players/daranath/qualtor/redtowr9.c","out",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    add_action("bedding","lie");
    }

    search(){
    write("You find nothing of value here, there must be something within\n"+
          "the tower in a hidden chamber.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

    bedding() {
    write("You lie down upon the four poster bed, its comfort completly\n"+
          "drawing you into a zone of comfort. You forget that others are\n"+
          "about the room as you spread out amongst the covers.\n");
    say(tp +" lies down upon the four poster bed within the room here.\n");
    return 1;
    }
