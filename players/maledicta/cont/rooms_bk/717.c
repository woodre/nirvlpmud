/* 10/11/05 Earwax: Converted to land. */

inherit "/players/earwax/housing/land.c";
#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
#define RNUM 717
inherit "players/maledicta/cont/inherit/room";


string rtype;
reset(arg){
  if(arg) return;

short_desc = "foothills";
set_light(1);
rtype = "hills";
long_desc = 
"                [32m#[2;37;0m [1;31m|[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [1;32m@[2;37;0m \n"+
"                [1;31m-[2;37;0m [1;31m+[2;37;0m [33mn[2;37;0m [32m#[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [1;32m@[2;37;0m    N\n"+
"                [32m#[2;37;0m [33mn[2;37;0m [1mM[2;37;0m [1;37mX[2;37;0m [33mn[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m   /|\n"+
"                [32m#[2;37;0m [33mn[2;37;0m [1mM[2;37;0m [1mM[2;37;0m [33mn[2;37;0m [32m#[2;37;0m [1;32m@[2;37;0m    | \n"+
"                [32m#[2;37;0m [32m#[2;37;0m [33mn[2;37;0m [1mM[2;37;0m [33mn[2;37;0m [32m#[2;37;0m [32m#[2;37;0m    | \n";
dest_dir = ({
"/players/maledicta/cont/rooms/685.c","north",
"/players/maledicta/cont/rooms/686.c","northeast",
"/players/maledicta/cont/rooms/684.c","northwest",
"/players/maledicta/cont/rooms/750.c","southeast",
"/players/maledicta/cont/rooms/718.c","east",
});
set_realm_name("PK Continent");
set_lot_size(3);
set_cost(310000);
setup_land();
}


init(){
   ::init();

}
is_cont_mal(){ return 1; }
query_room_type(){ return rtype; }
query_room_num(){ return RNUM; }
