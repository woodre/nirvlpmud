#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
#define RNUM 590
inherit "players/maledicta/cont/inherit/room";



reset(arg){
  if(arg) return;
/* Added by Sparrow to make compatable with both drivers */
if(version() == "3.01.02-DR") {
  string rtype;
}

short_desc = "foothills";
set_light(1);
rtype = "hills";
long_desc = 
"                [1;31m|[2;37;0m [33mn[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m \n"+
"                [1;31m|[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [34m~[2;37;0m [34m~[2;37;0m    N\n"+
"                [1;31m+[2;37;0m [32m#[2;37;0m [33mn[2;37;0m [1;37mX[2;37;0m [32m#[2;37;0m [34m~[2;37;0m [34m~[2;37;0m   /|\n"+
"                [1;31m|[2;37;0m [32m#[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [34m~[2;37;0m    | \n"+
"                [1;31m|[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m    | \n";
dest_dir = ({
"/players/maledicta/cont/rooms/558.c","north",
"/players/maledicta/cont/rooms/559.c","northeast",
"/players/maledicta/cont/rooms/557.c","northwest",
"/players/maledicta/cont/rooms/622.c","south",
"/players/maledicta/cont/rooms/623.c","southeast",
"/players/maledicta/cont/rooms/621.c","southwest",
"/players/maledicta/cont/rooms/591.c","east",
"/players/maledicta/cont/rooms/589.c","west",
});
}


init(){
   ::init();

}
is_cont_mal(){ return 1; }
query_room_type(){ return rtype; }
query_room_num(){ return RNUM; }
