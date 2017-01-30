#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
#define RNUM 457
inherit "players/maledicta/cont/inherit/room";


string rtype;
reset(arg){
  if(arg) return;

short_desc = "foothills";
set_light(1);
rtype = "hills";
long_desc = 
"                [32m#[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [33mn[2;37;0m [1;31m|[2;37;0m [33mn[2;37;0m \n"+
"                [34m~[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [33mn[2;37;0m [1;31m|[2;37;0m [33mn[2;37;0m    N\n"+
"                [34m~[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [1;37mX[2;37;0m [33mn[2;37;0m [1;31m|[2;37;0m [33mn[2;37;0m   /|\n"+
"                [1;32m@[2;37;0m [1;32m@[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [1;31m+[2;37;0m [1;31m-[2;37;0m    | \n"+
"                [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [1;31m|[2;37;0m [33mn[2;37;0m    | \n";
dest_dir = ({
"/players/maledicta/cont/rooms/426.c","northeast",
"/players/maledicta/cont/rooms/489.c","south",
"/players/maledicta/cont/rooms/490.c","southeast",
"/players/maledicta/cont/rooms/488.c","southwest",
"/players/maledicta/cont/rooms/458.c","east",
"/players/maledicta/cont/rooms/456.c","west",
});
}


init(){
   ::init();

}
is_cont_mal(){ return 1; }
query_room_type(){ return rtype; }
query_room_num(){ return RNUM; }
