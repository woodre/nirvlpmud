#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
if(!present("merchant")) {   
move_object(clone_object("/players/brittany/kadath/NPC/trader.c"),this_object());
}
   if(arg) return;
   set_light(1);
   
   short_desc = WHT+"Trade shop"+NORM;
   long_desc =
    "     Inside the trade shop the walls are made of a dark, dense\n"+
    "rock.  There are stone tables and chairs lined neatly around\n"+
    "the room.  Some merchants wait here for the galleys to port\n"+
    "so they can trade.  The shelves are stocked with different\n"+
    "items traded from several of the merchants.\n";
   
   items = ({
         "tables","Stone tables are lined neatly around the tavern",
         "chairs","The stone chairs are placed around the tables in the shop",
         "shelves","The shelves are stocked with different items",
         "walls","The walls are made of basalt, a dark, dense ingneous rock",
         "galleys","The large ships that port on the River Skai, with items to trade with the merchants",
          });

   dest_dir = ({
         "/players/brittany/kadath/k24.c","north",
          });
   
}

   init(){
  ::init();
   add_action("search","search");
}
 
search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}
