#define tp this_player()

#define tpn this_player()->query_name()

#define tpp this_player()->query_possessive()

inherit "room/room";

#include "/players/jaraxle/ansi.h"





reset(arg) {

if(!present("cont_dragon", this_object())){

move_object(clone_object("/players/jaraxle/cont/mobs/rdragon3.c"), this_object());

}

  if(arg) return;

set_light(1);



short_desc = "The Caves of the "+HIR+"Red"+NORM+RED+"Dragon Clan"+NORM;

long_desc =

"  This is a small side chamber. The walls here are made of\n"+

"a smooth black stone that is warm to the touch. A large\n"+

"map of the continent is engraved into the floor, which\n"+

"seems untouched except for a few scratches around its\n"+

"vast border.  An archway leading to the north and a large\n"+

"chamber.\n";



items = ({

"walls",

"The walls here are made from a smooth black stone",

"map",

"A huge map that you might be able to 'inspect' closer",

"floor",

"A smooth black stone floor with a large map carved\n"+

"into its surface",

"scratches",

"A few scratches that border the map in the floor",

"archway",

"A black stone archway that leads into a large chamber"

});



dest_dir = ({

  "/players/jaraxle/cont/rdragon/rooms/r5.c","north",

});



}

init(){

  ::init();

  add_action("inspect_map", "inspect");

  }



