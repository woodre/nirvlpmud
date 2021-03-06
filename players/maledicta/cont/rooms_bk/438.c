#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
#define RNUM 438
inherit "players/maledicta/cont/inherit/room";


string rtype;
reset(arg){
  if(arg) return;

short_desc = "a bend in the road";
set_light(1);
rtype = "road";
long_desc = 
"                [32m#[2;37;0m [32m#[2;37;0m [1;32m@[2;37;0m [1;31m+[2;37;0m [1;31m-[2;37;0m [1;31m-[2;37;0m [1;31m-[2;37;0m \n"+
"                [32m#[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [1;31m|[2;37;0m [1;32m@[2;37;0m [32m#[2;37;0m [34m~[2;37;0m    N\n"+
"                [32m#[2;37;0m [1;31m+[2;37;0m [1;31m-[2;37;0m [1;37mX[2;37;0m [1;32m@[2;37;0m [34m~[2;37;0m [32m#[2;37;0m   /|\n"+
"                [32m#[2;37;0m [1;31m|[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [34m~[2;37;0m [32m#[2;37;0m [1;32m@[2;37;0m    | \n"+
"                [1;31m-[2;37;0m [1;31m+[2;37;0m [32m#[2;37;0m [1;32m@[2;37;0m [1mM[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m    | \n";
dest_dir = ({
"/players/maledicta/cont/rooms/406.c","north",
"/players/maledicta/cont/rooms/407.c","northeast",
"/players/maledicta/cont/rooms/405.c","northwest",
"/players/maledicta/cont/rooms/470.c","south",
"/players/maledicta/cont/rooms/469.c","southwest",
"/players/maledicta/cont/rooms/439.c","east",
"/players/maledicta/cont/rooms/437.c","west",
});
}


init(){
   ::init();

}
is_cont_mal(){ return 1; }
query_room_type(){ return rtype; }
query_room_num(){ return RNUM; }
