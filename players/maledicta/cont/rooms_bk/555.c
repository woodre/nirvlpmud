#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
#define RNUM 555
inherit "players/maledicta/cont/inherit/room";


string rtype;
reset(arg){
  if(arg) return;

short_desc = "a road";
set_light(1);
rtype = "road";
long_desc = 
"                [33mn[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [1;31m+[2;37;0m [1;31m-[2;37;0m [1;31m-[2;37;0m [1;31m-[2;37;0m \n"+
"                [1;32m@[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [1;31m|[2;37;0m [33mn[2;37;0m [32m#[2;37;0m [32m#[2;37;0m    N\n"+
"                [1;32m@[2;37;0m [32m#[2;37;0m [33mn[2;37;0m [1;37mX[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [32m#[2;37;0m   /|\n"+
"                [1;31m-[2;37;0m [1;31m-[2;37;0m [1;31m-[2;37;0m [1;31m+[2;37;0m [32m#[2;37;0m [33mn[2;37;0m [33mn[2;37;0m    | \n"+
"                [32m#[2;37;0m [32m#[2;37;0m [33mn[2;37;0m [1;31m|[2;37;0m [32m#[2;37;0m [33mn[2;37;0m [33mn[2;37;0m    | \n";
dest_dir = ({
"/players/maledicta/cont/rooms/523.c","north",
"/players/maledicta/cont/rooms/524.c","northeast",
"/players/maledicta/cont/rooms/522.c","northwest",
"/players/maledicta/cont/rooms/587.c","south",
"/players/maledicta/cont/rooms/588.c","southeast",
"/players/maledicta/cont/rooms/586.c","southwest",
"/players/maledicta/cont/rooms/556.c","east",
"/players/maledicta/cont/rooms/554.c","west",
});
}


init(){
   ::init();

}
is_cont_mal(){ return 1; }
query_room_type(){ return rtype; }
query_room_num(){ return RNUM; }