inspect_map(str){

if(!str){

write("Inspect what?\n");

return 1;

}



if(str == "map"){

write(

"You look at the map...\n"+

""+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+NORM+YEL+"M "+NORM+YEL+"M "+NORM+YEL+"n "+GRN+"# "+NORM+YEL+"n "+GRN+"# "+GRN+"# "+GRN+"# "+HIG+"@ "+HIG+"@ "+HIG+"@ "+GRN+"# "+GRN+"# "+HIG+"@ "+HIG+"@ "+GRN+"# "+GRN+"# "+GRN+"# "+HIB+"~ "+HIB+"~ "+HIB+"~ \n"+  

 ""+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+NORM+YEL+"M "+NORM+YEL+"n "+GRN+"# "+GRN+"# "+GRN+"# "+GRN+"# "+GRN+"# "+HIG+"@ "+HIG+"@ "+HIG+"@ "+GRN+"# "+GRN+"# "+GRN+"# "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ \n"+  

 ""+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIM+"- + "+NORM+YEL+"n "+HIB+"~ "+NORM+YEL+"M "+NORM+YEL+"n "+GRN+"# "+HIG+"@ "+GRN+"# "+GRN+"# "+HIG+"@ "+HIG+"@ "+HIG+"@ "+HIG+"@ "+GRN+"# "+HIB+"~ "+HIB+"~ "+GRN+"# "+GRN+"# "+GRN+"# "+HIB+"~ "+HIB+"~ "+HIB+"~ \n"+  

 ""+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+NORM+YEL+"n "+HIM+"| "+NORM+YEL+"n "+NORM+YEL+"n "+HIB+"~ "+NORM+YEL+"n "+HIG+"@ "+HIG+"@ "+HIG+"@ "+GRN+"# "+GRN+"# "+HIG+"@ "+HIG+"@ "+HIG+"@ "+HIB+"~ "+GRN+"# "+GRN+"# "+HIG+"@ "+GRN+"# "+GRN+"# "+HIB+"~ "+HIB+"~ "+HIB+"~ \n"+  

 ""+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+NORM+YEL+"n "+NORM+YEL+"n "+NORM+YEL+"n "+NORM+YEL+"n "+HIM+"| "+NORM+YEL+"n "+NORM+YEL+"n "+NORM+YEL+"n "+GRN+"# "+HIG+"@ "+HIG+"@ "+HIG+"@ "+GRN+"# "+HIM+"| "+HIG+"@ "+HIG+"@ "+HIB+"~ "+GRN+"# "+HIG+"@ "+HIG+"@ "+HIG+"@ "+GRN+"# "+GRN+"# "+HIB+"~ "+HIB+"~ "+HIB+"~ \n"+  

 ""+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIG+"@ "+HIG+"@ "+HIG+"@ "+NORM+YEL+"n "+NORM+YEL+"n "+NORM+YEL+"n "+HIM+"+ "+HIM+"- "+HIM+"- "+HIM+"- "+HIM+"- "+HIM+"- "+HIM+"- "+HIM+"- "+HIM+"- "+HIM+"+ "+GRN+"# "+HIG+"@ "+NORM+YEL+"M "+HIG+"@ "+HIG+"@ "+HIG+"@ "+HIG+"@ "+HIG+"@ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ \n"+  

 ""+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIG+"@ "+HIG+"@ "+HIG+"@ "+HIG+"@ "+HIG+"@ "+NORM+YEL+"n "+NORM+YEL+"n "+HIM+"| "+NORM+YEL+"n "+GRN+"# "+GRN+"# "+HIG+"@ "+HIG+"@ "+HIG+"@ "+GRN+"# "+GRN+"# "+HIM+"| "+GRN+"# "+NORM+YEL+"M "+NORM+YEL+"M "+HIG+"@ "+HIG+"@ "+HIG+"@ "+HIG+"@ "+HIG+"@ "+HIG+"@ "+HIB+"~ "+HIB+"~ "+HIB+"~ \n"+  

 ""+HIB+"~ "+HIB+"~ "+HIG+"@ "+HIG+"@ "+HIG+"@ "+HIG+"@ "+HIG+"@ "+HIG+"@ "+GRN+"# "+NORM+YEL+"n "+HIM+"| "+NORM+YEL+"n "+NORM+YEL+"n "+GRN+"# "+GRN+"# "+GRN+"# "+HIG+"@ "+GRN+"# "+GRN+"# "+HIM+"| "+NORM+YEL+"M "+NORM+YEL+"M "+NORM+YEL+"M "+HIG+"@ "+HIG+"@ "+HIG+"@ "+HIG+"@ "+HIG+"@ "+HIG+"@ "+HIG+"@ "+HIB+"~ "+HIB+"~ \n"+  

 ""+HIB+"~ "+HIB+"~ "+HIG+"@ "+HIG+"@ "+HIG+"@ "+HIG+"@ "+HIG+"@ "+HIG+"@ "+GRN+"# "+NORM+YEL+"n "+HIM+"| "+GRN+"# "+NORM+YEL+"n "+NORM+YEL+"n "+GRN+"# "+HIG+"@ "+HIG+"@ "+HIG+"@ "+GRN+"# "+HIM+"| "+NORM+YEL+"M "+NORM+YEL+"M "+HIG+"@ "+HIG+"@ "+HIG+"@ "+HIM+"+ "+HIM+"- "+HIM+"- "+HIM+"- "+HIM+"- "+HIB+"~ "+HIB+"~ \n"+  

 ""+HIB+"~ "+HIB+"~ "+HIG+"@ "+GRN+"# "+HIG+"@ "+HIG+"@ "+HIG+"@ "+GRN+"# "+GRN+"# "+NORM+YEL+"n "+HIM+"| "+GRN+"# "+NORM+YEL+"n "+NORM+YEL+"n "+GRN+"# "+GRN+"# "+HIG+"@ "+HIG+"@ "+GRN+"# "+HIM+"+ "+HIM+"- "+HIM+"- "+HIM+"- "+HIM+"- "+HIM+"- "+HIM+"+ "+HIG+"@ "+HIG+"@ "+HIG+"@ "+HIB+"~ "+HIB+"~ "+HIB+"~ \n"+  

 ""+HIB+"~ "+HIB+"~ "+GRN+"# "+GRN+"# "+HIG+"@ "+HIG+"@ "+GRN+"# "+GRN+"# "+GRN+"# "+GRN+"# "+HIM+"| "+GRN+"# "+GRN+"# "+NORM+YEL+"n "+NORM+YEL+"n "+HIG+"@ "+HIG+"@ "+HIG+"@ "+HIG+"@ "+HIM+"| "+GRN+"# "+NORM+YEL+"M "+NORM+YEL+"n "+NORM+YEL+"n "+GRN+"# "+HIG+"@ "+HIG+"@ "+HIG+"@ "+HIG+"@ "+HIG+"@ "+HIB+"~ "+HIB+"~ \n"+  

 ""+HIB+"~ "+HIB+"~ "+HIB+"~ "+GRN+"# "+GRN+"# "+HIG+"@ "+GRN+"# "+GRN+"# "+HIM+"+ "+HIM+"- "+HIM+"+ "+NORM+YEL+"n "+GRN+"# "+NORM+YEL+"n "+NORM+YEL+"n "+HIG+"@ "+HIG+"@ "+HIG+"@ "+HIG+"@ "+HIM+"| "+GRN+"# "+NORM+YEL+"M "+NORM+YEL+"M "+NORM+YEL+"n "+NORM+YEL+"n "+GRN+"# "+HIG+"@ "+HIG+"@ "+HIG+"@ "+HIB+"~ "+HIB+"~ "+HIB+"~ \n"+  

 ""+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+GRN+"# "+GRN+"# "+HIM+"| "+GRN+"# "+NORM+YEL+"n "+NORM+YEL+"M "+NORM+YEL+"n "+NORM+YEL+"n "+HIG+"@ "+HIG+"@ "+HIG+"@ "+GRN+"# "+GRN+"# "+HIM+"| "+GRN+"# "+HIB+"~ "+NORM+YEL+"M "+NORM+YEL+"n "+NORM+YEL+"n "+NORM+YEL+"n "+HIG+"@ "+HIG+"@ "+HIG+"@ "+GRN+"# "+HIB+"~ "+HIB+"~ \n"+  

 ""+HIB+"~ "+HIB+"~ "+GRN+"# "+GRN+"# "+GRN+"# "+GRN+"# "+GRN+"# "+GRN+"# "+HIM+"| "+GRN+"# "+NORM+YEL+"n "+NORM+YEL+"M "+NORM+YEL+"M "+NORM+YEL+"n "+GRN+"# "+HIG+"@ "+HIG+"@ "+HIM+"+ "+HIM+"- + "+HIB+"~ "+NORM+YEL+"M "+NORM+YEL+"M "+NORM+YEL+"n "+NORM+YEL+"n "+GRN+"# "+GRN+"# "+HIG+"@ "+GRN+"# "+GRN+"# "+HIB+"~ "+HIB+"~ \n"+  

 ""+HIB+"~ "+HIB+"~ "+GRN+"# "+HIG+"@ "+HIG+"@ "+HIG+"@ "+GRN+"# "+GRN+"# "+HIM+"| "+GRN+"# "+GRN+"# "+NORM+YEL+"n "+NORM+YEL+"M "+NORM+YEL+"n "+GRN+"# "+GRN+"# "+HIG+"@ "+HIM+"| "+HIG+"@ "+GRN+"# "+HIB+"~ "+NORM+YEL+"M "+NORM+YEL+"n "+NORM+YEL+"n "+GRN+"# "+GRN+"# "+GRN+"# "+GRN+"# "+HIG+"@ "+HIB+"~ "+HIB+"~ "+HIB+"~ \n"+  

 ""+HIB+"~ "+HIB+"~ "+HIG+"@ "+HIG+"@ "+HIG+"@ "+HIG+"@ "+HIG+"@ "+GRN+"# "+HIM+"| "+GRN+"# "+GRN+"# "+NORM+YEL+"n "+NORM+YEL+"M "+NORM+YEL+"M "+NORM+YEL+"n "+GRN+"# "+GRN+"# "+HIM+"| "+GRN+"# "+GRN+"# "+HIB+"~ "+NORM+YEL+"M "+NORM+YEL+"n "+NORM+YEL+"n "+GRN+"# "+GRN+"# "+HIG+"@ "+GRN+"# "+HIG+"@ "+HIB+"~ "+HIB+"~ "+HIB+"~ \n"+  

 ""+HIB+"~ "+HIB+"~ "+HIM+"- "+HIM+"- "+HIM+"- "+HIM+"- "+HIM+"- "+HIM+"- "+HIM+"+ "+GRN+"# "+NORM+YEL+"n "+NORM+YEL+"M "+NORM+YEL+"M "+NORM+YEL+"M "+NORM+YEL+"n "+GRN+"# "+GRN+"# "+GRN+"# "+GRN+"# "+HIB+"~ "+HIB+"~ "+HIB+"~ "+NORM+YEL+"n "+NORM+YEL+"n "+HIB+"~ "+HIB+"~ "+HIB+"~ "+GRN+"# "+GRN+"# "+HIB+"~ "+HIB+"~ "+HIB+"~ \n"+  

 ""+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIG+"@ "+HIG+"@ "+HIG+"@ "+HIG+"@ "+GRN+"# "+GRN+"# "+GRN+"# "+NORM+YEL+"n "+NORM+YEL+"M "+NORM+YEL+"M "+NORM+YEL+"M "+NORM+YEL+"n "+GRN+"# "+GRN+"# "+GRN+"# "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+NORM+YEL+"n "+HIB+"~ "+HIB+"~ "+HIB+"~ "+GRN+"# "+GRN+"# "+GRN+"# "+GRN+"# "+HIB+"~ "+HIB+"~ \n"+  

 ""+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIG+"@ "+HIG+"@ "+HIG+"@ "+GRN+"# "+GRN+"# "+HIB+"~ "+GRN+"# "+GRN+"# "+NORM+YEL+"n "+NORM+YEL+"M "+HIB+"~ "+NORM+YEL+"n "+GRN+"# "+GRN+"# "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+GRN+"# "+GRN+"# "+GRN+"# "+GRN+"# "+HIB+"~ "+GRN+"# "+HIB+"~ "+HIB+"~ \n"+  

 ""+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+HIB+"~ "+NORM+"\n");  

return 1;

}

write("inspect what?\n");

return 1;

}

