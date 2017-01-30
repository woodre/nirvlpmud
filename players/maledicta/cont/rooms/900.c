/* 10/11/05 Earwax: Converted to land. */

inherit "/players/earwax/housing/land.c";
#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
#define RNUM 900
inherit "players/maledicta/cont/inherit/room";



reset(arg){
  if(arg) return;
/* Added by Sparrow to make compatable with both drivers */
if(version() == "3.01.02-DR") {
  string rtype;
}

short_desc = "a forest";
set_light(1);
rtype = "forest";
long_desc = 
"                [34m~[2;37;0m [34m~[2;37;0m [1;31m-[2;37;0m [1;31m-[2;37;0m [1;31m-[2;37;0m [1;31m-[2;37;0m [1;31m-[2;37;0m \n"+
"                [34m~[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m    N\n"+
"                [34m~[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [1;37mX[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [32m#[2;37;0m   /|\n"+
"                [34m~[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [34m~[2;37;0m    | \n"+
"                [34m~[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [34m~[2;37;0m    | \n";
dest_dir = ({
"/players/maledicta/cont/rooms/868.c","north",
"/players/maledicta/cont/rooms/869.c","northeast",
"/players/maledicta/cont/rooms/901.c","east",
});
set_realm_name("PK Continent");
set_lot_size(9);
set_cost(550000);
setup_land();
}


init(){
   ::init();

}
is_cont_mal(){ return 1; }
query_room_type(){ return rtype; }
query_room_num(){ return RNUM; }
