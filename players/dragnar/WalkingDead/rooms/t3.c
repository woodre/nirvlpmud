inherit "players/dragnar/WalkingDead/rooms/WalkingDeadRM";

#include <ansi.h>
#include "../defs.h"

status search_flag;

reset(arg) {

	search_flag = 0;
  
  if(arg) {
    if( !present("maverick") )
      move_object(clone_object("/players/dragnar/WalkingDead/mons/maverick"), this_object());
    return;
  }
    
  short_desc = BGRN+BLK+"Black Creek Pub"+NORM;
  set_light(1);
  items=({
    "bar","A standard wooden bar, except for the dark "+RED+"blood"+NORM+" stains on it",
    "shelves","What a beautiful sight they would be if they were full of liquor",
    "bottles", "Useless now that they are broken and empty",
    "blood","Dark red "+RED+"blood"+NORM+" splattered over the floor",
    "stains","Dark red "+RED+"blood"+NORM+" splattered over the floor",
    "floor", "Only "+RED+"blood"+NORM+" could stain a floor this dark",
    "walls", "Spatters of dark "+RED+"blood"+NORM+" match the floors perfectly",
    "stools", "If there was any booze here, it might be safer to stand than sit",
    "tables", "Mostly broken and useless, but you spot something under the one standing table",
  });
  dest_dir=({
    "/players/dragnar/WalkingDead/rooms/r7","east",
  });
  long_desc=
"Rather dark and depressing, this little pub looks like it has\n\
drowned many blues away with booze. Sadly the rows and rows of\n\
shelves behind the bar are empty, it looks like the place has been\n\
looted. Many of the bottles are broken as if a large fight broke out\n\
here. The floors and walls are dark and add to the gloominess. There\n\
are a few shabby tables still standing and some bar stools along the\n\
bar. The place is a mess though, many of the stools and tables are\n\
knocked over. The only exit is back east to the main street outside.\n";
  
  if( !present("maverick") )
     move_object(clone_object("/players/dragnar/WalkingDead/mons/maverick"), this_object());
     
  reanimate_corpse();
}

init() {
	::init();
  add_action("Search","search");
}


Search(string str ) {
  object treasure;
  if( !str )
    return 0;
  
  if( str == "table" || str == "tables" ) {
    if( present("maverick") ) {
      write("You bend over to look under the table.\n");
      say(this_player()->query_name()+" bends over to look under the table.\n");
      tell_room(this_object(), "Maverick says: 'I don't think so cowboy.'\n");
      return 1;
    }
    if( !search_flag++ ) {
      treasure = clone_object("/players/dragnar/WalkingDead/heals/mons/advil");
      move_object( treasure, this_object() );
      write("You find something hiding under the table!\n");
      say( this_player()->query_name()+" finds something under a table!\n");
    }
    else {
      write("You search the tables but find nothing after all.\n");
      say( this_player()->query_name()+" searches the tables and finds nothing.\n");
    }
  }
  return 1;
}

