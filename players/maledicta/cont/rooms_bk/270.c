#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
#define RNUM 270
inherit "players/maledicta/cont/inherit/room";


string rtype;
reset(arg){
  if(arg) return;

short_desc = "foothills";
set_light(1);
rtype = "hills";
long_desc = 
"                [34m~[2;37;0m [34m~[2;37;0m [1mM[2;37;0m [33mn[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m \n"+
"                [34m~[2;37;0m [1mM[2;37;0m [1mM[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m    N\n"+
"                [34m~[2;37;0m [1mM[2;37;0m [1mM[2;37;0m [1;37mX[2;37;0m [32m#[2;37;0m [33mn[2;37;0m [1;32m@[2;37;0m   /|\n"+
"                [34m~[2;37;0m [1mM[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [32m#[2;37;0m [33mn[2;37;0m [33mn[2;37;0m    | \n"+
"                [34m~[2;37;0m [1mM[2;37;0m [1mM[2;37;0m [33mn[2;37;0m [32m#[2;37;0m [33mn[2;37;0m [32m#[2;37;0m    | \n";
dest_dir = ({
"/players/maledicta/cont/rooms/238.c","north",
"/players/maledicta/cont/rooms/239.c","northeast",
"/players/maledicta/cont/rooms/302.c","south",
"/players/maledicta/cont/rooms/303.c","southeast",
"/players/maledicta/cont/rooms/301.c","southwest",
"/players/maledicta/cont/rooms/271.c","east",
});
}


init(){
   ::init();

}
is_cont_mal(){ return 1; }
query_room_type(){ return rtype; }
query_room_num(){ return RNUM; }
