#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
#define RNUM 466
inherit "players/maledicta/cont/inherit/room";


string rtype;
reset(arg){
  if(arg) return;

short_desc = "a forest";
set_light(1);
rtype = "forest";
long_desc = 
"                [33mn[2;37;0m [32m#[2;37;0m [1;32m@[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m \n"+
"                [33mn[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [32m#[2;37;0m [1;31m+[2;37;0m [1;31m-[2;37;0m    N\n"+
"                [32m#[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [1;37mX[2;37;0m [32m#[2;37;0m [1;31m|[2;37;0m [1;32m@[2;37;0m   /|\n"+
"                [1;31m-[2;37;0m [1;31m-[2;37;0m [1;31m-[2;37;0m [1;31m-[2;37;0m [1;31m-[2;37;0m [1;31m+[2;37;0m [32m#[2;37;0m    | \n"+
"                [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [1;31m|[2;37;0m [32m#[2;37;0m    | \n";
dest_dir = ({
"/players/maledicta/cont/rooms/434.c","north",
"/players/maledicta/cont/rooms/435.c","northeast",
"/players/maledicta/cont/rooms/433.c","northwest",
"/players/maledicta/cont/rooms/498.c","south",
"/players/maledicta/cont/rooms/499.c","southeast",
"/players/maledicta/cont/rooms/497.c","southwest",
"/players/maledicta/cont/rooms/467.c","east",
"/players/maledicta/cont/rooms/465.c","west",
});
}


init(){
   ::init();

}
is_cont_mal(){ return 1; }
query_room_type(){ return rtype; }
query_room_num(){ return RNUM; }
