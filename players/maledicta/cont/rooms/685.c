#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
#define RNUM 685
inherit "players/maledicta/cont/inherit/room";



reset(arg){
/* qualtor is closed for now -Bp
if(!present("city_object")){
move_object(clone_object("/players/daranath/qualtor/newstuff/obj/cont_entry"), this_object());
}
*/
  if(arg) return;
/* Added by Sparrow to make compatable with both drivers */
if(version() == "3.01.02-DR") {
  string rtype;
}

short_desc = "a large plain";
set_light(1);
rtype = "plain";
long_desc = 
"                [33mn[2;37;0m [1;31m|[2;37;0m [32m#[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [32m#[2;37;0m [32m#[2;37;0m \n"+
"                [32m#[2;37;0m [1;31m|[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [1;32m@[2;37;0m    N\n"+
"                [1;31m-[2;37;0m [1;31m+[2;37;0m [33mn[2;37;0m [1;37mX[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [1;32m@[2;37;0m   /|\n"+
"                [32m#[2;37;0m [33mn[2;37;0m [1mM[2;37;0m [33mn[2;37;0m [33mn[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m    | \n"+
"                [32m#[2;37;0m [33mn[2;37;0m [1mM[2;37;0m [1mM[2;37;0m [33mn[2;37;0m [32m#[2;37;0m [1;32m@[2;37;0m    | \n";
dest_dir = ({
"/players/maledicta/cont/rooms/653.c","north",
"/players/maledicta/cont/rooms/654.c","northeast",
"/players/maledicta/cont/rooms/652.c","northwest",
"/players/maledicta/cont/rooms/717.c","south",
"/players/maledicta/cont/rooms/718.c","southeast",
"/players/maledicta/cont/rooms/686.c","east",
"/players/maledicta/cont/rooms/684.c","west",
});
}


init(){
   ::init();

}
is_cont_mal(){ return 1; }
query_room_type(){ return rtype; }
query_room_num(){ return RNUM; }
