/* 10/11/05 Earwax: Converted to land. */

inherit "/players/earwax/housing/land.c";
#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
#define RNUM 562
inherit "players/maledicta/cont/inherit/room";


string rtype;
reset(arg){
  if(arg) return;

short_desc = "a large plain";
set_light(1);
rtype = "plain";
long_desc = 
"                [1;31m-[2;37;0m [1;31m-[2;37;0m [1;31m-[2;37;0m [1;31m-[2;37;0m [1;31m-[2;37;0m [1;31m+[2;37;0m [32m#[2;37;0m \n"+
"                [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [1;31m|[2;37;0m [32m#[2;37;0m    N\n"+
"                [32m#[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [1;37mX[2;37;0m [32m#[2;37;0m [1;31m|[2;37;0m [1mM[2;37;0m   /|\n"+
"                [32m#[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [32m#[2;37;0m [1;31m|[2;37;0m [1mM[2;37;0m    | \n"+
"                [32m#[2;37;0m [32m#[2;37;0m [34m~[2;37;0m [1;32m@[2;37;0m [32m#[2;37;0m [1;31m+[2;37;0m [1;31m-[2;37;0m    | \n";
dest_dir = ({
"/players/maledicta/cont/rooms/530.c","north",
"/players/maledicta/cont/rooms/531.c","northeast",
"/players/maledicta/cont/rooms/529.c","northwest",
"/players/maledicta/cont/rooms/595.c","southeast",
"/players/maledicta/cont/rooms/563.c","east",
});
set_realm_name("PK Continent");
set_lot_size(-2);
set_cost(1000000);
setup_land();
}


init(){
   ::init();

}
is_cont_mal(){ return 1; }
query_room_type(){ return rtype; }
query_room_num(){ return RNUM; }
