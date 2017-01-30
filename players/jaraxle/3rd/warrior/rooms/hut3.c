#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";
#define SQUIRE "/players/jaraxle/3rd/warrior/mercs/merc_daemon.c"

int squire_cost;

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Royal Hut";
long_desc =
        "  This is the living quarters of Willa, Queen of the Warrior\n"+
        "Maidens.  The floor is graced with a rug.  The walls have long,\n"+
        "cloth tapestries.  There is a large bed and chest of drawers here.\n"+
        "A small sign is strapped to the back wall.\n";

items = ({
  "sign","A long list of names for Mercenaries you can\nhire from Willa. <list>",
  "quarters","The living area of Willa",
  "floor","A nicely carved wood floor",
  "rug","A large "+MAG+"purple"+NORM+" and "+HIR+"red"+NORM+" rug",
  "tapestries","Tapestries with several designs hang from the walls",
  "bed","A large bed made of wood, and filled with straw",
  "chest","A large chest of drawers made of oak wood",
  "chest of drawers","A large chest of drawers made of oak wood",
  "walls","Eight foot high walls made of dark tree bark",
  "bark","Dark, rough tree bark",
});
MOCO("/players/jaraxle/3rd/warrior/mon/willa.c"),TO);
MOCO("/players/jaraxle/3rd/warrior/mon/willa_guard.c"),TO);
MOCO("/players/jaraxle/3rd/warrior/mon/willa_guard.c"),TO);
dest_dir = ({
  "/players/jaraxle/3rd/warrior/rooms/s_tree2.c","out",
});

}

init(){
    ::init();
   add_action("call_squire", "hire");
   add_action("list_squire", "list");
}

list_squire(){

   write("\nThe following mercenaries are currently available.\n"+
                 "\n           NAME:         XP:\n");
           write("\t"+SQUIRE->list_squires());
           write("\nHiring of a Mercenary requires "+HIY+"40,000"+NORM+" coins ("+HIY+"40k"+NORM+")\n");
           write("\n    Hire which mercenary? '"+HIW+"hire "+NORM+GRN+"<"+HIW+"#"+NORM+GRN+">"+NORM+"'\n");
return 1;
   }


call_squire(str){

   int doodyergettnadell;
   squire_cost = 40000;

if(!present("willa", this_object())){
write("You don't see anyone here.\n");
return 1;
}               

if(this_player()->query_money() < squire_cost){
        write("Willa says, 'You do not have enough coins.'\n");
        return 1;
        }


   if(!str){ 
     write("Hire which Mercenary? (1-10)\n");
     return 1;
     }

   sscanf(str, "%d", doodyergettnadell);

   if(doodyergettnadell < 1){ 
     write("Hire which Mercenary? (1-10)\n");
     return 1;
     }

   if(doodyergettnadell > 5){
     write("Hire which Mercenary? (1-10)\n");
     return 1;
     }

write_file("/players/jaraxle/3rd/warrior/mercs/buy.log",ctime(time())+" "+BLK+BOLD+this_player()->query_name()+NORM+" purchased a squire.\n");
  SQUIRE->initiate_squire();
  SQUIRE->get_squire(doodyergettnadell, this_player());
      move_object(this_player(), "/players/jaraxle/closed/templar/squires/back_hall.c");
      move_object(this_player(), this_object());
      write("Willa leads a Mercenary to the room for you.\n"); 
  return 1;
   }
