#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
#define RNUM 180
inherit "players/maledicta/cont/inherit/room";


string rtype;
reset(arg){
  if(arg) return;

short_desc = "a forest";
set_light(1);
rtype = "forest";
long_desc = 
" [1;32m@[2;37;0m [1;32m@[2;37;0m [32m#[2;37;0m [32m#[2;37;0m [1;34m~[2;37;0m   You find yourself in a forest of giant trees.\n"+
" [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [32m#[2;37;0m [32m#[2;37;0m All around these behemoths stand as guardians\n"+
" [1;32m@[2;37;0m [1;32m@[2;37;0m X [1;32m@[2;37;0m [32m#[2;37;0m to this quiet forest. Vegetation is scattered\n"+
" [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m throughout the forest as well as saplings.\n"+
" [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m [1;32m@[2;37;0m\n";
dest_dir = ({
"/players/maledicta/cont/rooms/148.c","north",
"/players/maledicta/cont/rooms/212.c","south",
"/players/maledicta/cont/rooms/181.c","east",
"/players/maledicta/cont/rooms/179.c","west",
});
items = ({"trees",
"Giant trees that stand over 200 ft tall",
"saplings",
"Very young trees that seem to grow well here",
"vegetation",
"Scattered ferns and other lush and full plants",
"canopies",
"Large green canopies that filter the available light",
});
}


init(){
   ::init();

}
is_cont_mal(){ return 1; }
query_room_type(){ return rtype; }
query_room_num(){ return RNUM; }
