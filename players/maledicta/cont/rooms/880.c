#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
#define RNUM 880
inherit "players/maledicta/cont/inherit/room";



object guard1;
object guard2;
reset(arg){
if(!present("cont_lizardguard")){
        guard1 = clone_object("/players/maledicta/cont/ltown/mobs/lguard.c");
        move_object(guard1, this_object());
        guard2 = clone_object("/players/maledicta/cont/ltown/mobs/lguard.c");
        move_object(guard2, this_object());
        }
/* Bp took out, dunno, put back -Bp */
if(!present("city_object")){
move_object(clone_object("/players/maledicta/cont/castles/terkula_obj"), this_object());
}
  if(arg) return;
/* Added by Sparrow to make compatable with both drivers */
if(version() == "3.01.02-DR") {
  string rtype;
}

short_desc = "a large plain";
set_light(1);
rtype = "plain";
long_desc = 
"                [1mM[2;37;0m [1mM[2;37;0m [33mn[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [1;31m|[2;37;0m [32m#[2;37;0m \n"+
"                [1mM[2;37;0m [1mM[2;37;0m [33mn[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [32m#[2;37;0m    N\n"+
"                [1mM[2;37;0m [1mM[2;37;0m [33mn[2;37;0m [1;37mX[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [34m~[2;37;0m   /|\n"+
"                [1mM[2;37;0m [34m~[2;37;0m [33mn[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [34m~[2;37;0m [34m~[2;37;0m    | \n"+
"                [34m~[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [34m~[2;37;0m [34m~[2;37;0m    | \n";
dest_dir = ({
"/players/maledicta/cont/rooms/848.c","north",
"/players/maledicta/cont/rooms/849.c","northeast",
"/players/maledicta/cont/rooms/847.c","northwest",
"/players/maledicta/cont/rooms/912.c","south",
"/players/maledicta/cont/rooms/913.c","southeast",
"/players/maledicta/cont/rooms/911.c","southwest",
"/players/maledicta/cont/rooms/881.c","east",
"/players/maledicta/cont/rooms/879.c","west",
});
}


init(){
   ::init();

}
is_cont_mal(){ return 1; }
query_room_type(){ return rtype; }
query_room_num(){ return RNUM; }
