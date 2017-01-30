#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
#define RNUM 313
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
"                [1;32m@[2;37;0m [1;32m@[2;37;0m [34m~[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [34m~[2;37;0m [34m~[2;37;0m \n"+
"                [1;32m@[2;37;0m [34m~[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [1;32m@[2;37;0m [32m#[2;37;0m [32m#[2;37;0m    N\n"+
"                [34m~[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [1;37mX[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [32m#[2;37;0m   /|\n"+
"                [1;32m@[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [32m#[2;37;0m [32m#[2;37;0m    | \n"+
"                [1;31m+[2;37;0m [1;31m-[2;37;0m [1;31m-[2;37;0m [1;31m-[2;37;0m [32m#[2;37;0m [34m~[2;37;0m [34m~[2;37;0m    | \n";
dest_dir = ({
"/players/maledicta/cont/rooms/281.c","north",
"/players/maledicta/cont/rooms/282.c","northeast",
"/players/maledicta/cont/rooms/280.c","northwest",
"/players/maledicta/cont/rooms/345.c","south",
"/players/maledicta/cont/rooms/346.c","southeast",
"/players/maledicta/cont/rooms/344.c","southwest",
"/players/maledicta/cont/rooms/314.c","east",
"/players/maledicta/cont/rooms/312.c","west",
});
}


init(){
   ::init();

}
is_cont_mal(){ return 1; }
query_room_type(){ return rtype; }
query_room_num(){ return RNUM; }
