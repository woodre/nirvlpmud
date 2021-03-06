#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
#define RNUM 175
inherit "players/maledicta/cont/inherit/room2";



reset(arg){
  if(arg) return;
  /* Added by Sparrow to make compatable with both drivers */
if(version() == "3.01.02-DR") {
  string rtype;
}

set_light(-2);
rtype = "road";
long_desc = 
"                [33m#[2;37;0m [33m#[2;37;0m [33m#[2;37;0m [33m#[2;37;0m [33m#[2;37;0m [33m#[2;37;0m [33m#[2;37;0m \n"+
"                [33m#[2;37;0m [33m#[2;37;0m [33m#[2;37;0m [1;37m|[2;37;0m [33m#[2;37;0m [33m#[2;37;0m [33m#[2;37;0m    N\n"+
"                [34m~[2;37;0m [33m#[2;37;0m [33m#[2;37;0m [1;37mX[2;37;0m [33m#[2;37;0m [33m#[2;37;0m [33m#[2;37;0m   /|\n"+
"                [33m#[2;37;0m [1;37m-[2;37;0m [1;37m-[2;37;0m [1;37m+[2;37;0m [1;37m-[2;37;0m [1;37m-[2;37;0m [1;37m-[2;37;0m    | \n"+
"                [33m#[2;37;0m [33m#[2;37;0m [33m#[2;37;0m [1;37m|[2;37;0m [33m#[2;37;0m [33m#[2;37;0m [33m#[2;37;0m    | \n";
dest_dir = ({
"/players/maledicta/cont/urooms/143.c","north",
"/players/maledicta/cont/urooms/207.c","south",
"/players/maledicta/cont/urooms/208.c","southeast",
"/players/maledicta/cont/urooms/206.c","southwest",
});
}


short(){ return "Dark room"; }
init(){
   ::init();

}
is_underground_mal(){ return 1; }
query_room_type(){ return rtype; }
query_room_num(){ return RNUM; }
