#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
#define RNUM 278
inherit "players/maledicta/cont/inherit/room";


string rtype;
reset(arg){
  if(arg) return;

short_desc = "a forest";
set_light(1);
rtype = "forest";
long_desc = 
"                [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [34m~[2;37;0m \n"+
"                [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [34m~[2;37;0m [32m#[2;37;0m    N\n"+
"                [34m~[2;37;0m [34m~[2;37;0m [1;32m@[2;37;0m [1;37mX[2;37;0m [34m~[2;37;0m [32m#[2;37;0m [32m#[2;37;0m   /|\n"+
"                [34m~[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [1;32m@[2;37;0m    | \n"+
"                [34m~[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [1;32m@[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [1;32m@[2;37;0m    | \n";
dest_dir = ({
"/players/maledicta/cont/rooms/246.c","north",
"/players/maledicta/cont/rooms/247.c","northeast",
"/players/maledicta/cont/rooms/245.c","northwest",
"/players/maledicta/cont/rooms/277.c","west",
});
}


init(){
   ::init();

}
is_cont_mal(){ return 1; }
query_room_type(){ return rtype; }
query_room_num(){ return RNUM; }
