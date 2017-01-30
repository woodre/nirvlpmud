#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
#define RNUM 433
inherit "players/maledicta/cont/inherit/room";


string rtype;
reset(arg){
  if(arg) return;

short_desc = "a forest";
set_light(1);
rtype = "forest";
long_desc = 
"                [1mM[2;37;0m [33mn[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m \n"+
"                [1mM[2;37;0m [33mn[2;37;0m [32m#[2;37;0m [1;32m@[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [1;32m@[2;37;0m    N\n"+
"                [34m~[2;37;0m [33mn[2;37;0m [1;32m@[2;37;0m [1;37mX[2;37;0m [1;32m@[2;37;0m [32m#[2;37;0m [1;31m+[2;37;0m   /|\n"+
"                [33mn[2;37;0m [32m#[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [32m#[2;37;0m [1;31m|[2;37;0m    | \n"+
"                [1;31m-[2;37;0m [1;31m-[2;37;0m [1;31m-[2;37;0m [1;31m-[2;37;0m [1;31m-[2;37;0m [1;31m-[2;37;0m [1;31m+[2;37;0m    | \n";
dest_dir = ({
"/players/maledicta/cont/rooms/401.c","north",
"/players/maledicta/cont/rooms/402.c","northeast",
"/players/maledicta/cont/rooms/400.c","northwest",
"/players/maledicta/cont/rooms/465.c","south",
"/players/maledicta/cont/rooms/466.c","southeast",
"/players/maledicta/cont/rooms/464.c","southwest",
"/players/maledicta/cont/rooms/434.c","east",
"/players/maledicta/cont/rooms/432.c","west",
});
}


init(){
   ::init();

}
is_cont_mal(){ return 1; }
query_room_type(){ return rtype; }
query_room_num(){ return RNUM; }
