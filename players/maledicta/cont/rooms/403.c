#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
#define RNUM 403
inherit "players/maledicta/cont/inherit/room";



reset(arg){
  if(arg) return;
/* Added by Sparrow to make compatable with both drivers */
if(version() == "3.01.02-DR") {
  string rtype;
}

short_desc = "a large plain";
set_light(1);
rtype = "plain";
long_desc = 
"                [33mn[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [1;32m@[2;37;0m \n"+
"                [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [1;32m@[2;37;0m [1;31m+[2;37;0m    N\n"+
"                [32m#[2;37;0m [1;32m@[2;37;0m [32m#[2;37;0m [1;37mX[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [1;31m|[2;37;0m   /|\n"+
"                [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [32m#[2;37;0m [1;31m+[2;37;0m [1;31m-[2;37;0m [1;31m+[2;37;0m    | \n"+
"                [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [32m#[2;37;0m [1;31m|[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m    | \n";
dest_dir = ({
"/players/maledicta/cont/rooms/371.c","north",
"/players/maledicta/cont/rooms/372.c","northeast",
"/players/maledicta/cont/rooms/370.c","northwest",
"/players/maledicta/cont/rooms/435.c","south",
"/players/maledicta/cont/rooms/436.c","southeast",
"/players/maledicta/cont/rooms/434.c","southwest",
"/players/maledicta/cont/rooms/404.c","east",
"/players/maledicta/cont/rooms/402.c","west",
});
}


init(){
   ::init();

}
is_cont_mal(){ return 1; }
query_room_type(){ return rtype; }
query_room_num(){ return RNUM; }
