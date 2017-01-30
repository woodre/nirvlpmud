#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
#define RNUM 826
inherit "players/maledicta/cont/inherit/room";


string rtype;
reset(arg){
  if(arg) return;

short_desc = "a large plain";
set_light(1);
rtype = "plain";
long_desc = 
"                [1mM[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [32m#[2;37;0m [34m~[2;37;0m [32m#[2;37;0m [32m#[2;37;0m \n"+
"                [33mn[2;37;0m [33mn[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [1;32m@[2;37;0m    N\n"+
"                [33mn[2;37;0m [33mn[2;37;0m [32m#[2;37;0m [1;37mX[2;37;0m [1;32m@[2;37;0m [32m#[2;37;0m [1;32m@[2;37;0m   /|\n"+
"                [33mn[2;37;0m [33mn[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [32m#[2;37;0m [32m#[2;37;0m    | \n"+
"                [33mn[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m    | \n";
dest_dir = ({
"/players/maledicta/cont/rooms/794.c","north",
"/players/maledicta/cont/rooms/795.c","northeast",
"/players/maledicta/cont/rooms/793.c","northwest",
"/players/maledicta/cont/rooms/827.c","east",
"/players/maledicta/cont/rooms/825.c","west",
});
}


init(){
   ::init();

}
is_cont_mal(){ return 1; }
query_room_type(){ return rtype; }
query_room_num(){ return RNUM; }
