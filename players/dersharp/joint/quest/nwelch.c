inherit "room/room";
#include "ex.h"
object cookie;
reset(arg){
/*
   if(!present("cookie")){
      cookie = clone_object("/players/dersharp/stuff/dbcookie");
      move_object(cookie, tb);
      return 1;
   }
*/
   if(arg) return;
   short_desc="Intersection";
   long_desc ="  Tilden street intersects Welch Avenue here.\n"+
              "To the south you see Welch Avenue and to the \n"+
              "north and west the streets fade into obscurity.\n"+
              "To the northeast you see a large QuickTrip and\n"+
              "to the east you see what seems to be a large\n"+
              "warehouse.  You hear some music coming from that\n"+
              "direction.  Cool music!\n"; 
   set_light(1);
   dest_dir=
	({
		Quest+"welch2","south",
		Quest+"tildene","east",
                Quest+"quicktrip","northeast",
	});
}
