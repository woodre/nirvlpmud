#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
#define RNUM 491
inherit "players/maledicta/cont/inherit/room";



reset(arg){
/*
if(!present("warrior_tower")){
move_object(clone_object("/players/maledicta/closed/w/OBJ/tower_entrance"), this_object());
}
*/
  if(arg) return;
/* Added by Sparrow to make compatable with both drivers */
if(version() == "3.01.02-DR") {
  string rtype;
}

short_desc = "a bend in the road";
set_light(1);
rtype = "road";
long_desc = 
"                [34m~[2;37;0m [34m~[2;37;0m [33mn[2;37;0m [1;31m|[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [34m~[2;37;0m \n"+
"                [33mn[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [1;31m|[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [33mn[2;37;0m    N\n"+
"                [33mn[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [1;37mX[2;37;0m [1;31m-[2;37;0m [1;31m-[2;37;0m [1;31m-[2;37;0m   /|\n"+
"                [1;32m@[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [1;31m|[2;37;0m [33mn[2;37;0m [32m#[2;37;0m [32m#[2;37;0m    | \n"+
"                [1;32m@[2;37;0m [32m#[2;37;0m [33mn[2;37;0m [1;31m|[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [32m#[2;37;0m    | \n";
dest_dir = ({
"/players/maledicta/cont/rooms/459.c","north",
"/players/maledicta/cont/rooms/460.c","northeast",
"/players/maledicta/cont/rooms/458.c","northwest",
"/players/maledicta/cont/rooms/523.c","south",
"/players/maledicta/cont/rooms/524.c","southeast",
"/players/maledicta/cont/rooms/522.c","southwest",
"/players/maledicta/cont/rooms/492.c","east",
"/players/maledicta/cont/rooms/490.c","west",
});
}


init(){
   ::init();

}
is_cont_mal(){ return 1; }
query_room_type(){ return rtype; }
query_room_num(){ return RNUM; }
