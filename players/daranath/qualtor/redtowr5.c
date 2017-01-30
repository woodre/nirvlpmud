#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
move_object(clone_object("/players/daranath/qualtor/mon/mourn_coil.c"),this_object());
  if(!arg){
    
    set_light(1);
short_desc= (BOLD+BLK+"City of Qual'tor "+NORM+"("+RED+"RedTower"+NORM+")");
    long_desc=
     "Boxes and wooden crates are stacked all about the room, cobwebs\n"+
     "and a thick layer of dust covering everything. A keg sticks out\n"+
     "from within the mass of boxes and crates, its contents long\n"+
     "since dry. The only exit is back to the west.\n";

    items=({
     "wall","The red stone walls are the same as elsewhere in the tower",
     "keg","The keg used to hold a rich ale, now it is empty",
     "box","Most of the boxes have not been moved in years",
     "boxes","Most of the boxes have not been moved in years",
     "crate","The crates have not been disturbed for years",
     "crates","The crates have not been disturbed for years",
     "dust","A thikc layer of dust covers everything here but you",
     "room","The storage room is very plain and simple",
    });

    dest_dir=({
      "/players/daranath/qualtor/redtowr3.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    add_action("enter","enter");
    }

    search(){
    write("You find a secret panel to the north behind a sliding wall.\n"+
          "Perhaps you should "+HIR+"<"+NORM+"enter"+HIR+">"+NORM+" it.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

    enter(){
    write("You enter the secret door.\n");
    this_player()->move_player("behind a large crate#/players/daranath/qualtor/redtowr6.c");
  return 1;
}
