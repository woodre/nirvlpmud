#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
#define RNUM 539
inherit "players/maledicta/cont/inherit/room";


string rtype;
reset(arg){
  if(arg) return;

short_desc = "a forest";
set_light(1);
rtype = "forest";
long_desc = 
"                [32m#[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [34m~[2;37;0m \n"+
"                [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [34m~[2;37;0m [34m~[2;37;0m    N\n"+
"                [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [1;37mX[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [34m~[2;37;0m   /|\n"+
"                [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m    | \n"+
"                [1;32m@[2;37;0m [1;32m@[2;37;0m [1;31m+[2;37;0m [1;31m-[2;37;0m [1;31m-[2;37;0m [1;31m-[2;37;0m [1;31m-[2;37;0m    | \n";
dest_dir = ({
"/players/maledicta/cont/rooms/507.c","north",
"/players/maledicta/cont/rooms/508.c","northeast",
"/players/maledicta/cont/rooms/506.c","northwest",
"/players/maledicta/cont/rooms/571.c","south",
"/players/maledicta/cont/rooms/572.c","southeast",
"/players/maledicta/cont/rooms/570.c","southwest",
"/players/maledicta/cont/rooms/540.c","east",
"/players/maledicta/cont/rooms/538.c","west",
});
}


init(){
   ::init();

}
is_cont_mal(){ return 1; }
query_room_type(){ return rtype; }
query_room_num(){ return RNUM; }
