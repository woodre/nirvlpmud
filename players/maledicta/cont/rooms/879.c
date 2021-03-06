#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
#define RNUM 879
inherit "players/maledicta/cont/inherit/room";



reset(arg){
/* Bp had commented out, put back, dunno... Bp */
if(!present("city_object")){
move_object(clone_object("/players/maledicta/cont/castles/red_obj"), this_object());
}
  if(arg) return;
/* Added by Sparrow to make compatable with both drivers */
if(version() == "3.01.02-DR") {
  string rtype;
}

short_desc = "foothills";
set_light(1);
rtype = "hills";
long_desc = 
"                [33mn[2;37;0m [1mM[2;37;0m [1mM[2;37;0m [33mn[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [1;31m|[2;37;0m \n"+
"                [1mM[2;37;0m [1mM[2;37;0m [1mM[2;37;0m [33mn[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m    N\n"+
"                [1mM[2;37;0m [1mM[2;37;0m [1mM[2;37;0m [1;37mX[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m   /|\n"+
"                [33mn[2;37;0m [1mM[2;37;0m [34m~[2;37;0m [33mn[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [34m~[2;37;0m    | \n"+
"                [34m~[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [34m~[2;37;0m    | \n";
dest_dir = ({
"/players/maledicta/cont/rooms/847.c","north",
"/players/maledicta/cont/rooms/848.c","northeast",
"/players/maledicta/cont/rooms/911.c","south",
"/players/maledicta/cont/rooms/912.c","southeast",
"/players/maledicta/cont/rooms/880.c","east",
});
}


init(){
   ::init();

}
is_cont_mal(){ return 1; }
query_room_type(){ return rtype; }
query_room_num(){ return RNUM; }
