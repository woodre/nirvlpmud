#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
if(!present("table")){
move_object(clone_object("/players/daranath/qualtor/obj/table.c"),this_object());
}
if(!present("coil")){
move_object(clone_object("/players/daranath/qualtor/mon/mourn_coil2.c"),this_object());
move_object(clone_object("/players/daranath/qualtor/mon/mourn_coil2.c"),this_object());
move_object(clone_object("/players/daranath/qualtor/mon/mourn_coil2.c"),this_object());
}
  if(!arg){
    
    set_light(1);
short_desc= (BOLD+BLK+"City of Qual'tor "+NORM+"("+RED+"RedTower"+NORM+")");
    long_desc=
     "The sliding wall opens to reveal a small room lit by a glowing\n"+
     "crystal set in the far wall. A long table sits against the eastern\n"+
     "wall, as if it was meant to display items of value. A large, red\n"+
     "carpet covers the floor, still in extremly good shape despite the\n"+
     "destruction within the city.\n";

    items=({
     "wall","The red stone walls are the same as elsewhere in the tower",
     "corridor","The hallway runs east and north from here",
     "room","The small room to the south seems to be a storage area",
    });

    dest_dir=({
      "/players/daranath/qualtor/redtowr5.c","back",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    add_action("dar_get","take");
    add_action("dar_get","get");
    add_action("dar_back","back");
    }

    search(){
    write("You find nothing within the room that is of any value.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

    dar_get(str) { /* I changed this so people can get from bags - Feld 5/1/00 */
      string targ, from;
      if(sscanf(str,"%s from %s",targ,from) != 2)
        return 0;
      if(present("coil") && from=="table") {
        write("The Mourning Coil blocks you from getting anything while in the room.\n");
        return 1;
      }
      return 0;
    }

    dar_back(){
    if(present("coil")){
    write("The Mourning Coil blocks you from getting out!!!\n");
    return 1; }
    return 0;
    }

